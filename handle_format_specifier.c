#include <unistd.h>
#include <stdarg.h>
#include "holberton.h"

/**
 * handle_format_specifier - check the character after the % and if it is
special character write or put it in buffer otherwise compilation error
 * @format: input pointer
 * @ptrbuffer: a pointer to the buffer struct
 * @arg: pointer to argument variable of the format specifier
 */
size_t handle_format_specifier(const char *format, struct WriteBuffer *ptrbuffer, va_list *arg)
{
	size_t count;

	count = 0;
	format++;
	switch (*format)
	{
	case 'c':
		count = write_char(va_arg(*arg, int), &count, ptrbuffer);
		format++;
		break;
	case 's':
		count = write_string(va_arg(*arg, char *), &count, ptrbuffer);
		format++;
		break;
	case 'd':
		count = write_integer(va_arg(*arg, int), &count, ptrbuffer);
		format++;
		break;
	case 'i':
		count = write_integer(va_arg(*arg, int), &count, ptrbuffer);
		format++;
		break;
	case 'b':
		count = write_binary(va_arg(*arg, int), &count, ptrbuffer);
		format++;
		break;
	case 'u':
		count = write_unsigned(va_arg(*arg, int), &count, ptrbuffer);
		format++;
		break;
	case 'o':
		count = write_octal(va_arg(*arg, int), &count, ptrbuffer);
		format++;
		break;
	case 'x':
		count = write_xhex(va_arg(*arg, int), &count, ptrbuffer);
		format++;
		break;
	case 'X':
		count = write_Xhex(va_arg(*arg, int), &count, ptrbuffer);
		format++;
		break;
	case '%':
		write_or_buffer(ptrbuffer, '%');
		count++;
		format++;
		break;
	default:
		format++;
	}
	return (count);
}
