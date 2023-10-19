#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, char *key) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = key[text[i] - 'A'];
            } else if (islower(text[i])) {
                text[i] = tolower(key[text[i] - 'a']);
            }
        }
    }
}

void decrypt(char *text, char *key) {
    int i, j;
    char original[] = "abcdefghijklmnopqrstuvwxyz";
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                for (j = 0; j < 26; j++) {
                    if (key[j] == text[i]) {
                        text[i] = original[j];
                        break;
                    }
                }
            } else if (islower(text[i])) {
                for (j = 0; j < 26; j++) {
                    if (tolower(key[j]) == tolower(text[i])) {
                        text[i] = original[j];
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    char key[] = "qwertyuiopasdfghjklzxcvbnm";
    char text[100];
    int choice;

    while (1) {
        printf("Monoalphabetic Substitution Cipher\n");
        printf("1. Encrypt\n2. Decrypt\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            if (choice == 1) {
                printf("Enter the text: ");
                scanf(" %99[^\n]", text);
                encrypt(text, key);
                printf("Encrypted text: %s\n", text);
            } else {
                printf("Enter the ciphertext: ");
                scanf(" %99[^\n]", text);
                decrypt(text, key);
                printf("Decrypted text: %s\n", text);
            }
        } else if (choice == 3) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
