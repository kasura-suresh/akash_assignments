/*********************************************************
*
*To Swap the nibble
*Author: Akash Kumar Gupta
*Date: 26/2/2020
*
*********************************************************/

#include <stdio.h>
struct{
	unsigned char a: 8;
}nibble;

int main()
{
    nibble.a='ba';
    printf("%c",nibble.a >>4 | nibble.a <<4);
	return 0;
}

