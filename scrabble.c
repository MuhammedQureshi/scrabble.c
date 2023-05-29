#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if(score1 > score2) // Checks if Player 1's score is greater than Player 2's score
    {
        printf("Player 1 Wins!\n");
    }
    else if (score1 < score2) // Checks if Player 2's score is greater than Player 1's score
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tied!\n"); // If both scores are equal, it's a tie, so print "Tied!"
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int tpoints = 0; //total points will be stored in this variable

    for (int i = 0; i < strlen(word); i++) // Iterates over each character in the word
    {
        int letterIndex; // Index of each letter in the POINTS array

        if(isupper(word[i])) // Checks if the word is uppercase
        {
            letterIndex = word[i] - 'A'; // Calculate the index based on ASCII value
            tpoints += POINTS[letterIndex]; // Adds the corresponding points to the total score
        }

        else if(islower(word[i])) // Checks if the word is lowercase
        {
            letterIndex = word[i] - 'a'; // Calculate the index based on ASCII value
            tpoints += POINTS[letterIndex]; // Adds the corresponding points to the total score
        }
    }
    return tpoints; // Return the total score for the word

}
