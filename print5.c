#include "main.h"

/**
 * print_string - non printable characters (0 < ASCII value < 32 or >= 127)
 * printed : /x followed by ASCII code in hexa (upper case, always 2 char)
 * @str: string to be printed
 * @len: length
 * Return: void
 */

void print_string(char *str, int *len)
{
int i;

for (i = 0; str[i]; i++)
{
if (str[i] < 32 || str[i] >= 127)
{
*len += _putchar('\\');
*len += _putchar('x');
*len += _putchar((str[i] / 16) < 10 ?
(str[i] / 16) + '0' : (str[i] / 16) - 10 + 'A');
*len += _putchar((str[i] % 16) < 10 ?
(str[i] % 16) + '0' : (str[i] % 16) - 10 + 'A');
}
else
{
*len += _putchar(str[i]);
}
}
}
