// C program that asks the user to complete pre determined quotes
// if they get it right they get to see the full quote
// if they get it wrong they will also see how its written
// it is case sensitive so try to write accurately

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUOTES 3
#define MAX_QUOTE_LENGTH 100

// Fuction to pick random quote from the array
char* getRandomQuote() {
    char* quotes[MAX_QUOTES] = {
        "The quick brown fox jumped over the lazy dog",
        "The early bird catches the worm",
        "To be or not to be, that is the question"
    };

    // Generate a random index
    int randomIndex = rand() % MAX_QUOTES;

    return quotes[randomIndex];
}

// Function to check if the user's answer is correct
int isAnswerCorrect(char* original, char* userAnswer) {
    return (strcmp(original, userAnswer) == 0);
}

int main() {
    // Seef for random number generation
    srand(time(NULL));

    // Get a random quote
    char* originalQuote = getRandomQuote();

    //Display a portion of the quote to the user
    int protionLength = 10; // Adjust the length as needed
    printf("Complete the followng quote:\n");
    printf("%.*s\n", protionLength, originalQuote);

    // Get user input
    char userAnswer[MAX_QUOTE_LENGTH];
    printf("Your completion: ");
    scanf(" %[^\n]", userAnswer); // %[^\n] to read the whole line, including spaces

    // Check if the answer is correct
    if (isAnswerCorrect(originalQuote, userAnswer)){
        printf("Correct! You completed the quote.\n");
    } else {
        printf("Incorrect! The correct completion is:\n%s\n", originalQuote);
    }

    return 0;
}