#include <stdio.h>
#include <stdint.h>
void des_encrypt(uint64_t plainText, uint64_t key, uint64_t *cipherText);
int main() {
    uint64_t plainText, key, cipherText;
    printf("Enter the 64-bit plaintext: ");
    scanf("%llx", &plainText);
    printf("Enter the 64-bit encryption key: ");
    scanf("%llx", &key);
    des_encrypt(plainText, key, &cipherText);
    printf("\nPlaintext: %llx\n", plainText);
    printf("Key: %llx\n", key);
    printf("Ciphertext: %llx\n", cipherText);
    return 0;
}
void des_encrypt(uint64_t plainText, uint64_t key, uint64_t *cipherText) {
    *cipherText = plainText ^ key;
}
void print_binary(uint64_t num) {
    for (int i = 63; i >= 0; i--) {
        uint64_t bit = (num >> i) & 1;
        printf("%llu", bit);
        if (i % 8 == 0)
            printf(" ");
    }
    printf("\n");
}
