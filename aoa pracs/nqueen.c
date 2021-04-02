#include<stdio.h>
#include<math.h>
//#include<string.h>
int x[10];

int place(int k,int i)
{
	//printf("IN place\n");
	int j;
	for(j=1;j<=k-1;j++)
	{
		if(x[j]=i || abs(x[j]-i)==abs(j-k))
			return 0;
	}
	return 1;
	
}

void nqueen(int k,int n)
{
	//printf("in nqueen\n");
	int i;
	for(i=1;i<=n;i++)
	{
		if(place(k,i))
		{
			x[k]=i;
			//printf("%d %d\n",x[k],i);
			if(k==n)
			{
				for(i=1;i<=n;i++)
					printf("%d\t",x[i]);
				printf("\n");
			}
			else
			{
				nqueen(k+1,n);
			}
		}
		
	}
}
int main()
{
	int k=1,n;
	printf("Enter the number of queen\n");
	scanf("%d",&n);
	nqueen(k,n);
	return 0;
		 
}
