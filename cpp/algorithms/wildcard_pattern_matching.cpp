/*Given a text and a wildcard pattern, implement wildcard pattern matching algorithm that finds if wildcard pattern is matched with text. The matching should cover the entire text (not partial text).

The wildcard pattern can include the characters ‘?’ and ‘*’
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)

For example,

Text = "baaabab",
Pattern = “*****ba*****ab", output : true
Pattern = "baaa?ab", output : true
Pattern = "ba*a?", output : true
Pattern = "a*ab", output : false */

// C++ program to implement wildcard 
// pattern matching algorithm 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function that matches input str with 
// given wildcard pattern 
bool strmatch(char str[], char pattern[], 
              int n, int m) 
{ 
    // empty pattern can only match with 
    // empty string 
    if (m == 0) 
        return (n == 0); 
  
    // lookup table for storing results of 
    // subproblems 
    bool lookup[n + 1][m + 1]; 
  
    // initailze lookup table to false 
    memset(lookup, false, sizeof(lookup)); 
  
    // empty pattern can match with empty string 
    lookup[0][0] = true; 
  
    // Only '*' can match with empty string 
    for (int j = 1; j <= m; j++) 
        if (pattern[j - 1] == '*') 
            lookup[0][j] = lookup[0][j - 1]; 
  
    // fill the table in bottom-up fashion 
    for (int i = 1; i <= n; i++) 
    { 
        for (int j = 1; j <= m; j++) 
        { 
            // Two cases if we see a '*' 
            // a) We ignore ‘*’ character and move 
            //    to next  character in the pattern, 
            //     i.e., ‘*’ indicates an empty sequence. 
            // b) '*' character matches with ith 
            //     character in input 
            if (pattern[j - 1] == '*') 
                lookup[i][j] = lookup[i][j - 1] || 
                               lookup[i - 1][j]; 
  
            // Current characters are considered as 
            // matching in two cases 
            // (a) current character of pattern is '?' 
            // (b) characters actually match 
            else if (pattern[j - 1] == '?' || 
                    str[i - 1] == pattern[j - 1]) 
                lookup[i][j] = lookup[i - 1][j - 1]; 
  
            // If characters don't match 
            else lookup[i][j] = false; 
        } 
    } 
  
    return lookup[n][m]; 
} 
  
int main() 
{ 
    char str[] = "baaabab"; 
    char pattern[] = "*****ba*****ab"; 
    // char pattern[] = "ba*****ab"; 
    // char pattern[] = "ba*ab"; 
    // char pattern[] = "a*ab"; 
    // char pattern[] = "a*****ab"; 
    // char pattern[] = "*a*****ab"; 
    // char pattern[] = "ba*ab****"; 
    // char pattern[] = "****"; 
    // char pattern[] = "*"; 
    // char pattern[] = "aa?ab"; 
    // char pattern[] = "b*b"; 
    // char pattern[] = "a*a"; 
    // char pattern[] = "baaabab"; 
    // char pattern[] = "?baaabab"; 
    // char pattern[] = "*baaaba*"; 
  
    if (strmatch(str, pattern, strlen(str), 
                         strlen(pattern))) 
        cout <<    "Yes" << endl; 
    else
        cout << "No" << endl; 
  
    return 0; 
} 
