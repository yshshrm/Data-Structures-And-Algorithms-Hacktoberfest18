#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool AreAnagrams(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}
