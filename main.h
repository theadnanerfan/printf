#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

/**
 * struct format_t - struct for format and function
 * @type: The format
 * @f: The function
 */
typedef struct format_t
{
    char type;
    int (*f)(va_list);
} format_t;

#endif /* MAIN_H */
