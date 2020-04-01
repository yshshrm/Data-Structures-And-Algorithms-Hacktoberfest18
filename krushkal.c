#include<stdio.h>
#include<stdlib.h>
int rank[20];
typedef struct edge{
	int u,v,w;
}edge;


int findSet(int i,int parent[])	//parent of the vertex
{
	if(parent[i]!=i)
		parent[i]=findSet(parent[i],parent);
	return parent[i];
}

void link(int x, int y, int parent[])
{
	if(rank[x]>rank[y])
	parent[y]=x;
	else
	{
		parent[x]=y;
		if(rank[x]==rank[y])
		rank[y]++;
	}

}

void Union(int p,int q,int parent[])	//function to merge or make a union of a set of vertex
{
	link(findSet(p,parent),findSet(q,parent),parent);
}


int partition(edge a[],int p,int r)	//using the quick sort algo for sorting
{
	edge x = a[r];
	int i=p-1,j;
	edge temp;
	for(j=p;j<=r-1;j++)
	{
		if(a[j].w<=x.w)
		{
			i=i+1;
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}
	}
	temp=a[r];
	a[r]=a[i+1];
	a[i+1]=temp;
	return (i+1);
}

void quickSort(edge a[],int p,int r)
{
	int q,i;
	if(p<r)
	{
		q=partition(a,p,r);
		quickSort(a,p,q-1);
		quickSort(a,q+1,r);
	}
}

void print(edge e[],int n)
{
	int i;
	printf("Source\tDestination\tWeight\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\n",e[i].u,e[i].v,e[i].w);
	}
}

void main()
{
	int i,j,n,ne,minCost=0,s,d;
	printf("\nENTER NUMBER OF VERTICES AND EDGES\n");
	scanf("%d %d",&n,&ne);
	edge e[ne];
	int parent[ne];
	printf("\nENTER VALUES AS SOURCE DESTINATION AND EDGE WEIGHT\n");
	for(i=0;i<ne;i++)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
		//initializing the parent
	for(i=0;i<n;i++)
		{
		parent[i]=i;
		rank[i]=0;
		}
	quickSort(e,0,ne-1);
	print(e,ne);
	printf("After Sorting the edges\nSource\tDestination\tWeight\n");
	for(i=0;i<ne;i++)
	{
		s=findSet(e[i].u,parent);
		d=findSet(e[i].v,parent);
			//if the parent is not the part of the component then union is performed
		if(s!=d)
		{
			//printing and computing minimum cost
			printf("%d\t%d\t%d\n",e[i].u,e[i].v,e[i].w);
			minCost+=e[i].w;
			Union(e[i].u,e[i].v,parent);
		}
	}
	printf("Cost of Minimum Spanning tree = %d",minCost);
}
