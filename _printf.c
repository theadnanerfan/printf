#include "main.h"

void print_buffer(char buffer[], int *indexBuff);

/**
 * _printf - printf custom
 * @format: format pointer
 * Return: characters written
 */
int _printf(const char *format, ...)
{
	int i;
	int prnt = 0, prtChars = 0, indexBuff = 0;
	int flags, width, precision, size;
	va_list variadlist;
	char buffer[BufferSize];

	if (format == NULL)
		return (-1);

	va_start(variadlist, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[indexBuff++] = format[i];
			if (indexBuff == BufferSize)
				print_buffer(buffer, &indexBuff);
			prtChars++;
		}
		else
		{
			print_buffer(buffer, &indexBuff);
			flags = get_flags(format, &i);
			width = get_width(format, &i, variadlist);
			precision = get_precision(format, &i, variadlist);
			size = get_size(format, &i);
			++i;
			prnt = handle_print(format, &i, variadlist, buffer,
				flags, width, precision, size);
			if (prnt == -1)
				return (-1);
			prtChars += prnt;
		}
	}

	print_buffer(buffer, &indexBuff);
	
	va_end(variadlist);

	return (prtChars);
}

/**
 * print_buffer - prints buffer contents
 * @buffer: char[]
 * @indexBuff: buffers index
 */
void print_buffer(char buffer[], int *indexBuff)
{
	if (*indexBuff > 0)
		write(1, &buffer[0], *indexBuff);

	*indexBuff = 0;
}
