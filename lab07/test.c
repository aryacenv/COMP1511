#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int encrypt(int character, int shift)
{
                // here we get to see where the '%' operator is used
                char c = character;
                
                if(islower(c))
                {
                        if(character+shift>122)
                                return (character-97+shift)%26+97;
                        else
                                return (character+shift);
                }
                if(isupper(c))
                {
                        if(character+shift>90)
                                return (character-65+shift)%26+65;
                        else
                                return (character+shift);
                }
                        
        return character;
}
int main(int argc, char** argv)
{
        
        char line[300];
        
        // inappropriate number of arguments are not accepted
    if(argc>2)
    {
        printf(" Seems like you have given more than a single command line argument!\n ");
        exit(0);
        }
    
    // convert string to number
    int shift = atoi(argv[1]);
    
    if(shift<0)
    {
        shift = -1*shift;
        shift = 26 - shift%26;
        }
    while(1)
    {
        // read a line from user
        scanf("%[^\n]",line);
        
        // if the entered line is empty, we understand that
        // the uer is no more inputting any sentences, thus we stop.
        if(getchar()==EOF)
                break;
        
        int i = 0;
        char c;
        
        // encrypt each character in the sentence
        while(line[i]!='\0')
        {
                c = encrypt(line[i],shift);
                printf("%c",c);
                ++i;
                }
                printf("\n");
        fflush(stdin);
        }

    return 0;
}
