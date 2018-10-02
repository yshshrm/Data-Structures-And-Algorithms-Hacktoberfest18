import java.util.*;

class edit_distance {
	public static int EditDistance(String s, String t) {
		int n = s.length();
		int m = t.length();
		int [][] d = new int[n+1][m+1];
		for(int i = 0; i <= n; ++i) {
			d[i][0] = i;
		}
		for(int i = 0; i <= m; ++i) {
			d[0][i] = i;
		}
		int cost = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				if(s.charAt(i-1) == t.charAt(j-1))
					cost = 0;
				else
					cost = 1;
				d[i][j] = Math.min(Math.min(d[i-1][j],d[i][j-1]) + 1, d[i-1][j-1] + cost);
			}
		}
		return d[n][m];	  
	}
	
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);

		String s = scan.next();
		String t = scan.next();

		System.out.println(EditDistance(s, t));
	}

}
