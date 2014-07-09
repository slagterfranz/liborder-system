#ifndef FUNC_CONST_H
#define FUNC_CONTS_H
#define MAX_BOOKS   64000
#define BOOK_END_OF_INDEX -3
#define BOOK_ERROR -2
#define BOOK_OUT_OF_BOUND -1
#define BOOK_OK 0

typedef struct {
    long long IBN;
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
int insert_book(char* author, char* title, long long ibn);
int delete_book(long long ibn);
int search_book(char* title); 
int print_all_books();
int print_free(char* title);
int change_head(int cheader);
int change_tail(int ctail);
book get_book();
int get_head();
int get_tail();
int change_next(int b, int next);
int change_author(int b, char* author);
int change_title(int b, char* title);
int change_ibn(int b, long long ibn);
int change_is_used(int b, int is);
#endif
