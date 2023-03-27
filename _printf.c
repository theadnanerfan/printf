#include "main.h"
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    const char *p;

    va_start(args, format);

    for (p = format; *p != '\0'; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            printed_chars++;
        }
        else
        {
            p++;
            if (*p == '%')
            {
                putchar('%');
                printed_chars++;
            }
            else if (*p == 'c')
            {
                char c = va_arg(args, int);
                putchar(c);
                printed_chars++;
            }
            else if (*p == 's')
            {
                char *s = va_arg(args, char *);
                int i;
                for (i = 0; s[i] != '\0'; i++)
                {
                    putchar(s[i]);
                    printed_chars++;
                }
            }
        }
    }

    va_end(args);

    return printed_chars;
}
