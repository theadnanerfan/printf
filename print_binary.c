#include "main.h"


/**
 * print_binary - changes unsigned int to binary
 * by theadnanerfan and Nje-t
 * @binary: array of memory
 * @size: size of binary in byte
 * or positive
 * @result: the number in decimal value
 * and positive
 * Return: binary number
 */
int *print_binary(int *binary, unsigned int result, int size)
{
int a;

for (a = 0; a < size; a++)
binary[a] = '0';
binary[a] = '\0';

for (a = size - 1; result > 1; a--)
{
if (result % 2 != 0)
binary[a] = '1';
result /= 2;
}
if (result != 0)
binary[a] = '1';

return (binary);
}
