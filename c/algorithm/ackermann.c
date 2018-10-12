/**
* This is the implementation of Ackermann's total computable function with 2 arguments.
* For reference see: https://en.wikipedia.org/wiki/Ackermann_function
*
* Really useful to stress a cpu. Instanciate 1 job per CPU (core or thread) available on
* your computer and go to bed, take a rest or read a book.
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int ackerman(int a, int b)
{
	if (!a) return ++b;
	else if (!b) return ackerman (a-1, 1);
	else return ackerman (a-1, ackerman (a,b-1));
}

int main (int argc, char ** argv)
{
	time_t t0 = time(NULL);
	printf("result: %d\n", ackerman (atoi(argv[1]),atoi(argv[2])));
	printf("done: %d", difftime(time(NULL),t0));
	return 0;
}
