#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

size_t string_len(char *string){
    if (string == NULL){
        return 0;
    }
    size_t length = 0;
    for (size_t i = 0; string[i] != '\0'; ++i){
        length +=1;
    }
    return length;
}

char *stringn_cpy (char *destination, char *source, size_t n){
    if(n < 0){
        n = 0;
    }
    size_t size = string_len(source);
    size_t i = 0;
    for( i = 0; i < n; ++i){
        destination[i] = source[i];
    }
    *(destination+i) = '\0';
    return destination;
}

char *stringn_cat(char *destination, char *source, size_t n){
    if(n < 0){
        n = 0;
    }
    size_t dest_len = string_len(destination);
    size_t size = dest_len + n;
    char *both =(char*) calloc((size+1) , sizeof(char));
    size_t i = 0;
    for(i = 0; i < dest_len; ++i){
        both[i] = destination[i];
    }
    size_t j = 0;
    for(j = 0; j < n; ++j){
        if (source != NULL){
            both[j+i] = source[j];
        }
    }
    return both;
}

int stringn_cmp( char *string1,  char *string2, size_t n){
    for (int i = 0; i <n && *string1 != '\0' && *string2!= '\0'; ++i){
        if(*string1 > *string2) {
            return 1;
        }
        if(*string1 < *string2) {
            return -1;
        }
        ++string1;
        ++string2;
    }
    return 0;
}

int main() {
    char *text = (char*) calloc(7, sizeof(char ));
    strcpy(text, "Hello!");
    char *text1 = (char*) calloc(14, sizeof(char ));
    strcpy(text1, "Hello, world!");
    char *text3 = (char*) calloc(105, sizeof(char ));
    strcpy(text3, "FfBZCxgUMBm4qxfikmYo\n"
                  "OV6sSTSTqBLhMIUFlAKz\n"
                  "jQbnKz8evOP2cwv9fdnx\n"
                  "hkEuWGJwVEH3VhikveCl\n"
                  "QC3NYwtG6FRdC2gqflo0");

    char *textCopy = (char*) calloc(120, sizeof(char ));
    strncpy(textCopy, text, 5);
    assert(strcmp(textCopy , stringn_cpy(text1, text, 5)) == 0);
    strncpy(textCopy, text3, 20);
    assert(strcmp(textCopy , stringn_cpy(text1, text3, 20)) == 0);
    stringn_cpy(text1, "TestText1", 4);
    assert(strcmp("Test" , text1) == 0);
    assert(strcmp("TestText" , stringn_cpy(text1, "TestText", 8)) == 0);
    assert(strcmp("" , stringn_cpy(text1, "TestText", 0)) == 0);
    assert(strcmp("TestText" , stringn_cpy(text1, "TestText", 10)) == 0);

    strcpy(text, "Hello!");
    strcpy(text1, "Hello, world!");
    strcpy(text3, "FfBZCxgUMBm4qxfikmYo\n"
                  "OV6sSTSTqBLhMIUFlAKz\n"
                  "jQbnKz8evOP2cwv9fdnx\n"
                  "hkEuWGJwVEH3VhikveCl\n"
                  "QC3NYwtG6FRdC2gqflo0");
    assert(strcmp(strncat(text1, text, 5) , stringn_cat(text1, text, 5)) == 0);
    assert(strcmp(strncat(text1, text3, 20) , stringn_cat(text1, text3, 20)) == 0);
    text3 = stringn_cat(text, text1, 10);
    assert(strcmp(strncat(text, text1, 10) , text3) == 0);
    assert(strcmp("TestTex" , stringn_cat("Test", "Text", 3)) == 0);
    text = NULL;
    assert(strcmp("Text" , stringn_cat(text, "Text", 4)) == 0);
    text = NULL;
    assert(strcmp("Text" , stringn_cat("Text", text, 4)) == 0);
    text = (char*) calloc(7, sizeof(char ));
    strcpy(text, "Hello!");
    strcpy(text1, "Hello, world!");
    assert(strcmp(strncat(text1, text3, 0) , stringn_cat(text1, text3, 0)) == 0);
    assert(strcmp(strncat(text1, text3, 20) , stringn_cat(text1, text3, 20)) == 0);



    strcpy(text, "Hello!");
    strcpy(text1, "Hello, world!");
    strcpy(text3, "NO no no");
    assert(strncmp(text, text1, 5) == stringn_cmp(text, text1, 5));
    assert(strncmp(text, text3, 3) == stringn_cmp(text, text3, 3));
    int number = stringn_cmp(text, text1, 10);
    assert(number == strncmp(text, text1, 10));
    assert(stringn_cmp("Ab", "A", 1) == strncmp("Ab", "A", 1));
    assert(stringn_cmp("A", "B", 0) == strncmp("A", "B", 0));
    return 0;
}
