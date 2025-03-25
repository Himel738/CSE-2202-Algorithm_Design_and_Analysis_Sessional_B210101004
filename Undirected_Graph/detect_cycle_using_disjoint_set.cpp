#include<bits/stdc++.h>
using namespace std;

class Edge
{
    public:
        int src,dest;  
};

class Graph
{
    public:
        int v,e;
        Edge * edge;
};

Graph *createGraph(int v,int e)
{
    Graph * graph = new Graph();
    graph -> v = v;
    graph -> e = e;

    graph -> edge = new Edge[graph -> e * sizeof(Edge)];

    return graph;
}

int find(int parent[],int i)
{
    if(parent[i] == -1)
    {
        return i;
    }

    return find(parent,parent[i]);
}

void Union(int parent[],int x,int y)
{
    parent[y] = x;
}

int isCycle(Graph * graph)
{
    int * parent = new int[graph -> v];

    for(int i = 0; i <  graph-> v; i++)
    {
        parent[i] = -1;
    }

    for(int i = 0; i < graph -> e; i++)
    {
        int x = find(parent,graph -> edge[i].src);
        int y = find(parent, graph -> edge[i].dest);

        if(x==y && (x != -1 && y != -1))
        {
            return 1;
        }
        else
        {
            Union(parent,x,y);
        }

    }
}



int main ()
{
    int v = 5, e = 5;

    Graph * graph = createGraph(v,e);

    graph -> edge[0].src = 0;
    graph -> edge[0].dest = 1;

    graph -> edge[0].src = 0;
    graph -> edge[0].dest = 2;

    graph -> edge[1].src = 1;
    graph -> edge[1].dest = 3;

    graph -> edge[1].src = 1;
    graph -> edge[1].dest = 4;



    graph -> edge[3].src = 3;
    graph -> edge[3].dest = 4;

    if(isCycle(graph))
    {
        cout << "Graph Contains Cycle" << endl;
    }
    else
    {
        cout << "Dosen't Have a Cycle" << endl;
    }

}