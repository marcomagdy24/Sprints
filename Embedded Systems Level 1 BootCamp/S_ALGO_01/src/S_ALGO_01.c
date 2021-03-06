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
//	uint32_t x[] = { 29, 10, 14, 37, 14, 20, 50, 12 };
//	uint8_t n = sizeof(x) / sizeof(x[0]);
//	sint8_t result = binarySearch(x, n, 12);
//	uint32_t y[] = { 29, 10, 14, 37, 14, 11, 12, 50 };
//	n = sizeof(y) / sizeof(y[0]);
//	result = binarySearch(y, n, 12);
//	uint32_t z[] = { 10, 13, 14, 15, 20, 25, 30 };
//	n = sizeof(z) / sizeof(z[0]);
//	result = binarySearch(z, n, 12);
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
		printf("[INFO] %ld is first found at index %d", key, result);
}
