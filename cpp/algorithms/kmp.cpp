#include <iostream>
#include <string>
#include <vector>


using namespace std;


const int N = 5e5 + 50;

int f[N];
void buildF(string str) {
	int l;
	f[0] = 0;
	for (int i = 1; i < str.size(); ++i) {
		l = f[i - 1];

		while (l && str[i] != str[l])
			l = f[l - 1];
		if (str[i] == str[l])
			++l;

		f[i] = l;
	}
}

vector<int> kmp(string text, string patt) {
	buildF(patt);
	vector<int> occ;
	int l = 0;
	for (int i = 0; i < text.size(); ++i) {

		if (text[i] == patt[l])
			l++;

		else {
			while (l && text[i] != patt[l])
				l = f[l - 1];
			if (text[i] == patt[l])
				l++;
		}

		if (l == patt.size()) {
			occ.push_back(i - l + 1);
			l = f[l - 1];
			continue;
		}
	}

	return occ;
}
int main() {
	string text;
	string patt;
	vector<int> occ;

	//*********Test Case 1****************************
	text = "ABABDABACDABABCABAB";
	patt = "ABABCABAB";

	occ = kmp(text, patt);

	for (int i = 0; i < occ.size(); ++i)
		cout << occ[i] << " \n"[i == occ.size() - 1];

	//*********Test Case 2****************************
	text = "THIS IS A TEST TEXT";
	patt = "TEST";

	occ = kmp(text, patt);

	for (int i = 0; i < occ.size(); ++i)
		cout << occ[i] << " \n"[i == occ.size() - 1];

	//*********Test Case 3****************************
	text = "AABAACAADAABAABA";
	patt = "AABA";

	occ = kmp(text, patt);

	for (int i = 0; i < occ.size(); ++i)
		cout << occ[i] << " \n"[i == occ.size() - 1];


	return 0;

}
