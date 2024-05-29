#include <stdio.h> 
#include<limits.h>
void swap(int* a, int* b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 
 
int partition(int arr[], int low, int high) 
{ 
	int pivot = arr[low]; 
	int i = low; 
	int j = high; 

	while (i < j) { 
		while (arr[i] <= pivot && i <= high - 1) { 
			i++; 
		} 
		while (arr[j] > pivot && j >= low + 1) { 
			j--; 
		} 
		if (i < j) { 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[low], &arr[j]); 
	return j; 
} 
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) { 
		int partitionIndex = partition(arr, low, high); 
		quickSort(arr, low, partitionIndex - 1); 
		quickSort(arr, partitionIndex + 1, high); 
	} 
} 
int main() 
{ 
	int arr[] = { 19, 17, 15, 12, 16, 18, 11, 13 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printf("Original array: "); 
	for (int i = 0; i < n; i++) { 
		printf("%d ", arr[i]); 
	} 
	quickSort(arr, 0, n - 1); 

	printf("\nSorted array: "); 
	for (int i = 0; i < n; i++) { 
		printf("%d ", arr[i]); 
	} 

	return 0; 
}
// Algorithm
// function quickSort(array, low, high)
//     if low < high
//         pivotIndex = partition(array, low, high)
//         quickSort(array, low, pivotIndex - 1)
//         quickSort(array, pivotIndex + 1, high)

// function partition(array, low, high)
//     pivot = array[high]
//     i = low - 1
//     for j = low to high - 1
//         if array[j] < pivot
//             i = i + 1
//             swap array[i] with array[j]
//     swap array[i + 1] with array[high]
//     return i + 1
