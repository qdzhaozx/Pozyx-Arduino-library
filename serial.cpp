#include <stdio.h>
#include "serial.h"

void SerialClass::begin(int baud)
{
	//set uart buad output
}

void SerialClass::print(const char *str)
{
	printf("%s",str);
}
void SerialClass::print(int d, int dec)
{
	if (dec) 
		printf("%d", d);
	else 
		printf("%x", d);
}

void SerialClass::println(const char *str)
{
	if (!str) 
		printf("\n");
	else 
		printf("%s\n",str);
}
void SerialClass::println(int d, int dec)
{
	if (dec) 
		printf("%d\n", d);
	else 
		printf("%x\n", d);
}

SerialClass Serial;
