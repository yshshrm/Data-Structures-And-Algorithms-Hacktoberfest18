import logging
import random
import numpy as np
from cvxopt import matrix, solvers
import copy
import time
import pickle


class BinarySVM:
    def __init__(self, kernel='linear', alg='SMO', gamma=None, degree=None, C=1.0, verbose=False):
        self.eps = 1e-6
        self.alg = alg
        self.C, self.w, self.b, self.ksi = C, [], 0.0, []
        self.n_sv = -1
        self.sv_x, self.sv_y, self.alphas = np.zeros(0), np.zeros(0), np.zeros(0)
        self.kernel = kernel
        if self.kernel == 'poly':
            self.degree = degree if degree is not None else 2.0
        elif self.kernel == 'rbf':
            self.gamma = gamma
        if verbose:
            logging.basicConfig(level=logging.INFO)
        else:
            logging.basicConfig(level=logging.WARNING)

    def _kernel(self, x, z=None):
        if z is None:
            z = x
        if self.kernel == 'linear':
            return np.dot(x, z.T)
        elif self.kernel == 'poly':
            return (np.dot(x, z.T) + 1.0) ** self.degree
        elif self.kernel == 'rbf':
            xx, zz = np.sum(x*x, axis=1), np.sum(z*z, axis=1)
            res = -2.0 * np.dot(x, z.T) + xx.reshape((-1, 1)) + zz.reshape((1, -1))
            # del xx, zz
            return np.exp(-self.gamma * res)
        # elif self.kernel == 'sigmoid':
        #     pass
        else:
            print 'Unknown kernel'
            exit(3)

    def _SMO(self, K, y):
        # def select_pairs():
        #     # return -1, -1 if not proper alphas are found
        #     return 1, 1
        print 'Begin SMO...'
        tol, m = 1e-4, len(y)  # m: number of training samples
        self.alphas, self.b = np.zeros(m), 0.0
        niter = 0
        while True:
            # i, j = select_pairs()
            num_against_kkt_alphas = 0
            unbounded = [i for i in xrange(m) if self.eps < self.alphas[i] < self.C - self.eps]
            bounded = [i for i in xrange(m) if self.alphas[i] <= self.eps or self.alphas[i] >= self.C - self.eps]
            # for i in xrange(m):
            for i in unbounded+bounded:
                yi, ai_old = y[i], self.alphas[i]
                Ei = np.sum(self.alphas * y * K[i]) + self.b - yi
                logging.debug('Ei = ' + str(Ei))
                if (yi*Ei < -tol and ai_old < self.C) or (yi*Ei > tol and ai_old > 0):
                    num_against_kkt_alphas += 1
                    for j in xrange(m):
                        if j==i:
                            continue
                        eta = K[i, i] + K[j, j] - 2.0 * K[i, j]
                        logging.debug('eta = ' + str(eta))
                        if np.abs(eta) <= self.eps:  # eta == 0.0
                            continue
                        # print 'Ei', Ei
                        # print 'Ej_list', Ej_list
                        # print '|Ej-Ei|', np.abs(Ei - Ej_list)
                        print 'Choose', i, 'and', j
                        yi, yj, ai_old, aj_old = y[i], y[j], self.alphas[i], self.alphas[j]
                        s = yi * yj
                        Ej = np.sum(self.alphas * y * K[j]) + self.b - yj
                        # logging.debug('Ei = ' + str(Ei))

                        # input('*******\n')
                        if yi != yj:
                            L, H = max(0.0, aj_old - ai_old), min(self.C, self.C + aj_old - ai_old)
                        else:
                            L, H = max(0.0, ai_old + aj_old - self.C), min(self.C, ai_old + aj_old)
                        logging.debug('L = ' + str(L) + ', H = ' + str(H))
                        if H - L < self.eps:
                            continue

                        print 'delta_j:', yj, Ei - Ej, eta
                        aj_new = aj_old + yj * (Ei - Ej) / eta
                        logging.debug('i, j, yi, yj = ' + ' '.join(map(str, [i, j, yi, yj])))
                        logging.debug('Ei = ' + str(Ei) + ', Ej = ' + str(Ej))
                        logging.debug('aj_new = ' + str(aj_new))
                        if aj_new > H:
                            aj_new = H
                        elif aj_new < L:
                            aj_new = L
                        delta_j = aj_new - aj_old
                        print 'alphas:', self.alphas
                        print aj_new, aj_old
                        if abs(delta_j) < 1e-4:
                            print "j = %d, is not moving enough" % j
                            continue
                        ai_new = ai_old - s * delta_j
                        delta_i = ai_new - ai_old
                        self.alphas[i], self.alphas[j] = ai_new, aj_new
                        print 'New alpha_i and alpha_j:', ai_new, aj_new
                        bi = self.b - Ei - yi * delta_i * K[i, i] - yj * delta_j * K[i, j]
                        bj = self.b - Ej - yi * delta_i * K[i, j] - yj * delta_j * K[j, j]
                        # self.b = (bi + bj) / 2.0
                        if 0 < ai_new < self.C:
                            self.b = bi
                        elif 0 < aj_new < self.C:
                            self.b = bj
                        else:
                            self.b = (bi + bj) / 2.0
                        break
            if num_against_kkt_alphas == 0:
                break
            else:
                niter += 1
                print 'In iteration', niter, ',', num_against_kkt_alphas, 'alphas are against KKT conditions'
        print 'Finish SMO...'
        return self.alphas, self.b

    def _SMO1(self, K, y):
        print 'Begin SMO...'
        m = len(y)
        self.alphas, self.b = np.zeros(m), 0.0
        tol = self.eps
        passes, max_passes = 0, 10
        logging.debug('m = ' + str(m))
        n_iter = 0
        while passes < max_passes:
            n_iter += 1
            logging.info('Iteration ' + str(n_iter))
            logging.debug('passes = ' + str(passes))
            num_changed_alphas = 0
            # run over pair (i, j).  But for some alpha_i, only choose one alpha_j in an iteration epoch.
            for i in xrange(m):
                # Ei = self.f(x[i]) - y[i]
                yi, ai_old = y[i], self.alphas[i]
                Ei = np.sum(self.alphas * y * K[i]) + self.b - yi
                logging.debug('Ei = ' + str(Ei))
                if (yi*Ei < -tol and ai_old < self.C) or (yi*Ei > tol and ai_old > 0):
                    # logging.debug('Now select j!')
                    # select j!=i randomly
                    # while True:
                    #     j = random.randint(0, m-1)
                    #     yj = y[j]
                    #     Ej = np.sum(self.alphas * y * K[j]) + self.b - yj
                    #     if abs(Ej - Ei) > self.eps:
                    #         break
                    for j in xrange(m):
                        if j == i:
                            continue
                        # need to update Ei, because changes in self.alphas may change Ei
                        # Ei = np.sum(self.alphas * y * K[i]) + self.b - yi
                        yj = y[j]
                        Ej = np.sum(self.alphas * y * K[j]) + self.b - yj
                        if abs(Ej - Ei) <= self.eps:
                            continue
                        aj_old = self.alphas[j]
                        if yi != yj:
                            L, H = max(0.0, aj_old - ai_old), min(self.C, self.C + aj_old - ai_old)
                        else:
                            L, H = max(0.0, ai_old + aj_old - self.C), min(self.C, ai_old + aj_old)
                        logging.debug('L = ' + str(L) + ', H = ' + str(H))
                        if H - L < self.eps:
                            continue
                        eta = 2.0 * K[i, j] - K[i, i] - K[j, j]
                        logging.debug('eta = ' + str(eta))
                        if eta >= -self.eps:  # eta >= 0.0
                            continue
                        aj_new = aj_old - yj * (Ei - Ej) / eta
                        logging.debug('i, j, yi, yj = ' + ' '.join(map(str, [i, j, yi, yj])))
                        logging.debug('Ei = ' + str(Ei) + ', Ej = ' + str(Ej))
                        logging.debug('aj_new = ' + str(aj_new))
                        if aj_new > H:
                            aj_new = H
                        elif aj_new < L:
                            aj_new = L
                        delta_j = aj_new - aj_old
                        if abs(delta_j) < 1e-4:
                            print "j = %d, is not moving enough" % j
                            continue
                        ai_new = ai_old + yi * yj * (aj_old - aj_new)
                        # ai_new = ai_old + yi * yj * delta_j
                        delta_i = ai_new - ai_old
                        self.alphas[i], self.alphas[j] = ai_new, aj_new
                        bi = self.b - Ei - yi * delta_i * K[i, i] - yj * delta_j * K[i, j]
                        bj = self.b - Ej - yi * delta_i * K[i, j] - yj * delta_j * K[j, j]
                        if 0 < ai_new < self.C:
                            self.b = bi
                        elif 0 < aj_new < self.C:
                            self.b = bj
                        else:
                            self.b = (bi + bj) / 2.0
                        num_changed_alphas += 1
                        break
            if num_changed_alphas == 0:
                passes += 1
            else:
                passes = 0
        print 'Finish SMO...'
        return self.alphas, self.b

    def _SMO2(self, K, y):
        def take_step(j, i, Ei, Ej=None):
            if j == i:
                return False
            yi, yj, ai_old, aj_old = y[i], y[j], self.alphas[i], self.alphas[j]
            if Ej is None:
                Ej = np.sum(self.alphas * y * K[j]) + self.b - yj
            # s = yj * yi

            if yi != yj:
                L, H = max(0.0, aj_old - ai_old), min(self.C, self.C + aj_old - ai_old)
            else:
                L, H = max(0.0, ai_old + aj_old - self.C), min(self.C, ai_old + aj_old)
            logging.debug('L = ' + str(L) + ', H = ' + str(H))
            if H - L < self.eps:
                return False
            eta = 2.0 * K[i, j] - K[i, i] - K[j, j]
            if eta < -self.eps:
                ai_new = ai_old - yi * (Ej - Ei) / eta
                if ai_new < L:
                    ai_new = L
                elif ai_new > H:
                    ai_new = H
            else:
                return False
                # Lobj, Hobj = W(ai=L), W(ai=H)
                # if Lobj > Hobj + self.eps:
                #     ai_new = L
                # elif Lobj < Hobj - self.eps:
                #     ai_new = H
                # else:
                #     ai_new = ai_old

            if ai_new < self.eps:
                ai_new = 0.0
            elif ai_new > self.C - self.eps:
                ai_new = self.C
            if abs(ai_new - ai_old) < self.eps * (ai_new + ai_old + self.eps):
                return False
            aj_new = aj_old + yj * yi * (ai_old - ai_new)
            # update bias
            self.alphas[i], self.alphas[j] = ai_new, aj_new
            delta_j = aj_new - aj_old
            delta_i = ai_new - ai_old
            bi = self.b - Ei - yi * delta_i * K[i, i] - yj * delta_j * K[i, j]
            bj = self.b - Ej - yi * delta_i * K[i, j] - yj * delta_j * K[j, j]
            if 0 < ai_new < self.C:
                self.b = bi
            elif 0 < aj_new < self.C:
                self.b = bj
            else:
                self.b = (bi + bj) / 2.0
            # update w, if linear SVM
            # update error cache
            print 'Choosing (', i, ',', j, ')'
            return True

        def examine_example(i):
            yi, ai_old = y[i], self.alphas[i]
            Ei = np.sum(self.alphas * y * K[i]) + self.b - yi
            if (yi*Ei < -tol and ai_old < self.C) or (yi*Ei > tol and ai_old > 0):
                # calculate ids of non-zero and non-C alphas
                mid_alpha_ids = filter(lambda j: 0.0 < self.alphas[j] < self.C, xrange(m))
                if len(mid_alpha_ids) > 1:
                    # todo: second heuristic
                    for j in xrange(m):
                        Ej = np.sum(self.alphas * y * K[j]) + self.b - y[j]
                        if abs(Ei - Ej) < self.eps:
                            continue
                        if take_step(j, i, Ei, Ej):
                            return True
                        else:
                            break
                for j in mid_alpha_ids:
                    if take_step(j, i, Ei):
                            return True
                for j in xrange(m):
                    if take_step(j, i, Ei):
                        return True
            return False
        print 'Begin SMO...'
        m = len(y)
        self.alphas, self.b = np.zeros(m), 0.0
        tol = self.eps
        num_changed_alphas, examine_all = 0, True  # examine_all=True means needing to examine all examples
        while num_changed_alphas > 0 or examine_all:
            num_changed_alphas = 0
            if examine_all:
                for i in xrange(m):
                    num_changed_alphas += examine_example(i)
            else:
                for i in xrange(m):
                    if 0 < self.alphas[i] < self.C:
                        num_changed_alphas += examine_example(i)
            if examine_all:
                examine_all = False
            elif num_changed_alphas == 0:
                examine_all = 1
        # passes, max_passes = 0, 10
        # logging.debug('m = ' + str(m))
        # n_iter = 0
        # while passes < max_passes:
        #     n_iter += 1
        #     logging.info('Iteration ' + str(n_iter))
        #     logging.debug('passes = ' + str(passes))
        #     num_changed_alphas = 0
        #     # run over pair (i, j).  But for some alpha_i, only choose one alpha_j in an iteration epoch.
        #     for i in xrange(m):
        #         # Ei = self.f(x[i]) - y[i]
        #         yi, ai_old = y[i], self.alphas[i]
        #         Ei = np.sum(self.alphas * y * K[i]) + self.b - yi
        #         logging.debug('Ei = ' + str(Ei))
        #         if (yi*Ei < -tol and ai_old < self.C) or (yi*Ei > tol and ai_old > 0):
        #             # logging.debug('Now select j!')
        #             # select j!=i randomly
        #             # while True:
        #             #     j = random.randint(0, m-1)
        #             #     yj = y[j]
        #             #     Ej = np.sum(self.alphas * y * K[j]) + self.b - yj
        #             #     if abs(Ej - Ei) > self.eps:
        #             #         break
        #             for j in xrange(m):
        #                 if j == i:
        #                     continue
        #                 # need to update Ei, because changes in self.alphas may change Ei
        #                 # Ei = np.sum(self.alphas * y * K[i]) + self.b - yi
        #                 yj = y[j]
        #                 Ej = np.sum(self.alphas * y * K[j]) + self.b - yj
        #                 if abs(Ej - Ei) <= self.eps:
        #                     continue
        #                 aj_old = self.alphas[j]
        #                 if yi != yj:
        #                     L, H = max(0.0, aj_old - ai_old), min(self.C, self.C + aj_old - ai_old)
        #                 else:
        #                     L, H = max(0.0, ai_old + aj_old - self.C), min(self.C, ai_old + aj_old)
        #                 logging.debug('L = ' + str(L) + ', H = ' + str(H))
        #                 if H - L < self.eps:
        #                     continue
        #                 eta = 2.0 * K[i, j] - K[i, i] - K[j, j]
        #                 logging.debug('eta = ' + str(eta))
        #                 if eta >= -self.eps:  # eta >= 0.0
        #                     continue
        #                 aj_new = aj_old - yj * (Ei - Ej) / eta
        #                 logging.debug('i, j, yi, yj = ' + ' '.join(map(str, [i, j, yi, yj])))
        #                 logging.debug('Ei = ' + str(Ei) + ', Ej = ' + str(Ej))
        #                 logging.debug('aj_new = ' + str(aj_new))
        #                 if aj_new > H:
        #                     aj_new = H
        #                 elif aj_new < L:
        #                     aj_new = L
        #                 delta_j = aj_new - aj_old
        #                 if abs(delta_j) < 1e-4:
        #                     print "j = %d, is not moving enough" % j
        #                     continue
        #                 ai_new = ai_old + yi * yj * (aj_old - aj_new)
        #                 delta_i = ai_new - ai_old
        #                 self.alphas[i], self.alphas[j] = ai_new, aj_new
        #                 bi = self.b - Ei - yi * delta_i * K[i, i] - yj * delta_j * K[i, j]
        #                 bj = self.b - Ej - yi * delta_i * K[i, j] - yj * delta_j * K[j, j]
        #                 if 0 < ai_new < self.C:
        #                     self.b = bi
        #                 elif 0 < aj_new < self.C:
        #                     self.b = bj
        #                 else:
        #                     self.b = (bi + bj) / 2.0
        #                 num_changed_alphas += 1
        #                 break
        #     if num_changed_alphas == 0:
        #         passes += 1
        #     else:
        #         passes = 0
        print 'Finish SMO...'
        return self.alphas, self.b

    def _SMO3(self, K, y):
        def choose_alphas():  # choose alpha heuristically
            yield -2, -2, 0.0, 0.0  # initiate
            passes, max_passes, changed = 0, 1, False
            while passes < max_passes:
                num_changed_alphas = 0
                # unbounded = [i for i in xrange(m) if self.eps < self.alphas[i] < self.C - self.eps]
                # bounded = [i for i in xrange(m) if self.alphas[i] <= self.eps or self.alphas[i] >= self.C - self.eps]
                range_i = np.argsort((self.alphas - self.eps) * (self.eps - self.C + self.alphas))
                # print 'range_i:', range_i
                for i in range_i:
                    # print 'Try i:', i
                    yi, ai_old = y[i], self.alphas[i]
                    Ei = np.sum(self.alphas * y * K[i]) + self.b - yi
                    logging.debug('Ei = ' + str(Ei))
                    if (yi*Ei < -tol and ai_old < self.C) or (yi*Ei > tol and ai_old > 0):
                        # print i, 'is against KKT conditions'
                        range_j = range(m)
                        random.shuffle(range_j)
                        # print 'range j:', range_j
                        # for j in xrange(m):
                        for j in range_j:
                            if j == i:
                                continue
                            yj = y[j]
                            Ej = np.sum(self.alphas * y * K[j]) + self.b - yj
                            if abs(Ej - Ei) <= self.eps:
                                continue
                            yield (i, j, Ei, Ej)
                            changed = yield (i, j, Ei, Ej)  # receive return value from the main function
                            if changed:  # if (i, j) pair changed in the latest iteration
                                num_changed_alphas += 1
                                break
                    else:
                        # print i, 'satisfies KKT conditions'
                        pass
                if num_changed_alphas == 0:
                    passes += 1
                else:
                    passes = 0
            yield -1, -1, 0.0, 0.0

        print 'Begin SMO3...'
        m = len(y)
        self.alphas, self.b = np.zeros(m), 0.0
        tol = self.eps
        logging.debug('m = ' + str(m))
        gen = choose_alphas()
        n_iter = 0
        updated = False
        gen.next()
        while True:
            n_iter += 1
            logging.info('Iteration ' + str(n_iter))
            # logging.debug('passes = ' + str(passes))
            # run over pair (i, j).  But for some alpha_i, only choose one alpha_j in an iteration epoch.
            try:
                gen.send(updated)
                i, j, Ei, Ej = gen.next()
            except StopIteration, e:
                break
            # print '(i, j)', i, j
            # input('********\n')
            if i == -1:  # no more (i, j) pairs against KKT condition
                break
            updated = False
            yi, yj, ai_old, aj_old = y[i], y[j], self.alphas[i], self.alphas[j]
            if yi != yj:
                L, H = max(0.0, aj_old - ai_old), min(self.C, self.C + aj_old - ai_old)
            else:
                L, H = max(0.0, ai_old + aj_old - self.C), min(self.C, ai_old + aj_old)
            logging.debug('L = ' + str(L) + ', H = ' + str(H))
            if H - L < self.eps:
                continue
            eta = 2.0 * K[i, j] - K[i, i] - K[j, j]
            logging.debug('eta = ' + str(eta))
            if eta >= 0:  # eta >= 0.0
                continue
            aj_new = aj_old - yj * (Ei - Ej) / eta
            logging.debug('i, j, yi, yj = ' + ' '.join(map(str, [i, j, yi, yj])))
            logging.debug('Ei = ' + str(Ei) + ', Ej = ' + str(Ej))
            logging.debug('aj_new = ' + str(aj_new))
            if aj_new > H:
                aj_new = H
            elif aj_new < L:
                aj_new = L
            delta_j = aj_new - aj_old
            if abs(delta_j) < 1e-4:
                # print "j = %d, is not moving enough" % j
                continue
            ai_new = ai_old + yi * yj * (aj_old - aj_new)
            # ai_new = ai_old + yi * yj * delta_j
            delta_i = ai_new - ai_old
            self.alphas[i], self.alphas[j] = ai_new, aj_new
            bi = self.b - Ei - yi * delta_i * K[i, i] - yj * delta_j * K[i, j]
            bj = self.b - Ej - yi * delta_i * K[i, j] - yj * delta_j * K[j, j]
            if 0 < ai_new < self.C:
                self.b = bi
            elif 0 < aj_new < self.C:
                self.b = bj
            else:
                self.b = (bi + bj) / 2.0
            updated = True
            print 'Updated through', i, j
            print 'alphas:', self.alphas

        print 'Finish SMO3...'
        return self.alphas, self.b

    def _SMO4(self, K, y):
        def getE(i):
            return np.sum(self.alphas * y * K[i]) + self.b - y[i]
        # assert np.linalg.norm(K - K.T, 'F')
        print 'Begin SMO...'
        # print 'K = ', K
        tol, m = 1e-4, len(y)  # m: number of training samples
        self.alphas, self.b = np.zeros(m), 0.0
        niter = 0
        while True:
            num_against_kkt_alphas = 0
            for i in xrange(m):
                yi, ai_old = y[i], self.alphas[i]
                # Ei = np.sum(self.alphas * y * K[i]) + self.b - yi
                Ei = getE(i)
                logging.debug('Ei = ' + str(Ei))
                if (yi*Ei < -tol and ai_old < self.C) or (yi*Ei > tol and ai_old > 0):
                    num_against_kkt_alphas += 1
                    for j in xrange(m):
                        if j == i:
                            continue
                        eta = K[i, i] + K[j, j] - 2.0 * K[i, j]
                        logging.debug('eta = ' + str(eta))
                        if eta <= 0:  # eta == 0.0
                            continue
                        # print 'Ei', Ei
                        # print 'Ej_list', Ej_list
                        # print '|Ej-Ei|', np.abs(Ei - Ej_list)
                        # print 'Choose', i, 'and', j
                        yj, aj_old = y[j], self.alphas[j]
                        s = yi * yj
                        # Ej = np.sum(self.alphas * y * K[j]) + self.b - yj
                        Ej = getE(j)
                        if yi != yj:
                            L, H = max(0.0, aj_old - ai_old), min(self.C, self.C + aj_old - ai_old)
                        else:
                            L, H = max(0.0, ai_old + aj_old - self.C), min(self.C, ai_old + aj_old)
                        logging.debug('L = ' + str(L) + ', H = ' + str(H))
                        if H - L < self.eps:
                            continue

                        # print 'delta_j:', yj, Ei - Ej, eta
                        aj_new = aj_old + yj * (Ei - Ej) / eta
                        logging.debug('i, j, yi, yj = ' + ' '.join(map(str, [i, j, yi, yj])))
                        logging.debug('Ei = ' + str(Ei) + ', Ej = ' + str(Ej))
                        logging.debug('aj_new = ' + str(aj_new))
                        if aj_new > H:
                            aj_new = H
                        elif aj_new < L:
                            aj_new = L
                        delta_j = aj_new - aj_old
                        # print 'alphas:', self.alphas
                        # print aj_new, aj_old
                        if abs(delta_j) < 1e-4:
                            # print "j = %d, is not moving enough" % j
                            continue

                        ai_new = ai_old - s * delta_j
                        delta_i = ai_new - ai_old
                        # print i, j
                        # print 'delta = ', delta_i, delta_j
                        # print 's = ', s
                        # print 'Before:', self.alphas
                        self.alphas[i], self.alphas[j] = ai_new, aj_new
                        # print 'New alpha_i and alpha_j:', ai_new, aj_new
                        bi = self.b - Ei - yi * delta_i * K[i, i] - yj * delta_j * K[i, j]
                        bj = self.b - Ej - yi * delta_i * K[i, j] - yj * delta_j * K[j, j]
                        # self.b = (bi + bj) / 2.0
                        if 0 < ai_new < self.C:
                            self.b = bi
                        elif 0 < aj_new < self.C:
                            self.b = bj
                        else:
                            self.b = (bi + bj) / 2.0
                        # print 'After: alpha:', self.alphas
                        # print 'sum(alpha * y):', np.dot(self.alphas, y)
                        break  # try next alpha_i
            if num_against_kkt_alphas == 0:
                break
            else:
                niter += 1
                print 'In iteration', niter, ',', num_against_kkt_alphas, 'alphas are against KKT conditions'
                num_against_kkt_alphas = 0
        print 'Finish SMO...'
        return self.alphas, self.b

    def _QP(self, x, y):
        # In QP formulation (dual): m variables, 2m+1 constraints (1 equation, 2m inequations)
        m = len(y)
        print x.shape, y.shape
        P = self._kernel(x) * np.outer(y, y)
        P, q = matrix(P, tc='d'), matrix(-np.ones((m, 1)), tc='d')
        G = matrix(np.r_[-np.eye(m), np.eye(m)], tc='d')
        h = matrix(np.r_[np.zeros((m,1)), np.zeros((m,1)) + self.C], tc='d')
        A, b = matrix(y.reshape((1,-1)), tc='d'), matrix([0.0])
        # print "P, q:"
        # print P, q
        # print "G, h"
        # print G, h
        # print "A, b"
        # print A, b
        solution = solvers.qp(P, q, G, h, A, b)
        if solution['status'] == 'unknown':
            print 'Not PSD!'
            exit(2)
        else:
            self.alphas = np.array(solution['x']).squeeze()

    def _SMO5(self, K, y):
        def choose_alphas():  # choose alpha heuristically
            check_all_examples = False  # whether or not need to check all examples
            # passes, max_passes = 0, 2
            # while passes < max_passes:
            while True:
                num_changed_alphas = 0
                if check_all_examples:
                    # in range_i, unbounded alphas rank first
                    # range_i = np.argsort((self.alphas - self.eps) * (self.alphas + self.eps - self.C))
                    range_i = xrange(m)
                else:
                    # check unbounded examples only
                    range_i = [i for i in xrange(m) if self.eps < self.alphas[i] < self.C - self.eps]
                # print 'range_i:', range_i
                for i in range_i:
                    # print 'Try i:', i
                    yi, ai_old = y[i], self.alphas[i]
                    Ei = np.sum(self.alphas * y * K[i]) + self.b - yi
                    logging.debug('Ei = ' + str(Ei))
                    if (yi*Ei < -tol and ai_old < self.C) or (yi*Ei > tol and ai_old > 0):
                        # print i, 'is against KKT conditions'
                        range_j = range(m)
                        random.shuffle(range_j)
                        # print 'range j:', range_j
                        # for j in xrange(m):
                        for j in range_j:
                            if j == i:
                                continue
                            yj = y[j]
                            Ej = np.sum(self.alphas * y * K[j]) + self.b - yj
                            # if abs(Ej - Ei) <= self.eps:
                            #     continue
                            yield (i, j, Ei, Ej)
                            if updated[0]:  # if (i, j) pair changed in the latest iteration
                                num_changed_alphas += 1
                                break
                if num_changed_alphas == 0:
                    if check_all_examples:  # if have checked all examples and no alpha violates KKT condition
                        break
                    else:
                        check_all_examples = True  # check all examples in the next iteration as a safeguard
                else:
                    check_all_examples = False
            yield -1, -1, 0.0, 0.0

        print 'Begin SMO5...'
        m = len(y)
        self.alphas, self.b = np.zeros(m), 0.0
        tol = self.eps
        logging.debug('m = ' + str(m))
        gen = choose_alphas()
        n_iter = 0
        updated = [False]  # use mutable object to pass message between functions
        while True:
            n_iter += 1
            logging.info('Iteration ' + str(n_iter))
            # logging.debug('passes = ' + str(passes))
            # run over pair (i, j).  But for some alpha_i, only choose one alpha_j in an iteration epoch.
            try:
                # gen.send(updated)
                i, j, Ei, Ej = gen.next()
            except StopIteration, e:
                break
            if i == -1:  # no more (i, j) pairs against KKT condition
                break
            updated[0] = False
            yi, yj, ai_old, aj_old = y[i], y[j], self.alphas[i], self.alphas[j]
            if yi != yj:
                L, H = max(0.0, aj_old - ai_old), min(self.C, self.C + aj_old - ai_old)
            else:
                L, H = max(0.0, ai_old + aj_old - self.C), min(self.C, ai_old + aj_old)
            logging.debug('L = ' + str(L) + ', H = ' + str(H))
            if H - L < self.eps:
                continue
            eta = K[i, i] + K[j, j] - 2.0 * K[i, j]
            logging.debug('eta = ' + str(eta))
            if eta <= 0:  # This should not be happen, because gram matrix should be PSD
                if eta == 0.0:
                    logging.warning('eta = 0, possibly identical examples encountered!')
                else:
                    logging.error('GRAM MATRIX IS NOT PSD!')
                input('*****************')
                continue
            aj_new = aj_old + yj * (Ei - Ej) / eta
            logging.debug('i, j, yi, yj = ' + ' '.join(map(str, [i, j, yi, yj])))
            logging.debug('Ei = ' + str(Ei) + ', Ej = ' + str(Ej))
            logging.debug('aj_new = ' + str(aj_new))
            if aj_new > H:
                aj_new = H
            elif aj_new < L:
                aj_new = L
            delta_j = aj_new - aj_old
            if abs(delta_j) < 1e-5:
                # print "j = %d, is not moving enough" % j
                continue
            ai_new = ai_old + yi * yj * (aj_old - aj_new)
            # ai_new = ai_old - yi * yj * delta_j
            delta_i = ai_new - ai_old
            self.alphas[i], self.alphas[j] = ai_new, aj_new
            bi = self.b - Ei - yi * delta_i * K[i, i] - yj * delta_j * K[i, j]
            bj = self.b - Ej - yi * delta_i * K[i, j] - yj * delta_j * K[j, j]
            if 0 < ai_new < self.C:
                self.b = bi
            elif 0 < aj_new < self.C:
                self.b = bj
            else:
                self.b = (bi + bj) / 2.0
            updated[0] = True
            logging.info('Updated through' + str(i) + str(j))
            logging.debug('alphas:' + str(self.alphas))

        print 'Finish SMO5...'
        return self.alphas, self.b

    def fit(self, x, y):
        # x, y: np.ndarray
        # x.shape: (m, n), where m = # samples, n = # features.
        # y.shape: (m,), m labels which range from {-1.0, +1.0}.
        assert type(x) == np.ndarray
        # print type(x), type(y)
        print x.shape, y.shape
        # In the design matrix x: m examples, n features
        # In QP formulation (dual): m variables, 2m+1 constraints (1 equation, 2m inequations)
        # print 'x = ', x
        # print 'y = ', y
        if self.kernel == 'rbf' and self.gamma is None:
            self.gamma = 1.0 / x.shape[1]
            print 'gamma = ', self.gamma
        if self.alg == 'dual':
            self._QP(x, y)
        else:
            assert self.alg == 'SMO'
            K = self._kernel(x)
            self._SMO5(K, y)

        logging.info('self.alphas = ' + str(self.alphas))
        sv_indices = filter(lambda i:self.alphas[i] > self.eps, xrange(len(y)))
        self.sv_x, self.sv_y, self.alphas = x[sv_indices], y[sv_indices], self.alphas[sv_indices]
        self.n_sv = len(sv_indices)
        logging.info('sv_indices:' + str(sv_indices))
        print self.n_sv, 'SVs!'
        logging.info(str(np.c_[self.sv_x, self.sv_y]))
        if self.kernel == 'linear':
            self.w = np.dot(self.alphas * self.sv_y, self.sv_x)
        if self.alg == 'dual':
            # calculate b: average over all support vectors
            sv_boundary = self.alphas < self.C - self.eps
            self.b = np.mean(self.sv_y[sv_boundary] - np.dot(self.alphas * self.sv_y,
                                                             self._kernel(self.sv_x, self.sv_x[sv_boundary])))

    def predict_score(self, x):
        return np.dot(self.alphas * self.sv_y, self._kernel(self.sv_x, x)) + self.b

    def show(self):
        if (self.alg == 'dual') or (self.alg == 'SMO'):
            print '\nFitted parameters:'
            print 'n_sv = ', self.n_sv
            print 'sv_x = ', self.sv_x
            print 'sv_y = ', self.sv_y
            print 'alphas = ', self.alphas
            if self.kernel == 'linear':
                print 'w = ', self.w
            print 'b = ', self.b
        else:
            print 'No known optimization method!'

    def predict(self, x):
        return np.sign(self.predict_score(x))

    def save(self, file_name='BinarySVM1.pkl'):
        fh = open('../model/' + file_name, 'wb')
        pickle.dump(self, fh)
        fh.close()


class MultiSVM:
    def __init__(self, kernel='linear', alg='SMO', decision_function='ovo', gamma=None, degree=None, C=1.0):
        self.degree, self.gamma, self.decision_function = degree, gamma, decision_function
        self.alg, self.C = alg, C
        self.kernel = kernel
        self.n_class, self.classifiers = 0, []

    def fit(self, x, y):
        labels = np.unique(y)
        self.n_class = len(labels)
        print labels
        if self.decision_function == 'ovr':  # one-vs-rest method
            for label in labels:
                y1 = np.array(y)
                y1[y1 != label] = -1.0
                y1[y1 == label] = 1.0
                print 'Begin training for label', label, 'at', \
                    time.strftime('%Y-%m-%d, %H:%M:%S', time.localtime(time.time()))
                t1 = time.time()
                clf = BinarySVM(self.kernel, self.alg, self.gamma, self.degree, self.C)
                clf.fit(x, y1)
                t2 = time.time()
                print 'Training time for ' + str(label) + '-vs-rest:', t2 - t1, 'seconds'
                self.classifiers.append(copy.deepcopy(clf))
        else:  # use one-vs-one method
            assert self.decision_function == 'ovo'
            n_labels = len(labels)
            for i in xrange(n_labels):
                for j in xrange(i+1, n_labels):
                    neg_id, pos_id = y == labels[i], y == labels[j]
                    x1, y1 = np.r_[x[neg_id], x[pos_id]], np.r_[y[neg_id], y[pos_id]]
                    y1[y1 == labels[i]] = -1.0
                    y1[y1 == labels[j]] = 1.0
                    # print 'y1 = ', y1
                    print 'Begin training classifier for label', labels[i], 'and label', labels[j], 'at', \
                        time.strftime('%Y-%m-%d, %H:%M:%S', time.localtime(time.time()))
                    t1 = time.time()
                    clf = BinarySVM(self.kernel, self.alg, self.gamma, self.degree, self.C)
                    clf.fit(x1, y1)
                    t2 = time.time()
                    print 'Training time for ' + str(labels[i]) + '-vs-' + str(labels[j]) + ':', t2 - t1, 'seconds'
                    self.classifiers.append(copy.deepcopy(clf))

    def predict(self, test_data):
        n_samples = test_data.shape[0]
        if self.decision_function == 'ovr':
            score = np.zeros((n_samples, self.n_class))
            for i in xrange(self.n_class):
                clf = self.classifiers[i]
                score[:, i] = clf.predict_score(test_data)
            return np.argmax(score, axis=1)
        else:
            assert self.decision_function == 'ovo'
            assert len(self.classifiers) == self.n_class * (self.n_class - 1) / 2
            vote = np.zeros((n_samples, self.n_class))
            clf_id = 0
            for i in xrange(self.n_class):
                for j in xrange(i+1, self.n_class):
                    res = self.classifiers[clf_id].predict(test_data)
                    vote[res < 0, i] += 1.0  # negative sample: class i
                    vote[res > 0, j] += 1.0  # positive sample: class j
                    # print i, j
                    # print 'res = ', res
                    # print 'vote = ', vote
                    clf_id += 1
            return np.argmax(vote, axis=1)

    def save(self, file_name='MultiSVM1.pkl'):
        fh = open('../model/' + file_name, 'wb')
        pickle.dump(self, fh)
        fh.close()

    def show(self):
        for clf in self.classifiers:
            clf.show()
