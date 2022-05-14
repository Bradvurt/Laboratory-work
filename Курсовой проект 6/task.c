#include "base.h"

bool is_int(const char *str) {
    while (*str) {
        if (*str < '0' || *str > '9')
            return false;
        str++;
    }
    return true;
}

void print_graduate(graduate *s) {
    fprintf(stdout, "+---------------+--------+---+-----+------+----------+-------------+\n");
    fprintf(stdout, "|%-15s|   %s   | %s |%-5s|%-6s|%-10s|%-13s|\n", s->surname, s->initials, s->sex, s->class, s->letter, s->university, s->profession);
}

int main(int argc, const char * argv[]) {

    FILE *f;

    f = fopen("/home/bradvurt/Рабочий стол/Laboratory-work/Курсовой проект 6/BD.bin", "rb");
    char p[MAXCHAR] = "";
    bool f_flag = false;
    for(int i = 1; i < argc; i++) {
        if(strcmp(argv[i], "-f") == 0) {
            fprintf(stdout, "+---------------+--------+---+-----+------+----------+-------------+\n");
            fprintf(stdout, "|    Surname    |Initials|Sex|Class|Letter|University| Profession  |\n");
            f_flag = true;
        }
        if(strcmp(argv[i], "-p") == 0) {
            strcpy(p, argv[i+1]);
            i++;
        }
    }
    int ch;
    if (is_int(p)) {
        ch = atoi(p);
        if (ch > 11) {
            printf("Error");
            return 0;
        }
    }
    graduate s;
    int count_10 = 0;
    int count_p = 0;
    while(get_graduate(&s, f) == 0) {
        if(strcmp(s.class, p) == 0) {
            count_p += 1;
            if(f_flag) print_graduate(&s);
        }
        else{
            if(strcmp(s.class, "10") == 0) {
                count_10 += 1;
            }    
        }
    }
    if(f_flag) fprintf(stdout, "+---------------+--------+---+-----+------+----------+-------------+\n");
    fprintf(stdout, "%d %d\n", count_p, count_10);
    if (count_p > count_10) {
        fprintf(stdout, "There are %d more %d grade students than 10\n", count_p - count_10, ch);
    }
    else if (count_p == count_10) {
        fprintf(stdout, "Students in grades 10 and %d equally\n", ch);
    }
    else {
        fprintf(stdout, "There are %d more 10 grade students than %d\n", count_10 - count_p, ch);
    }
    fclose(f);
    return 0;
}

