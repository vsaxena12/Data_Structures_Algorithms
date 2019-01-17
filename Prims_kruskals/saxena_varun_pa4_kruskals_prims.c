#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

// Maximum number of vertex for the random graph.
typedef struct edge
{
	int vertex1;
	int vertex2;
}Edge;

int infinity = 999;
int max1 = 10;

int set[10], height[10];
int min,min1,mincost=0,mincost1=0,parent[10],visited[10],cost[10],queue[10];
int front=0;
int rear=-1;

int find3(int x)
{
	int root=x;
	while(root!=set[root])
	{
		root=set[root];
	}
	return root;
}

void union3(int repx,int repy)
{
	if(height[repx]==height[repy])
	{
		height[repx]++;
		set[repy]=repx;
	}
	else if(height[repx]>height[repy])
	{
		set[repy]=repx;
	}
	else
	{
		set[repx]=repy;
	}
}

void merge(int x,int y)
{
	int repx=find3(x);
	int repy=find3(y);
	if(repx!=repy)
	{
		union3(repx,repy);
	}
}

int weight(Edge e, int A[SIZE][SIZE])
{
	return A[e.vertex1][e.vertex2];
}

void sort(Edge arr[],int edge_count,int A[SIZE][SIZE])
{
	int i, j;
	for(i = 0; i < edge_count-1; i++)      
		for(j = 0; j < edge_count-i-1; j++)
			if(weight(arr[j],A) > weight(arr[j+1],A))
			{
				Edge temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
}

void push(int element)
{
	if(rear==9)
	{
		printf("Queue full, cannot push\n");
	}
	else
	{
		rear++;
		queue[rear]=element;
	}
}

int pop()
{
	if(rear<front)
	{
		printf("Queue empty, cannot pop\n");
		return -1;
	}
	int i;
	int min=999;		//some very large number
	int min_vertex=-1;
	int queue_pos=-1;
	for(i=front;i<=rear;i++)
	{
		if(cost[queue[i]]<min)
		{
			min=cost[queue[i]];
			min_vertex=queue[i];
			queue_pos=i;
		}
	}

	for(i=queue_pos+1;i<=rear;i++)
	{
		queue[i-1]=queue[i];
	}
	rear--;
	return min_vertex;
}

int queue_size()
{
	return rear-front+1;
}


void prims(int A[SIZE][SIZE],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
		cost[i]=infinity;
		parent[i]=-1;	//-1 indicates null
	}
	int initial_node=0;
	cost[initial_node]=0;

	for(i=0;i<n;i++)
	{
		push(i);
	}

	printf("n=%d\n",n);
	while(queue_size()!=0)
	{
		int node=pop();
		visited[node]=1;
		for(j=0;j<n;j++)
		{
			if(visited[j]==0)
			{
				if(cost[j]>A[node][j])
				{
					cost[j]=A[node][j];
					parent[j]=node;
				}
			}
		}
	}
	printf("Printing edges in MST generated using Prim's algorithm\n");
	int weight_total=0;
	for(i=0;i<n;i++)
	{
		if(parent[i]!=-1)
		{
			printf("Edges between %d and %d: weight= %d\n",i+1,parent[i]+1, A[i][parent[i]]);
			weight_total+=A[i][parent[i]];
		}
	}

	printf("Total weight of MST: %d\n",weight_total);


}

void kruskal(int A[SIZE][SIZE],int n)
{
	int i,j;

	int edge_count=(n*(n-1))/2;			//max number of edges in a graph
	Edge edge_list[edge_count];
	int ctr=0;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i<j)
			{
				edge_list[ctr].vertex1=i;
				edge_list[ctr].vertex2=j;
				ctr++;
			}
		}
	}

	sort(edge_list,edge_count,A);

	Edge result[n-1];
	int result_len=0;

	for(i=0;i<n;i++)	//For each v∈V create a set.
	{
		set[i]=i;
		height[i]=0;
	}

	int shortest_edge_index=0;
	while(result_len<n-1)
	{
		Edge shortest_edge=edge_list[shortest_edge_index++];
		int u=shortest_edge.vertex1;
		int v=shortest_edge.vertex2;
		int ucomp=find3(u);
		int vcomp=find3(v);

		if(ucomp!=vcomp)
		{
			result[result_len]=shortest_edge;
			result_len++;
			union3(ucomp,vcomp);

		}
	}
	printf("Printing edges in MST generated using Kruskal's algorithm\n\n");
	int weight_total=0;
	for(i=0;i<result_len;i++)
	{
		printf("Edges between %d and %d: weight= %d\n",result[i].vertex1+1,result[i].vertex2+1, A[result[i].vertex1][result[i].vertex2]);
		weight_total+=A[result[i].vertex1][result[i].vertex2];
	}

	printf("Total weight of MST: %d\n",weight_total);


}




int main()
{
//Graph
	srand(time(NULL));
	int A[SIZE][SIZE];
	int n = (5 + rand() % 6);
	printf("Number of Vertices: %d\n", n);
	int n1=n;
	int i=0;
	int j=0;
/*
int z=1+(int) (10.0*rand()/(RAND_MAX+1.0));
*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				A[i][j]=0;
			}
			else{
				int random_weight=rand()%10+1;
				A[i][j]=random_weight;
				A[j][i]=random_weight;
				
			}
		}
	}

	for(i=0;i<n; i++)
  	{
    	for(j=0;j<n;j++)
    	{
          printf("%d\t", A[i][j]);     
    	}
    	printf("\n");
    	
  	}


	printf("\n");
	printf("1.Implement Prims minimum spanning tree algorithm\n2.Implement kruskals minimum spanning tree algorithm-> \n");
	printf("\nEnter Your choice?: ");
	int choice;
	scanf("%d",&choice);
	if(choice == 1)
	{
		printf("Using Prims Algorithm\n");
		prims(A,n); //For Prims
	}

	else if(choice == 2)
	{
		printf("Using kruskal\n");
		kruskal(A,n1); //For Kruskals
	}

	else
	{
		printf("Select the proper Greedy Algorithm\n");
	}
	
	return 0;
}
