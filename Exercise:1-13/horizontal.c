#include <stdio.h>
#include <string.h>

#define MAX 26
#define IN 1
#define OUT 0

int main(){
    int gChar, nl, nc, nw;
    char save_words[MAX];
    int state = OUT;

    for (int i = 0; i < MAX; i++) {
        save_words[i] = 0;
    }
    nl = nc = nw = 0;
    while ((gChar = getchar()) != EOF) {
        nc++;
        if (gChar == '\n')
            nl++;
        if (gChar == ' ' || gChar == '\n' || gChar == '\t') {
            state = OUT;
        }else {
            state = IN;
            nw++;
            for(int i = 0; save_words[i] == OUT; i++){
                save_words[nc] = gChar;
                state = OUT;
            }
        }
    }

    char copy_words[MAX][MAX] = {'\0'};
    int sep_word = 0;

    for (int i = 0; i < nc; i++){
        if (save_words[i] == ' ' || save_words[i] == '\0') {
            copy_words[state][sep_word] = '\0';
            state++;
            sep_word = 0;
        } else {
            copy_words[state][sep_word] = save_words[i];
            sep_word++;
        }
    }

    int len[state], lens = 0;
    printf("lengths of words :\n");
    for (int i = 1; i <= state; i++) {
        len[i] = 0;
        if (len[i] == 0){
            len[i] = strlen(copy_words[i]);
            for(int j = 0; j < len[i]; j++) printf("\uf0c8");
            printf("\n");
        }
    }

    return OUT;
}
