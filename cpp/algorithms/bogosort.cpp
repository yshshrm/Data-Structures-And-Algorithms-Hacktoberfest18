#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <vector>
std::vector<int> switchSpot(std::vector<int> val, int index1, int index2){
	int temp = val[index1];
	val[index1] = val[index2];
	val[index2] = temp;
	return val;
}
bool isSorted(std::vector<int> val){
	for(unsigned int x = 0; x < val.size()-1; x++)
		if(val[x] > val[x+1])
			return false;
	return true;
}
void printAll(std::vector<int> val){

	for(unsigned int x = 0; x < val.size();x++)
		std::cout << val[x] << " ";
	std::cout << std::endl;

}
void bogosort(std::vector<int> val){
	srand(time(NULL));
	int count = 1;
	while(!isSorted(val)){
		for(unsigned int x = 0; x < val.size(); x++)
			val = switchSpot(val, x, rand()%val.size());
		std::cout << count++ << ": ";
		printAll(val);

	}
}
int main() {
	std::vector<int> values = {3,8,4,7,5,1,9,2,6};
	bogosort(values);
	return 0;
}
