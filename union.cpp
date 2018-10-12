#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct edge
{
int src,dest,sum,weight;
};

struct graph
{
int v,e;
struct edge* edg;
};
struct subset
{
    int par;
    int rnk;
};

struct graph* create(int v,int e)
{
    struct graph* grap=(struct graph*)malloc(sizeof(struct graph));
    grap->v=v;
    grap->e=e;
    grap->edg=(struct edge*)malloc(sizeof(struct edge)*e);
};

void print(struct graph* graph)
{
    int i;
    for(i=0;i<graph->e;i++)
    {
        cout<<graph->edg[i].src<<" "<<graph->edg[i].dest<<graph->edg[i].sum<<endl;
    }


}

bool compare(struct edge e1,struct edge e2)
{
    if(e1.weight==e2.weight)
    {
        if(e1.sum!=e2.sum)
        {
        return e1.sum<e2.sum;
        }
        else
        {
            return e1.sum;
        }
    }
    return e1.weight<e2.weight;
}

void swap(struct edge *a,struct edge *b )
{
    struct edge temp=*a;
    *a=*b;
    *b=temp;
}

int fnd(struct subset s[],int x)
{
    if(s[x].par!=x)
    {
        s[x].par=fnd(s,s[x].par);
    }
    return s[x].par;
}
void uni(struct subset s[],int x,int y)
{
    int xt=fnd(s,x);
    int yt=fnd(s,y);
    if(s[xt].rnk<s[yt].rnk)
    {
        s[xt].par=yt;
    }
    else if(s[xt].rnk>s[yt].rnk)
    {
        s[yt].par=xt;
    }
    else
    {
        s[yt].par=xt;
        s[xt].rnk++;
    }
}
void kruskal(struct graph *g)
{
    int i=0;
    struct edge res[g->v];
    for(int d=0;d<g->v;d++)
    {
        res[d].src=0;
        res[d].dest=0;
    }
    struct subset *sub=(struct subset*)malloc(sizeof(struct subset)*(g->v+1));
    for(int i=1;i<g->v+1;i++)
    {
        sub[i].par=i;
        sub[i].rnk=0;
    }
    int e=0;
    while(e<g->v-1)
    {

        struct edge ed=g->edg[i++];
        int x=fnd(sub,ed.src);
        int y=fnd(sub,ed.dest);
        if(x!=y)
        {
            res[e++]=ed;
            uni(sub,x,y);

        }
    }
    int sum=0;
    for(int e=0;e<g->v;e++)
    {

        if(res[e].src!=0&&res[e].dest!=0)
        {
            sum=sum+res[e].weight;
        }
    }
cout<<sum;
}
int main()
{
int v,e;
cin>>v>>e;
struct graph* g=create(v,e);
for(int i=0;i<e;i++)
{
    int x,y,z;
    cin>>x>>y>>z;
    g->edg[i].src=x;
    g->edg[i].dest=y;
    g->edg[i].sum=x+y+z;
    g->edg[i].weight=z;
}

for(int i=0;i<e;i++)
{
 for(int j=0;j<e-i-1;j++)
 {
    if(g->edg[j].weight>g->edg[j+1].weight)
    {
        swap(g->edg[j],g->edg[j+1]);
    }

     if(g->edg[j].weight==g->edg[j+1].weight)
     {
         if(g->edg[j].sum>g->edg[j].sum)
         {
             swap(g->edg[j],g->edg[j+1]);
         }
     }
 }
}
kruskal(g);
}
