#include <stdio.h>
#include <stdlib.h>

#define alphabet 26

void countCharacters(FILE *input, int characterFrequency[alphabet]);
void printCharacters(FILE *output, int characterFrequency[alphabet]);

int main(int argc, char *argv[]) {
    
    FILE *input, *output;
    // Initialize an array of character frequency with zeros
    int characterFrequency[alphabet] = {0};

    // Check if the number of arguments is not 3
    // or if opening input or output fails.
    if(argc != 3 || !(input = fopen(argv[1], "r")) ||
       !(output = fopen(argv[2], "w"))) 
    {
        printf("Error opening files.\n");
        printf("Correct usage of the program:"
               " %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    countCharacters(input, characterFrequency);
    printCharacters(output, characterFrequency);

    fclose(input);
    fclose(output);

    printf("Operation completed successfully.\n");

    return 0;
}

/**
 * This function counts the frequency of letters in the input and updates a frequency array.
 *
 * @param input: Pointer to the input file.
 * @param characterFrequency: An array to store the frequency of letters.
 */
void countCharacters(FILE *input, int characterFrequency[alphabet]) {
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        if(ch >= 'A' && ch <= 'Z') {
            characterFrequency[ch - 'A']++;
        } else if (ch >= 'a' && ch <= 'z')
            characterFrequency[ch - 'a']++;
    }
}

/**
 * This function prints the frequency of letters to an output file.
 *
 * @param output: Pointer to the output file.
 * @param characterFrequency: An array containing the frequency of letters.
 */
void printCharacters(FILE *output, int characterFrequency[alphabet]) {
    for (int i = 0; i < alphabet; i++) {
        if (characterFrequency[i] > 0) {
            fprintf(output, "%c: #%d\n", 'A' + i, characterFrequency[i]);
        }
    }
}
