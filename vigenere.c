#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void vigenere (string key)
{
    string decrypText;
    int tLength, kLength;
    string k = key;
    
    //printf("Please enter the string you wanted encrypted with the key of %s: ", k);
    decrypText = GetString();
    
    tLength = strlen(decrypText);
    kLength = strlen(k);
   
    for (int i = 0, j = 0; i < tLength; i++)
    {
        if(isalpha(decrypText[i]))
        {
           int keyRefVal, refVal;
           
           if (isupper(k[j % kLength]))
                keyRefVal = 65;
           else
                keyRefVal = 97;
                
           if (isupper(decrypText[i]))
                refVal = 65;
           else
                refVal = 97;    
           
           printf("%c", ((decrypText[i] - refVal + (k[j%kLength]) - keyRefVal) % 26 ) + refVal);
           
           j++;
        }
        else
            printf("%c", decrypText[i]);
    }
    printf("\n");
}

int main(int argc, string argv[])
{
    string key;
    
    if(argc != 2)
    {
        printf("Program accepts one, and only one, argument.\n");
        return 1;
    }
    
    for(int i = 0; i < strlen(argv[1]); i++)
    {
        if(!isalpha(argv[1][i]))
        {
            printf("Program only accepts characters belonging to the alphabet.\n");
            return 1;
        }
    }
    
    key = argv[1];
    vigenere(key);
    return 0;
    
    /*if(argc == 2)
    {
        key = argv[1];
        vigenere(key);
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
    }*/
}

