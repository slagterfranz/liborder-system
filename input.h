#ifndef INPUT_H
#define INPUT_H 
#define ONE_CHAR 1
#define MORE_CHARS 0
void quit();
char* input();

typedef struct {
    int more_than_one_element;
} elements;

//problems with newline, OS specific
int intinput();
int get_int_output();
#endif
