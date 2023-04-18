#include <stdio.h>
#define MAX_STRING_LENGTH 20

int stringcomp(char string_one[MAX_STRING_LENGTH+1], char string_two[MAX_STRING_LENGTH+1])
{
    for(int i = 0; i < MAX_STRING_LENGTH; i++ )
    {
        if(string_one[i] != string_two[i])
        {
            return -1;
        }
    }
    return 0;
}

int main() {
 char stringone[MAX_STRING_LENGTH +1] = "Test ";
 char stringtwo[MAX_STRING_LENGTH +1] = "Test ";
 int gleich;

 // hier wird die Funktion aufgerufen:
gleich = stringcomp(stringone, stringtwo);
printf("gleich: %d ", gleich);

 return 0;
}