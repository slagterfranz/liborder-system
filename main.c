#include "input.h"
#include "menumain.h"
#include "func.h"


int main () {

    init_books_table();
    insert_book("author", "title", 1);
    insert_book("klap", "grethe", 7);
    insert_book("klap12", "utopi", 2);
    insert_book("klap2", "utopi", 3);
    insert_book("klap44", "utopi", 4);
    insert_book("klap44", "utopi", 5);
    insert_book("klap44", "utopi", 6);
    while (1) {
    menumain();
    }
    print_all_books();

    return 0;
}
