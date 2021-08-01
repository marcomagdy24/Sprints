/*
 * utils.c
 *
 * Created: 7/20/2021 2:38:04 PM
 *  Author: Mohamed Wagdy
 */ 

/*- INCLUDES
----------------------------------------------*/
#include "utils.h"

/*- LOCAL MACROS
------------------------------------------*/
#define TRUE                  (uint8_t)(1)
#define FALSE                 (uint8_t)(0)

/*- APIs IMPLEMENTATION
-----------------------------------*/
/**
* @brief: This function is a dummy delay.
*/
void dummy_delay(void)
{
   for(volatile uint8_t u8_iterator=0; u8_iterator<100; u8_iterator++)
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
   
   while((str1[u8_counter] != END_OF_STRING) && (str1[u8_counter] != NEW_LINE))
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

/**
* @brief: This function reverse string.
*
* @param [in]  string   -  pointer to the string.
* @param [in]  int	   -  string length.
*
* @return function error state.
*/
// void reverse(ptr_uint8_t str, uint8_t u8_len)
// {
// 	uint8_t u8_iterator = 0, u8_stringEnd = u8_len - 1, u8_temp;
// 	
// 	while (u8_iterator < u8_stringEnd) {
// 		u8_temp = str[u8_iterator];
// 		str[u8_iterator] = str[u8_stringEnd];
// 		str[u8_stringEnd] = u8_temp;
// 		u8_iterator++;
// 		u8_stringEnd--;
// 	}
// }
// 
// 
// /**
// * @brief: This function converts integer to string.
// * u8_digitNumbers is the number of digits required in the output.
// * If u8_digitNumbers is more than the number of digits in u8_number,
// * then 0s are added at the beginning.
// *
// * @param [in]  int	   -  number that converts to string
// * @param [in]  str	   -  pointer of string required to convert in
// * @param [in]  int	   -  digit numbers after point
// *
// * @return function error state.
// */
// uint8_t intToStr(uint32_t u32_number, ptr_uint8_t str, uint32_t u32_digitNumbers)
// {
// 	uint32_t u32_iterator = 0;
// 	while (u32_number) {
// 		str[u32_iterator++] = (u32_number % 10) + '0';
// 		u32_number = u32_number / 10;
// 	}
// 	
// 	// If number of digits required is more, then
// 	// add 0s at the beginning
// 	while (u32_iterator < u32_digitNumbers)
// 	str[u32_iterator++] = '0';
// 	
// 	reverse(str, u32_iterator);
// 	str[u32_iterator] = END_OF_STRING;
// 	return u32_iterator;
// }
// 
// /**
// * @brief: This function converts float to string.
// *
// * @param [in]  float	   -  number that converts to string
// * @param [in]  str	   -  pointer of string required to convert in
// * @param [in]  int	   -  digit numbers after point
// *
// * @return function error state.
// */
// void ftos(ufloat32_t f32_number, ptr_uint8_t pu8_res, uint8_t u8_afterpoint)
// {
// 	// Extract integer part
// 	uint32_t ipart = (uint32_t) f32_number;
// 	
// 	// Extract floating part
// 	ufloat32_t fpart = f32_number - (ufloat32_t)ipart;
// 	
// 	// convert integer part to string
// 	uint32_t u8_iterator = intToStr(ipart, pu8_res, 0);
// 	
// 	// check for display option after point
// 	if (u8_afterpoint != 0) 
// 	{
// 		pu8_res[u8_iterator] = '.'; // add dot
// 		
// 		// Get the value of fraction part up to given no.
// 		// of points after dot. The third parameter
// 		// is needed to handle cases like 233.007
// 		fpart = fpart * pow(10, u8_afterpoint);
// 		
// 		intToStr((uint32_t)fpart, pu8_res + u8_iterator + 1, u8_afterpoint);
// 	}
// }
// 
// /**
// * @brief: This function converts string to float.
// *
// * @param [in]  str	   -  pointer of string required to convert in
// *
// * @return float number.
// */
// ufloat32_t stof(ptr_uint8_t ptr_str)
// {
// 	ufloat32_t result= 0.0;
// 	uint32_t u32_len = StringLength(ptr_str);
// 	uint32_t u32_dotPosition = 0;
// 
// 	for (int u8_iterator = 0; u8_iterator < u32_len; u8_iterator++)
// 	{
// 		if (ptr_str[u8_iterator] == '.')
// 		{
// 			u32_dotPosition = u32_len - u8_iterator  - 1;
// 		}
// 		else
// 		{
// 			result = result * 10.0 + (ptr_str[u8_iterator]-'0');
// 		}
// 	}
// 
// 	while (u32_dotPosition--)
// 	{
// 		result /= 10.0;
// 	}
// 
// 	return result;
// }