# printf

This file contains functions that used to print print character, string, \
float, integer, octal and hexadecimal ) onto the output screen.values

The _printf(const char *, ...) functions uses format specifier to display the \
value variables.

* %c is used to display character

* %d for float integer

* %s for string variable

* %u for unsigned and

* %x for hexadecimal variable.

To generate a special characters such as newline,we use "/" \
and character after it.

* alert (beep)	    \a

* backslash	    \\

* backspace	    \b

* carriage return   \r

* double quote	    \"

* formfeed	    \f.

* horizontal tab    \t

* newline    \n

* null character	\0

* single quote		\'

* vertical tab		\v

* question mark		\?

The function uses a buffer of 1024 before calling the write function to \
decrease the expensive system call

# Example

``` c

#include "holberton.h"

/**

 * main - Entry point

 *

 * Return: Always 0

 */

int main(void)

{
char *str;
int i;

str = "printf";
i = 2;
_printf("This is %s project at holberton which is done %d students", str, i);
return (0);

}
