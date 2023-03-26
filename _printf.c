#include "main.h"

#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int handle_print(const char *format, int *i, va_list list, char buffer[],
                 int flags, int width, int precision, int size);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, buffer, *buff_ind);
    }
    *buff_ind = 0;
}

/**
 * _printf - Printf function
 * @format: format string
 * Return: number of printed chars
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
    {
        return (-1);
    }

    va_list list;
    va_start(list, format);

    int i = 0;
    int printed_chars = 0;
    int buff_ind = 0;
    char buffer[BUFF_SIZE];

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
            {
                print_buffer(buffer, &buff_ind);
            }
            printed_chars++;
        }
        else
        {
            print_buffer(buffer, &buff_ind);
            i++;
            int flags = get_flags(format, &i);
            int width = get_width(format, &i, list);
            int precision = get_precision(format, &i, list);
            int size = get_size(format, &i);
            int printed = handle_print(format, &i, list, buffer, flags,
                                        width, precision, size);
            if (printed == -1)
            {
                va_end(list);
                return (-1);
            }
            printed_chars += printed;
        }
        i++;
    }
    print_buffer(buffer, &buff_ind);
    va_end(list);
    return (printed_chars);
}

