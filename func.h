#ifndef FUNC_CONST_H
#define FUNC_CONTS_H
#define MAX_BOOKS   64000
#define BOOK_END_OF_INDEX -3
#define BOOK_ERROR -2
#define BOOK_OUT_OF_BOUND -1
#define BOOK_OK 0

typedef struct {
    int IBN;
    char author[100];
    char title[100];
    int is_used;
    int next;
} book;


typedef struct search{
    book* book;
    int is_last;
    struct search *next;
}search_book_mal; 


static struct {
    int head;
    int tail;
} hd_tl = {-1,-1};

static struct {
    struct search *first;
    struct search *last;
    int is_empty_first;
    int is_empty_array; 
} hd_tl_s;



int init_books_table();
int insert_book(char* author, char* title, int ibn);
int delete_book(int ibn);
int search_book(char* title); 
int print_all_books();
int print_free(char* title);
book get_book();
#endif
