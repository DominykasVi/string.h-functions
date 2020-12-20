#include <stdio.h>
#include <string.h>
#include <assert.h>

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

int main() {
    char text[7];
    strcpy(text, "Hello!");
    char text1[14];
    strcpy(text1, "Hello, world!");
    char *text2 = NULL;
    char text3[105];
    strcpy(text3, "FfBZCxgUMBm4qxfikmYo\n"
                  "OV6sSTSTqBLhMIUFlAKz\n"
                  "jQbnKz8evOP2cwv9fdnx\n"
                  "hkEuWGJwVEH3VhikveCl\n"
                  "QC3NYwtG6FRdC2gqflo0");
    assert(6 == string_len(text));
    assert(13 == string_len(text1));
    assert(0 == string_len(text2));
    assert(104 == string_len(text3));
    return 0;
}
