#ifndef HEADER_FILE
#define HEADER_FILE

#include <unistd.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

/**
 * buffer - a local buffer of char to minimize write calls
 * @bufferArr - character array buffer
 * @index - an index the previous write of a buffer stops
 *
 */
struct WriteBuffer
{
	char bufferArr[1024];
	int index;
};

int _printf(const char *, ...);
size_t handle_format_specifier(const char *, struct WriteBuffer *, va_list *);
void handle_special_char(const char *, struct WriteBuffer *);
void write_or_buffer(struct WriteBuffer *, char);
size_t write_char(int, size_t *, struct WriteBuffer *);
size_t write_string(char *, size_t *, struct WriteBuffer *);
size_t write_integer(int, size_t *, struct WriteBuffer *);
size_t write_binary(unsigned int, size_t *, struct WriteBuffer *);
size_t write_unsigned(unsigned int, size_t *, struct WriteBuffer *);
size_t write_octal(unsigned int, size_t *, struct WriteBuffer *);
size_t write_Xhex(unsigned int, size_t *, struct WriteBuffer *);
size_t write_xhex(unsigned int, size_t *, struct WriteBuffer *);

#endif
