#include <iostream>
using namespace std;

void toh(int n , char source  , char destination ,char aux)
{
    /*
    taking two rods with n disks such that no upper disk is 
    larger than lower one , an auxilary disk is used 
    to transfer disks .

    */
   if(n>0){

          /*
    let assume all the n-1 disks are transfered to aux disk and then 
    so taking a recursive function -> from source to aux;
    since we can transfer single disk at a time.
   */
       
   toh(n - 1 , source, aux , destination  ) ;
  
    cout<<source <<"-> "<<destination<<endl;

    /*
    then the last nth disk given to destination


    */
   
   toh(n -1, aux, destination , source );

   /*

   then take all the n-1 disk from aux o destination;
   */
   }
   
}

int main(){
    int n;
    char a = '1',b ='2',c = '3';
    cout<<"enter n :";
    cin>>n;
    toh(n , a ,b,c);
    
    return 0;
}
