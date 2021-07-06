/*
 * binary_search.c
 *
 *  Created on: Jul 5, 2021
 *      Author: Marco
 */

#include "binary_search.h"

void swap(uint32_t *smaller, uint32_t *bigger) {
	int temp = *smaller;
	*smaller = *bigger;
	*bigger = temp;
}

void bubbleSort(uint32_t* arr, uint8_t size) {
	uint8_t i, j;
	for (i = 0; i < size - 1; i++)
		// Last i elements are already in place
		for (j = 0; j < size - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

int isSorted(uint32_t* arr, uint8_t size) {
	sint8_t isSorted = -1;
	for (uint8_t i = 0; i < size - 1; i++) {
		if (arr[i] < arr[i + 1])
			isSorted = SORTED;
		else{
			isSorted = NOT_SORTED;
			break;
		}
		printf("[DEBUG] Element is %ld\n", arr[i]);
		printf("[DEBUG] isSorted = %d\n", isSorted);
	}
	return isSorted;
}

void printArray(uint32_t* arr, uint8_t size) {
	uint8_t i;
	for (i = 0; i < size; i++)
		printf("%ld ", arr[i]);
	printf("\n");
}

uint32_t* initializeSearch(uint32_t* arr, uint8_t size) {
	printf("[INFO] Array Inserted: ");
	printArray(arr, size);
	uint8_t checkArray = isSorted(arr, size);
	if (!checkArray) {
		bubbleSort(arr, size);
		printf("[INFO] Array is unsorted\n");
		printf("[INFO] Sorted Array: ");
		printArray(arr, size);
	} else
		printf("[INFO] Array is sorted\n");
	return arr;
}

uint8_t binarySearch(uint32_t* arr, uint8_t size, uint32_t number) {
	sint8_t index = NOT_FOUND;
	uint8_t start = 0, end = size - 1;
	uint8_t mid = (start + end) / 2;
	arr = initializeSearch(arr, size);

	while (start <= end) {
		if (arr[mid] < number)
			start = mid + 1;
		else if (arr[mid] == number) {
			index = mid;
			break;
		} else
			end = mid - 1;
		mid = (start + end) / 2;
	}

	return index;

}
