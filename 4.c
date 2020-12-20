#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

char *string_chr(char *str, int c){
    size_t len = strlen(str);
    for(int i = 0; i < len; ++i){
        if(*str == c){
            return str;
        }
        ++str;
    }
    return NULL;
}

char *string_rchr(char *str, int c){
    size_t len = strlen(str);
    str += len-1;

    for(int i = len; i > 0; --i){
        if(*str == c){
            return str;
        }
        --str;
    }
    return NULL;
}

char *string_str(char *haystack, char *needle){
    size_t len_h = strlen(haystack);
    size_t len_n = strlen(needle);
    int match = 0;
    if(strcmp(needle, "") == 0){
        return haystack;
    }
    for(int i = 0; i < len_h; ++i){
        if(haystack[i] == needle[0]){
            for(int j = 1; j < len_n; ++j){
                if(haystack[i+j] == needle[j]){
                    ++match;
                }
            }
            if(match == len_n - 1){
                return (haystack+i);
            }
        }
    }
    return NULL;
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
    assert(strcmp(strchr(text, 'l'), string_chr(text, 'l')) == 0);
    assert(strcmp(strchr(text1, ','), string_chr(text1, ',')) == 0);
    assert(strchr(text1, 'A') == string_chr(text1, 'A'));
    assert(strchr(text3, '0') == string_chr(text3, '0'));
    assert(strchr(text, 'H') == string_chr(text, 'H'));
    char *temp;
    temp = strchr(text1, 'e');
    assert(temp == string_chr(text1, 'e'));

    assert(strrchr(text, 'l') == string_rchr(text, 'l'));
    assert(strcmp(strrchr(text1, ','), string_rchr(text1, ',')) == 0);
    assert(strrchr(text1, 'A') == string_rchr(text1, 'A'));
    assert(strrchr(text3, '0') == string_rchr(text3, '0'));
    assert(strrchr(text, 'H') == string_rchr(text, 'H'));
    temp = strrchr(text1, 'e');
    assert(temp == string_rchr(text1, 'e'));

    assert(strstr(text, "el") == string_str(text, "el"));
    assert(strstr(text1, "world") == string_str(text1, "world"));
    assert(strstr(text3, "o0") == string_str(text3, "o0"));
    assert(strstr(text1, "He") == string_str(text1, "He"));
    assert(strstr(text1, "") == string_str(text1, ""));
    assert(strstr(text1, "A") == string_str(text1, "A"));
    return 0;
}
