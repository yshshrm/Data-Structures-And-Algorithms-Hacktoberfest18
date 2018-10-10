/**
 * Author: Ygor Sad <https://github.com/ysads>
 *
 * Algorithm that interpolates the coefficients of a k-order
 * polinomium based on a series of k different points (x, y)
 * of these equation. To accomplish that, it creates a k-order
 * linear system that once solved will give us the polinomium
 * coefficients a_1, a_2, ..., a_k
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef double t_matrix;


void adjust_row(t_matrix** matrix, int dimension, int current_row) {
    int i, j;
    t_matrix aux;

    aux = matrix[current_row][current_row];
    for (j = 0; j <= dimension; j++) {
        matrix[current_row][j] = matrix[current_row][j] / aux;
    }

    for (i = 0; i < dimension; i++) {
        if (i != current_row) {
            aux = matrix[i][current_row] * -1;
            for (j = 0; j <= dimension; j++) {
                matrix[i][j] = matrix[i][j] + matrix[current_row][j] * aux;
            }
        }
    }
}


void solve_linear_system(t_matrix** matrix, int dimension, t_matrix** solution) {
    int i, j, current_row;

    for (current_row = 0; current_row < dimension; current_row++) {

        if (matrix[current_row][current_row] != 0) {
            adjust_row(matrix, dimension, current_row);
        }
        else {

            i = current_row + 1;
            while ((matrix[i][current_row] == 0) && (i < dimension)) {
                i++;
            }

            if (i == dimension) {
                exit(1);
            }
            else {
                t_matrix aux;

                for (j = 0; j <= dimension; j++) {
                    aux = matrix[i][j];
                    matrix[i][j] = matrix[current_row][j];
                    matrix[current_row][j] = aux;
                }
                adjust_row(matrix, dimension, current_row);
            }
        }        
    }
    for (current_row = 0; current_row < dimension; current_row++) {
        solution[current_row][0] = matrix[current_row][dimension];
    }
}


void build_equations(t_matrix** equations, t_matrix** points, int coefficients) {
    int i, j;
    t_matrix abscissae;
    
    for (i = 0; i < coefficients; i++) {
        abscissae = points[i][0];
    
        for (j = 0; j < coefficients; j++) {
            equations[i][j] = pow(abscissae, coefficients-j-1);
        }
        equations[i][coefficients] = points[i][1];
    }
}


int instantiate_matrix(t_matrix*** matrix, int linhas, int colunas) {
    int i;

    *matrix = (t_matrix**) malloc(sizeof(t_matrix*) * linhas);
    if (*matrix == NULL) {
        return 0;
    }

    for (i = 0; i < linhas; i++) {

        (*matrix)[i] = (t_matrix*) malloc(sizeof(t_matrix) * colunas);
        if ((*matrix)[i] == NULL) {
            return 0;
        }
    }
    return 1;
}


void desallocate_matrix(t_matrix*** matrix, int linhas) {
    int i;

    for (i = 0; i < linhas; i++) {
        free((*matrix)[i]);
    }
    free(*matrix);
    *matrix = NULL;
}


int main() {

    int i, j, num_coefficients;
    t_matrix** points;
    t_matrix** equations;
    t_matrix** solutions;

    /**
     * Reads the number of coefficients the equations will have
     */
    scanf("%d", &num_coefficients);
  
    if (!instantiate_matrix(&equations, num_coefficients, num_coefficients+1)) {
        exit(1);
    }
    if (!instantiate_matrix(&points, num_coefficients, 2)) {
        exit(1);
    }
    if (!instantiate_matrix(&solutions, num_coefficients, 1)) {
        exit(1);
    }

    /**
     * Reads <num_coefficients> points (x, y) that will be used
     * to interpolate the equation's coefficients
     */
    for (i = 0; i < num_coefficients; i++) {        
        scanf("%lf", &points[i][0]);
        scanf("%lf", &points[i][1]);
    }

    /**
     * Builds the equations and solves them to find their solutions
     */
    build_equations(equations, points, num_coefficients);
    solve_linear_system(equations, num_coefficients, solutions);


    for (i = 0; i < num_coefficients; i++) {
        printf("%lf\n", solutions[i][0]);
    }


    desallocate_matrix(&equations, num_coefficients);
    desallocate_matrix(&solutions, num_coefficients);
    desallocate_matrix(&points, num_coefficients);

    return 0;
}
