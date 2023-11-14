#include "main.h"
#include "intarg.c"

/**
 * _print - This function is a custom formated output function
 * it leverages the special character '%' to give a
 * formated output based on the character that follows
 */

int _printf(const char *format, ...)
{
    int char_count = 0;  /* this will track and return the number of characters printed */
    va_list fmt_string;

    /* if the argument we recieve is an invalid character
    or empty this code will immediately
    terminate the program with a -1 return value */
    if(format == NULL)
        return -1;

    /*==================START RECEIVING ARGUMENT FROM USER===================*/
    va_start(fmt_string, format);

    for (; *format; format++) /* THIS WILL ITERATE THROUGH ALL THE CHARACTERS ENTERED */
    {
        if (*format != '%')
        {
            write(1, format, 1);
            char_count++;
        }
        else /* checks if the character entered is % */
        {
            format++; /* this skips the % and check the next data in front of the % */
            if (*format == '\0')
                break;

            switch (*format)
            {
            case 'c':
            {
                char c = (char)va_arg(fmt_string, int);
                write(1, &c, 1);
                char_count++;
                break;
            }

            case 'd':
            case 'i':
            {
                int num = va_arg(fmt_string, int);
                char num_str[12]; /* Enough to hold any int value */
                int len = intconvert(num, num_str);
                write(1, num_str, len);
                char_count += len - 1; /* Adjust for incrementing later on */
                break;
            }

            case 's':
            {
                char *str = va_arg(fmt_string, char *);
                int string_len = 0;

                while (str[string_len] != '\0')
                    string_len++;

                write(1, str, string_len);
                char_count += string_len - 1; /* Adjust for incrementing later on */
                break;
            }

            case '%':
                write(1, format, 1);
                char_count++;
                break;

            default:
                write(1, "*", 1); /* Handle unknown specifiers */
                write(1, format, 1); /* And then the unknown specifier itself */
                char_count += 2;
            }
        }
    }

    va_end(fmt_string);
    return char_count;
}

