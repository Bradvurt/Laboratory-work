#ifndef base_h
#define base_h
#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#define MAXCHAR 128

typedef struct graduate{
    char surname[MAXCHAR];
    char initials[MAXCHAR];
    char sex[MAXCHAR];
    char class[MAXCHAR];
    char letter[MAXCHAR];
    char university[MAXCHAR];
    char profession[MAXCHAR];
}graduate;

int str_write(char *s, FILE *f) {
    if(fwrite(s, sizeof(s[0]), MAXCHAR, f) != MAXCHAR) {
        printf("ERROR");
        return 1;
    }
    return 0;
}

int str_read(char *s, FILE *f) {
    if(fread(s, sizeof(s[0]), MAXCHAR, f) != MAXCHAR) {
        return 1;
    }
    return 0;
}

int get_graduate(graduate *s, FILE *f) {
    int a = 1;
    a = a * str_read(s->surname, f);
    a = a * str_read(s->initials, f);
    a = a * str_read(s->sex, f);
    a = a * str_read(s->class, f);
    a = a * str_read(s->letter, f);
    a = a * str_read(s->university, f);
    a = a * str_read(s->profession, f);
    return a;
}

#endif
