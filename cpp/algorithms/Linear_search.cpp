#include<iostream>
using namespace std;
int main() {
  int i, key, n, count = 0, pos;
  cout << "Enter the array size : ";
  cin >> n;
  int arr[n];
  cout << "Enter Array Elements : ";
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << "Enter the number to be searched : ";
  cin >> key;
  for (i = 0; i < n; i++) {
    if (arr[i] == key) {
      count = 1;
      pos = i + 1;
      break;
    }
  }
  if (count == 0) {
    cout <<"Number not found..!!";
  } else {
    cout <<"found at position " << pos;
  }
}
