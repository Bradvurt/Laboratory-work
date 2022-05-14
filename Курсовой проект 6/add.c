#include "base.h"

int main() {

    FILE *f;
    f = fopen("/home/bradvurt/Рабочий стол/Laboratory-work/Курсовой проект 6/BD.bin", "ab");

    graduate *s = malloc(sizeof(graduate));
    bool modifying = true;
    while(modifying) {
        fprintf(stdout, "Enter graduate surname:\n");
        fscanf(stdin, "%s", s->surname);
        fwrite(s->surname, sizeof(char), MAXCHAR, f);
        fprintf(stdout, "Enter graduate initials:\n");
        fscanf(stdin, "%s", s->initials);
        fwrite(s->initials, sizeof(char), MAXCHAR, f);
        fprintf(stdout, "Enter graduate sex: M (male) or W (female)\n");
        fscanf(stdin, "%s", s->sex);
        fwrite(s->sex, sizeof(char), MAXCHAR, f);
        fprintf(stdout, "Enter graduate class:\n");
        fscanf(stdin, "%s", s->class);
        fwrite(s->class, sizeof(char), MAXCHAR, f);
        fprintf(stdout, "Enter graduate class letter:\n");
        fscanf(stdin, "%s", s->letter);
        fwrite(s->letter, sizeof(char), MAXCHAR, f);
        fprintf(stdout, "Enter graduate university:\n");
        fscanf(stdin, "%s", s->university);
        fwrite(s->university, sizeof(char), MAXCHAR, f);
        fprintf(stdout, "Enter graduate profession:\n");
        fscanf(stdin, "%s", s->profession);
        fwrite(s->profession, sizeof(char), MAXCHAR, f);
        fprintf(stdout, "Graduate with surname %s added\n", s->surname);
        fprintf(stdout, "Add new graduate? (yes or no)\n");
        char str[MAXCHAR];
        fscanf(stdin, "%s", str);
        if(strcmp(str, "no") == 0) modifying = false;
    }
    fprintf(stdout, "End modifying table\n");
    fclose(f);

    return 0;
}
