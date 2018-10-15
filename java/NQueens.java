import java.util.Arrays;
import java.util.Scanner;

public class NQueens {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        eightQueens(scan.nextInt());
        System.out.println(count);

    }

    private static void valid(char[][] board, int row, int column, char k) {
        int rowUp = row - 1, rowDown = row + 1;

        for (int i = column; i >= 0; i--) {

            board[row][i] = k;

            if (rowUp >= 0) {
                board[rowUp--][i] = k;
            }

            if (rowDown < board.length ) {
                board[rowDown++][i] = k;
            }
        }
    }

    private static boolean isValidPut(char[][] board, int row, int column) {
        int rowUp = row - 1, rowDown = row + 1;

        for (int i = column; i >= 0; i--) {
            if (board[row][i] == 'q') {
                return false;
            }

            if (rowUp >= 0 && board[rowUp--][i] == 'q') {
                return false;
            }

            if (rowDown < board.length && board[rowDown++][i] == 'q') {
                return false;
            }
        }

        return true;
    }

    private static void printBoard(char[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println();

    }

    private static int count = 0;
    private static void eightQueens(char[][] board, int column) {

        if (column >= board.length) {
            count++;
            printBoard(board);
            return;
        }

        for (int j = 0; j < board.length; j++) {
            if (isValidPut(board, j, column - 1)) {
                board[j][column] = 'q';
                eightQueens(board, column + 1);
                board[j][column] = '.';
            }
        }
    }


    private static void eightQueens(int n) {
        char[][] board = new char[n][n];
        for (int i = 0; i < board.length; i++) {
            Arrays.fill(board[i], '.');
        }
        eightQueens(board, 0);
    }
}

