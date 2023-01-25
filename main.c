/*
 * main.c
 *
 *  Created on: Jan. 23, 2023
 *      Author: Emilee Oquist
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "defs.h"
#include "stats.h"
#include "menu.h"

/**
 * @brief Main function
 *
 * @param argc Ignore
 * @param argv Ignore
 * @return int
 */
int main(int argc, char *argv[])
{
	// declare and initialize the histogram
	int histogram[ALPHABET_SIZE];
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		histogram[i] = 0;
	}

	char endCondition = '#';
	int isComplete = 0;
	char str[MAX_INPUT_LEN];
	char tmp[MAX_INPUT_LEN]; // was having issues only using str
	int option = 0;

	// TODO: start by getting strings from users until # is input
	printf("Enter strings (%c to stop):\n", endCondition);
	while (isComplete == 0)
	{
		while ((tmp[0] != endCondition) && (strlen(tmp) != 2))
		{
			fgets(tmp, MAX_INPUT_LEN, stdin);
			if (tmp[0] != endCondition)
			{
				strcat(str, tmp);
			}
		}

		// TODO: after # is input, print menu options
		option = getMenuOption();
		while (option != 5)
		{
			if (option == 1) // vowel and consonant frequency
			{
				getFrequency(str);
				option = getMenuOption();
			}
			else if (option == 2) // word count
			{
				wordCount(str);
				option = getMenuOption();
			}
			else if (option == 3) // histogram
			{
				int len = strlen(str);
				for (int i = 0; i < len; i++)
				{
					str[i] = tolower(str[i]);
				}
				for (int i = 0; i < len; i++)
				{
					int letter = (int)str[i] - 97;
					if (isalpha(letter))
					{
						histogram[letter] = str[i];
					}
				}
				displayHistogram(histogram);
				option = getMenuOption();
			}
			else if (option == 4) // continue getting inputs
			{
				tmp[0] = '\0';
				printf("test tmp len %d", strlen(tmp)); // !!!
				while ((tmp[0] != endCondition) && (strlen(tmp) != 2))
				{
					fgets(tmp, MAX_INPUT_LEN, stdin);
					printf("option 4 chosen got input\n"); // !!!
					strcat(str, tmp);
				}
				option = getMenuOption();
			}
			else
			{
				printf("The option %d is invalid.\n", option);
				option = getMenuOption();
			}
		}
		if (option == 5)
		{
			printf("Exiting...\n");
			return 0; // signifies a normal exit --> a non-zero value indicates an error
		}
	}
}