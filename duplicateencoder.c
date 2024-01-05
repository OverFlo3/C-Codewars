#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encode the string
char *DuplicateEncoder(const char *string) {
    // Get the length of the input string
    int length = strlen(string);

    // Allocate memory for the encoded string (+1 for null terminator)
    char *encodedString = calloc(length + 1, sizeof(char));

    // Array to keep count of character occurrences (for ASCII characters)
    int count[256] = {0};

    // Check if memory allocation was successful
    if (encodedString == NULL) {
        return NULL; // Return NULL if allocation failed
    }

    // First pass: convert each character to lowercase and count occurrences
    for (int i = 0; i < length; i++) {
        count[tolower(string[i])]++;
    }

    // Second pass: determine encoding for each character based on its count
    for (int i = 0; i < length; i++) {
        // If character appears more than once, use ')', else use '('
        encodedString[i] = (count[tolower(string[i])] > 1) ? ')' : '(';
    }

    // Return the encoded string
    return encodedString;
}

// Main function to test the DuplicateEncoder function
int main() {
    // Test string
    const char *testString = "PresumeNotThatIAmTheThingIAppear";

    // Call DuplicateEncoder and store the result
    char *encoded = DuplicateEncoder(testString);

    // Check if encoding was successful
    if (encoded != NULL) {
        printf("Encoded string: %s\n", encoded); // Print encoded string
        free(encoded); // Free the allocated memory for the encoded string
    } else {
        printf("Memory allocation failed.\n"); // Error message if encoding failed
    }

    // End of main function
    return 0;
}

