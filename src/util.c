#include <stdlib.h>
#include <string.h>

#include "util.h"

int Util_parse(char * string, long min, long max)
{
	char * garbage_text;
	long temp = strtol(string, &garbage_text, 10);
	if (temp >= min && temp <= max)
		return temp;
	else
		return min;
}

void Util_strcpy(char * dest, char * string)
{
	if (strlen(string) > strlen(dest))
	{
		strncpy(dest, string, sizeof(dest)-1);
		dest[strlen(dest)] = '\0';
	}
	else
	{
		strcpy(dest, string);
	}
}
