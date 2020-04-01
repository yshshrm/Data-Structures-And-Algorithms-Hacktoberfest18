#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char From_Rod, char To_Rod, char Aux_Rod)
{
	if (n == 1) //Base case: When the last disc is left on the 'From' rod
	{
		cout << "Move disk 1 from rod " << From_Rod <<" to rod " << To_Rod<<endl;
		return;
	}
	towerOfHanoi(n - 1, From_Rod, Aux_Rod, To_Rod);
	cout << "Move disk " << n << " from rod " << From_Rod <<
								" to rod " << To_Rod << endl;
	towerOfHanoi(n - 1, Aux_Rod, To_Rod, From_Rod);
}

// Driver code
int main()
{
	int n = 4; // Number of disks
	towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
	return 0;
}



