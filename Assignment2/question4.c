/*
kabir
24k-0927
question1
*/
#include <stdio.h>

int main() {
    char *transactions[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int grouped[6] = {0}; // To track grouped transactions
    int n = 6; // Number of transactions

    printf("Grouped Anagrams:\n");

    for (int i = 0; i < n; i++) {
        if (grouped[i] == 1) continue; // Skip if already grouped

        printf("[");
        // Mark current as grouped
        grouped[i] = 1;

        // Initialize character count for the current transaction
        int count[26] = {0};
        for (int k = 0; transactions[i][k] != '\0'; k++) {
            count[transactions[i][k] - 'a']++;
        }

        // Print the first transaction in the group
        printf("'%s'", transactions[i]);

        // Check for anagrams in the rest of the transactions
        for (int j = i + 1; j < n; j++) {
            if (grouped[j] == 0) { // Only check ungrouped transactions
                int temp_count[26] = {0};

                // Count characters in the new transaction
                for (int k = 0; transactions[j][k] != '\0'; k++) {
                    temp_count[transactions[j][k] - 'a']++;
                }

                // Compare character counts
                int is_anagram = 1; // Assume it's an anagram unless proven otherwise
                for (int k = 0; k < 26; k++) {
                    if (count[k] != temp_count[k]) {
                        is_anagram = 0; // Not an anagram
                        break;
                    }
                }

                if (is_anagram) {
                    printf(", '%s'", transactions[j]); // Print the anagram
                    grouped[j] = 1; // Mark this transaction as grouped
                }
            }
        }
        printf("]\n"); // Close the current group
    }

    return 0;
}

