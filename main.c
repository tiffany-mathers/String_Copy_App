
/* 
 * File:   copyStringFixed.cpp
 * Author: Tiffany Mathers
 * Class: SDEV 325
 * Purpose: Fixes CWE-676 : Use of potentially dangerous function
 * Created on November 25, 2016, 2:20 PM
 */

//headers
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

int main (void)
{
    // declare variables
    char strA[50];
    char strB[50];
   
    // display welcome message, request user input
    printf("********** Welcome to the copy station! **********");
    printf("\nPlease enter a string you want copied: \n");
    fgets(strA,50,stdin);

    // confirm that strB has no assigned value
    printf("\nBefore copy, strB is = %s\n", strB);
    
    // copy value from strA to strB.
    // snprintf() limits a maximum buffer capacity to fill, and
    // mitigates buffer overflow
    snprintf(strB, sizeof(strA)+1, strA);
    
    //memcpy(strB, strA, strlen(strA)+1); - incorrect code, could lead to buffer overflow
    
    // display value of strB
    printf("size of strA is %d", sizeof(strA));
    printf("\nsize of strB is %d", sizeof(strB));
    printf("\nAfter copy, strB = %s\n", strB);
   
    printf("The copy was a success!");
}