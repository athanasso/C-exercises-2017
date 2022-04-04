#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void changeChars(char[], int);
 
int main()
{
    char* letters;
    int n, i;
   
    printf("Strings to read: ");
    scanf("%d", &n);
   
    for (i = 0; i < n; i++) {
        fflush(stdin);
       
        letters = (char*)malloc(255);
       
        printf("string %d: ", i + 1);
        gets(letters);
        changeChars(letters, strlen(letters));
        printf("After function: %s\n", letters);
       
        free(letters);
    }
   
    return 0;
}

void changeChars(char letters[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (letters[i] >= 65 && letters[i] <= 90) {
            letters[i] += 32;
        }
        else if (letters[i] >= 97 && letters[i] <= 122) {
            letters[i] -= 32;
        }
    }
}