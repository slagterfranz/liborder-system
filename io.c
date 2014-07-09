#include <stdlib.h>
#include <stdio.h>
#include "io.h"
#include "func.h"
#include <string.h>

//loads the book database
int load_saved_books() {
 
    FILE *fp2 = fopen("saves.liborder", "r");
    char checkerc[100];
    int i = 0;
    int fields = 0;
   
    while (1) {

        fgets(checkerc, 100, fp2);
        remove_nl(checkerc);
        //determining at which fields the chars are inserted
        if (feof(fp2)) {
            break;
        }
        

        if (i % 3 == 0) {
            change_is_used(fields,1);
            change_author(fields, checkerc); 
        //printf("auth: %s",get_book(fields).author);
        }
        if (i % 3 == 1) {
            change_title(fields, checkerc); 
        //printf(gb.title);
        }

        if (i % 3 == 2) {
            long long ibni = atol(checkerc);
            change_ibn(fields,ibni);

            if (get_head() == -1) {
                change_head(fields);
                change_tail(fields);
                change_next (fields, -1);
                }

            else {
                change_next(get_tail(), fields); 
                change_tail(fields);

                change_next(fields, -1);
                }   
            //printf("ibn: %lld\n",ibni);
            fields++;
        }
        i++;
    }
    fclose(fp2); 
    return BOOK_OK; 
}

int remove_nl(char* nl) {
    char *p = nl;
    int c = 0;
    while (1) {
        
        if (c > 98) {
            break;
        }
        if (*(p+c) == '\n') {
            *(p+c) = '\0';
            return BOOK_OK;
        }
        c++;
    }
    return BOOK_ERROR;
}

int add_nl(char* nl) {
    char *p = nl;
    int c = 0;
    while(1) {
        if(*(p+c) == '\0') {
            *(p+c) = '\n';
            *(p+c+1) = '\0';
        }
        c++;
    }
}


int *read_line(FILE *fp) {
    int i = 0;
    int *k = (int *)malloc(sizeof(int) * 100);
    while (i < 100) {
        int c = fgetc(fp);
        if (c == '\n')  {
            return k;

        }
        else {
            k[i] = c;
            i++;
        }
    }
    return k;
    fclose(fp);
}

int number_of_lines(FILE *fp) {
    int num = 0;
    int i = 0;
    while (i != EOF) {
        i = fgetc(fp);
        if (i == '\n')
            num++;
    }
    return num;
}
