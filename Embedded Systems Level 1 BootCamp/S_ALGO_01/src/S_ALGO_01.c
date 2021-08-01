/*
 ============================================================================
 Name        : S_ALGO_01.c
 Author      : Marco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Binary Search/binary_search.h"

int main(void) {
	uint32_t element, key;
	uint8_t size;
	int result;
	printf("Enter no of elements: ");
	fflush(stdout);
	scanf("%d", &size);
	fflush(stdin);
	printf("Enter a number to search for: ");
	fflush(stdout);
	scanf("%ld", &key);
	fflush(stdin);
	uint32_t arr[size];
	for (uint8_t i = 0; i < size; i++) {
		printf("Enter Element %d: ", i + 1);
		fflush(stdout);
		scanf("%ld", &element);
		fflush(stdin);
		arr[i] = element;
	}
	result = binarySearch(arr, size, key);
	if (result == NOT_FOUND)
		printf("[INFO] %ld is not Found", key);
	else
		printf("[INFO] %ld is first found at index %d in the Sorted array", key, result);
}
