#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"

int main() {
    FILE *f = fopen("/home/bradvurt/Рабочий стол/Laboratory-work/Курсовой проект 6/BD.bin", "wb");

    char surnames[][MAXCHAR] = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor", "Anderson", "Thomas", "Jackson", "White", "Harris", "Martin", "Thompson", "Wood", "Lewis", "Scott"};
    char initial[][MAXCHAR] = {"AB", "BC", "CD", "DE", "EF", "FG", "GH", "HI", "IJ", "GK", "KL", "LM", "MN", "NO", "OP", "PQ", "QR", "RS", "ST", "TU"};
    char sex[][MAXCHAR] = {"M", "W"};
    char class_number[][MAXCHAR] = {"1", "2", "3", "4", "5", "6", "7","8", "9", "10", "11"};
    char class_letter[][MAXCHAR] = {"A", "B", "C", "D", "E"};
    char university[][MAXCHAR] = {"Harvard", "MIT", "Stanford", "Cambridge", "CIT", "Oxford", "Princeton", "Chicago", "TUM", "MAI"};
    char profession[][MAXCHAR] = {"designer", "photographer","composer", "conductor", "programmer", "worker","tailor", "carpenter", "teacher", "doctor", "surgeon", "psychiatrist", "policeman", "fireman", "geologist", "clown", "banker", "accountant", "mathematician", "physicist"};
    srand(time(0));
    for(int i = 1; i <= 10; i++) {
        fwrite(surnames[rand()%20], sizeof(char), MAXCHAR, f);
        fwrite(initial[rand()%20], sizeof(char), MAXCHAR, f);
        fwrite(sex[rand()%2], sizeof(char), MAXCHAR, f);
        fwrite(class_number[rand()%11], sizeof(char), MAXCHAR, f);
        fwrite(class_letter[rand()%5], sizeof(char), MAXCHAR, f);
        fwrite(university[rand()%10], sizeof(char), MAXCHAR, f);
        fwrite(profession[rand()%20], sizeof(char), MAXCHAR, f);
    }
    fclose(f);
    return 0;
}
