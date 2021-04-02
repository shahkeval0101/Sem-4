#include<stdio.h>
void main()
{
	int b[10],bno,pno,p[10],a[10],f[10],i,j;
	for(i=0;i<10;i++)
	{
		f[i]=0;
		a[i]=-1;
	}
	printf("Enter the no of the block\n");
	scanf("%d",&bno);
	printf("Enter the blocks\n");
	for(i=0;i<bno;i++)
	{
		scanf("%d",&b[i]);
	}
	printf("Enter the no of the processses\n");
	scanf("%d",&pno);
	printf("Enter the processes\n");
	for (i=0;i<pno;i++)
	{
		scanf("%d",&p[i]);
	}
	for(i=0;i<pno;i++)
	 for(j=0;j<bno;j++)
	  if(f[j]==0 && b[j]>=p[i])
	   {
	   	a[j]=1;
	   	f[j]=1;
	   	break;
	   }
	printf("block no\t size \t process \tsize");
	for(i=0;i<bno;i++)
	 if(f[i]==1)
	 printf("\n%d",a[i]);
}
