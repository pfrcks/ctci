#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <list>

using namespace std;

struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

struct AdjList
{
    struct AdjListNode* head;
};

struct Graph
{
    int v;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int v)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->v = v;
    graph->array = (struct AdjList*)malloc(v*sizeof(struct AdjList));
    for(int i=0; i < v; i++)
        graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    struct AdjListNode* node = newAdjListNode(dest);
    node->next = graph->array[src].head;
    graph->array[src].head = node;

    //node = newAdjListNode(src);
    //node->next = graph->array[dest].head;
    //graph->array[dest].head = node;
}

void printGraph(struct Graph* graph)
{
    for(int i=0; i < graph->v; i++)
    {
        struct AdjListNode* temp = graph->array[i].head;
        cout << "For vertex " << i << endl;
        while(temp)
        {
            cout <<"-> " << temp->dest;
            temp = temp->next;
        }
    }
}

void bfs(struct Graph* graph, int src)
{
    bool *visited = new bool[graph->v];
    for(int i=0; i < graph->v; i++)
        visited[i] = false;
    list<int> queue;
    visited[src] = true;
    queue.push_back(src);
    while(!queue.empty())
    {
        int s = queue.front();
        cout << s << endl;
        queue.pop_front();
        struct AdjListNode* tmp = graph->array[s].head;
        while(tmp)
        {
            if(visited[tmp->dest] == false)
            {
                visited[tmp->dest] = true;
                queue.push_back(tmp->dest);
            }
            tmp = tmp->next;
        }
    }
}

void dfsUtil(struct Graph* graph, int src, bool visited[])
{
    visited[src] = true;
    cout << src << endl;
    struct AdjListNode* tmp = graph->array[src].head;
    while(tmp)
    {
        if(visited[tmp->dest] == false)
            dfsUtil(graph, tmp->dest, visited);
        tmp = tmp->next;
    }
}

void dfs(struct Graph* graph)
{
    bool *visited = new bool[graph->v];
    for(int i=0; i<graph->v; i++)
        visited[i] =false;
    for(int i=0; i< graph->v; i++)
        if(visited[i] == false)
        dfsUtil(graph, i, visited);
}
