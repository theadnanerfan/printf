#include "main.h"
/**
 * rev_print - the function returns the reverse string
 *
 * @str: string
 * @len: count len
 *
 * Return: void
 */
void rev_print(char *str, int *len)
{
int i;

i = 0;
while (str[i])
i++;
*len += i;
i--;
while (i >= 0)
{
_putchar(str[i]);
i--;
}
}
