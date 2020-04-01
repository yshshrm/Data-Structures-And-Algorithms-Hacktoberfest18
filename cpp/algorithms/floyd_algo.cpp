// Floyd-Warshall Algorithm in C++

#include <bits/stdc++.h>

//INFNUM says that between graph[x][y], there is no path
#define INFNUM 10000000

using namespace std;

int main(){

    //Inputs
    //Take the graph as an array V*V
    //The graph is says whether there is a path between x and y, according to the graph[x][y] value
    //If graph[x][y] value is INFNUM, then there is no path
    int V;
    
    //Take vertex
    cin >> V;

    //Initialize the graph
    int graph[V][V];

    //Fill the graph
    for(int i=0;i<V;i++){
        //Take the input like
        //0 1 1
        //1 0 0
        //1 3 0
        for(int j=0;j<V;j++){
            cin >> graph[i][j];
        }
    }


    //Algorithm is here
    //Floyd-Warshall algorithm is a n^3 algorithm as seen there is 3 inside loops
    //The algorithm controls if between i,j there is a closer path with crossing k
    //If there is, it decreases the path as [i][j]=[i][k]+[i][j]
    //To be clear, it does i -> k -> j. If this path is closer than the path for now, algorithm changes to i->k->j
    //To work algorithm correctly, we have to use this loop,first k,then i,then j or first k,then j,then i
    //It is important that k is first, because while we are doing changes to the graph, we can miss some changes if we don't use first k
    for(int k=0;k<V;k++){

        for(int i=0;i<V;i++){

            for(int j=0;j<V;j++){

                graph[i][j]=min(graph[i][j],graph[i][k] + graph[k][j]);

            }

        }

    }




    //Just print
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]==INFNUM)
                cout << "INF ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
        //print the graph path values line by line
    }
    


    return 0;
}
