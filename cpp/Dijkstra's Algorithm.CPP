#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<iomanip.h>
class Graph
{
 char Vnames[10][10];
 int nodes,cost[10][10];
 public:
 Graph();
 int Position(char S[10]);
 void creat_graph();
 void display();
 void Dijkstra();
}
Graph::Graph()
{
nodes=0;
for(i=0;i<10;i++)
for(int j=0;j<10;j++)
 {
 if(i==j)
	 cost[i][j]=0;
 else
	 cost[i][j]=999;
 }
}
void Graph::creat_graph()
{
char ans,Start[10],End[10];
int wt,i,j;
cout<<"Enter number of nodes";
cin>>nodes;
cout<<"\n Enter vertex name:";
for(i=0;i<nodes;i++)
{ cin>>Vnames[i];
}
do
{
cout<<"\nEnter Start and end point of edge";
cin>>Start>>End;
cout<<"Enter weight";
cin>>wt;
i=Position(Start);
j=Position(End);
cost[j][i]=cost[i][j]=wt;
cout<<"\nMore Edges ";
ans=getche();
}while(ans=='y' || ans=='Y');
}
void Graph::display()
{
int i,j;
 cout<<"\nAdjecancy Matrix\n\t";
  for(i=0;i<nodes;i++)
	  cout<<"\t"<<Vnames[i];

 for(i=0;i<nodes;i++)
	{
	 cout<<"\n\t"<<Vnames[i];
	 for(j=0;j<nodes;j++)
		 cout<<"\t"<<cost[i][j];
	}
}
int Graph::Position(char S[10])
{
int i;
for(i=0;i<10;i++)
if(strcmp(Vnames[i],S)==0)
break;
return i;
}
void Graph::Dijkstra()
{
int x,dis[10],visit[10],flag[10]={0};
int i,j,v,sor,min,mnode,k;
char Start[10];

cout<<"\nSingle Source & multiple destinations Algo";
cout<<"\nEnter Source: ";
cin>>Start;
sor=Position(Start);
flag[sor]=1; //init.
dis[sor]=0;

for(v=0;v<nodes;v++)  // initial distance matrix
{ dis[v]=cost[sor][v];}
visit[0]=sor;
cout<<"\nShortest path matrics\nNode\t\t Weight\n\t        ";
for(i=0;i<nodes;cout<<setw(3)<<i,i++);
i=0;
cout<<"\n";
for(x=0;x<=i;x++)
 cout<<setw(3)<<visit[x];
for(x=i+1;x<nodes;x++)
cout<<"  -";
cout<<"  : ";
for(x=0;x<nodes;x++)
cout<<setw(3)<<dis[x];

/*main loop         */
for(i=1;i<nodes;i++)
{   min=999;

    for(k=0;k<nodes;k++)
    {
	 if(flag[k]==0 && dis[k] < min) //find min. distance
		  {min=dis[k];mnode=k;}
     }
      flag[mnode]=1;
      visit[i]=mnode;
  for(j=0;j<nodes;j++)
   {  if(flag[j]==0 && cost[mnode][j]!=999)
	{  if(dis[j]>dis[mnode]+cost[mnode][j])
	     dis[j]=dis[mnode]+cost[mnode][j];
	 }
     }


cout<<"\n";
for(x=0;x<=i;x++)
 cout<<setw(3)<<visit[x];
for(x=i+1;x<nodes;x++)
cout<<"  -";

cout<<"  : ";
for(x=0;x<nodes;x++)
cout<<setw(3)<<dis[x];
getch();

}
}
void main()
{
Graph ShortestPath;
ShortestPath.creat_graph();
ShortestPath.display();
ShortestPath.Dijkstra();
}










