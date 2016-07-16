#include <stdio.h>

size_t getFileSize(char * path)
{
	FILE *file = fopen(path, "r");
	if (file == NULL)
	{
		fprintf(stderr, "File not found: %s\n", path);
		return 0;
	}
	
	fseek(file, 0L, SEEK_END);
	size_t size = ftell(file);
	rewind(file);

	fclose(file);

	return size;
}

size_t readFile(char * path, unsigned char * buffer, size_t size)
{
	FILE *file = fopen(path, "r");
	if (file == NULL)
	{
		fprintf(stderr, "File not found: %s\n", path);
		return 0;
	}
	
	size_t bytesRead = 0;
	bytesRead = fread(buffer, 1, size, file);

	fclose(file);

	return bytesRead;
}

size_t writeFile(char * path, unsigned char * buffer, size_t size)
{
	FILE *file = fopen(path, "w+");

	size_t bytesWritten;
	bytesWritten = fwrite(buffer, 1, size, file);

	fclose(file);

	return bytesWritten;
}
