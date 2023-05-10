#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int i,j,temp;

void disp(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void bubble(int arr[],int n)
{
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}

}
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}	

int partition(int arr[], int low, int high)
{
	int pivot=arr[high];
	int i=low,j;
	
	for(j=low;j<high;j++)
	{
		if(arr[j]<pivot)
		{
			swap(&arr[i],&arr[j]);
			i++;
		}
	}
	swap(&arr[i],&arr[high]);
	return i;
}

void quicksort(int arr[], int low, int high)
{
	if(low<high)
	{
		int pindex=partition(arr,low,high);
		quicksort(arr,low,pindex-1);
		quicksort(arr,pindex+1,high);
	}
}

void main()
{
	//srand(time(NULL));  
	FILE *f ;
	f = fopen("sort.dat", "a+");

	clock_t start_t, end_t;

	double t1,t2;

	//int r = rand();
	int n,k,num;
	printf("Enter number of elements: ");
	scanf("%d",&n);	
	int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		num=rand()%10000;
		a[i]=num;
		b[i]=num;
	}
	disp(a,n);
	start_t=clock();
	bubble(a,n);
	end_t=clock();
	t1 = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("\nThe sorted elements are :");
	disp(a,n);
	printf("Time taken for Bubble sort: %f\n",t1);

	
	start_t=clock();
	quicksort(b,0,n-1);
	end_t=clock();
	t2 = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("\nThe sorted elements are :");
	disp(b,n);
	printf("Time taken for Quick sort: %f\n",t2);
	
	fprintf(f,"%d %f %f \n",n, t1, t2);
}




