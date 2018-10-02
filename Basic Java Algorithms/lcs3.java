import java.util.*;

public class lcs3 {
	private static int[] print_lcs2(int [] a, int [] b) {
		int m = a.length;
		int n = b.length;
		int[][] L = new int[m+1][n+1];
		
		for(int i=0; i<=m; i++) {
			for(int j=0; j<=n; j++) {
				if(i == 0 || j == 0)
					L[i][j] = 0;
				else if(a[i-1] == b[j-1])
					L[i][j] = L[i-1][j-1] + 1;
				else
					L[i][j] = Math.max(L[i-1][j], L[i][j-1]);
			}
		}
		
		int index = L[m][n];
		int[] lcs = new int[index];

		int i = m, j = n;
		while (i>0 && j>0) {
			if (a[i-1] == b[j-1]){
				lcs[index-1] = a[i-1];
				i--;
				j--;
				index--;
			}
			else if (L[i-1][j] > L[i][j-1])
				i--;
			else
				j--;
		}
		return lcs;
	}

    private static int lcs3(int[] a, int[] b, int[] c) {
        int m = a.length;
		int n = b.length;
		int p = c.length;
		int[][][] L = new int[m+1][n+1][p+1];
		
		for(int i=0; i<=m; i++) {
			for(int j=0; j<=n; j++) {
				for(int k=0; k<=p; k++) {
					if(i == 0 || j == 0 || k == 0)
						L[i][j][k] = 0;
					else if(a[i-1] == b[j-1] && a[i-1] == c[k-1])
						L[i][j][k] = L[i-1][j-1][k-1] + 1;
					else
						L[i][j][k] = Math.max(Math.max(Math.max(Math.max(Math.max(L[i-1][j][k], L[i][j-1][k]), L[i][j][k-1]), L[i-1][j-1][k]), L[i-1][j][k-1]), L[i][j-1][k-1]);
				}
			}
		}
        return L[m][n][p];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int an = scanner.nextInt();
        int[] a = new int[an];
        for (int i = 0; i < an; i++) {
            a[i] = scanner.nextInt();
        }
        int bn = scanner.nextInt();
        int[] b = new int[bn];
        for (int i = 0; i < bn; i++) {
            b[i] = scanner.nextInt();
        }
        int cn = scanner.nextInt();
        int[] c = new int[cn];
        for (int i = 0; i < cn; i++) {
            c[i] = scanner.nextInt();
        }
        System.out.println(lcs3(a, b, c));
    }
}
