 /*
DFS ALGORITHM:-
S  = Stack
St = first node
G  = Graph

DFS(G,St)
	push(St)
	
	while stack is not empty,
		v = pop()
		for all neighbours(w) of v in graph G
			if w is not visited
				push(w)
				mark w as visited
~~~~~~THE END~~~~~~
*/
#include<stdio.h>
#define MAX 100

#define INITIAL 0
#define WAITING 1
#define VISITED 2

int G[MAX][MAX];
int stack[MAX],n,top=-1;
int state[MAX];


void create_graph();
void DFS(int s);
void push(int x);
int pop();
int isEmpty();

int main()
{
	create_graph();
	DFS(0);
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
void push(int x)
{
	if(top == MAX-1)//condition for overflow
		printf("ERROR! Stack Overflow!");
	else
	{
		top++;
		stack[top] = x;
	}
}
int pop()
{
	if(top == -1)//condition for underflow
		printf("ERROR !!! Stack underflow");
	else
	{
		int t = stack[top];
		top--;
		return t;
	}
}
int isEmpty()
{
	if(top == -1)
		return 1;
	else
		return 0;
}
void DFS(int s)
{
	for(int i = 0 ; i < n ; i++)
		state[i] = INITIAL;
		
	state[s]=VISITED;//visiting the source node
	push(s);
	while(!isEmpty())//loop as long as the stack is not empty
	{
		int v = pop();
		state[v]=VISITED;
		printf("%d",v);
		for(int i = 0 ; i < n ; i++)
		{
			//if i is a neighbour of v and it is not visited,
			if(state[i] == INITIAL && G[v][i] == 1)
			{
				push(i);
				state[i]=WAITING;
			}
		}
	}
}
