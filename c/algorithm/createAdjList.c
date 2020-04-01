#include "my.h"
#define MAX_VERTICES 26

void createAdjList(Vertex* vertices[], FILE* inputFile)
{
	Vertex* startVertex = vertices[0];
	Vertex* firstVertex = (Vertex*)malloc(sizeof(Vertex));
	Vertex* secondVertex = (Vertex*)malloc(sizeof(Vertex));

	printf("\n");	
	printf("Adjacency List\n");
	printf("--------------------\n");
	while (fscanf(inputFile, "%c %c ", &firstVertex->letter, &secondVertex->letter) == 2)
	{
		firstVertex->edges = NULL;
		secondVertex->edges = NULL;
		firstVertex->isVisited = false;
		secondVertex->isVisited = false;

		int i;
		for (i = 0; i < MAX_VERTICES; i++)
		{
			if (vertices[i]->letter == '?')
			{
				*vertices[i] = *firstVertex;
			}
			if (vertices[i]->letter == firstVertex->letter)
			{
				firstVertex = vertices[i];
				break;
			}
		}
		for (i = 0; i < MAX_VERTICES; i++)
		{
			if (vertices[i]->letter == '?')
			{
				*vertices[i] = *secondVertex;
			}
			if (vertices[i]->letter == secondVertex->letter)
			{
				secondVertex = vertices[i];
				break;
			}
		}
		Edge* newEdge = (Edge*)malloc(sizeof(Edge));
		newEdge->nextEdge = NULL;
		newEdge->connectingVertex = secondVertex;

		if (firstVertex->edges == NULL)
		{
			firstVertex->edges = newEdge;
			firstVertex->edges->nextEdge = NULL;
			firstVertex->edges->connectingVertex = secondVertex;
			firstVertex->tailEdge = newEdge;
		}
		else
		{
			firstVertex->tailEdge->nextEdge = newEdge;
			firstVertex->tailEdge = newEdge;
		}
		firstVertex = (Vertex*)malloc(sizeof(Vertex));
		secondVertex = (Vertex*)malloc(sizeof(Vertex));
	}
	int i;
	for (i = 1; i < MAX_VERTICES; i++)
	{
		Edge* edge = startVertex->edges;
		
		if (vertices[i]->letter == '?')
		{
			break;
		}
		else
		{
			while(edge != NULL)
			{
				if (edge->connectingVertex->letter == vertices[i]->letter)
				{
					break;
				}
				else if (edge->nextEdge == NULL)
				{
					edge->nextEdge = (Edge*)malloc(sizeof(Edge));
					edge->nextEdge->connectingVertex = vertices[i];
					edge->nextEdge->nextEdge = NULL;
					startVertex->tailEdge = edge->nextEdge;
				}
				else
				{
					edge = edge->nextEdge;
				}
			}
		}
	}
	for (i = 0; i < MAX_VERTICES; i++)
	{
		Edge* edge = vertices[i]->edges;
		if (vertices[i]->letter == '?')
		{
			break;
		}
		printf("%c \t| ", vertices[i]->letter);
		while (edge != NULL)
		{
			printf("%c ", edge->connectingVertex->letter);
			edge = edge->nextEdge;
		}
		printf("\n");
	}
	printf("\n-------------------\n");
}
