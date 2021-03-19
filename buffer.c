#include <unistd.h>
#include "holberton.h"

/**
 * write_or_buffer - write a character to standatd output or put it in buffer
 * @ptrbuffer: a pointer to the buffer struct
 * @c: a character to be writen
 *
 */
void write_or_buffer(struct WriteBuffer *ptrbuffer, char c)
{
	if (ptrbuffer->index == BUFFER_SIZE - 1)
	{
		write(1, ptrbuffer->bufferArr, BUFFER_SIZE);
		ptrbuffer->index = 0;
	}
	ptrbuffer->bufferArr[ptrbuffer->index] = c;
	ptrbuffer->index++;
}
