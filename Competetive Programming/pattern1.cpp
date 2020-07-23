#include <iostream>

using namespace std;

int main() {
	int num;
	int j=0;
	cin >> num;
	for(int i=1; i<=num; i++){
        int count =0;
        while( j<100){
            j++;
            cout<<j<<" ";
            count++;
            if(count ==i)
                break;
        }
        //j++;
        cout<<endl;
	}
}
