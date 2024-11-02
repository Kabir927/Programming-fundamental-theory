/*
kabir
24k-0927
question1
*/
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int compressWord(char *word, char *compressedWord) {
    int removedCount = 0;
    int j = 0;  // Index for the compressed word

    for (int i = 0; i < strlen(word); i++) {
        if (i == 0 || word[i] != word[i - 1]) {
            compressedWord[j++] = word[i];
        } else {
            removedCount++;
        }
    }

    compressedWord[j] = '\0';
    return removedCount;
}

int main() {
    char word[MAX_WORD_LENGTH];
    char compressedWord[MAX_WORD_LENGTH];

    printf("Enter a word: ");
    scanf("%s", word);

    int removedCount = compressWord(word, compressedWord);

    printf("Compressed word: %s\n", compressedWord);
    printf("Total characters removed: %d\n", removedCount);

    return 0;
}
