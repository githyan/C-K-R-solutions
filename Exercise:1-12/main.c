#include <stdio.h>

int main() 
{
    int c, nw, cw;
    nw = cw = 0;

    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == ' ' || c == '\t'){
            nw = c;
            putchar('\n');
        }
    }
}
