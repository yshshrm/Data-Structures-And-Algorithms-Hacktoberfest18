package Recursioncontd;

import java.util.*;

public class printTargetSS {

	public static void main(String[] args) {
		int[] arr = { 10, 20, 30, 40, 50 };
		int tar = 50;
		printTargetSS1(arr, tar, 0, 0, "");

		ArrayList<Integer> a = new ArrayList<>();
		ArrayList<String> b = new ArrayList<>();
		//printTargetSS2(arr, 50, 0, a);
		printTargetSS1(arr, 50, 0, b);
	}
	public static void printTargetSS3(int[] arr, int tar, int vidx, ArrayList<String> ssf) {

		if (arr.length == vidx) {
			if (sosf == tar) {
				System.out.println(ssf);
			}
			return;
		}

		ssf.add(arr[vidx]+"");
		sosf += arr[vidx];
		printTargetSS3(arr, tar, vidx + 1, ssf);

		sosf -= arr[vidx];
		ssf.remove(ssf.size() - 1);
		printTargetSS3(arr, tar, vidx + 1, ssf);
	}

	public static void printTargetSS1(int[] arr, int tar, int vidx, int sosf, String ssf) {

		if (arr.length == vidx) {
			if (sosf == tar)
				System.out.println(ssf);
			return;
		}

		printTargetSS1(arr, tar, vidx + 1, sosf + arr[vidx], ssf + " " + arr[vidx]);

		printTargetSS1(arr, tar, vidx + 1, sosf, ssf);
	}

	static int sosf = 0;

	public static void printTargetSS2(int[] arr, int tar, int vidx, ArrayList<Integer> ssf) {

		if (arr.length == vidx) {
			if (sosf == tar) {
				System.out.println(ssf);
			}
			return;
		}

		ssf.add(arr[vidx]);
		sosf += arr[vidx];
		printTargetSS2(arr, tar, vidx + 1, ssf);

		sosf -= arr[vidx];
		ssf.remove(ssf.size() - 1);
		printTargetSS2(arr, tar, vidx + 1, ssf);
	}
	
	public static ArrayList<String> printTargetSS2(int[] arr, int tar, int vidx) {

        if (arr.length == vidx) {
            ArrayList <String> a = new ArrayList<>();
            if (sosf == tar) {
                a.add("");
            }
            return a;
        }
       ArrayList <String> res = printTargetSS2(arr, tar, vidx+1);
       ArrayList <String> b = new ArrayList<>();
        for(String var: res){
            b.add(var);
            b.add(arr[vidx]+" "+var);
            //System.out.println(b);
            sosf += arr[vidx];
        }
       sosf-=arr[vidx];
    return b;
    }
	

}
