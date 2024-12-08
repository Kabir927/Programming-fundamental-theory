#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email) {
    int atCount = 0, dotCount = 0;
    int i = 0;

    while (email[i] != '\0') {
        if (email[i] == '@') {
            atCount++;
        } else if (email[i] == '.') {
            dotCount++;
        }
        i++;
    }
    return (atCount == 1 && dotCount >= 1 && strlen(email) > 0);
}

int main() {
    char *email;
    int size;
    printf("Enter the size of the email address: ");
    scanf("%d", &size);
    email=(char *)malloc(size * sizeof(char));

    if (email == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter an email address: ");
    scanf("%s", email);
    if (validateEmail(email)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }
    free(email);

    return 0;
}
