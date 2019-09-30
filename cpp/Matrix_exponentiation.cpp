#include<bits/stdc++.h>
using namespace std;
#define ll long long

//https://github.com/Ashishgup1/Competitive-Coding/blob/master/Matrix%20Struct.cpp
const ll MAX_N = 2 // Change as per the question

struct Matrix{	// Fibonacci (and related) Matrix

	ll a[MAX_N][MAX_N];
	ll mod = 1e9 + 7;

	void reset(){
		memset(arr,0,sizeof arr);
	}
	void Identity(){
		ll i,j;
		reset();
		for(i = 0;i < MAX_N;i++){
			a[i][i] = 1;
		}
	}

	Matrix operator + (const Matrix &o) const{
		Matrix res;
		ll i,j;
		for(i = 0;i < MAX_N;i++){
			for(j = 0;j < MAX_N;j++){
				res[i][j] = (a[i][j] % mod + o.a[i][j] % mod) % mod;
			}
		}
		return res;
	};

	Matrix operator * (const Matrix &o) const{
		Matrix res;
		ll i,j,k;
		for(i = 0; i < MAX_N; i++){
			for(j = 0; j < MAX_N; j++){
				res.a[i][j] = 0;
				for(k = 0;k < MAX_N;k++){
					res.a[i][j] = (res.a[i][j] % mod + (a[i][k] % mod * o.a[k][j] % mod) % mod) % mod;
				}
			}
		}
		return res;
	};

	Matrix print (Matrix a){
		ll i,j;
		for(i = 0;i < MAX_N;i++){
			for(j = 0;j < MAX_N;j++){
				cerr << a.a[i][j] << ' ';
			}cerr << '\n';
		}
	}

	Matrix power (Matrix a, ll n){

		Matrix res;
		res.Identity();
		while(n){
			if(n &  1){
				res = res * a;
			}
			a = a * a;
			n /= 2;
		}
		return res;
	}	
};

int main(){

	Matrix m;	
	m.reset();

	ll n = 10 //let

	m.a[0][0] = m.a[0][1] = 1;
	m.a[1][0] = 1;

	m = m.power(m, n - 1); // Finds (F_n,F_n-1) in terms of F_0 and F_1 (n = 10 here)

}