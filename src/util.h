#ifndef UTIL_H_
#define UTIL_H_

// Parse number from string using strtol
int Util_parse(char * string, long min, long max);

// Copy one string to another and prevent overflow
void Util_strcpy(char * string, char * dest);

#endif
