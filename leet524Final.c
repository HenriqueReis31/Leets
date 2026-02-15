#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Sub(char *s, char *w) {
    while (*s && *w) {
        if (*s == *w){
        w++;
        }
        s++;
    }
    return *w == '\0';
}

int Comparation_String(const void *c, const void *d){
     char *c1 = *(char **)c;
    char *d2 = *(char **)d;

    int len_1 = strlen (c1);
    int len_2 = strlen (d2);

    if(len_1 != len_2){
      return len_2 - len_1;
    }   
    else{
     return strcmp (c1,d2);
    }

}

char* findLongestWord(char* s, char** dictionary, int dictionarySize) {
    qsort(dictionary, dictionarySize, sizeof(char*), Comparation_String);
    
    for(int i = 0; i<dictionarySize; i++){
       if (Sub(s, dictionary[i]))
            return dictionary[i];
        }
    return "";
}



 