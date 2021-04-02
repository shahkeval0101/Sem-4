#include<stdio.h>
int cost[10][10],a[10][10];

void apsp(n)
{
	 a[n][n];
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=cost[i][j];
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				{
					if(a[i][j]>a[i][k]+a[k][j])
						a[i][j]=a[i][k]+a[k][j];
				}
	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d",a[i][j]);
		printf("\n");
	}
}

int main()
{
	int n,i,j;
	printf("enter the size adjacency matrix\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&cost[i][j]);
	apsp(n);
}
