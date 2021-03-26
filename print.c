#include "holberton.h"

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

	va_start(arg, format);
	buffer.index = 0;
	if (format == NULL)
		return (0);
	while (*format)
	{
		if (*format == '\\')
		{
			handle_special_char(format, &buffer);
			counter++;
			format += 2;
			continue;
			}
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
