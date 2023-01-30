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
    for (int i = 1; i < len - 1; i++)
    {
        symbol = str[i];
        if ((symbol == 'A') || (symbol == 'a') || (symbol == 'E') || (symbol == 'e') || (symbol == 'I') || (symbol == 'i') || (symbol == 'O') || (symbol == 'o') || (symbol == 'U') || (symbol == 'u'))
        {
            numVowel++;
            numTotal++;
        }
        else if (isalpha(symbol) && symbol != ' ')
        {
             numConsonant++;
            numTotal++;
        }
    }
    printf("Vowels = %d (%2.2f%c), Consonants = %d (%2.2f%c), Total = %d\n", numVowel, ((double)numVowel / (double)numTotal) * 100, 37, numConsonant, ((double)numConsonant / (double)numTotal) * 100, 37, numTotal);
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
 * Prints a histogram of the letter frequencies. Looks stretched because of tabs. W/o tabs it gets misaligned
 * when there's more input.
 */
void displayHistogram(int hist[], int maxFreq)
{
    // vertical printing *****
    int count = maxFreq;
    for (int i = count; i > 0; i--) // print * as necessary and ' ' when not >=
    {
        for (int j = 0; j < ALPHABET_SIZE; j++)
        {
            if (hist[j] >= i)
            {
                printf("*\t");
            }
            else
            {
                printf(" \t");
            }
        }
        printf("\n");
    }

    // the horizontal printing tango
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        printf("%c\t", 97 + i);
    }
    printf("\n"); // don't bully me too hard
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        printf("%d\t", hist[i]);
    }
    printf("\n");
}
