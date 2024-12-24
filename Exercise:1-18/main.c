/*
 * Write a program to remove trailing blanks and tabs from each line of input
 * and to delete entirely blank lines.
 *
 * */

#include <stdio.h>

#define MAXLINE 1000

int bufferline(char so[], int lim);
void copy(char src[], char dest[]);
int main(){
    int len, max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];
    
    while ((len = bufferline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0)
        printf("%s", longest);
    return 0;
}

int bufferline(char src[], int lim){
    int c, i = 0;

    for(; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        src[i] = c;
        if (c == ' ' || c == '\t'){
            src[i] = src[i] - 1;
        }
    }
    if(c == '\n') {
        src[i] = c;
        i++;
    }
       
    src[i] = '\0';
    return i;
}

void copy(char src[], char dest[])
{
    for (int i = 0; (src[i] = dest[i]) != '\0'; i++);
}
