#include<stdio.h>

#define MAX 100
int adj[MAX][MAX];
int sorted[3][MAX];
int mstSet[MAX];
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
		
		sorted[0][i] = src;
		sorted[1][i] = dest;
		sorted[2][i] = wt;
	}
	
	for(int i = 0 ; i < e - 1; i++)
	{
		for(int j = 0 ; j < e - i - 1; j++)
		{
			if(sorted[2][j] > sorted[2][j+1])
			{
				int tmp = sorted[2][j];
				sorted[2][j] = sorted[2][j+1];
				sorted[2][j+1] = tmp;

				tmp = sorted[1][j];
				sorted[1][j] = sorted[1][j+1];
				sorted[1][j+1] = tmp;

				tmp = sorted[0][j];
				sorted[0][j] = sorted[0][j+1];
				sorted[0][j+1] = tmp;
			}
		}
	}
	printf("sorted");
	for(int i = 0 ; i < n ; i++)
		mstSet[i] = parent[i] = 0;
	int x = 0;
	for(int i = 0 ; i < n - 1 ; i++)
	{
		if(mstSet[ sorted[0][x] ] == 0 || mstSet[ sorted[1][x] ] == 0)
		{
			printf("%d\n",sorted[2][x]);
			mstSet[ sorted[0][x] ] = mstSet[ sorted[1][x] ] = 1;
			parent[ sorted[0][x] ] = sorted[1][x];
			
		}
		else
			i--;
		x++;
	}
	for(int i = 0 ; i < n ; i++)
		printf("src - %d , dest - %d ",i , parent[i]);
	return 0;
}
