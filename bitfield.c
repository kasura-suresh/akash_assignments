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

