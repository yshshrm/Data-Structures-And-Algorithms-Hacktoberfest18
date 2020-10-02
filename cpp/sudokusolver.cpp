#include<iostream>
using namespace std ; 
void printBoard(int board[][9])
{
    for(int i=0; i<9 ;i++)
    {
        for(int j=0; j<9 ; j++)
        {
            cout << board[i][j] << " " ;
        }
        cout << endl ;
    }
    cout << endl ; 
    return ; 
}
bool isRowSafe(int board[][9],int row ,int num )
{
    for(int j=0 ; j<9 ;j++)
    {
        if(board[row][j]==num)
        return false ;
    }
    return true;
}
bool isColSafe(int board[][9] , int col ,int num )
{
     for(int i=0; i<9;i++)
     {
         if(board[i][col]==num)
         return false ;
     }
     return true ; 
}
bool isBoxSafe(int board[][9] , int row ,int col , int num)
{
     int rs = row - row%3;
     int cs = col - col%3; 

     for(int i=rs ; i<rs+3 ;i++)
     {
         for(int j=cs ; j<cs+3 ;j++)
         {
             if(board[i][j]==num)
             return false ; 
         }
     }
     return true ;
 }
bool canPlaceNum(int board[][9] , int row , int col , int num)
{
    if(!isRowSafe(board,row,num)) return false ;
    if(!isColSafe(board,col,num)) return false ;
    if(!isBoxSafe(board,row,col,num)) return false ;

    return true; 
}
bool sudokuSolver(int board[][9])
{
/// initialise the initial values 
   int row =-1 ; 
   int col = -1 ; 
   bool isEmpty = false ; 

   for(int i=0; i<9 ; i++)
   {
       for(int j=0; j<9 ;j++)
       {
           if(board[i][j]==0)
           {
               isEmpty = true ; 
               row = i ; 
               col = j ; 
               break ;
           }
       }
       if(isEmpty)
       break;
   }

   if(!isEmpty)
   return true ;

   for(int num =1 ; num<=9 ;num++)
   {
       if(canPlaceNum(board,row,col,num))
       {
           board[row][col] = num;
           if(sudokuSolver(board))
           {
               return true;
           }
           board[row][col] = 0 ;

       }
   }

   return false ;
}
int main()
{
    int t; 
    cin >> t ; 
    int board[9][9];
    while(t--)
    {
      for(int i=0 ; i<9 ; i++)
      {
          for(int j=0;j<9;j++)
          {
              cin>>board[i][j];
          }
      }
       bool ans = sudokuSolver(board); 
       if(ans)
       {
           printBoard(board); 
       }
       else 
       {
           return -1; 
       }
    }
    return 0 ;
}