# DAA
#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n,i,j,lar,key;
	printf("Enter the number of elements in the array:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("Enter the element to be deleted:");
	scanf("%d",&key);
	
	for(i=0;i<n;i++)
	{
		if(arr[i]==key)
		{
			arr[i]=0;
		}
	}
	lar=key;
	for(i=1;i<n;i++)
	{
		if(arr[i]>lar)
		{
			lar=arr[i];
		}
	}
	for(i=0;i<n;i++)
	{
		if(arr[i]>key)
		{
			if(arr[i]<=lar)
			{
				lar=arr[i];
			}
		}
	}
	printf("Element returned is:%d",lar);

	
}
			

