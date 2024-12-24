#include <stdio.h>

#define MAXLINE 1000
#define LIMIT 80

int bufferline(char line[], int lim);
void copy(char sources[], char dest[]);

int main(){
   int len, max;
   char line[MAXLINE] = {'0'};
   char longest[MAXLINE];

   len = max = 0;
   while ((len = bufferline(line, MAXLINE)) > 0) {
        if (len > LIMIT) {
            max = LIMIT;
            copy(longest, line);
        }
   }
   if(max > 0)
       printf("%s\n strlen: %d", longest, max);

    return 0;
}

int bufferline(char line[], int lim){
    int c, i =0;
    for(; i < lim - 1 &&(c = getchar()) != EOF && c != '\n'; i++ ){
        if(i < LIMIT){
            line[i] = c;
        }
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

void copy(char from[], char to[]){
    for(int i = 0; (from[i] = to[i]) != '\0'; i++)
        ;
}

