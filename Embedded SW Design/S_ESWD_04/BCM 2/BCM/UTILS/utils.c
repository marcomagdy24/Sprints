/*
* utils.c
*
* Created: 7/20/2021 2:38:04 PM
*  Author: Marco Magdy
*/

/*- INCLUDES
----------------------------------------------*/
#include "utils.h"

/*- LOCAL MACROS
------------------------------------------*/


/*- LOCAL FUNCTIONS
------------------------------------------*/
void reverse(ptr_uint8_t str, uint8_t len)
{
	uint8_t u8_iterator = 0, j = len - 1, temp;
	while (u8_iterator < j) {
		temp = str[u8_iterator];
		str[u8_iterator] = str[j];
		str[j] = temp;
		u8_iterator++;
		j--;
	}
}

/*- APIs IMPLEMENTATION
-----------------------------------*/
/**
* @brief: This function is a dummy delay.
*/
void dummy_delay(void)
{
	for(volatile uint8_t i=0; i<100; i++)
	{
		for(volatile uint8_t j=0; j<32; j++)
		{
			for(volatile uint8_t k=0; k<32; k++)
			{
				
			}
		}
	}
}

/**
* @brief: This function compares if two strings are identical.
*
* @param [in]  str1   -  pointer to the first string.
* @param [in]  str2   -  pointer to the second string.
*
* @return function error state.
*/
uint8_t StringCompare(uint8_t * str1, uint8_t * str2)
{
	uint8_t u8_counter = 0;
	uint8_t u8_isEqual = TRUE;
	
	while(str1[u8_counter] != END_OF_STRING && str1[u8_counter] != NEW_LINE)
	{
		if(str1[u8_counter] != str2[u8_counter])
		{
			u8_isEqual = FALSE;
			u8_counter++;
			break;
		}
		u8_counter++;
	}
	if( str2[u8_counter] != END_OF_STRING )
	{
		u8_isEqual = FALSE;
	}
	return u8_isEqual;
}

/**
* @brief: This function gets string size.
*
* @param [in]  string   -  pointer to the string.
*
* @return function error state.
*/
uint8_t StringLength(uint8_t * string)
{
	uint8_t u8_counter = 0;
	
	while(string[u8_counter] != END_OF_STRING && string[u8_counter] != NEW_LINE)
	{
		u8_counter++;
	}
	
	return u8_counter;
}

// Converts a given integer x to string str[].
// d is the number of digits required in the output.
// If d is more than the number of digits in x,
// then 0s are added at the beginning.
/**
* @brief: This function gets string size.
*
* @param [in]  string   -  pointer to the string.
*
* @return function error state.
*/
uint8_t intToStr(uint32_t x, uint8_t str[], uint32_t d)
{
	
	uint32_t u8_iterator = 0;
	if (x == 0)
	{
		return '0';
	}
	while (x)
	{
		str[u8_iterator++] = (x % 10) + '0';
		x = x / 10;
	}
	
	// If number of digits required is more, then
	// add 0s at the beginning
	while (u8_iterator < d)
	str[u8_iterator++] = '0';
	
	reverse(str, u8_iterator);
	str[u8_iterator] = END_OF_STRING;
	return u8_iterator;
}

void ftos(float32_t n, ptr_uint8_t res, uint8_t afterpoint)
{
	// Extract integer part
	uint32_t ipart = (uint32_t) n;
	
	// Extract floating part
	float32_t fpart = n - (float32_t)ipart;
	
	// convert integer part to string
	uint32_t u32_iterator = intToStr(ipart, res, 0);
	
	// check for display option after point
	if (afterpoint != 0) {
		res[u32_iterator] = '.'; // add dot
		
		// Get the value of fraction part up to given no.
		// of points after dot. The third parameter
		// is needed to handle cases like 233.007
		fpart = fpart * pow(10, afterpoint);
		
		intToStr((uint32_t)fpart, res + u32_iterator + 1, afterpoint);
	}
}

float32_t stof(ptr_uint8_t str)
{
	
	float32_t result= 0.0;
	uint32_t len = StringLength(str);
	uint32_t dotPosition = 0;

	for (uint8_t u8_iterator = 0; u8_iterator < len; u8_iterator++)
	{
		if (str[u8_iterator] == '.')
		{
			dotPosition = len - u8_iterator  - 1;
		}
		else
		{
			result = result * 10.0 + (str[u8_iterator]-'0');
		}
	}

	while (dotPosition--)
	{
		result /= 10.0;
	}

	return result;
	
}