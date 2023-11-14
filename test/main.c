#include "myprint.c"

int main()
{
    _printf("%c\n", 'a');
    _printf("%s\n", "hello");
    _printf("%%\n");
    _printf("%d\n", 65+2);
    _printf("%i\n", 65+2);
    _printf("hello world!\n");
}