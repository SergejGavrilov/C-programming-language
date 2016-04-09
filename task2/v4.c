#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct person {
    char *name;
    char *tel;
    char *checkname;
    char *chektel;
    struct person *next;
    int id;
} person;

struct person *head = NULL;
struct person *tail = NULL;

void add(struct person *per) {
    tail->id = per->id;
    tail->name = per->name;
    //  tail->tel = per->tel;
    (tail->next) = (struct person *) malloc(sizeof(struct person));
    tail = tail->next;
    tail->next = NULL;
}

void readFromFile(FILE *file, struct person *per) {

    while (fscanf(file, "%d", &(per->id)) > 0) {
        per->name = read(file);
        per->tel = read(file);
        add(per);
    }

}

char *read(FILE *file) {
    int c;
    int bufSize = 30;
    int count = 0;
    char* buf = (char *) malloc(sizeof(char) * bufSize);
    while (1) {
        c = fgetc(file);
        if (c == EOF || c == " " || c == "\0" || c == "\n") {
            break;
        }
        if (count == bufSize) {
            bufSize *= 2;
            buf = realloc(buf, sizeof(char) * bufSize);
        }
        buf[count++] = c;
    }
}

int main(int argc, char *argv[]) {
    struct person per;
    per.next = NULL;
    struct person book;
    book.next = NULL;

    head = &book;
    tail = &book;
    FILE *file;

    file = fopen("in.txt", "r");
    if (file == NULL) {
        printf("new file created \n");
        file = fopen("in.txt", "w");
    } else {
        readFromFile(file, &per);
    }

    struct person *iter = head;

    while ((iter->next) != NULL) {
        printf("%d ", iter->id);
        iter = iter->next;
    }
    char command[30];

    while (1) {
        scanf("%s", command);
        if (!strcmp(command, "exit")) {
            break;
        }
    }
    return 0;
}
