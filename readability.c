#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letters(string input);
int words(string input);
int sentences(string input);

int main(void)
{

    // Prompt the user for some text

    string input = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text

    // Letters
    int letterCount = letters(input);
    //  printf("Letters: %i\n", letterCount); // Debugging code to show total valid letters

    // Words
    float wordCount = words(input);
    //  printf("Words: %f\n", wordCount);

    // Sentences
    int sentenceCount = sentences(input);
    //  printf("Sentences: %i\n", sentenceCount);

    // Compute the Coleman-Liau index

    float L = (letterCount / wordCount) * 100.0;

    float S = (sentenceCount / wordCount) * 100.0;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Print the grade level

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }
}
int letters(string input)
{
    int letterCount = 0;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        char c = input[i];

        if (islower(c) || isupper(c))
        {
            letterCount++;
        }
        else
        {
            continue;
        }
    }

    return letterCount;
}

int words(string input)
{
    int spaceCount = 0;
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        char c = input[i];
        if (isspace(c))
        {
            spaceCount++;
        }
        else
        {
            continue;
        }
    }
    return spaceCount + 1;
}

int sentences(string input) // . , !, ? - indicates a sentence
{
    int sentenceCount = 0;
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        char c = input[i];
        if (c == '.' || c == '!' || c == '?')
        {
            sentenceCount++;
        }
        else
        {
            continue;
        }
    }
    return sentenceCount;
}
