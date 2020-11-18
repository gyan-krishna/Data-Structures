/*
 * mstSet[] - vertices already included in the MST - [bool]
 * key[] 	- min wt edge connecting node n to the MST
 *
 * Algorithm :-
 *
 * mstSet[] = empty
 * key[1-n]    = Inf
 * key[0]	   = 0
 *
 * While, mstSet[] dont have all vertices,
 *		-  select Vertex v, which is not in mstSet and has min key
 * 		-  add v to mstSet
 * 		-  update key of neighbours of v,
 * 			> iterate through all vertices, if wt of edge(n-v) < key[n], key[n] = wt of edge(n-v)
*/

#include<stdio.h>
#include<limits.h>

#define MAX 100
#define INF INT_MAX

//int adj[MAX][MAX];
int adj[5][5] = { { 0, 2, 0, 6, 0 }, 
                  { 2, 0, 3, 8, 5 }, 
                  { 0, 3, 0, 0, 7 }, 
                  { 6, 8, 0, 0, 9 }, 
                  { 0, 5, 7, 9, 0 } }; 

int mstSet[MAX];
int key[MAX];
int parent[MAX];
int n;


int main()
{
	int e,src,dest,wt;
	printf("Enter number of vertices:: ");
	scanf("%d",&n);
	
	printf("enter number of edges in the graph::");
	scanf("%d",&e);
	
	for(int i = 0 ;  i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			adj[i][j] = 0;

	printf("enter the edges in the format of src - dest - weight:\n");
	for(int i = 0 ; i < e ; i++)
	{
		printf("edge no %d. = ",i);
		scanf("%d%d%d",&src,&dest,&wt);
		//non directional graph, so adding the edges src-dest and dest-src
		adj[src][dest] = wt;
		adj[dest][src] = wt;
	}
	
	//initialising mst with no elements
	for(int i = 0 ; i < n ; i++)
		mstSet[i] = 0;
	
	//initialising the key as infinite
	for(int i = 0 ; i < n ; i++)
		key[i] = INF;
	key[0] = 0;	// distance from src to src = 0
	
	for(int u = 0 ; u < n ; u++)//using loop to populate mstSet
	{
		//now, picking up a vertex v, that is not in mstSet,
		//and has min key value
		int min = INF,v; // v = pos of min element in key,
		for(int i = 0 ; i < n ; i++)
			if(mstSet[i] == 0 && key[i] < min)
			{
				min = key[i];
				v = i;
			}
		//adding the newly selected vertex to the mstSet
		mstSet[v] = 1;
		
		//updating key of neighbours of v,
		for(int i = 1 ; i < n ; i++)
		{
			
			if(adj[v][i] != 0)//checking if i is a neighbour of v!
			{
				if(mstSet[i] == 0)//checking if i is not in MST already!
				{
					//checking if new weight is less than prev one, if so, updating
					if(adj[v][i] < key[i])
					{
						key[i] = adj[v][i];
						parent[i] = v;
					}
				}
			}
		}
	}
	// printing the MST
	for(int i = 1 ; i < n ; i++)
		printf("%d - %d wt[%d]\n",i,parent[i],adj[i][parent[i]]);
	return 0;
}
