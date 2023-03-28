#include "main.h"
#include <unistd.h>

/**
 * _putchar_buff - uses a local buffer of 1024 to write
 * by theadnanerfan and Nje-t
 * @c: character to print
 * Return: 1 on success. else return -1
 */

int _putchar_buff(char c)
{
/* static variables retain their values between function calls*/

static char buff[1024];
static int i;

if (c == -1 || i >= 1024)
{
write(1, &buff, i); /* writes the contents of buffer */
i = 0; /* resets the counter i to 0.*/
}
if (c != -1)
{
buff[i] = c;
i++;
}
return (1);
}
