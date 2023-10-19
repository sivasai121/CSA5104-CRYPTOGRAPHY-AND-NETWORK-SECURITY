#include <stdio.h>
#include <string.h>
void encryptRailFence(char* text, int key, char* ciphertext, char rail_design[][100]) {
    char rail[key][strlen(text)];
    int dir_down = 0;
    int row = 0, col = 0;

    for (int i = 0; i < key; i++) {
        for (int j = 0; j < strlen(text); j++) {
            rail[i][j] = ' ';
        }
    }

    for (int i = 0; i < strlen(text); i++) {
        if (row == 0 || row == key - 1)
            dir_down = !dir_down;
        rail[row][col] = text[i];
        col++;

        if (dir_down)
            row++;
        else
            row--;
    }

    int index = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < strlen(text); j++) {
            rail_design[i][j] = rail[i][j];
            if (rail[i][j] != ' ') {
                ciphertext[index] = rail[i][j];
                index++;
            }
        }
    }

    ciphertext[index] = '\0';
    rail_design[key][strlen(text)] = '\0';
}

void decryptRailFence(char* cipher, int key, char* plaintext, char rail_design[][100]) {
    char rail[key][strlen(cipher)];
    int dir_down = 1;
    int row = 0, col = 0;

    for (int i = 0; i < key; i++) {
        for (int j = 0; j < strlen(cipher); j++) {
            rail[i][j] = ' ';
        }
    }

    for (int i = 0; i < strlen(cipher); i++) {
        if (row == 0)
            dir_down = 1;
        if (row == key - 1)
            dir_down = 0;
        rail[row][col] = '*';
        col++;

        if (dir_down)
            row++;
        else
            row--;
    }

    int index = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < strlen(cipher); j++) {
            if (rail[i][j] == '*' && index < strlen(cipher)) {
                rail[i][j] = cipher[index];
                index++;
            }
        }
    }

    index = 0;
    for (int i = 0; i < strlen(cipher); i++) {
        for (int j = 0; j < key; j++) {
            if (rail[j][i] != ' ') {
                plaintext[index] = rail[j][i];
                index++;
            }
        }
    }
    plaintext[index] = '\0';

    for (int i = 0; i < key; i++) {
        for (int j = 0; j < strlen(cipher); j++) {
            rail_design[i][j] = rail[i][j];
        }
    }
}

int main() {
    int choice;
    char text[100];
    int key;
    char ciphertext[100];
    char rail_design[100][100];
    char plaintext[100];

    while (1) {
        printf("Rail Fence Cipher Menu:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the text to encrypt: ");
            scanf(" %99[^\n]", text); 
            printf("Enter the key: ");
            scanf("%d", &key);

            encryptRailFence(text, key, ciphertext, rail_design);
            printf("Encrypted: %s\n", ciphertext);

            printf("Rail Fencing Design:\n");
            for (int i = 0; i < key; i++) {
                printf("%s\n", rail_design[i]);
            }
        } else if (choice == 2) {
            printf("Enter the ciphertext to decrypt: ");
            scanf(" %99[^\n]", ciphertext);
            printf("Enter the key: ");
            scanf("%d", &key);

            decryptRailFence(ciphertext, key, plaintext, rail_design);
            printf("Decrypted: %s\n", plaintext);

            printf("Rail Fencing Design:\n");
            for (int i = 0; i < key; i++) {
                printf("%s\n", rail_design[i]);
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