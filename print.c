#include "holberton.h"
#include <stdio.h>
/**
 * _printf - the function a user called to print anything
 * @format: foramt specifier or string just like printf
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list  arg;
	int counter = 0;
       	struct WriteBuffer buffer;
	char *p = "(null)";

	va_start(arg, format);
	buffer.index = 0;
	if (format == NULL)
	{
		_printf("%s\n", p);
		return (7);
	}
	while (*format)
	{
		if (*format != '%')
		{
			write_or_buffer(&buffer, *format);
			counter++;
			format++;
			continue;
		}
		counter += handle_format_specifier(format, &buffer, &arg);
		format += 2;
	}
	write(1, buffer.bufferArr, buffer.index);
	return (counter);
}
