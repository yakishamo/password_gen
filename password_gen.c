#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *password_gen(char *symbols, int len) {
    char alphabet[] = "qwertyuiopasdfghjklzxcvbnm";
    char *pass;
    int char_kinds = 26;
    int r = 0;

    char_kinds += strlen(symbols);
    pass = malloc(len+1);

    for(int i = 0; i < len; i++) {
        r = rand()%char_kinds;
        if(r < 26) {
            pass[i] = alphabet[r];
        } else {
            pass[i] = symbols[r-26];
        }
    }
    return pass;
}

int main(void) {
    srand(time(NULL));
    char *pass = password_gen("!@_*+-=1234567890",12);
    printf("%s\n", pass);
    free(pass);
    return 0;

}