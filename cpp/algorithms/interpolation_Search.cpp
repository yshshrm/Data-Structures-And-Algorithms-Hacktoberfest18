#include <iostream>


using namespace std;


//Time Complexity: If elements are uniformly distributed, then O (log log n)). In worst case it can take upto O(n).
//Auxiliary Space: O(1)


//Print array values

void print_ar (int ar[], int size)

{

  for (int i = 0; i < size; ++i)

  {

    cout << ar[i] << " ";

  }

    cout << endl;

}



//Interpolation Search
//Algorithm:


//Step1: In a loop, calculate the value of “pos” using the probe position formula.
//Step2: If it is a match, return the index of the item, and exit.
//Step3: If the item is less than arr[pos], calculate the probe position of the left sub-array. Otherwise calculate the same in the right sub-array.
//Step4: Repeat until a match is found or the sub-array reduces to zero.
// If x is present in arr[0..n-1], then returns
// index of it, else returns -1.

int interpolation_search (int ar[], int value, int size)

{
    // Find indexes of two corners

  int low = 0;

  int high = size - 1;

  int mid;


// Since array is sorted, an element present
    // in array must be in range defined by corner
  while (ar[low] <= value && ar[high] >= value)

  {

    mid = low + ((value - ar[low]) * (high - low)) / (ar[high] - ar[low]);

    if (ar[mid] < value)

    {

      low = mid + 1;

    }

    else if (ar[mid] > value)

    {

      low = mid - 1;

    }

    else

    {

      return mid;

    }

  }



  if (ar[low] == value)

  {

    return low;

  }

  else

  {

    return -1;

  }

}



//Driver Function

int main()

{

  int ar [] = {1, 2, 78, 18, 16, 30, 29, 2, 0, 199};

  int value, pos;



  cout << "Your Array : ";

  print_ar (ar, 10);



  cout << "Enter the value to search : ";

  cin >> value;

  pos = interpolation_search (ar, value, 10);

  if (pos != -1)

  {

    cout << "Value Found! at position : " << pos + 1 << endl;

  }

  else

  {

    cout << "Sorry, the value you searched for is not present." << endl;

  }



  return 0;

}

