#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - prints output according to a format
 * @format: format string containing the characters and the specifiers
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, j, len = 0;
	char *str;

	va_start(args, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == 'c')
				len += print_char(args);

			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				len += print_string(str);
			}

			else if (format[i] == '%')
				len += print_percent(args);

			else if (format[i] != '\0')
			{
				_putchar('%');
				_putchar(format[i]);
				len += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
	}

	va_end(args);

	return (len);
}

/**
 * print_char - prints a character
 * @args: list of arguments containing the character to print
 *
 * Return: 1
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);

	return (1);
}

/**
 * print_string - prints a string
 * @args: list of arguments containing the string to print
 *
 * Return: the number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i;

	if (!str)
		str = "(null)";

	for (i = 0; str[i]; i++)
		_putchar(str[i]);

	return (i);
}

/**
 * print_percent - prints a percent sign
 * @args: list of arguments (unused)
 *
 * Return: 1
 */
int print_percent(va_list args)
{
	(void) args;

	_putchar('%');

	return (1);
}
