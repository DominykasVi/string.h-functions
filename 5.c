#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

void *memory_cpy(void *dest,  void * src, size_t n){
    if(n < 0){
        n = 0;
    }
    void *start = dest;
    for(int i = 0; i < n; ++i){
        dest = src;
        ++dest;
        ++src;
    }
    return start;
}

int memory_cmp( void *str1, void *str2, size_t n){
    unsigned char *p = str1;
    unsigned char *q = str2;

    while (n > 0)
    {
        if (*p > *q){
            return 1;
        }
        if (*p != *q){
            return -1;
        }
        n--;
        p++;
        q++;
    }
    return 0;

}

void *memory_set(void *str, int c, size_t n){
    unsigned char *p = str;
    for(int i = 0; i < n; ++i){
        *p = c;
        ++str;
    }
    return p;
}

void *memory_chr(void *str, int c, size_t n){
    unsigned char *p = str;
    for(int i = 0; i < n; ++i){
        if(*p == c){
            return p;
        }
        ++p;
    }
    return NULL;
}

int main() {
    char *text = (char*) calloc(7, sizeof(char ));
    strcpy(text, "Hello!");
    char *text1 = (char*) calloc(14, sizeof(char ));
    strcpy(text1, "Hello, world!");

    assert(memcpy(text1, text, 6) == memory_cpy(text1, text, 6));
    assert(memcpy(text, text1, 6) == memory_cpy(text, text1, 6));
    assert(memcpy(text, text1, 0) == memory_cpy(text, text1, 0));
    assert(memcpy(text, text1, 20) ==  memory_cpy(text, text1, 20));

    //printf("%d %d", memcmp(text, text1, 5), memory_cmp(text, text1, 5));
    assert(memcmp(text, text1, 5) == memory_cmp(text, text1, 5));
    assert(memcmp(text, text1, 6) == memory_cmp(text, text1, 6));
    assert(memcmp(text, text1, 0) == memory_cmp(text, text1, 0));
    assert(memcmp(text, text1, 20) == memory_cmp(text, text1, 20));
    int number = memory_cmp(text, text1, 5);
    assert(number == memcmp(text, text1, 5));
    //printf("%d %d", memcmp("Ab", "A", 2), memory_cmp("Ab", "A", 2));
    assert(memcmp("Ab", "A", 2) == memory_cmp("Ab", "A", 2));
    assert(memory_cmp("A", "A", 1) == memcmp("A", "A", 1));

    //printf("%s %s", memset(text, '$', 3), memory_set(text, '$', 3));
    assert(memset(text, '$', 3) == memory_set(text, '$', 3));
    assert(memset(text, '$', 0) == memory_set(text, '$', 0));
    assert(memset(text, '$', 30) == memory_set(text, '$', 30));
   // assert(memset(text, "", 30) == memory_set(text, "", 30)); // undefined behaviour
    //assert(memset("text", '0', 30) == memory_set("text", '0', 30));//memset crashes

    assert(memchr(text, 'e', 5) == memory_chr(text, 'e', 5));
    assert(memchr(text1, 'l', 5) == memory_chr(text1, 'l', 5));
    assert(memchr(text, 'e', 0) == memory_chr(text, 'e', 0));
    assert(memchr(text, 'e', 30) == memory_chr(text, 'e', 30));
    assert(memchr(text, 'A', 30) == memory_chr(text, 'A', 30));

    return 0;
}
