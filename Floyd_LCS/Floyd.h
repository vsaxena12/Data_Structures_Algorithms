#define FLOYD_H_

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

void printPath(int n,int P[n][n],int q,int r)
{
	if(P[q][r]!=0)
	{
		printPath(n,P,q,P[q][r]);
		printf("V%d ",P[q][r]+1);
		printPath(n,P,P[q][r],r);
	}
}

void floyd(int n, int dist[n][n],int P[n][n])
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(dist[i][j]>dist[i][k]+dist[k][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
					P[i][j]=k;
				}
			}
		}
	}
}