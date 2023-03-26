#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format.
 * @format: A string containing zero or more directives to write.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;
	char *str;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					len += write(1, (char)va_arg(args, int), 1);
					break;
				case 's':
					str = va_arg(args, char *);
					len += write(1, str, strlen(str));
					break;
				case '%':
					len += write(1, "%", 1);
					break;
				default:
					len += write(1, "%", 1);
					len += write(1, &(*format), 1);
			}
		}
		else
		{
			len += write(1, &(*format), 1);
		}
		format++;
	}
	va_end(args);

	return (len);
}
