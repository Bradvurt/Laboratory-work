#include "base.h"

int main() {

    FILE *f;

    f = fopen("/home/bradvurt/Рабочий стол/Laboratory-work/Курсовой проект 6/BD.bin", "rb");
    fprintf(stdout, "+---------------+--------+---+-----+------+----------+-------------+\n");
    fprintf(stdout, "|    Surname    |Initials|Sex|Class|Letter|University| Profession  |\n");
    graduate s;
    while (get_graduate(&s, f) == 0) {
        fprintf(stdout, "+---------------+--------+---+-----+------+----------+-------------+\n");
        fprintf(stdout, "|%-15s|   %s   | %s |%-5s|%-6s|%-10s|%-13s|\n", s.surname, s.initials, s.sex, s.class, s.letter, s.university, s.profession);
    }
    fprintf(stdout, "+---------------+--------+---+-----+------+----------+-------------+\n");
    fclose(f);
    return 0;
}

