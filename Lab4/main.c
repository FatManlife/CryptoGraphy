#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

enum {
       rows = 8, 
       cols = 7,
       k_size= 8,
       klen_b = 64,
       kplen_b = 56
    };

int main(){
    const int PC1[rows][cols] = {
        {57, 49, 41, 33, 25, 17,  9},
        { 1, 58, 50, 42, 34, 26, 18},
        {10,  2, 59, 51, 43, 35, 27},
        {19, 11,  3, 60, 52, 44, 36},
        {63, 55, 47, 39, 31, 23, 15},
        { 7, 62, 54, 46, 38, 30, 22},
        {14,  6, 61, 53, 45, 37, 29},
        {21, 13,  5, 28, 20, 12,  4}
    };

    unsigned char key[k_size];

    int choice;
    int ch;

    printf("1. Enter key\n2. Generate random key\nChoice: "); 

    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) { 
            puts("Invalid choice.");
        return 1; 
    } 

    while ((ch = getchar()) != '\n' && ch != EOF) {}

    if (choice == 1) {
        size_t length = 0;
        int valid = 1;

        printf("Enter exactly 8 ASCII characters: ");

        while ((ch = getchar()) != '\n' && ch != EOF) {
            if (length < k_size)
                key[length++] = (unsigned char)ch;
            else
                valid = 0;
        }

        if (!valid || length != k_size) {
            puts("Invalid key.");
            return 1;
        }

    } else {
        srand((unsigned int)time(NULL));

        for (size_t i = 0; i < k_size; i++)
            key[i] = (unsigned char)(rand() % 256);
    }

    system("clear");

    unsigned char keyb[klen_b];
    unsigned char key_plus[kplen_b];

    printf("PC-1:\n");

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++)
            printf("%3d", PC1[i][j]);

        printf("\n");
    }

    printf("\nOriginal: ");
    for (size_t i = 0; i < k_size; i++)
        printf("%c", key[i]);

    printf("\nHex k: ");
    for (size_t i = 0; i < k_size; i++)
        printf("%02X", key[i]);

    printf("\nBits k: ");
    for (size_t i = 0; i < k_size; i++) {
        unsigned char byte = key[i];
        for (int bit = 7; bit >= 0; bit--){
            keyb[i*8 + 7-bit] = (byte >>  bit) & 1;
            printf("%u", keyb[i*8 + 7-bit]);
        }
        printf(" ");
    }

    for(size_t ctr = 0 ,i = 0, i2 = rows/2; i < rows/2; i++, i2++){ 
        for(size_t j = 0; j < cols; j++, ctr++){
            key_plus[ctr] =  keyb[PC1[i][j] - 1];
            key_plus[kplen_b/2 + ctr] =  keyb[PC1[i2][j] - 1];
        } 
    }

    printf("\nBits k+: ");
    for(size_t i = 0, ctr = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++, ctr++)
            printf("%u", key_plus[ctr]);
        printf(" ");
    }

    printf("\n");

    return 0;
}