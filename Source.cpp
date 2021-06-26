#include <stdio.h>
#include <conio.h>

/* This function takes last element as pivot, places the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */

int partition(int arr[], int low, int high)
{
	int pivot = arr[high], temp;

	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)				// If current element is smaller than the pivot 
		{
			i++;

			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;

	return (i + 1);
}

// The main function that implements QuickSort.  low --> Starting index, high --> Ending index 

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);				// pi is partitioning index, arr[pi] is now at right place

		quickSort(arr, low, pi - 1);					// Separately sort elements before partition and after partition 
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

int main()
{
	int arr[] = { 10, 80, 30, 90, 40, 50, 70 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	printf(" Sorted array: \n");
	printArray(arr, n);
	_getch();
}