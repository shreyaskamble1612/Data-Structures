#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include <math.h>

// Function to hash the alphanumeric key
void hash(char key[], int size, int maxAddr, int *addr) {
    int looper, i;

    // Initialize looper and addr
    looper = 0;
    *addr = 0;

    // Hash the key
    for (i = 0; i < size; i++) {
        // Ignore spaces
        if (!isspace(key[i])) {
            // Add character to address
            *addr += key[i];

            // Rotate addr 12 bits right
            *addr = (*addr >> 12) | (*addr << (32 - 12));
        }
    }

    // Test for negative address
    if (*addr < 0) {
        *addr = abs(*addr);
    }

    // Take modulo with maxAddr
    *addr = *addr % maxAddr;
}

int main() {
    char *key;
    scanf("%s",key);
    int size = strlen(key) - 1;  // Size of the key excluding the null terminator
    int maxAddr = 100;  // Maximum possible address
    int addr;

    // Call the hash function
    hash(key, size, maxAddr, &addr);

    // Display the hashed address
    printf("Hashed Address: %d\n", addr);

    return 0;
}
