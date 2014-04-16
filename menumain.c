#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "func.h"
#include "menumain.h"
int menumain(){
    printf("*****************************************\n");
    printf("*       Welcome to liborder             *\n");
    printf("*                                       *\n");
    printf("*       what do you want to do?         *\n");
    printf("*   1.  insert book(title, author, ibn) *\n");
    printf("*   2.  search(title)                   *\n");
    printf("*   3.  delete book(ibn)                *\n");
    printf("*   4.  print all books                 *\n");
    printf("*****************************************\n");

int inp = get_int_output();


    switch(inp) {
        case 1:
            printf("Title of book: ");
            char* name = input();
            printf("%s\n", name);

            printf("Author of book: ");
            char* author = input();
            printf("%s\n", author);

            printf("ibn of book: ");
            int ibn = intinput();
            printf("%d\n", ibn);
            insert_book(author, name, ibn);
            system("clear");
            return BOOK_OK;
                break;

        case 2:
            printf("Search book: ");
            char* sec = input();
            if (print_free(sec) == BOOK_ERROR)
                printf("Book not found\n");
                break;

        case 3:
            printf("Delete book: ");
            int del = intinput();
            int delp = delete_book(del);
            if (delp == BOOK_OUT_OF_BOUND)
                printf("Book not existing");
            
            printf("deleteing: ");  
            return BOOK_OK;
                break;

        case 4:
            system("clear");
            print_all_books();
            return BOOK_OK;
                break;

        default:
            system("clear");
            printf("Don't try to use commands that doesn't exist\n");       
            return BOOK_ERROR;
                break;
    }
    return BOOK_OK;
}
                                                                
