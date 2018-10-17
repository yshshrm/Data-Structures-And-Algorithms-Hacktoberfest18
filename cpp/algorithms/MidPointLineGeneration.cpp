#include<iostream>
using namespace std;

void printLine(int x1, int x2, int y1, int y2){
    int dy = y2 - y1, dx = x2 - x1;
    //initial value of the decision parameter
    int d0 = dy - (dx/2);
    int startx = x1, starty = y1;
    cout<<startx<<" "<<starty<<endl;
    while(startx < x2){
        startx++;
        if(d0 < 0){
            //The Next point is EAST
            d0 = d0 + dy;
        }
        else{
            //The Next point is North East
            d0 = d0 + dy - dx;
            starty++;

        }
    cout<<startx<<" "<<starty<<endl;
    }
}
int main(){
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;

    printLine(x1, x2, y1, y2);
}