#include<stdio.h>
#include<string.h>
char text[100],pattern[10];
int d[100],m,n;

void lps()
{
	int k=-1,q=0,i;
	d[0]=0;
	for(q=1;q<m;q++)
	{
		while(k>-1 && pattern[k+1]!=pattern[q])
		{
			k=d[k];
		}
		if(pattern[k+1]==pattern[q])
		{
			k=k+1;
		}
		d[q]=k;
	}
	printf("The lps table is\n");
	for(i=0;i<m;i++)
	{
		printf("%d",d[i]);
	}
}

void kmp()
{
	int i;
	int k=-1;
	lps();
	for(i=0;i<n;i++)
	{
		while(k>-1 && pattern[k+1]!=text[i])
		{
			k=d[k];	
		}
		if(text[i]==pattern[k+1])
		{
			k++;
		}
		if(k==m-1)
		{
			printf("\n0match found at position %d",(i-k+1));
		}
	}
}

int main()
{
	printf("KMP algorithm\n");
	printf("Enter the string\n");
	scanf("%s",text);
	printf("Enter the pattern\n");
	scanf("%s",pattern);
	n=strlen(text);
	m=strlen(pattern);
	kmp();
	return 0;	
}
