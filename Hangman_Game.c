#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRIES 10
#define WORD_COUNT 5

const char *wordList[WORD_COUNT] = {"programming", "computer", "hangman", "developer", "function"};

void displayWord(const char *word, int *guessedLetters) {
    for (int i = 0; i < strlen(word); i++) {
        if (guessedLetters[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int checkGuess(const char *word, char guess, int *guessedLetters) {
    int found = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == guess) {
            guessedLetters[i] = 1;
            found = 1;
        }
    }
    return found;
}

int main() {
    char playAgain;
    do {
        int guessedLetters[20] = {0}; // Array to track guessed letters
        int tries = 0;
        int wordIndex = rand() % WORD_COUNT; // Randomly select a word
        const char *chosenWord = wordList[wordIndex];
        
        printf("Welcome to Hangman!\n");
        
        while (tries < MAX_TRIES) {
            displayWord(chosenWord, guessedLetters);
            char guess;
            printf("Enter a letter: ");
            scanf(" %c", &guess);
            
            if (!checkGuess(chosenWord, guess, guessedLetters)) {
                tries++;
                printf("Wrong guess! You have %d tries left.\n", MAX_TRIES - tries);
            }
            
            // Check for win
            int won = 1;
            for (int i = 0; i < strlen(chosenWord); i++) {
                if (!guessedLetters[i]) {
                    won = 0;
                    break;
                }
            }
            if (won) {
                printf("Congratulations! You've guessed the word: %s\n", chosenWord);
                break;
            }
        }
        
        if (tries == MAX_TRIES) {
            printf("Sorry, you've run out of tries! The word was: %s\n", chosenWord);
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y');

    return 0;
}
