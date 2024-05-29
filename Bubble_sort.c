#include<stdio.h>
int main()
{
	int arr[50],i,j,n,x,flag=0;
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
 printf("\nUnsorted Array: ");
	for(i=0;i<n;i++)
	printf("%d  ",arr[i]);
	for(i=0;i<n-1;i++)
	{
	for(j=0;j<n-i-1;j++)
	{
		if(arr[j]>arr[j+1])
		{
			int temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
	}
}
	printf("\nSorted Array: ");
	for(i=0;i<n;i++)
	printf("%d  ",arr[i]);
	return 0;
}

// Algorithm
// START
//   DECLARE arr as array of size 50
//   DECLARE i, j, n as integer
//   DECLARE temp as integer

//   PRINT "Enter the number of terms: "
//   READ n

//   FOR i from 0 to n-1
//     PRINT "Enter element ", i+1, ": "
//     READ arr[i]

//   PRINT "Unsorted Array: "
//   FOR i from 0 to n-1
//     PRINT arr[i], " "

//   FOR i from 0 to n-2
//     FOR j from 0 to n-i-2
//       IF arr[j] > arr[j+1]
//         temp = arr[j]
//         arr[j] = arr[j+1]
//         arr[j+1] = temp

//   PRINT "Sorted Array: "
//   FOR i from 0 to n-1
//     PRINT arr[i], " "

// END
