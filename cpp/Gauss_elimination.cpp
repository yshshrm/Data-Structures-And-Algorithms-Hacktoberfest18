struct Gauss{

	// Remember to declare a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE], Ans[MAX_SIZE] & mod globally
	// Remember to declare the Modular_operations class before this, Goto ^
	// Goto ^
	// Solution of system of linear equations using Gauss - Jordan method under modulo `mod`
	// This code finds the coefficients of a polynomial of degree k (set here to be max 10)
	// This code can also be used to find the solutions to a given SOLE
	// Make sure to change MAX_SIZE as per the question --> Runs in O(MAX_SIZE^3), so use only when MAX_SIZE ~ 100
	// Goto ^

	ll MAX_SIZE = 10;	// Set it as per the question

	// Use for interactive problems like https://codeforces.com/contest/1155/problem/E

	ll interactor(ll x){

		ll f[MAX_SIZE + 1] = {1,0,1,0,0,0,0,0,0,0,0};

		ll curr = 1;

		ll ans = 0;

		for(ll i = 0;i <= MAX_SIZE;i++){
			ans = add(ans,mul(f[i],curr));
			curr = mul(curr,x);
		}
		return ans;
	}

	// ---- Routine Algorithm --- //

	void swap_row(ll i,ll j){

		for(ll k = 0;k <= MAX_SIZE;k++){
			swap(a[i][k],a[j][k]);
		}
		swap(b[i],b[j]);
	}

	// --- For Debugging purposes --- //

	void print_mat(){
		
		for(ll i = 0;i <= MAX_SIZE;i++){
			for(ll j = 0;j <= MAX_SIZE;j++){
				cout << fixed << setfill(' ') << setw(10);
				cout << a[i][j] << ' ';
			}
			cout << " : " << b[i];
			cout << '\n';
		}
	}

	// --- Stores the final solution to the SOLE --- //

	void getans(){
		for(ll i = 0;i <= MAX_SIZE;i++){
			cout << Ans[i] << ' ';
		}
		cout << '\n';
	}

	// --- Reduce the given matrix to Echelon Form --- //
	// --- Remember, the below subroutine is for SOl of SOLE under a modulo `mod`
		// Don't use the below snippets for the actual answers (the answer calculated here are modulo `mod`)

	void forward_elimination(){

		for(ll i = 0; i <= MAX_SIZE; i++){
			ll row,val;
			row = i;val = a[row][i];
			for(ll j = i + 1; j <= MAX_SIZE; j++){
				if(a[j][i] > val){
					val = a[j][i];
					row = j;
				}
			}
			// cerr << row << '\n';
			if(row != i)
				swap_row(row,i);

			for(ll j = i + 1;j <= MAX_SIZE;j++){
				ll d = divide(a[j][i],a[i][i]);
				for(ll k = i;k <= MAX_SIZE;k++){
					a[j][k] = sub(a[j][k], mul(d,a[i][k]));
				}
				b[j] = sub(b[j],mul(d,b[i]));
			}
			// cout << "---" << i << "---\n";
			// print_mat();
		}
	}

	void backward_substitution(){

		for(ll i = MAX_SIZE;i >= 0;i--){

			Ans[i] = b[i];

			for(ll j = i + 1;j <= MAX_SIZE; j++){

				Ans[i] = sub(Ans[i],mul(a[i][j],Ans[j]));
			}

			Ans[i] = divide(Ans[i],a[i][i]);
		}
		// cout << "---Final---\n";
		// print_mat();
	}
};
