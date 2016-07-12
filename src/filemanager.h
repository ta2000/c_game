#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_

size_t getFileSize(char * path);
size_t readFile(char * path, char * buffer, size_t size);
size_t writeFile(char * path, char * buffer, size_t size);

#endif
