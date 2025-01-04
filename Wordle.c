#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Defines the constants for result colors
#define ResultGreen 1
#define ResultYellow 2
#define ResultRed 4

// Defines custom types needed for results
typedef char Result;

bool isin(char, char*);  // Function declaration for isin

void Example_print_results(Result*);  // Correct function declaration
Result* checkWord(char*, char*);
Result checkChar(char, int, char*);
int main(int, char**);

// Function to print results
void Example_print_results(Result *res) {
    int i;

    for (i = 0; i < 5; i++) {
        switch (res[i]) {
            case ResultGreen:
                printf("Green\n");
                break;
            case ResultYellow:
                printf("Yellow\n");
                break;
            case ResultRed:
                printf("Red\n");
                break;
            default:
                printf("unknown: %d\n", res[i]);
                break;
        }
    }
}

// Function to check if a character is in a string
bool isin(char c, char *str) {
    int i, size;

    size = strlen(str);  // Calculate string size

    for (i = 0; i < size; i++) {
        if (str[i] == c) {
            return true;  // Found the character
        }
    }
    return false;  // Character not found
}

// Function for checking a character in a guess
Result checkChar(char guess, int idx, char *word) {
    char correct;

    correct = word[idx];

    if (guess == correct) {
        return ResultGreen;  // Correct letter in the correct position
    } else if (isin(guess, word)) {
        return ResultYellow;  // Correct letter but wrong position
    }

    return ResultRed;  // Incorrect letter
}

Result* checkWord(char *guess, char *word) {
    static Result res[5];  // Static array for storing results
    int i;

    for (i = 0; i < 5; i++) {
        res[i] = checkChar(guess[i], i, word);  // Check each character
    }

    return res;
}

int main(int argc, char *argv[]) {
    char *correct, *guess;
    Result *res;

    if (argc < 3) {
        fprintf(stderr, "usage: %s CORRECTWORD GUESSWORD\n", argv[0]);
        return -1;
    }

    correct = argv[1];
    guess = argv[2];

    // Call checkWord function
    res = checkWord(guess, correct);

    // Call Example_print_results function
    Example_print_results(res);

    return 0;
}
