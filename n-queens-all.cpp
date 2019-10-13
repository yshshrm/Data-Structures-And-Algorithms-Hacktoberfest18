#include<bits/stdc++.h>
#include<iostream>

using namespace std;

bool check(vector<vector<int>> &board, int row, int col, int n) {
	// top left
	for(int i=row-1, j=col-1;i>=0 && j>=0;i--,j--) {
		if(board[i][j] == 1)
			return false;
	}
	// left
	for(int j=col-1;j>=0;j--) {
		if(board[row][j] == 1)
			return false;
	}
	//down left
	for(int i=row+1, j=col-1;i<n && j>=0; i++, j--) {
		if(board[i][j] == 1)
			return false;
	}
	return true;
}

void place_queens(vector<vector<int>> &board, int col, int n, vector<vector<vector<int>>> &ans) {

	if(col == n) {
		ans.push_back(board);
	}
	int i=0;
	while(i < n) {
		board[i][col] = 1;
		if(check(board, i, col, n)) {
			place_queens(board, col+1, n, ans);
		}
		board[i][col] = 0;
		i++;
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> board;
	for(int i=0;i<n;i++) {
		vector<int> temp(n, 0);
		board.push_back(temp);
	}
	vector<vector<vector<int>>> ans;
	place_queens(board, 0, n, ans);
	
	if(ans.size() == 0) {
		cout << "No solution is possible";
		return 0;
	}

	for(int a=0;a<ans.size();a++) {
		board = ans[a];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

}