#include<stdio.h>
void prims(int);
int minimum(int);
int cost[10][10],n;
int main()
{
	int i,j,k;
	printf("Prims algo\n");
	printf("Enter the size of the adjacency matrix\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			printf("Enter the element %d,%d  ",i+1,j+1);
			scanf("%d",&cost[i][j]);
		}
	printf("Enter the root the matrix\n");
	scanf("%d",&k);
		prims(k);		
	return 0;
}

void prims(int k)
{
	int near[n],t[n-1][2],i,j,mincost=0,l,temp;
	l=minimum(k);
	mincost=cost[k][l];
	t[0][0]=k;
	t[0][1]=l;
	for(i=0;i<n;i++)
	{
		if(cost[k][i]>cost[l][i])
			near[i]=l;
		else
			near[i]=k;
	}
	near[k]=-1,near[l]=-1;
	for(i=1;i<=n-2;i++)
	{
		int min=99;
		for(j=0;j<n;j++)
		{
			if (near[j]!=-1 && min>cost[j][near[j]])
			{
				temp=j;
				min=cost[j][near[j]];
			}
		}
		mincost+=min;
		t[i][0]=temp,t[i][1]=near[temp];
		near[temp]=-1;
		
	for(j=0;j<n;j++)
	{
		if(near[j]!=-1 && cost[j][near[j]]>cost[j][temp])
			near[j]=temp;
	}
	}
	for(i=0;i<n-1;i++)
		printf("%d-%d\n",t[i][0],t[i][1]);
	printf("The value the minimum spanning tree is %d\n",mincost);
	
	
}

int minimum(int k)
{
	int min=99,i,l;
	for(i=0;i<n;i++)
	if(min>cost[k][i])
	{
		min=cost[k][i];
		l=i;
	}
	return l;
}
