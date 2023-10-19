#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MOD 26

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate the modular multiplicative inverse using the Extended Euclidean Algorithm
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; // Inverse doesn't exist
}

// Function to perform Hill cipher encryption
void hillEncrypt(int key[][2], char *text, int len) {
    int result[len];
    int size = 2;

    for (int i = 0; i < len; i += size) {
        for (int j = 0; j < size; j++) {
            result[i + j] = 0;
            for (int k = 0; k < size; k++) {
                result[i + j] += key[j][k] * (text[i + k] - 'a');
            }
            result[i + j] %= 26;
            text[i + j] = 'a' + result[i + j];
        }
    }
}

// Function to perform Hill cipher decryption
void hillDecrypt(int key[][2], char *text, int len) {
    int result[len];
    int size = 2;
    int determinant = key[0][0] * key[1][1] - key[0][1] * key[1][0];

    if (determinant == 0 || gcd(determinant, MOD) != 1) {
        printf("Matrix not invertible.\n");
        return;
    }

    int inverse = modInverse(determinant, MOD);
    if (inverse == -1) {
        printf("Matrix not invertible.\n");
        return;
    }

    int a = (key[1][1] * inverse) % MOD;
    int b = (MOD - key[0][1]) * inverse % MOD;
    int c = (MOD - key[1][0]) * inverse % MOD;
    int d = (key[0][0] * inverse) % MOD;

    for (int i = 0; i < len; i += size) {
        for (int j = 0; j < size; j++) {
            result[i + j] = 0;
            for (int k = 0; k < size; k++) {
                result[i + j] += (a * (text[i + k] - 'a') + b * (text[i + k + 1] - 'a')) % MOD;
                result[i + j] += (c * (text[i + k] - 'a') + d * (text[i + k + 1] - 'a')) % MOD;
                result[i + j] %= MOD;
                text[i + j] = 'a' + result[i + j];
            }
        }
    }
}

int main() {
    char text[100];
    int key[2][2];
    int size = 2;
    int len, choice;

    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid choice. Please choose 1 for encryption or 2 for decryption.\n");
        return 1;
    }

    printf("Enter the key matrix (%dx%d):\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &key[i][j]);
        }
    }

    printf("Enter the text (in lowercase, no spaces): ");
    scanf("%s", text);
    len = strlen(text);

    if (choice == 1) {
        hillEncrypt(key, text, len);
        printf("Encrypted text: %s\n", text);
    } else {
        hillDecrypt(key, text, len);
        printf("Decrypted text: %s\n", text);
    }

    return 0;
}