/**
 * Author: Ygor Sad
 * 
 * The present algorithm aims to implement the Gauss-Jordan numeric method
 * to solve linear systems. Better explanation about the method's steps
 * can be found here: <https://en.wikipedia.org/wiki/Gaussian_elimination>.
 */

#include <stdio.h>
#include <stdlib.h>

void adjust_line(double*** matrix, int order, int current_line) {
    int i, j;
    double aux;

    /**
     * Makes pivot value 1
     */
    aux = (*matrix)[current_line][current_line];
    for (j = 0; j <= order; j++) {
        (*matrix)[current_line][j] = (*matrix)[current_line][j] / aux;
    }

    /**
     * Makes the other elements on pivot column
     * to be evaluate 0 
     */
    for (i = 0; i < order; i++) {
        if (i != current_line) {
            aux = (*matrix)[i][current_line] * -1;
            for (j = 0; j <= order; j++) {
                (*matrix)[i][j] = (*matrix)[i][j] + (*matrix)[current_line][j] * aux;
            }
        }
    }
}


void adjust_matrix(double*** matrix, int order, int current_line) {
    int i, j;

    /**
     * If the element right on the main diagonal is different
     * from zero, then adjusts this row immediatelly
     */
    if ((*matrix)[current_line][current_line] != 0) {
        adjust_line(matrix, order, current_line);
    }
    else {

        /**
         * Finds first non-zero element on given column
         */
        i = current_line + 1;
        while (((*matrix)[i][current_line] == 0) && (i < order)) {
            i++;
        }

        if (i == order) {
            exit(1);
        }
        else {
            double aux;
            for (j = 0; j <= order; j++) {
                aux = (*matrix)[i][j];
                (*matrix)[i][j] = (*matrix)[current_line][j];
                (*matrix)[current_line][j] = aux;
            }
            adjust_line(matrix, order, current_line);
        }
    }
}


int main() {

    int i, j;
    int order;
    double** matrix;

    /**
     * Gets the linear system order, that is, the number of equations/variables
     * the linear system (LS) has. eg: if the LS has 3 variables, it's of order 3
     */
    scanf("%d", &order);


    /**
     * Allocates a matrix of doubles to hold the LS coefficients
     */
    matrix = (double**) malloc(sizeof(double*) * order);
    if (matrix == NULL) {
        exit(1);
    }
    for (i = 0; i < order; i++) {
        matrix[i] = (double*) malloc(sizeof(double) * (order+1));
        if (matrix[i] == NULL) {
            exit(1);
        }
    }

    /**
     * Receives from standard input the numbers which will
     * form the linear system coefficientes.
     */
    for (i = 0; i < order; i++) {
        for (j = 0; j < order; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    for (i = 0; i < order; i++) {
        scanf("%lf", &matrix[i][order]);
    }


    /**
     * Solves the LS applying many eliminations on the
     * coefficients matrix
     */
    for (i = 0; i < order; i++) {
        adjust_matrix(&matrix, order, i);
    }


    /**
     * Prints the LS solutions
     */
    for (i = 0; i < order; i++) {
        printf("%lf\n", matrix[i][order]);
    }


    /**
     * Disallocates the coefficients matrix
     */
    for (i = 0; i < order; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
