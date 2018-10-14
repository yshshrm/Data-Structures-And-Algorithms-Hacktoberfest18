#include <iostream>
#include <cstring>
#include <cstdlib>

// input array as string e.g. "0120"
// small inputs recommended because computational complexity is uncertain and (based on probability of correct order) grows with (n!).

bool test(int* nums, int length) {
	for (int i = 0; i < length-1; i++) {
		if (nums[i] > nums[i+1]) {
			return false;
		}
	}
	return true;
}

void swap(int* nums, int iind, int nind) {
	int temp = nums[iind];
	nums[iind] = nums[nind];
	nums[nind] = temp;
}

int main(int argc, char* argv[]) {
	//check for args
	if (argc < 2) {
		std::cout << "Invalid number of arguments, please specify a numstring as follows: " << argv[0] << " 0,11,2" << std::endl;
		return 1;
	}

	//concat input arguments
	int arglen = 0;
	for (int i = 1; i < argc; i++) {
		arglen += strlen(argv[i]);
	}
	char* numarg = new char[arglen+1]; //null char
	for (int i = 1; i < argc; i++) {
		strcpy(numarg, argv[i]);
	}

	//split by comma
	int commacount = 0;
	for (int i = 0; i < arglen; i++) {
		if (numarg[i] == ',') {
			commacount++;
		}
	}
	numarg[arglen] = ',';
	int* numarr = new int[commacount+1];
	int si = 0;
	int ni = 0;
	for (int i = 0; i < arglen+1; i++) {
		if (numarg[i] == ',') {
			numarg[i] = 0;
			errno = 0;
			numarr[ni] = strtol(numarg+si, NULL, 10);
			if (errno != 0) { //check for valid number
				std::cout << "Invalid argument string!" << std::endl;
				return 1;
			}
			si = i+1;
			ni++;
		}
	}
	delete[] numarg;

	int iter = 0;
	//randomly arrange cstring and test for correct order
	do {
		if (iter % 100 == 0) {
			std::cout << "[" << iter << "] mixing numbers.." << std::endl;
		}
		for (int i = 0; i < ni; i++) {
			swap(numarr, i, rand() % ni);
		}
		iter++;
	} while (!test(numarr, ni));

	//print result
	std::cout << "Sorted array: ";
	for (int i = 0; i < ni-1; i++) {
		std::cout << numarr[i] << ",";
	}
	std::cout << numarr[ni-1] << std::endl;
}