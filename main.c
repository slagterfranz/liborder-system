#include "input.h"
#include "menumain.h"
#include "func.h"


int main () {
    init_books_table();
    while (1) {
        menumain();
    }
    print_all_books();
    return 0;
}
