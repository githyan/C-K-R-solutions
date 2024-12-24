#include <linux/limits.h>
#include <stdio.h>

#define MAXLEN 50

int get_line(char src[], int lim);
void copy(char from[], char to[]);
int main(){
    int len, max = 0;
    char line[MAXLEN] = {'\0'};
    char dest[MAXLEN] = {'\0'};

    while ((len = get_line(line, MAXLEN)) > 0) {
        if(len > max){
            max = len;
            reverse(dest, line);
        }
    }
    if(max > 0)
        for (int j = MAXLEN; j >= 0; j--) {
            printf("%c", dest[j]);       
        }

    return 0;
}

int get_line(char src[], int lim) {
    int c, i = 0;

    for(; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        src[i] = c;
    }
    if(c == '\n'){
        src[i] = c;
        i++;
    }
    src[i] = '\0';
   
    return i;
}

void copy(char src[], char to[]) {
    for (int i = 0; (src[i] = to[i]) != '\0'; i++);
}
