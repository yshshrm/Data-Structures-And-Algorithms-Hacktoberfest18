#include <bits/stdc++.h>  
using namespace std;  
  
// Function returns length of longest  
// substring starting with X and  
// ending with Y  
int longestSubstring(string str,  
                    char X, char Y)  
{  
    // Length of string  
    int N = str.length();  
    int start = 0;  
    int end = N - 1;  
    int xPos = 0;  
    int yPos = 0;  
  
    // Find the length of the string  
    // starting with X from the beginning  
    while (true) {  
  
        if (str[start] == X) {  
            xPos = start;  
            break;  
        }  
        start++;  
    }  
  
    // Find the length of the string  
    // ending with Y from the end  
    while (true) {  
  
        if (str[end] == Y) {  
            yPos = end;  
            break;  
        }  
        end--;  
    }  
  
    // Longest substring  
    int length = (yPos - xPos) + 1;  
  
    // Print the length  
    cout << length;  
}  
  
// Driver Code  
int main()  
{  
    // Given string str  
    string str;
    cout << "Enter String: " << endl;
    cin>>str;
  
    // Starting and Ending characters  
    char X, Y;
    cout << "X: " << endl;
    cin >> X;
    cout << "Y: " << endl;
    cin >> Y;
  
    // Function Call  
    longestSubstring(str, X, Y);  
    return 0;  
}
