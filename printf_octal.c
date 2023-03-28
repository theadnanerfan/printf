#include "main.h"

/**
 * print_octal_number - print octal number
 * by theadnanerfan and Nje-t
 * @number: input octal number
 * @len: a pointer to integer
 *Return: void
 */

void print_octal_number(unsigned int number, int *len)
{
if (number > 7)
{
print_octal_number(number / 8, len);
}
*len += putchar(number % 8 + '0');
}
