#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define ResultGreen 1
#define ResultYellow 2
#define ResultRed 4

typedef char Result;
typedef Result[5] Results;

Result checkChar(char, int, char*);
int main();

Result checkChar(char guess, int idx, char *word) {
    
    char correct;

    correct = word[idx];
    
    switch(word[idx]) {
        case correct :
            return ResultGreen;
        default:
            if (isin(correct, word))
                return ResultYellow;
    }
}




int main() {
    printf("abc\n");
}