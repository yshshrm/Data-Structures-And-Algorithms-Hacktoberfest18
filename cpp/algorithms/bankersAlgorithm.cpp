// 2018-CS-44
// Zaeema Anwar
// Banker's Algorithm

#include<iostream>

using namespace std;

class banker {
    private :
        int no_of_processes;
        int no_of_resources;
        int *available;
        int **maximum;
        int **allocation;
        int ** need;
        int * work;

    public :
        banker(int n, int m);
        void setData();
        void runAlgo();
        void getSafeSequence();
};
int main (){
    int n, m;
    cout << "Enter the number of processes : ";
    cin >> n;
    cout << "Enter the number of resources : ";
    cin >> m;

    banker obj (n, m);
    obj.setData();
    obj.runAlgo();
    obj.getSafeSequence();

    return 0;
};

banker:: banker(int n, int m){
    no_of_processes = n;
    no_of_resources = m;
    work = new int [no_of_processes];
    available = new int [no_of_processes];
    maximum = new int *[no_of_processes];
    allocation = new int *[no_of_processes];
    need = new int *[no_of_processes];
    for (int i=0 ; i<no_of_processes; i++){
        maximum[i] = new int [no_of_resources];
        allocation[i] = new int [no_of_resources];
        need[i] = new int [no_of_resources];
    }
}

void banker :: setData(){
    cout << "     Enter available instances of resources : " << endl;
    cout << "    -----------------------------------------" << endl;
    for(int i=0; i<no_of_resources; i++){
        cout << "Resource " << i+1 << " : ";
        cin >> available[i];
    }
    for (int i=0; i<no_of_processes; i++){
        cout << "   ========= PROCESS " << i+1 << " ========="<< endl;
        for (int j=0; j<no_of_resources; j++){
            cout << "     ---- Resource " << j+1 << "----" << endl;
            cout << "Maximum demand of process : ";
            cin >> maximum[i][j];
            cout << "Currently allocated resource instances  : ";
            cin >> allocation[i][j];
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
        cout << endl;
    }
}

void banker :: runAlgo(){
    bool *finish = new bool [no_of_resources];
    for (int j=0; j<no_of_resources; j++)
        finish[j] = false;
    int ind = 0;
    for (int k =0; k<no_of_processes; k++){
        for (int i =0 ;i < no_of_processes ; i++){
            if (finish[i] == false){
                bool temp = false;
                for (int j = 0 ; j < no_of_resources; j++){
                    if (need[i][j] > available[j]){
                        temp = true;
                        break;
                    }
                }
                if (temp == false){
                    work[ind++] = i;
                    for (int y=0; y<no_of_resources; y++)
                        available[y] = available[y]+allocation[i][y];
                    finish[i] = true;
                }
            }
        }
    }
}

void banker :: getSafeSequence() {
    cout << "The safe Sequence for the processes is : ";
    for (int i =0 ; i< no_of_processes ; i++)
        cout << "Process (" << work[i] << ")   ";
}