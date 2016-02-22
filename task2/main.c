#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
    char name[50], tel[20], checkname[50];
    int id;
};

typedef struct vector{
    struct person *p;
    int vsize;
    int currentsize;
};

void vecInit(struct vector *vec){
    vec->p = (struct hum*)malloc(10 * sizeof(struct person));
    vec->vsize = 10;
    vec->currentsize = 0;

}
int main(int argc, char *argv[])
{
    struct person per;
    struct vector book;
    char command[30];
    char name[50], tel[50];
    int j;
    FILE *file;
    /*file = fopen(argv[1], "r");
    if (file == NULL){
        file = fopen(argv[1], "w");
        printf("new file created \n");
    }else{
        printf("file has been overwritten \n");
        file = fopen(argv[1], "w");
    }*/
    file = fopen("in.txt", "w");
    vecInit(&book);
    int i = 0;
    while(1){
        scanf("%s", &command);
        if (!strcmp(command, "create")){

            scanf("%s %s \n", &book.p[i].name, &book.p[i].tel);
            fprintf(file, "%s %s \n", &book.p[i].name, &book.p[i].tel);
            printf("%d \n", i);
            i++;

        }else if(!strcmp(command, "exit")){
            for (j = 0; j <= i; j++){
                printf("%s %s \n", book.p[j].name, book.p[j].tel);
            }
            break;
        }

    }
    return 0;
}
