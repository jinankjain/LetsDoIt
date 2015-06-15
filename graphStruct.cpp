#include <bits/stdc++.h>
using namespace std;

struct AdjListNode
{
	int node;
	struct AdjListNode* next;
};

struct AdjList
{
	struct AdjListNode* head;
};

struct AdjListNode* newNode(int node)
{
	struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->node = node;
	newNode->next = NULL;
	return newNode;
}

struct Graph
{
	int V; // Number of Vertices in Graph
	struct AdjList* list;
};

struct Graph* create(int V)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;

	graph->list = (struct AdjList*) malloc(V*sizeof(struct AdjList));
	for(int i=0;i<V;i++)
	{
		graph->list[i].head = NULL;
	}
	return graph;
}

void addEdge(struct Graph* g, int src, int dst)
{
	struct AdjListNode* temp = newNode(dst);
	temp->next = g->list[src].head;
	g->list[src].head = temp;
}

void printGraph(struct Graph* g)
{
	for(int i=0;i<g->V;i++)
	{
		struct AdjListNode* temp = g->list[i].head;
		printf("\n Adjacency list of vertex %d head ", i);
		while(temp)
		{
			printf("-> %d", temp->node);
			temp = temp->next;
		}
	}
}

int main()
{
	int V = 5;
    struct Graph* graph = create(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 	//print the Graph
    printGraph(graph);
	return 0;
}