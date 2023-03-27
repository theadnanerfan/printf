#include "main.h"

/**
 * printf_rev - Prints function in reverse
 * by theadnanerfan and Nje-t
 * @list: it is allocated printf arguments
 *
 * Return: the reverse string
 */
int printf_rev(va_list list)
{

char *str;
char *rev;
int j;
int k = 0;

if (s == NULL)
s = "(null)";
while (s[k] != '\0')
k++;
for (j = k - 1; j >= 0; j--)
_putchar(s[j]);
return (j);
}
