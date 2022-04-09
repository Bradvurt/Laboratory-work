#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "queue.h"

bool is_int(const char*str) {
    while(*str)  {
        if((*str< '0' || *str > '9') && *str != '-' && *str != '.')
            return false;
        *str++;
    }
    return true;
}


int main() {
    bool program_works = true;
    queue *q;
    q = init();
    while(program_works) {
        char menu[] = "0";
        while (!strcmp("0", menu)) {
            printf("What you want to do?\n1: Add new element\n2: Print queue\n3: Delete element\n4: Sort the queue\n5: Exit\n");
            scanf("%s", menu);
            if (!strcmp("1", menu)) {
                int input;
                char c[] = "";
                bool value_is_incorrect = true;
                while (value_is_incorrect) {
                    printf("Adding a new element, enter its value:\n");
                    scanf("%s", c);
                    if (is_int(c)) {
                        input = atoi(c);
                        value_is_incorrect = false;
                    } else {
                        printf("\nError, is not number!\n\n");
                    }
                }
                insert(q, input);
            } else if (!strcmp("2", menu)) {
                printf("\n");
                print(q);
                printf("\n");
            } else if (!strcmp("3", menu)) {
                removal(q);
            } else if (!strcmp("4", menu)) {
                q = sort(q);
            } else if (!strcmp("5", menu)) {
                printf("End of program.\n");
                program_works = false;
            } else {
                printf("\nError, incorrect input!\n\n");
            }
        }
    }
    delite(q);
    return 0;
}
