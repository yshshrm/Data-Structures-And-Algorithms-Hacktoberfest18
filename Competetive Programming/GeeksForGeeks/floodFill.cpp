#include<bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[0].size(); j++){
            cout<<arr[i][j]<<" ";
        }
    }
}

void floodFill(vector<vector<int>> arr, int x, int y, int k, int prev){
    int rows = arr.size();
    int cols = arr[0].size();
    if(x<0 || x>=rows || y<0 || y>=cols)
        return;

    if(arr[x][y] != prev)
        return;

    arr[x][y] = k;

    floodFill(arr, x, y+1, k, prev);
    floodFill(arr, x+1, y, k, prev);
    floodFill(arr, x-1, y, k, prev);
    floodFill(arr, x, y-1, k, prev);

    printMatrix(arr);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
	    int n,m;
	    scanf("%d %d", &n, &m);
	    vector<vector<int>> arr;
	    for(int i=0; i<n; i++){
	        vector<int> vect;
	        for(int j=0; j<m; j++){
	            int temp;
	            scanf("%d", &temp);
	            vect.push_back(temp);
	        }
	        arr.push_back(vect);
	    }
	    int x,y,k;
	    scanf("%d %d %d", &x, &y, &k);

	    floodFill(arr, x, y, k, arr[x][y]);
	    cout<<endl;
	}
    return 0;
}
