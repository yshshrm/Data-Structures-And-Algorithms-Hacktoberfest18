#include <stdio.h>
#include <stdlib.h>
 

struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode* next;
};

struct AdjList
{
    struct AdjListNode *head;  
};

struct Graph
{
    int V;
    struct AdjList* array;
};
 
struct MinHeapNode
{
    int  v;
    int key;
};

struct MinHeap
{
    int size;      
    int capacity;  
    int *pos;    
    struct MinHeapNode **array;
};

 
int isEmpty(struct MinHeap* minHeap)
{
    return minHeap->size == 0;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

int isInMinHeap(struct MinHeap *minHeap, int v)
{
   if (minHeap->pos[v] < minHeap->size)
     return 1;
   return 0;
}

void printArr(int arr[], int n)
{
    int i,sum=0;
    for ( i = 0; i < n; ++i)
    {
        sum+=arr[i];
        //printf("%d - %d\n", arr[i], i);
        
    }
    printf("%d\n",sum );
}

struct AdjListNode* newAdjListNode(int dest, int weight)
{
    struct AdjListNode* newNode =(struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
 

struct Graph* createGraph(int V)
{
    int i;
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
 
    for ( i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
void addEdge(struct Graph* graph, int src, int dest, int weight)
{

    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

struct MinHeapNode* newMinHeapNode(int v, int key)
{
    struct MinHeapNode* minHeapNode =(struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->key = key;
    return minHeapNode;
}
 

struct MinHeap* createMinHeap(int capacity)
{
    struct MinHeap* minHeap =(struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->pos = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array =(struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}
 
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;
 
    if (left < minHeap->size &&
        minHeap->array[left]->key > minHeap->array[smallest]->key )
    smallest = left;
 
    if (right < minHeap->size &&
        minHeap->array[right]->key > minHeap->array[smallest]->key )
    smallest = right;
 
    if (smallest != idx)
    {
      
        struct MinHeapNode *smallestNode = minHeap->array[smallest];
        struct MinHeapNode *idxNode = minHeap->array[idx];
 
       
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
 
        minHeapify(minHeap, smallest);
    }
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    if (isEmpty(minHeap))
        return NULL;
    struct MinHeapNode* root = minHeap->array[0];
 

    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
 

    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;
 

    --minHeap->size;
    minHeapify(minHeap, 0);
 
    return root;
}

void decreaseKey(struct MinHeap* minHeap, int v, int key)
{

    int i = minHeap->pos[v];
    minHeap->array[i]->key = key;
 
    while (i && minHeap->array[i]->key > minHeap->array[(i - 1) / 2]->key)
    {
        minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
        swapMinHeapNode(&minHeap->array[i],  &minHeap->array[(i - 1) / 2]);
 
        i = (i - 1) / 2;
    }
}
 
void PrimMST(struct Graph* graph)
{
    int v;
    int V = graph->V;
    int parent[V];
    int length[V];   
    int key[V];      
 
    struct MinHeap* minHeap = createMinHeap(V);
 
    for (v = 1; v < V; ++v)
    {
        parent[v] = -1;
        key[v] = 0;
        minHeap->array[v] = newMinHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }
    key[0] = 0;
    minHeap->array[0] = newMinHeapNode(0, key[0]);
    minHeap->pos[0]   = 0;
 
    minHeap->size = V;

    while (!isEmpty(minHeap))
    {
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v; 
 
        struct AdjListNode* temp = graph->array[u].head;
        while (temp != NULL)
        {
            int v = temp->dest;
 
            if (isInMinHeap(minHeap, v) && temp->weight > key[v])
            {
                key[v] = temp->weight;
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
            temp = temp->next;
        }
    }
 
    printArr(key, V);
}
 

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int v,e;
        scanf("%d",&v);
        scanf("%d",&e);
        struct Graph* graph = createGraph(v);
        while(e--)
        {
            int src,dest,weight;
            scanf("%d",&src);
            scanf("%d",&dest);
            scanf("%d",&weight);
            addEdge(graph, src-1, dest-1, weight);
        }
        PrimMST(graph);
    }
    return 0;
}
