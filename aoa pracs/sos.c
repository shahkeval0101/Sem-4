#include<stdio.h>
int i,x[10],w[10],m,n;
 
void sos(int s, int k , int r)
{
	
	x[k]=1;
	if(s+w[k]==m)
	{
		for(i=0;i<n;i++)
			if(x[i]==1)
				printf("%d\t",w[i]);
		
	}
	

	else if(s+w[k]+w[k+1]<=m)
		sos(s+w[k],k+1,r-w[k]);
	if(s+r-w[k]>=m && s+w[k+1]<=m)
	{
		x[k]=0;
		sos(s,k+1,r-w[k]);
	}

}
int main()
{
	int s=0,r=0,k=0;
	printf("Enter the no of the element\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&w[i]);
		r+=w[i];
	}
	printf("Enter the max sum\n");
	scanf("%d",&m);
	sos(s,k,r);
	return 0;
}
