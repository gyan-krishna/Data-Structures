/*
BFS ALGORITHM
G- graph
S- start node
Q- queue
BFS(G,S)
	q.enqueue(s)
	mark s as visited
	
	while (q is not empty)  
		v = q.dequeue -- REMOVING VERTEX FROM Q THAT WILL BE VISITED NOW
		for all neighbours(w) of v in graph G,
			if w is not visited,
				enqueue w
				mark w as visited
~~~~THE END~~~~
*/

/*
PROGRAM NOTES,
> Adjecency matrix
> directed graph
*/


#include<stdio.h>
#define MAX 100     //max no of nodes

//states of the nodes
#define INITIAL     0
#define WAITING     1
#define VISITED     2

int n;				//number of nodes
int G[MAX][MAX];	//adjecency matrix for Graph
int state[MAX];		//visited state

int queue[MAX];		//queue for bfs
int front = -1;		//front of queue
int back  = -1;		//back of queue

void create_graph();
void BFS(int v);

void enqueue(int x);
int dequeue();
int queueEmpty();

int main()
{
	create_graph();
	BFS(0);
}
void create_graph()
{
	int v1,v2;
	printf("enter number of vertices");
	scanf("%d",&n);
	
	int max_edge = n*(n-1);		//maximum possible edges in a graph with n nodes
	printf("enter the edges [-1,-1] to stop\n");
	for(int i = 0 ; i < max_edge ; i++)//accepting the data
	{
		printf("enter edge no %d in format [v1,v2] ::",i);
		scanf("%d%d",&v1,&v2);
		
		if(v1 == -1 && v2 == -1)//stop taking input
			break;
		else if(v1 >= 0 && v1 < n && v2 >= 0 && v2 < n)//checking for validity of input
			G[v1][v2] = 1;
		else//invalid edge entry
		{
			printf("invalid entry! enter again!\n");
			i--;
			continue;
		}
	}
}
//-------------------------------------------------BREADTH FIRST SEARCH-------------------------------------
void BFS(int s)
{
	for(int i = 0 ; i < n ; i++)
		state[i] = INITIAL;
	
	enqueue(s);	//visiting the source node
	state[s] = WAITING;
	
	while( !queueEmpty() ) //loop as long as q is not empty
	{
		int v = dequeue();
		printf("%d -> ",v);
		state[v] = VISITED;
		
		for(int i = 0 ; i < n ; i++)
		{
			//if i is a neighbour of v and it is not visited,
			if(G[v][i] == 1 && state[i] == INITIAL)
			{
				enqueue(i);
				state[i] = WAITING;
			}
		}
	}
	printf("END\n");
}
//-------------------------------------------------QUEUE FUNCTIONS----------------------------------------
void enqueue(int x)
{
	if(back == n-1)//queue overflow 
	{
		printf("ERROR queue overflow!!");
		return;
	}
	else if(front == -1 && back == -1)//empty queue
	{
		front = back = 0;
		queue[front] = x;
	}
	else
	{
		back++;
		queue[back] = x;
	}
}
int dequeue()
{
	if(front == -1 && back == -1)//queue underflow
	{
		printf("ERROR queue Underflow!");
		return -1;
	}
	else if(front == back)//last element
	{
		int t = front;
		front = back = -1;
		return queue[t];
	}
	else
	{
		int t = front;
		front++;
		return queue[t];
	}
}
int queueEmpty()
{
	if(front == -1 && back == -1)
		return 1;
	else
		return 0;
}
/*
//-------------------------------------------------SAMPLE OUTPUT----------------------------------------

enter number of vertices9
enter the edges [-1,-1] to stop
enter edge no 0 in format [v1,v2] ::0 1
enter edge no 1 in format [v1,v2] ::0 3
enter edge no 2 in format [v1,v2] ::0 4
enter edge no 3 in format [v1,v2] ::1 2
enter edge no 4 in format [v1,v2] ::3 6
enter edge no 5 in format [v1,v2] ::4 7
enter edge no 6 in format [v1,v2] ::6 7
enter edge no 7 in format [v1,v2] ::6 7
enter edge no 8 in format [v1,v2] ::2 5
enter edge no 9 in format [v1,v2] ::4 5
enter edge no 10 in format [v1,v2] ::7 5
enter edge no 11 in format [v1,v2] ::7 8
enter edge no 12 in format [v1,v2] ::-1 -1

0 -> 1 -> 3 -> 4 -> 2 -> 6 -> 5 -> 7 -> 8 -> END

enter number of vertices7
enter the edges [-1,-1] to stop
enter edge no 0 in format [v1,v2] ::0 1
enter edge no 1 in format [v1,v2] ::1 3
enter edge no 2 in format [v1,v2] ::1 4
enter edge no 3 in format [v1,v2] ::3 4
enter edge no 4 in format [v1,v2] ::4 2
enter edge no 5 in format [v1,v2] ::0 2
enter edge no 6 in format [v1,v2] ::2 6
enter edge no 7 in format [v1,v2] ::2 5
enter edge no 8 in format [v1,v2] ::-1 -1
0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> END
*/

