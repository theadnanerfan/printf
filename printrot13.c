#include "main.h"
/**
 * rot - function crypt string
 *
 * @str: str
 * @len: lenght string
 *
 * Return: void
 */
void rot(char *str, int *len)
{
int i;
int j;

char rot13[] = "ABCDEFGHIJKLMabcdefghijklmNOPQRSTUVWXYZnopqrstuvwxyz";
char rot13ed[] = "NOPQRSTUVWXYZnopqrstuvwxyzABCDEFGHIJKLMabcdefghijklm";
for (i = 0; str[i]; i++)
{
for (j = 0; j < 52; j++)
{
if (str[i] == rot13[j])
{
str[i] = rot13ed[j];
break;
}
}
}
*len += puts(str);
}
