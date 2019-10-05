// CPP program to print Fizz Buzz 
#include <iostream> 
#include <algorithm> 
#include <vector> 
	
int main() 
{ 
	// dynamic array(range) of size 100 of int type 
	std :: vector<int> range(100); 

	// 'iota' to fill the vector in increasing manner 
	std :: iota(range.begin(), range.end(), 1); 

	// initializing dynamic array of string type 
	std :: vector<std::string> values; 

	// resize the vector(values) as that of vector(range) 
	values.resize(range.size()); 

	//'auto' to deduce the type of the variable 
	auto fizzbuzz = [](int i) -> std::string				 
	{ 
		// number divisible by 15(will also be 
		// divisible by both 3 and 5), print 'FizzBuzz' 
		if ((i%15) == 0) 
			return "FizzBuzz"; 

		// number divisible by 5, print 'Buzz' 
		if ((i%5) == 0) 
			return "Buzz"; 

		// number divisible by 3, print 'Fizz' 
		if ((i%3) == 0) 
			return "Fizz"; 

		// to print other numbers 
		return std::to_string(i); 
	}; 

	// Operation to each of the elements in the 
	// range [begin(), end()) and stores the 
	// value returned by each operation in the 
	// range that begins at values.begin(). 
	std :: transform(range.begin(), range.end(), 
					values.begin(), fizzbuzz);	 
	for (auto& str: values)												 
		std::cout << str << std::endl; 

	return 0;																					 
} 
