#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void vigenere_encrypt(char *message, const char *key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    for (int i = 0; i < message_len; i++) {
        if (isalpha(message[i])) {
            char shift = isupper(key[i % key_len]) ? 'A' : 'a';
            int key_index = toupper(key[i % key_len]) - 'A';
            message[i] = ((toupper(message[i]) - 'A' + key_index) % 26) + shift;
            if (islower(message[i]))
                message[i] = tolower(message[i]);
        }
    }
}

void vigenere_decrypt(char *message, const char *key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    for (int i = 0; i < message_len; i++) {
        if (isalpha(message[i])) {
            char shift = isupper(key[i % key_len]) ? 'A' : 'a';
            int key_index = toupper(key[i % key_len]) - 'A';
            message[i] = ((toupper(message[i]) - 'A' - key_index + 26) % 26) + 'A';
            if (islower(message[i]))
                message[i] = tolower(message[i]);
        }
    }
}

int main() {
    char message[1000];
    char key[100];
    char choice;
    
    printf("Enter 'E' for encryption or 'D' for decryption: ");
    scanf("%c", &choice);
    getchar(); // Consume newline
    
    if (choice == 'E' || choice == 'e') {
        printf("Enter the message to encrypt: ");
        fgets(message, sizeof(message), stdin);
        
        printf("Enter the key: ");
        scanf("%s", key);
        
        vigenere_encrypt(message, key);
        printf("Encrypted message: %s\n", message);
        
        FILE *file = fopen("encrypted_message.txt", "w");
        if (file == NULL) {
            printf("Error opening file!\n");
            return 1;
        }
        fprintf(file, "%s", message);
        fclose(file);
    } else if (choice == 'D' || choice == 'd') {
        printf("Enter the message to decrypt: ");
        fgets(message, sizeof(message), stdin);
        
        printf("Enter the key: ");
        scanf("%s", key);
        
        vigenere_decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    return 0;
}
