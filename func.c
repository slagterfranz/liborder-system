#include <string.h>
#include <stdio.h>
#include "func.h"

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

int search_book(char* title) {
    int i;
    i = hd_tl.head;
    while (strncmp(books_table[i].title, title, 100) != 0) {
        if (books_table[i].next == -1) {
            return BOOK_ERROR;
            }
        i = books_table[i].next;
    }
    return i;
}


int print_all_books() {
    int i = hd_tl.head;
    while (books_table[i].is_used != 0) {
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

