#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int printhelper(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

int printchar(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printstring(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printpercent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printint(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printbin(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printunsign(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printoct(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printunsignhex(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_upperhex(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printhex(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int getflag(const char *format, int *i);
int getwidth(const char *format, int *i, va_list list);
int getprec(const char *format, int *i, va_list list);
int getsize(const char *format, int *i);
int writechar(char c, char buffer[],
	int flags, int width, int precision, int size);
int writestring(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int writenum(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int writeptr(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int writeunsign(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);
int printable(char);
int asccihex(char, char[], int);
int isnum(char);
long int numsize(long int num, int size);
long int unsignedsize(unsigned long int num, int size);

#endif /* MAIN_H */
