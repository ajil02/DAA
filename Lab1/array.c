# DAA			
#include<stdio.h>
#include<stdlib.h>
//#include<time.h>
void main()
{
	int i,n,key,del,max;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int arr[n];
	//srand(time(0));
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]=rand()%100);
	}
	printf("\nEnter the position to be deleted:");
	scanf("%d",&key);
	del=arr[key];
	for(i=key;i<n;i++)
	{
		arr[i]=arr[i+1];
	}
	for(i=0;i<n;i++)
	{
		if(arr[i]>del)
		{
			max=arr[i];
		}
	}
	for(i=0;i<n;i++)
	{
		if(arr[i]>del)
		{
			if(arr[i]<max)
			{
				max=arr[i];
			}
		}
	}
	for(i=0;i<n-1;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nNext element:%d",max);
}

