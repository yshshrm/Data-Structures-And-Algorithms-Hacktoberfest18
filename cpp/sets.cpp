#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class BagPacking {
public:
	int minPay(vector <int> bagsizes) {
	    sort(bagsizes.begin(),bagsizes.end());
	    int total=0;
	    vector<int> ::iterator it = bagsizes.begin();
            for(int i=1;i<bagsizes.size();i++){
                if(bagsizes[i]>bagsizes[i-1])
                    total++;
            }
            total = bagsizes.size()-total;
            return total;
	    }


	};


