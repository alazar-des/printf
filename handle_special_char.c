#include <unistd.h>
#include "holberton.h"

/**
 * handle_special_char - check the character after the \ and if it is special
character write or put it in buffer otherwise compilation error
 * @format: input pointer
 * @ptrbuffer: a pointer to the buffer struct
 *
 */
void handle_special_char(const char *format, struct WriteBuffer *ptrbuffer)
{
	format++;
	switch(*format)
	{
	case 'a':
		write_or_buffer(ptrbuffer, '\a');
		break;
	case 'b':
		write_or_buffer(ptrbuffer, '\b');
		break;
	case 'f':
		write_or_buffer(ptrbuffer, '\f');
		break;
	case 'n':
		write_or_buffer(ptrbuffer, '\n');
		break;
	case 'r':
		write_or_buffer(ptrbuffer, '\r');
		break;
	case 't':
		write_or_buffer(ptrbuffer, '\t');
		break;
	case 'v':
		write_or_buffer(ptrbuffer, '\v');
		break;
	case '\\':
		write_or_buffer(ptrbuffer, '\\');
		break;
	case '%':
		write_or_buffer(ptrbuffer, '%');
		break;
	default:
		write(1, format, 1);
	}
}
