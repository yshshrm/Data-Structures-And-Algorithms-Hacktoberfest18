__author__ = "Markus Guenther"

import copy
import sys
import random
import math
import Queue
import time

class OptimizationProblem:
    '''This is the base class for optimization problems. It provides a
    a very simple interface for concrete problems. Every implementation of 
    of OptimizationProblem should provide the herein defined methods as
    generator functions.
    '''
    def __init__(self):
        pass
    
    def get_random_solution(self):
        '''Generator function that returns a random solution from the
        problem domain.        
        '''
        pass
    
    def neighbourhood_of(self, solution):
        '''Generator function that returns solutions that are neighbours
        to the given solution.
        '''
        pass

def hill_climbing(problem, evaluate):
    '''Simplistic local search approach that does small local changes to a
    given solution in order to obtain better solutions. Solutions are evaluated
    using an evaluation function that is passed to this function. Please note
    that this algorithm can easily get stuck on local optima. If you want to
    prohibit this behaviour to some extent, you should use the taboo search
    algorithm.
    '''
    best_neighbour = problem.get_random_solution()
    best_neighbour_cost = evaluate(best_neighbour)
    
    while True:
        improved = False
        
        # check the neighbourhood of the current solution for better ones
        for neighbour in problem.neighbourhood_of(best_neighbour):
            neighbour_cost = evaluate(neighbour)
            if neighbour_cost < best_neighbour_cost:
                improved = True
                best_neighbour = neighbour
                best_neighbour_cost = neighbour_cost
       
        # if there is no neighbour with better costs, then our local search
        # has come to an end and we can return the found solution
        if not improved:
            return best_neighbour
        
def taboo_search(problem, evaluate, iterations=100, taboo_limit=5):
    '''Local search approach that - at least to some extent - prevents the
    search from getting stuck in a local optimum. Taboo search always chooses
    the best neighbour of the current neighbourhood, even if the current
    solution has a better evaluation cost. Because it is likely that the search
    would go back to a better, previously found solution, the algorithm
    prohibits this by putting such a solution into a taboo list for taboo_limit 
    iterations. After each iteration, every previously found solution in the 
    taboo list gets its specific taboo_limit value decremented by 1. If this 
    value reaches 0, the solution will no longer be prohibited and can be 
    chosen again. Please note that the size of the taboo list is in the order 
    of taboo_limit, since during each iteration, at most one solution comes 
    into that list and at most one solution leaves the list.
    
    Due to its complexity, this algorithm can take a little bit longer than
    the simple hill climbing approach, but it usually finds better solutions.
    
    The implemented variant of taboo search does early termination if it
    encounters a solution with optimal cost during the search (costs = 0).
    '''
    taboo = {}
    current_solution = problem.get_random_solution()
    current_solution_cost = evaluate(current_solution)
    
    for i in xrange(iterations):
        best_neighbour = None
        best_neighbour_cost = sys.maxint
        
        # check the neighbourhood of the current solution for better ones
        for neighbour in problem.neighbourhood_of(current_solution):
            neighbour_cost = evaluate(neighbour)
            # if this neighbour is better than the current and if it
            # is not penaltized by a previous visit, update the best neighbour
            if neighbour_cost < best_neighbour_cost and \
            neighbour not in taboo.values():
                best_neighbour = neighbour
                best_neighbour_cost = neighbour_cost
        
        # update taboo list
        updated_taboo = {}
        for key in taboo.keys():
            if key is not 1:
                updated_taboo[key-1] = taboo[key]
        taboo = updated_taboo
        taboo[taboo_limit] = current_solution
        current_solution = best_neighbour
        current_solution_cost = best_neighbour_cost
        
        if current_solution_cost is 0:
            # early termination
            return current_solution  
    
    return current_solution

def random_temperature_schedule(how_many, min_temperature, max_temperature):
    '''Used to generate temperature schedules for the simulated annealing
    algorithm. how_many specifies the amount of temperatures to be generated.
    min_temperature and max_temperature defines the boundaries for the
    values of the generated temperatures. The list of generated temperatures
    is sorted in ascending order before it is returned.
    '''
    temperatures = []
    for i in xrange(how_many):
        temperatures.append(min_temperature + random.random() * max_temperature)
    temperatures.sort()

    return temperatures

def simulated_annealing(problem, evaluate, iterations_per_temperature, schedule):
    '''This approach is a combination of the simple hill climbing search
    with a probabilistic scheme called random walk. Simulated annealing has
    to be perfectly configured for the specific problem, otherwise it will
    fail to find good solutions.
    
    This implementation is actually by the book. However, as I can not figure
    out how to configure it properly for specific problems, it is only kept
    as a reference for possible future improvements. I strongly recommend
    that you do not waste your precious trying to figure out on how can get
    a suitable simulated annealing configuration for your specific problem;
    just try out the other optimization algorithms that come along with this
    package.
    '''
    current = problem.get_random_solution()
    current_cost = evaluate(current)
    T = schedule.pop()
    t = 0
    while True:
        # check if we have to move on to the next temperature
        if t % iterations_per_temperature == 0:
            # if schedule is empty, we return the current solution as
            # the best found
            if len(schedule) == 0:
                return current
            T = schedule.pop()
            
        neighbourhood = problem.neighbourhood_of(current)
        random_neighbour = neighbourhood.next()
        for neighbour in neighbourhood:
            if random.random() > 0.5:
               random_neighbour = neighbour
               break
        neighbour_cost = evaluate(neighbour)
            
        if neighbour_cost < current_cost:
            current = neighbour
            current_cost = neighbour_cost
        else:
            # make a probabilistic yes/no decision
            # this fucntion minimizes the fitness of a solution,
            # so current_cost - neighbour_cost
            threshold = math.exp((current_cost - neighbour_cost) / T)
            if threshold > 0.5:
                current = neighbour
                current_cost = neighbour_cost
        t += 1

def beam_search(problem, evaluate, k):
    initial_solutions = []
    for i in xrange(k):
        initial_solutions.append(problem.get_random_solution())
    # at the beginning, this is just an evaluation of a randomly
    # generated solution
    best_solution = initial_solutions[0]
    best_solution_cost = evaluate(initial_solutions[0])
        
    while True:
        queue = Queue.PriorityQueue(0)
        for solution in initial_solutions:
            neighbourhood = problem.neighbourhood_of(solution)
            for neighbour in neighbourhood:
                queue.put((evaluate(neighbour), neighbour))
        # now select the k best neighbours from all k father solutions
        new_solutions = []
        for i in xrange(k):
            new_solutions.append(queue.get()[1])
        new_best_solution_cost = evaluate(new_solutions[0])
        if new_best_solution_cost > best_solution_cost:
            # terminate if we have not found a new neighbour with
            # better costs than the previously chosen best solution
            return best_solution
        else:
            best_solution = new_solutions[0]
            best_solution_cost = new_best_solution_cost
        initial_solutions = new_solutions

# ___________________________________________________________________________________________________
# EXAMPLE: N-QUEENS
# ___________________________________________________________________________________________________

class QueensProblem(OptimizationProblem):
    def __init__(self, size):
        self._size = size
    
    def get_random_solution(self):
        random_solution = []
        for i in xrange(self._size):
            random_solution.append(int(random.random() * self._size))
        return random_solution
    
    def neighbourhood_of(self, solution):
        for i in xrange(len(solution)):
            for j in xrange(0,self._size):
                if j is solution[i]:
                    continue
                new_solution = copy.deepcopy(solution)
                new_solution[i] = j

                yield new_solution

def evaluate(solution):
    def check_diagonally(x,y,i):
        temp_score = 0
        pos_x = i
        pos_y = solution[pos_x]
        length = len(solution)-1
        while pos_x > 0 and pos_x < length and pos_y > 0 and pos_y < length:
            pos_x += x
            pos_y += y
            if solution[pos_x] is pos_y:
                temp_score += 1
        return temp_score
    
    score = 0
    for i in xrange(len(solution)):
        queen_at = solution[i]
        # check diagonally, up+down, left+right
        for go_left in xrange(i):
            if solution[go_left] is queen_at:
                score += 1
        for go_right in xrange(i+1, len(solution)):
            if solution[go_right] is queen_at:
                score += 1
        score += check_diagonally(-1,-1,i)
        score += check_diagonally(-1,1,i)
        score += check_diagonally(1,-1,i)
        score += check_diagonally(1,1,i)
    
    return score

if __name__ == "__main__":
    queens = QueensProblem(25)
    ts_before = time.time()
    solution = beam_search(queens, evaluate, 5)
    ts_after = time.time()
    print "BEAM SEARCH: QUEENS(%i): found solution %s with costs %i in %i seconds." % \
    (8, solution, evaluate(solution), ts_after-ts_before)
    ts_before = time.time()
    solution = hill_climbing(queens, evaluate)
    ts_after = time.time()
    print "LOCAL SEARCH: QUEENS(%i): found solution %s with costs %i in %i seconds." % \
        (8, solution, evaluate(solution), ts_after-ts_before)
    ts_before = time.time()
    solution = taboo_search(queens, evaluate)
    ts_after = time.time()
    print "TABOO SEARCH: QUEENS(%i): found solution %s with costs %i in %i seconds." % \
        (8, solution, evaluate(solution), ts_after-ts_before)
    ts_before = time.time()
    schedule = random_temperature_schedule(50, 0, 10000)
    solution = simulated_annealing(queens, evaluate, 500, schedule)
    ts_after = time.time()
    print "SIMULATED ANNEALING: QUEENS(%i): found solution %s with costs %i in %i seconds." % \
        (8, solution, evaluate(solution), ts_after-ts_before)
