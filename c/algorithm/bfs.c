#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct que{
	int data[20];
	int rear,front;
}que;

typedef struct node{
	int vertex;
	struct node *next;
}node;

	node *g[20];
	int visited[20];
	int n;
	void read_graph();
	void insert(int,int);
	//void dfs(int);
	void bfs(int);
	int empty(que *);
	int full(que *);
	void enque(que *,int);
	int deque(que *);

int main()
{
	read_graph();
	int i;
	for(i=0;i<n;i++)
		visited[i] = 0;
		
	//dfs(1);
	bfs(0);
}

void read_graph()
{
	int no_of_edges,i=0,u,v;
	printf("enter no of vertices");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		g[i]=NULL;
	printf("enter no of edges");
	scanf("%d",&no_of_edges);
	
	for(i=0;i<no_of_edges;i++)
	{
		printf("enter vertices u,v");
		scanf("%d %d",&u,&v);
		insert(u,v);
	}	
}
void insert(int u,int v)
{
	node *p,*q;
	q = (node*)malloc(sizeof(node));
	q->vertex = v;
	q->next = NULL;
	
	if(g[u] == NULL)
	{
		g[u] = q;
	}
	else
	{
		p = g[u];
		while(p->next!=NULL)
		p=p->next;
		
		p->next = q;
	}
}
/*void dfs(int i)
{
	node *p;
	printf("%d",i);
	p = g[i];
	visited[i] = 1;	
	
	while(p!=NULL)
	{
		i = p->vertex;
		if(!visited[i])
		dfs(i);
		
		p = p->next;
	}
}
bool biparite(int v)
{
	visited[v] = true;
	node *temp = g[v];
	while(temp!=NULL)
	{
		int i = temp->vertex;
		if(!visited[i])
		{
			color[i]=!color[v];
			if(!biparite(i))
			return false;
		}
		else if(color[i] == color[v])
		return false;
	temp = temp->next;
	}
	return true;
}*/

void bfs(int i)
{
	node *p;
	que q;
	q.rear = q.front =-1;
	
	/*int visited[20];
	for(int i=0;i<n;i++)
	visited[i] = 0;*/
	
	enque(&q,i);
	printf("%d",i);
	visited[i] = 1;
	
	while(!empty(&q))
	{
		i=deque(&q);
		p = g[i];
		while(p!=NULL)
		{int w = p->vertex;
			if(visited[w]==0)
			{
				enque(&q,w);
				visited[w]=1;
				printf("%d",w);
			}
			p = p->next;
		}
	}
}

int empty(que *p)
{
	if(p->rear==-1)
	return 1;
	return 0;
}
int full(que *p)
{
	if(p->rear==19)
	return 1;
	return 0;
}
void enque(que *p,int x)
{
	if(p->rear == -1)
	{	
		p->rear = p->front =0;
		p->data[p->rear] = x;
	}
	else
	{
		p->rear = p->rear+1;
		p->data[p->rear] = x;
	}
}
int deque(que *p)
{
	int x;
	x=p->data[p->front];
	if(p->rear==p->front)
	{
		p->rear = -1;
		p->front = -1;
	}
	else
	p->front = p->front+1;
	return x;
}




















	
		
		
		
		
		
		
		
		
		
		
		
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
