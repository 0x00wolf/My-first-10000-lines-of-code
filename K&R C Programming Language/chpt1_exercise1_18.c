/* Write a program to remove trailing blanks and tabs from
 * each line of input, and to delete entirely blank lines. */

#include <stdio.h>
#define MAXLINE 1000    // maximum input line size

int getlinef(char line[], int maxline);
void trimchk(char line[]);

void main(){
    int len;    // current line length
    char line[MAXLINE];  // current input line

    while ((len = getlinef(line, MAXLINE)) > 0){
        trimchk(line);
        if (line[0] != '\n' && line[0] != '\0'){
            printf("%s", line);
        }
    }
}

// getline: read a line into s, return length
int getlinef(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void trimchk(char line[]){
    char c;
    int i;
    int mark = -1;
    for (i = 0; (c = line[i]) != '\n' && c != '\0'; i++){
        if (c == ' ' || c == '\t') {
            if (mark == -1) 
                mark = i;
        }
        else
            mark = -1;
    }

    if (mark != -1 && i > 0) {
        if (line[i] == '\n') {
            line[mark++] = '\n';
        }
        line[mark] = '\0';
    }
}
      
    
    
        
