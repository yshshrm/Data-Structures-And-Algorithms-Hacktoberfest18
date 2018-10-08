/*
 * Putting N Queens in a chess board in safe positions
 * Author: Progyan Bhattacharya <progyanb@acm.org>
 * Repo: Design-And-Analysis-of-Algorithm [MIT LICENSE]
 */

#include "NQueens.h"

static int isSafe(int n, int Board[n][n], int row, int col) {
    for (int i = 0; i < n; i++) {
        if (Board[row][i] || Board[i][col]) {
            return 0;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (Board[i][j]) {
            return 0;
        }
    }
    for (int i = row, j = col; i < n && j < n; i++, j++) {
        if (Board[i][j]) {
            return 0;
        }
    }
    return 1;
}

static int PutQueen(int n, int Board[n][n], int col) {
    if (col >= n) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if (isSafe(n, Board, i, col)) {
            Board[i][col] = 1;
            if (PutQueen(n, Board, col + 1)) {
                return 1;
            }
            Board[i][col] = 0;
        }
    }
    return 0;
}

void NQueens(int n) {
    int Board[n][n];
    for (int i = 0, j = 0; j < n || (j = 0, ++i) < n; j++) {
        Board[i][j] = 0;
    }
    if (n > 3 && PutQueen(n, Board, 0)) {
        for (int i = 0, j = 0; j < n || (j = ! putchar('\n'), ++i) < n; j++) {
            printf("%d ", Board[i][j]);
        }
        return;
    }
    printf("The problem cannot be solved for %d X %d Board\n", n, n);
}
