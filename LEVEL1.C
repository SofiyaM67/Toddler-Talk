#include <stdio.h>
#include <string.h>

// Array of words for the game
const char* letters[] = {"A", "B", "C", "D", "E"};
const int totalletters = sizeof(letters) / sizeof(letters[0]);

// Function to get user input
void getUserInput(char* userInput, int maxLength) {
    fgets(userInput, maxLength, stdin);
    userInput[strcspn(userInput, "\n")] = '\0';  // Remove trailing newline
}

int main() {
    int score = 0;
    
    printf("Welcome to Toddlers TALK!!\n");
    printf("Listen to the word and repeat it correctly.\n");
    
    // Game loop
    for (int i = 0; i < totalletters; i++) {
        printf("\nWord %d: %s\n", i+1, letters[i]);
        printf("Say the letter: ");
        
        // User input
        char userInput[10];
        getUserInput(userInput, sizeof(userInput));
        
        // Check if the user's input matches the word
        if (strcmp(userInput, letters[i]) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct word is '%s'\n", letters[i]);
        }
    }
    
    printf("\nGame Over!\n");
    printf("Your score: %d out of %d\n", score, totalletters);
    
    return 0;
}
