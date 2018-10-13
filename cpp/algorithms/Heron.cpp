#include <iostream>
#include <math.h>
using namespace std;

void Heron() {
    float A, B, C, semiP, Area;

    cout << "Insert first side: ";
    cin >> A;
    
    cout << "Insert second side: ";
    cin >> B;

    cout << "Insert third side: ";
    cin >> C;

    cout << endl;

    semiP=(A+B+C)/2;

    if(semiP<=A or semiP<=B or semiP<=C)
        cout << "This triangle doesn't exist!" << endl;
    else
        Area=sqrt((semiP-A)*(semiP-B)*(semiP-C)*semiP);

    cout << "The area of the triangle is " << Area << "." << endl;
}

int main () {
    Heron();

return 0;
}