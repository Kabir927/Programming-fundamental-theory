//q7
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

fill(char arr[6][5]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = 'A' + (rand() % 26);
        }
    }
    arr[5][0] = '0';
    arr[5][1] = '5';
    arr[5][2] = '6';
    arr[5][3] = '0';
}

disparr(char arr[6][5]) {
    printf("\nCharacter Array:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int search(char arr[6][5], const char *str) {
    int len = strlen(str);
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= 5 - len; j++) {
            if (strncmp(&arr[i][j], str, len) == 0) {
                return 1; // Found horizontally
            }
        }
    }

    // Search vertically (top to down)
    for (int j = 0; j < 6; j++) {
        for (int i = 0; i <= 5 - len; i++) {
            int found = 1;
            for (int k = 0; k < len; k++) {
                if (arr[i + k][j] != str[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                return 1; // Found vertically
            }
        }
    }

    return 0; // Not found
}

int main() {
    char characters[6][5];
    char input[100];
    int score = 0;

    srand(time(NULL)); // Seed random number generator

    while (1) {
        fill(characters);
        disparr(characters);

        while (1) {
            printf("Enter a string to search (or type 'END' to repopulate): ");
            scanf("%s", input);

            if (strcmp(input, "END") == 0) {
                break; // Break out of inner loop to repopulate the array
            }

            if (search(characters, input)) {
                score++; // Increment score if found
                printf("%s is present. Score: %d\n", input, score);
            } else {
                score--; // Decrement score if not found
                printf("%s is not present. Score: %d\n", input, score);
            }
        }
    }

    return 0;
}
