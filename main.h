#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
void revstr(char str[], int length);
int intconvert(int num, char str[]);

#endif