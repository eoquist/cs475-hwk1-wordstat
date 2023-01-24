/*
 * histo.c
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "defs.h"
#include "stats.h"

// TODO: function definitions for dealing with histogram below
/**
 * Prints frequencies of vowels and consonants along with the total letter count in number and percentage format.
 * @param str to count letters and categorize into vowels and consonants
 */
void getFrequency(char str[])
{
    // do counting and all that jazz
    int numVowel = 0;
    int numConsonant = 0;
    int numTotal = 0;

    int len = strlen(str);
    char symbol;
    for (int i = 0; i < len; i++)
    {
        symbol = str[i];
        if((symbol == 'A') || (symbol == 'a') || (symbol == 'E') || (symbol == 'e') || (symbol == 'I') || (symbol == 'i') || (symbol == 'O') || (symbol == 'o') || (symbol == 'U') || (symbol == 'u')){
            numVowel++;
            numTotal++;
        }
        else if(isalpha(symbol)){
            numConsonant++;
            numTotal++;
        }
    }

    float vowelFreq = numVowel / numTotal;
    float consonantFreq = numConsonant / numTotal;

    printf("Vowels = %d (%2.2f), Consonants = %d (%2.2f), Total = %d\n", numVowel, vowelFreq, numConsonant, consonantFreq, numTotal);
}

/**
 * Prints the word count
 * @param str to tokenize by whitespace to count words
 */
void wordCount(char str[])
{
    int numWords = 0;
    char *token = strtok(str, " ");
    while (token != NULL)
    {
        ++numWords;
        token = strtok(NULL, " ");
    }

    printf("Total word count: %d", numWords);
}

/**
 * Prints a histogram of the letter frequencies.
 */
void displayHistogram(int hist[])
{
    printf("print histogram here :)\n");
}