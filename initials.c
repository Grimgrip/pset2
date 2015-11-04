#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

void getInitials (string name)
{
    if(!isspace(name[0]))
        printf("%c", toupper(name[0]));
    
    for(int i = 0; i < strlen(name); i++)
    {
        if(name[i] == ' ' && !isspace(name[i + 1]))
            printf("%c", toupper(name[i + 1]));
    }   

    printf("\n");
}

int main(void)
{
    string name = GetString();
    getInitials(name);
}
