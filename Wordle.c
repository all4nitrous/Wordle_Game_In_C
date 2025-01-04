#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Defines the constants for result colors
#define ResultGreen 1
#define ResultYellow 2
#define ResultRed 4

// Defines custom types needed for results
typedef char Result;
typedef Result[5] Results;

void Example_print_Results(Results);
Result checkWord(char*, char*);
Result checkChar(char, int, char*);
int main();

void Example_print_results(Results res) {
    int i;

    for (i=0; i<5; i++)
        switch (res[i]) {
            case ResultGreen:
                printf("%s\n", "Green");
                break;
            case ResultYellow:
                printf("%s\n", "Yellow");
    }
}


// Function for checking a character in a guess
Result checkChar(char guess, int idx, char *word) {
    char correct;

// Makes sure you get correct character for a word
   correct = word[idx];
    
// Checks the result based on your guess    
if (guess == correct) {
        return ResultGreen; // Correct letter in the correct position
    } else {
        // Checks if the guessed letter exists elsewhere in the word
        if (strchr(word, guess)) {
            return ResultYellow; // Correct letter but wrong position
        }
    }

    // Returns ResultRed for an incorrect guess
    return ResultRed;
}

Results checkWord(char *guess, char *word) {
    Results res;
    int i;

    for (i=0; i<5; i++)
        res[i] = checkChar(guess[i], i, word);

    return res;
}

int main() {
    // Example usage of checkChar
    char word[] = "apple"; // Example word
    char guess = 'p';      // Example guess
    int idx = 1;           // Index to check

    // Calls checkChar and prints the result
    Result result = checkChar(guess, idx, word);
    switch (result) {
        case ResultGreen:
            printf("Result: Green (Correct letter in correct position)\n");
            break;
        case ResultYellow:
            printf("Result: Yellow (Correct letter in wrong position)\n");
            break;
        case ResultRed:
            printf("Result: Red (Incorrect letter)\n");
            break;
    }

    return 0;
}