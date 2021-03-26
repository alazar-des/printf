#include "holberton.h"

/**
 * write_char - write or put into buffer a standard character
 * @c: character input
 * @count: counts the number of characters printed
 *
 * Return: the number of characters printed or buffered
 */
size_t write_char(int c, size_t *count, struct WriteBuffer *ptrbuffer)
{
	char ch;

	ch = (char)c;
	write_or_buffer(ptrbuffer, ch);
	(*count)++;
	return(*count);
}

/**
 * write_string - write or put string to standard out or buffer
 * @s: string input
 * @count: counts the number of characters printed
 *
 * Return: the number of characters printed or buffered
 */
size_t write_string(char *s, size_t *count, struct WriteBuffer *ptrbuffer)
{
	char *str;

	str = s;
	if (str == NULL)
		return (*count);
	while (*str != '\0')
	{
		write_or_buffer(ptrbuffer, *str);
		(*count)++;
		str++;
	}
	return (*count);
}

/**
 * write_integer - write or put an integer into to standard out or buffer
 * @n: integer input
 * @count: counts the number of characters printed
 *
 * Return: the number of characters printed or buffered
 */
size_t write_integer(int n, size_t *count, struct WriteBuffer *ptrbuffer)
{
	char c;

	if (n < 0)
	{
		n = -n;
		c = '-';
		write_or_buffer(ptrbuffer, c);
		(*count)++;
	}
	if (n / 10)
		write_integer(n / 10, count, ptrbuffer);
	n %= 10;
	c = n + '0';
	write_or_buffer(ptrbuffer, c);
	return(++(*count));
}

/**
 * write_binary - write or put an integer in a binary format
 * to standard out or buffer
 * @n: integer input
 * @count: counts the number of characters printed
 *
 * Return: the number of characters printed or buffered
 */
size_t write_binary(unsigned int n, size_t *count, struct WriteBuffer *ptrbuffer)
{
	char b;

	if (n / 2)
		write_binary(n / 2, count, ptrbuffer);
	n %= 2;
	b = n + '0';
	write_or_buffer(ptrbuffer, b);
	return(++(*count));
}


/**
 * write_unsigned - write or put an unsigned integer into to standard out
 * or buffer
 * @n: integer input
 * @count: counts the number of characters printed
 *
 * Return: the number of characters printed or buffered
 */
size_t write_unsigned(unsigned int n, size_t *count, struct WriteBuffer *ptrbuffer)
{
	char c;

	if (n / 10)
		write_integer(n / 10, count, ptrbuffer);
	n %= 10;
	c = n + '0';
	write_or_buffer(ptrbuffer, c);
	return(++(*count));
}

/**
 * write_octal - write or put an integer in octal form into to standard out
 * or buffer
 * @n: integer input
 * @count: counts the number of characters printed
 *
 * Return: the number of characters printed or buffered
 */
size_t write_octal(unsigned int n, size_t *count, struct WriteBuffer *ptrbuffer)
{
	char o;

	if (n / 8)
		write_octal(n / 8, count, ptrbuffer);
	n %= 8;
	o = n + '0';
	write_or_buffer(ptrbuffer, o);
	return(++(*count));
}

/**
 * write_integer - write or put an integer in upper case hex
 * to standard out or buffer
 * @n: integer input
 * @count: counts the number of characters printed
 *
 * Return: the number of characters printed or buffered
 */
size_t write_Xhex(unsigned int n, size_t *count, struct WriteBuffer *ptrbuffer)
{
	char h;

	if (n / 16)
		write_Xhex(n / 16, count, ptrbuffer);
	n %= 16;
	switch (n)
	{
	case 10:
		h = 'A';
		break;
	case 11:
		h = 'B';
		break;
	case 12:
		h = 'C';
		break;
	case 13:
		h = 'D';
		break;
	case 14:
		h = 'E';
		break;
	case 15:
		h = 'F';
		break;
	default:
		h = n + '0';
		break;
	}
	write_or_buffer(ptrbuffer, h);
	return(++(*count));
}

/**
 * write_integer - write or put an integer in lower case hex
 * to standard out or buffer
 * @n: integer input
 * @count: counts the number of characters printed
 *
 * Return: the number of characters printed or buffered
 */
size_t write_xhex(unsigned int n, size_t *count, struct WriteBuffer *ptrbuffer)
{
	char h;

	if (n / 16)
		write_xhex(n / 16, count, ptrbuffer);
	n %= 16;
	switch (n)
	{
	case 10:
		h = 'a';
		break;
	case 11:
		h = 'b';
		break;
	case 12:
		h = 'c';
		break;
	case 13:
		h = 'd';
		break;
	case 14:
		h = 'e';
		break;
	case 15:
		h = 'f';
		break;
	default:
		h = n + '0';
		break;
	}
	write_or_buffer(ptrbuffer, h);
	return(++(*count));
}

int write_address(void *add, size_t *count, struct WriteBuffer *ptrbuffer)
{
	char *c;
	int i;

	c = (char *) add;
	for (i = 0; i < 4; i++)
	{
		_printf("\n----------\nwrite_address\n");
		write_or_buffer(ptrbuffer, *c);
		c++;
	}
	(*count) += 7;
	return (*count);
}
