#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  char input[256];
  int letterCount[26] = {
      0};  // Array to store the count of each letter initialized to zeros

  printf("Enter text strings (press Enter on an empty line to exit):\n");

  while (1) {
    fgets(input, sizeof(input),
          stdin);  // get the input from the user via keyboard

    // Check for an empty line to exit the loop
    if (strlen(input) == 1 && input[0] == '\n') {
      break;
    }

    // Iterate through the characters in the input
    for (int i = 0; input[i] != '\0'; i++) {
      char currentChar = input[i];

      // Check if the character is a letter (A-Z or a-z)
      if (isalpha(currentChar)) {
        char lowercaseChar = tolower(currentChar);  // Convert to lowercase
        letterCount[lowercaseChar - 'a']++;
      }
    }
  }

  // Display the letter counts
  printf("Letter counts:\n");
  for (int i = 0; i < 26; i++) {
    char letter = 'a' + i;
    printf("%c: %d\n", letter, letterCount[i]);
  }

  return 0;
}
