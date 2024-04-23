#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

char* caesar_encrypt(char* plaintext, int key) {
    int length = strlen(plaintext);
    char* cypher = (char*) malloc(sizeof(char) * (length + 1));
    
    int i = 0;
    while (plaintext[i] != '\0') {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            cypher[i] = ((plaintext[i] - base + key) % 26) + base;
        } else if (isdigit(plaintext[i])) {
            cypher[i] = ((plaintext[i] - '0' + key) % 10) + '0';
        } else {
            cypher[i] = plaintext[i];
        }
        i++;
    }
    cypher[i] = '\0';
    
    return cypher;
}

char* caesar_decrypt(char* cypher, int key) {
    int length = strlen(cypher);
    char* plaintext = (char*) malloc(sizeof(char) * (length + 1));
    
    int i = 0;
    while (cypher[i] != '\0') {
        if (isalpha(cypher[i])) {
            char base = islower(cypher[i]) ? 'a' : 'A';
            plaintext[i] = ((cypher[i] - base - key + 26) % 26) + base;
        } else if (isdigit(cypher[i])) {
            plaintext[i] = ((cypher[i] - '0' + 10 - key) % 10) + '0';
        } else {
            plaintext[i] = cypher[i];
        }
        i++;
    }
    plaintext[i] = '\0';
    
    return plaintext;
}

int write_text(char* filename, char* text) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return EXIT_FAILURE;
    }
    
    fprintf(file, "%s", text);
    
    fclose(file);
    return EXIT_SUCCESS;
}

int main() {
    char text[MAXN];
    printf("Enter text: \n");
    fgets(text, MAXN, stdin);
    
    char filename[MAXN];
    printf("Enter filename: \n");
    scanf("%s", filename);
    
    int key;
    printf("Enter key: ");
    scanf("%d", &key);
    
    char* encrypted_text = caesar_encrypt(text, key);
    printf("Encrypted text: %s\n", encrypted_text);
    
    char* decrypted_text = caesar_decrypt(encrypted_text, key);
    printf("Decrypted text: %s\n", decrypted_text);
    
 
    if (write_text("encrypted_text.txt", encrypted_text) == EXIT_SUCCESS) {
        printf("Encrypted text written to encrypted_text.txt.\n");
    } else {
        printf("Failed to write encrypted text to file.\n");
    }
    
    if (write_text("decrypted_text.txt", decrypted_text) == EXIT_SUCCESS) {
        printf("Decrypted text written to decrypted_text.txt.\n");
    } else {
        printf("Failed to write decrypted text to file.\n");
    }
    
    free(encrypted_text);
    free(decrypted_text);
    
    return EXIT_SUCCESS;
}
