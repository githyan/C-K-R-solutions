#include <stdio.h>
#define MAXLENGTH 50

int buffline(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
    int len, max;
    char line[MAXLENGTH];
    char longest[MAXLENGTH];

    max = len = 0;
    
    while ((len = buffline(line, MAXLENGTH)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0){
       printf("%s\n", longest);
       printf("lengths : %d", max);
    }
       return 0;
}

int buffline(char s[], int lim)
{
    int c, i, j =0;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n' || c == ' ') {
       // s[i] = c;
       j++;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    for(int i = 0; (to[i] = from[i]) != '\0'; i++)
        ;
}
