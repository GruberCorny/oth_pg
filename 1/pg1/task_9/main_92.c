#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define lenth 100

void eingeabe(char *string){
    printf("Enter a string : ");
    fgets(string, lenth, stdin);
}

void umderehen(char *string, char *stringum){
    string = string +(lenth-1);
    for (int i = 0;i < lenth; i++){
        *stringum = *string;
        stringum += 1;
        string -= 1;
    }
}
void ausgabe(char *stringum){
    printf("\nder umgedrehte string is:");
    for (int i = 0; i < lenth; i++){
        stringum += 1;
        printf("%c", *stringum);
    }
}
void lehrzeichenweg(char *string){
    char funktionsstring[lenth] = {0};
    char *zeigerfunktionsstring = funktionsstring;
    int o = 0;
    for (int i = 0; i < lenth; i++){
        if (isalpha(*string) != 0){
            *zeigerfunktionsstring = *string;
            zeigerfunktionsstring += 1;
            o++;
        }
        string += 1;
    }
    for (int i = 0; i < lenth; i++){
       *string = *funktionsstring;
       string += 1;
       zeigerfunktionsstring += 1;
    }
}
void palindrom(char *string, char *stringum){
    unsigned long o = 0;
    for (int i = 0; i < strnlen(string, lenth); i++){
        if (*string == *stringum){
            o++;
        }
        if (o == strnlen(string, lenth)){
            printf("\ndieser ist ein palindrom\n");
        }
        string += 1;
        stringum += 1;
    }
}
int main(){
    char string[lenth] = {'0'};
    char stringumgedreht[lenth] = {'0'};
    char *zeigerstring = string;
    char *zeigerstringumgedreht = stringumgedreht;
    eingeabe(zeigerstring);
    umderehen(zeigerstring, zeigerstringumgedreht);
    ausgabe(zeigerstringumgedreht);
    lehrzeichenweg(zeigerstring);
    lehrzeichenweg(zeigerstringumgedreht);
    palindrom(zeigerstring, zeigerstringumgedreht);

    return 0;
}