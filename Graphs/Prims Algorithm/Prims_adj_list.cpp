#include<stdio.h>
#define<limits.h>

#define MAX 100
#define INF INT_MAX

struct Vertex
{
	struct Vertex *next;
	int Vert;
	int dest;
};
struct Graph
{
	int n;
	struct Vertex *list[];
};

typedef struct Vertex Vertex;
typedef struct Graph Graph;

int n;
int mstSet[MAX];
int key[MAX];
int parent[MAX];


int main()
{
	// input stuff
	
	for(int i = 0 ; i < n ; i++)
		mstSet[i] = 0;
	for(int i = 0 ; i < n ; i++)
		key[i] = INF;
	key[0] = 0;
	
	for(int u = 0 ; u < n ; u++)//using loop to fill up mstSet
	{
		// finding vertex v, which has min weight and not in mstSet
		int v,min=INF;//v = min wt in key[]
		for(int i = 0 ; i< n ; i++ )
			if(key[i] < min && mstSet[i] == 0)
			{
				v = i;
				min = key[i];
			}
		
		// adding v to mstSet !
		mstSet[v] = 1;
		//updating keys of neighbours of v!
		Vertex *neighbour = G->list[v]; 
		while(neighbour != NULL)
		{
			// if neighbour not in mstSet,
			if(mstSet[neighbour->Vert] == 0)
			{
				//checking if new weight is less than prev one, if so, updating
				if(neighbour->weight < key[neighbour->Vert])
				{
					key[neighbour->Vert] = neighbour->weight;
					parent[neighbour->Vert] = v;
				}
			}
		}
	}
	// printing the MST
	for(int i = 0 ; i < n ; i++)
		printf("%d - %d wt[%d]\n",i,parent[i],adj[i][parent[i]]);
	return 0;
}
