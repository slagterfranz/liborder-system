#include "func.h"
#include "input.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

elements element;
void quit() // write error message and quit
{
    fprintf(stderr, "memory exhausted\n");
    exit(1);
}

char* input()
{
    int max = 100;
    char* name = (char*)malloc(max); // allocate buffer
    if (name == 0) quit();

    while (true) { // skip leading whitespace
        int c = getchar();
        if (c == EOF) break; // end of file
        if (!isspace(c)) {
             ungetc(c, stdin);
             break;
        }
    }

    int i = 0;
    while (true) {
        int c = getchar();
        int nl = 10;
        if (c == EOF || c == nl) { // at end, add terminating zero
            name[i] = 0;
            break;
        }
        name[i] = c;
        i++;
        if (i > 1) {
            element.more_than_one_element = MORE_CHARS;
        }

        if (i == 1) {
            element.more_than_one_element = ONE_CHAR;
        }

    }
    /*printf("The filename is %s\n", name);*/
    /*free(name); // release memory*/
    return name;
}

int intinput() 
{
    int n;
    scanf ("%d",&n);
    return n;
}

    
int get_int_output() 
{
    char* c = input();
    if (element.more_than_one_element == ONE_CHAR) {
        int inp = c[0] - '0';
        return inp;
    }
    return BOOK_ERROR;
}


