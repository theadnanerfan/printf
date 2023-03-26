#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: the format string
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
				{
					const char *s = va_arg(args, const char *);
					while (*s != '\0')
					{
						putchar(*s);
						s++;
						count++;
					}
					break;
				}
				case '%':
					putchar('%');
					count++;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);

	return (count);
}
