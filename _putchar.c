#include <unistd.h>
/**
 * _putchar - write character to be printed
 * by theadnanerfan and Nje-t
 * @c: The character to print
 *
 * Return: 1 on success
 * On error, -1 is to be returned
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
