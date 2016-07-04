#ifndef SERIALIZE_H_
#define SERIALIZE_H_

void serialize_int(
	int value,
	unsigned char * buffer,
	int * index
);

void serialize_char(
	char value,
	unsigned char * buffer,
	int * index
);

void serialize_string(
	char * value,
	size_t size,
	unsigned char * buffer,
	int * index
);

void deserialize_int(
	int * value,
	unsigned char * buffer,
	int * index
);

void deserialize_char(
	char * value,
	unsigned char * buffer,
	int * index
);

void deserialize_uchar(
	unsigned char * value,
	unsigned char * buffer,
	int * index
);

void deserialize_string(
	char * value,
	size_t size,
	unsigned char * buffer,
	int * index
);

#endif
