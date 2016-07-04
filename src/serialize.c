#include <string.h>

#include "serialize.h"

void serialize_int(int value, unsigned char * buffer, int * index)
{
	// Split int into 4 seperate bytes
	buffer[(*index)++] = value >> 24;
	buffer[(*index)++] = value >> 16;
	buffer[(*index)++] = value >> 8;
	buffer[(*index)++] = value;
}

void serialize_char(char value, unsigned char * buffer, int * index)
{
	// Copy single char to buffer
	buffer[(*index)++] = value;
}

void serialize_string(char * value, size_t size, unsigned char * buffer, int * index)
{
	// Copy bytes over, starting at index
	memcpy( &(buffer[(*index)]), value, size);
	// Add number of bytes cpoied to index
	(*index) += (size/sizeof(char));
}
