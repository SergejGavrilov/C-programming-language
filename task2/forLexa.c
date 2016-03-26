
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct person{
    char *name;
    char *tel;
    char *checkname;
    char *chektel;
    struct person *next;
    int id;
};

struct person *head = NULL;
struct person *tail = NULL;

void add(struct person *per){
    (tail->next) = (struct person*)malloc(sizeof(struct person));
    tail = tail->next;
    tail->id = per->id;
  //  tail->name = per->name;
  //  tail->tel = per->tel;
    tail->next = NULL;
}

void readFromFile(FILE *file, struct person *per){
    while (!feof(file)){
            fscanf(file, "%d",  &(per->id));
            add(per);
        }

}

int main(int argc, char *argv[])
{
    struct person per;
    per.next = NULL;
    struct person book;
    book.next = NULL;

    head = &book;
    tail = &book;
    FILE *file;

    file = fopen(argv[1], "r");
    if (file == NULL){
        printf("new file created \n");
        file = fopen(argv[1], "w");
    }else{
        readFromFile(file, &per);
    }

    struct person *iter = head;

    while ((iter->next) != NULL){
        printf("%d", iter->id);
    }
    char *command;

    while(1){
        scanf("%s", command);
        if(!strcmp(command, "exit")){
           break;
        }
    }
    return 0;
}
