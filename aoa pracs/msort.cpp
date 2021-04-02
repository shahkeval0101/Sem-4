#include<stdio.h>
void msort(int[],int,int);
void merge(int[],int,int,int);
int main()
{
	int arr[10],n,i;
	printf("Merge sort\n ");
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			printf("Enter the array the element %d\n",i+1);
			scanf("%d",&arr[i]);
		}
		msort(arr,0,n-1);
	printf("The sorted array is \n");
	for(i=0;i<n;i++)
		printf("%d",arr[i]);
	return 0;
}
void msort(int arr[],int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		msort(arr,beg,mid);
		msort(arr,mid+1,mid);
		merge(arr,beg,mid,end);	
	}
	
}
void merge(int arr[],int beg,int mid,int end)
{
	int i=beg,j=mid+1,index=beg,temp[10],k;
	while(i<=mid && j<=end)
	{
		if(arr[i]<arr[j])
		{
			temp[index]=arr[i];
			i++;
		}
		else
		{
			temp[index]=arr[j];
			j++;
		}
		index++;	
	}
	if(i>mid)
	{
		while(j<=end)
		{
			temp[index]=arr[j];
			j++;
			index++;
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index]=arr[i];
			i++;
			index++;
		}
	}
	for(k=beg;k<index;k++)
		arr[k]=temp[k];
}
