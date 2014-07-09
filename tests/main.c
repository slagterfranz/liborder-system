#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    char oat[100];
    strncpy(oat, "hello", 100);
    add_nl(oat);
    to_saves(oat);
}

int add_nl(char* ch) {
    char *p = ch;
    int c = 0;
    while (1) {

        if (c > 29) {
            break;
        }

        if (*(p+c) != '\0' || *(p+c) != NULL) {
            *(p+c) = '\n';
            *(p+c+1) = '\0';
        }
        c++;
    }
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
             return 1;
         }
         c++;
     }
     printf("notfound");
     return 0;
} 

int append_sav() {
    char oat[100];
    strncpy(oat, "helo2\n", 100);
    FILE *fp = fopen("saves.liborder","a");
    fputs(oat,fp);
    fclose(fp);
    return 1;
}

int prints() {
    char aak[100];
    long long a = 299;
    sprintf(aak,"%lld", a);
    printf(aak);
    return 1;

}

int to_saves (char* helo) {
    char jelo[100];
    strncpy(jelo, helo, 100);
    FILE *fp = fopen("saves.liborder", "a");
    fputs(jelo,fp);
}

