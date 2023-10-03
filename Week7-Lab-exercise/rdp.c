#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool E(), Edash(), T(), Tdash(), F();

char *ip;
char string[50];

int main()
{
    printf("Enter the string\n");
    scanf("%s", string);
    ip = string;
    printf("\n\nInput\tAction\n--------------------------------\n");

    if (E() && *ip == '\0')
    { // Check if the entire input string is parsed
        printf("\n--------------------------------\n");
        printf("String is successfully parsed\n");
    }
    else
    {
        printf("\n--------------------------------\n");
        printf("Error in parsing String\n");
    }
}

bool E()
{
    printf("%s\tE->TE' \n", ip);
    if (T())
    {
        return Edash();
    }
    return false;
}

bool Edash()
{
    if (*ip == '+')
    {
        printf("%s\tE'->+TE' \n", ip);
        ip++;
        if (T())
        {
            return Edash();
        }
        return false;
    }
    else
    {
        printf("%s\tE'->^ \n", ip);
        return true; // Epsilon production
    }
}

bool T()
{
    printf("%s\tT->FT' \n", ip);
    if (F())
    {
        return Tdash();
    }
    return false;
}

bool Tdash()
{
    if (*ip == '*')
    {
        printf("%s\tT'->*FT' \n", ip);
        ip++;
        if (F())
        {
            return Tdash();
        }
        return false;
    }
    else
    {
        printf("%s\tT'->^ \n", ip);
        return true; // Epsilon production
    }
}

bool F()
{
    if (*ip == '(')
    {
        printf("%s\tF->(E) \n", ip);
        ip++;
        if (E())
        {
            if (*ip == ')')
            {
                ip++;
                return true;
            }
        }
        return false;
    }
    else if (*ip == 'i')
    {
        ip++;
        printf("%s\tF->id \n", ip);
        return true;
    }
    return false;
}
