#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

struct slidingWindow {
	deque<int> deq;

	int getMin() {
		return deq.front();
	}

	void insert(int val) {
		while (!deq.empty() && deq.back() < val)
			deq.pop_back();
		deq.push_back(val);
	}

	void remove(int val) {
		if (deq.front() == val)
			deq.pop_front();
	}

	int size() {
		return deq.size();
	}

};




int main(int argc, char* argv[]) {

	
	return 0;
}
