#include <string.h>
#include <stdio.h>
#include "func.h"
#include <stdlib.h>
book books_table[MAX_BOOKS];


int init_books_table() {
    int i;
    for (i = 0; i < MAX_BOOKS; i++) {
        books_table[i].is_used = 0;
        }
    return BOOK_OK;
}

int insert_book(char* author, char* title, int ibn) {
    int i = 0;
    while (books_table[i].is_used == 1) {
        i++;
    }
    books_table[i].is_used = 1;
    strncpy(books_table[i].author, author ,100);
    strncpy(books_table[i].title, title ,100);
    books_table[i].IBN = ibn;

    if (hd_tl.head == -1) {
        hd_tl.head = i;
        hd_tl.tail = i;
        books_table[i].next = -1;
        }
    else {
        books_table[hd_tl.tail].next = i;
        hd_tl.tail = i;
        books_table[i].next = -1;
        }
     return BOOK_OK;
}

int delete_book(int ibn) {
    
    //initializes the first 3 books, so that eventually 
    //if we are in the middle of the list (ie. not last 
    //or first element contained in 1.,2. or 3.), we can
    //unlink the 2nd element from the list.
    int first, second, third;
    first = hd_tl.head;
    second = books_table[first].next;
    third = books_table[second].next;

    //if the ibn number is equal to 1. (ie. there is only
    //1 element in the list), then 1. is set to is_used 1.
    if (ibn == books_table[first].IBN) {
        books_table[first].is_used = 0;
        hd_tl.head = second;
        return BOOK_ERROR;
        }
    
    if (books_table[second].next == -1) {
        return BOOK_ERROR;
    }     

    //checks if the 2. element equals the ibn.
    //if that is so, the 1. 3. is linked, and 
    //2. is set to is_used 0 (meaning it is not used).
    else {
        while (ibn != books_table[second].IBN) {
            first = second;
            second = books_table[first].next;
            third = books_table[second].next;

            //if 2. is the last element, return error
            if (books_table[second].next == -1) {
                return BOOK_OUT_OF_BOUND;
            }
        books_table[second].is_used = 0;
        books_table[first].next = third;
        return BOOK_OK;
        }
    }
    return BOOK_ERROR;
}

//checks how many books contains the same name, and return
//i number of same names.

int search_book(char* title) 
{
    int i; 
    hd_tl_s.is_empty_first = 1;
    hd_tl_s.is_empty_array = 1;
    for (i = hd_tl.head; books_table[i].next != -1;  i = books_table[i].next) {
        if (strncmp(books_table[i].title, title, 100) == 0) {
            hd_tl_s.is_empty_array = 0; 
            if (hd_tl_s.is_empty_first == 1) {
                hd_tl_s.is_empty_first = 0;
                search_book_mal *k = (search_book_mal*) malloc(sizeof(search_book_mal));
                hd_tl_s.first = k;
                hd_tl_s.last = k;
                k->book = &books_table[i];
                k->next = k;
                k->is_last = 1;
            }
            
            else {
                search_book_mal *k = (search_book_mal*) malloc(sizeof(search_book_mal));
                k->book = &books_table[i];
                k->next = k;
                k->is_last = 1;
                hd_tl_s.last->is_last = 0; 
                hd_tl_s.last->next = k;
                hd_tl_s.last = k;
           }
        }
    }        
    
    if (hd_tl_s.is_empty_array == 1) {
        return BOOK_ERROR;
    }

    return BOOK_OK;
}

int print_all_books() {
    int i = hd_tl.head;
    while (books_table[i].next != -1) {
        printf("Title: %s\nAuthor: %s\nIBN: %d\n\n", 
        books_table[i].title, books_table[i].author, books_table[i].IBN);
        i = books_table[i].next;
    }
    return BOOK_OK;
}

book get_book(int i)
{
    return books_table[i];
}

int print_free(char* title) 
{
    if (search_book(title) == BOOK_OK) {
    search_book_mal *k = hd_tl_s.first;

        while (1) {
            if (k->is_last == 1) {
                printf("Title: %s\n", k->book->title);
                printf("Author: %s\n", k->book->author);
                printf("IBN: %d\n\n", k->book->IBN);
                free(k);
                return BOOK_OK;
                }

            printf("Title: %s\n", k->book->title);
            printf("Author: %s\n", k->book->author);
            printf("IBN: %d\n\n", k->book->IBN);
            
            k = k->next;
            free(hd_tl_s.first);

            hd_tl_s.first = k;
        }
   return BOOK_OK;
   } 
   return BOOK_ERROR;
}

    
    

