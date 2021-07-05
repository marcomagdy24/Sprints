/*
 * binary_search.h
 *
 *  Created on: Jul 5, 2021
 *      Author: marco
 */

#ifndef BINARY_SEARCH_BINARY_SEARCH_H_
#define BINARY_SEARCH_BINARY_SEARCH_H_

#include <stdio.h>
#include "../types.h"

#define NOT_FOUND -1

#define NOT_SORTED 0
#define SORTED 1

#define bool enum{false, true}

uint8_t binarySearch(uint32_t* arr, uint8_t size, uint32_t number);

#endif /* BINARY_SEARCH_BINARY_SEARCH_H_ */
