#include "main.h"

/**
 * print_unsigned_number - print unsigned number
 * by theadnanerfan and Nje-t
 * @number: unsigned integer to be printed as a digit
 * @len: a pointer to integer
 * Return: void
 */

void print_unsigned_number(unsigned int number, int *len)
{
if (number > 9)
{
print_unsigned_number(number / 10, len);
}
*len += putchar((number % 10) + '0');
}
