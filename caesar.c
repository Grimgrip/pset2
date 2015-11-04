#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void caesar (string key)
{
    //if k > 26, k = k - 26
    
    string decrypText;
    int textLength;
    int k = atoi(key);
    
    //printf("Please enter the string you wanted encrypted with the key of %i: ", k);
    decrypText = GetString();
    textLength = strlen(decrypText);
    
    for (int i = 0; i < textLength; i++)
    {
        if(isalpha(decrypText[i]))
        {
            if(islower(decrypText[i]))
                printf("%c", ((((decrypText[i] - 97)+k)%26)+97));
            else
                printf("%c", ((((decrypText[i] - 65)+k)%26)+65));
        }
        else
            printf("%c", decrypText[i]);
    }
    printf("\n");
}

int main(int argc, string argv[])
{
    string key;
    
    if(argc == 2)
    {
        key = argv[1];
        caesar(key);
        return 0;
    }
    else if(argc > 2)
    {
        printf("Program only takes one argument. Calm down.\n");
        return 1;
    }
    else
    {
        printf("No argument was given. Try again.\n");
        return 1;
    }
}

