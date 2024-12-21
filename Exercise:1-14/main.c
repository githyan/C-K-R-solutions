#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX 10

int main(){
    int c, nother, nwhite, state;
    int ndigit[MAX];
    int copy_character[MAX];

    nother = nwhite = state = 0;
    for(int i = 0; i < MAX; i++){
        ndigit[i] = copy_character[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        if ((c >= '0' && c <= '9')){
            state = IN;
            ndigit[c - '0']++;
        }else if (c == ' ' || c == '\t' || c == '\n') {
            nwhite++;
            state = OUT;
        }else {
            nother++;
        }
    }

    int save_nother_and_nwhite[2] = {nother, nwhite};
    printf("digits\n");
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < ndigit[i]; j++) printf("*");
        printf("\n");
    }
    printf("nother and nwhite\n");
    int len = sizeof(save_nother_and_nwhite) / sizeof(save_nother_and_nwhite[0]);
    for(int i = 0; i < len; i++){
        for(int j = 0; j < save_nother_and_nwhite[i]; j++){
            printf("*");
        } printf("\n");
    }
    return 0;
}
