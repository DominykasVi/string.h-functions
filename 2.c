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

char *string_cpy (char *destination, char *source){//galima apsibrezti papildoma funkcionaluma, kaip tikrinti ar ne NULL,
    // ir ar ilgiai sutampa, bet strcpy to nedaro ir buna segmentation fault jeigu kazkas nesutampa, tokio funkcionalumo neduoda
    size_t size = string_len(source);
    size_t i = 0;
    for( i = 0; i < size; ++i){
        destination[i] = source[i];
    }
    *(destination+i) = '\0';
    return destination;
}

char *string_cat(char *destination, char *source){
    size_t dest_len = string_len(destination);
    size_t sour_len = string_len(source);
    size_t size = dest_len + sour_len;
    char *both =(char*) calloc((size+1) , sizeof(char));
    size_t i = 0;
    for(i = 0; i < dest_len; ++i){
        both[i] = destination[i];
    }
    size_t j = 0;
    for(j = 0; j < sour_len; ++j){
        both[j+i] = source[j];
    }
    //both[j+i+1] = '\0';
    return both;
}

int string_cmp( char *string1,  char *string2){
    while(*string1 != '\0' || *string2!= '\0'){
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
    strcpy(textCopy, text);
    assert(strcmp(textCopy , string_cpy(text1, text)) == 0);
   // printf("%s\n%s", text1, text);
    strcpy(textCopy, text3);
    assert(strcmp(textCopy , string_cpy(text1, text3)) == 0);
    string_cpy(text1, "TestText1");
    assert(strcmp("TestText1" , text1) == 0);
    assert(strcmp("TestText" , string_cpy(text1, "TestText")) == 0);

    strcpy(text, "Hello!");
    strcpy(text1, "Hello, world!");
    strcpy(text3, "FfBZCxgUMBm4qxfikmYo\n"
                  "OV6sSTSTqBLhMIUFlAKz\n"
                  "jQbnKz8evOP2cwv9fdnx\n"
                  "hkEuWGJwVEH3VhikveCl\n"
                  "QC3NYwtG6FRdC2gqflo0");
    assert(strcmp(strcat(text1, text) , string_cat(text1, text)) == 0);
    assert(strcmp(strcat(text1, text3) , string_cat(text1, text3)) == 0);
    text3 = string_cat(text, text1);
    assert(strcmp(strcat(text, text1) , text3) == 0);
    assert(strcmp("TestText" , string_cat("Test", "Text")) == 0);
    text = NULL;
    assert(strcmp("Text" , string_cat(text, "Text")) == 0);
    assert(strcmp("Text" , string_cat("Text", text)) == 0);

    text = (char*) calloc(7, sizeof(char ));
    strcpy(text, "Hello!");
    strcpy(text1, "Hello!");
    strcpy(text3, "NO no no");
    assert(strcmp(text, text1) == string_cmp(text, text1));
    //printf("%d %d", strcmp(text, text3), string_cmp(text, text3));
    assert(strcmp(text, text3) == string_cmp(text, text3));
    int number = string_cmp(text, text1);
    assert(number == strcmp(text, text1));
    assert(string_cmp("Ab", "A") == strcmp("Ab", "A"));
    assert(string_cmp("A", "A") == strcmp("A", "A"));
    return 0;
}
