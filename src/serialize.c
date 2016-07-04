#include <stdio.h>
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
	// Add number of bytes copied to index
	(*index) += (size/sizeof(char));
}

void deserialize_int(int * value, unsigned char * buffer, int * index)
{
	// Read int from 4 consecutive bytes
	(*value) |= (int)buffer[(*index)++] << 24;
	(*value) |= (int)buffer[(*index)++] << 16;
	(*value) |= (int)buffer[(*index)++] << 8;
	(*value) |= (int)buffer[(*index)++];
}

void deserialize_char(char * value, unsigned char * buffer, int * index)
{
	// Copy single unsigned char from buffer, cast as char
	(*value) = (char)buffer[(*index)++];
}

void deserialize_uchar(unsigned char * value, unsigned char * buffer, int * index)
{
	// Copy single unsigned char from buffer
	(*value) = buffer[(*index)++];
}

void deserialize_string(char * value, size_t size, unsigned char * buffer, int * index)
{
	// Copy bytes over, starting at index
	memcpy( value, &(buffer[(*index)]), size);
	// Add number of bytes copied to index
	(*index) += (size/sizeof(char));
}
