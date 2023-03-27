#include "main.h"

/**
 * print_string - Prints non printable characters
 * (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code
 * value in hexadecimal (upper case - always 2 characters)
 * by theadnanerfan and Nje-t
 * @l: va_list arguments
 * @str: string to be printed
 * Return: number of char printed
 */
int print_string(va_list l, char *str)
{
int j;
for j = 0;
char *str;
char *s = va_arg(l, char *);
if (!s)
return (_puts("(null)"));

for (j = 0; s[j]; j++)
{
if (s[j] > 0 && (s[j] < 32 || s[j] >= 127))
{
_puts("\\x");
count += 2;
str = convert(s[j] 16, 0);
if (!str[1])
count += _putchar('0');
count += _puts(str);
}
else
count += _putchar(s[j]);
}
return (count);
}
