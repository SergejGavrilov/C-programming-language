#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct person{
    char name[50];
    char tel[20];
    char checkname[50], chektel[20];
    int id;
};

typedef struct vector{
    struct person *p;
    int vsize;
    int currentsize;
};

void toLowerCase(char* s){
    int i = 0;
    for (i = 0; i < strlen(s); i++){
        if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] -= 'A' - 'a';
    }

}
void cleanString(char* str)
{
    int i;
    for (i = 0; i < strlen(str); i++){
        str[i] = NULL;
    }
}

void read(char* first, char* second)  //функция читает телефон и записывает его Эбез шедухи"
{
    char c;
    int k;
    int i = 0;
    int j = 0;
    cleanString(first);
    cleanString(second);
    while ((c = getchar()) == ' '){}
    while (c != '\n')
    {
        first[i++] = c;
        if (c != '(' && c  != ')' && c != ' ' && c != '-')
        {
            second[j++] = c;
        }
        c = getchar();
    }
    for (k = i; k < strlen(first); k++) // При чтении образуется мусор, который нуэно уюирать
    {
        first[k] = NULL;
    }
    for (k = j; k < strlen(second); k++)  // При чтении образуется мусор, который нуэно уюирать
    {
        second[k] = NULL;
    }
            /*int i, j = 0;
    for (i = 0; i < strlen(first); i++){
        if (first[i] != '(' && first[i]  != ')' && first[i]  != ' ' && first[i] != '-'){
            second[j++] = first[i];

        }
    }
    for (i = j; j < strlen(second); j++){
        second[i] = NULL;
    }*/
}

void vecInit(struct vector *vec){
    vec->p = (struct person*)malloc(10 * sizeof(struct person));
    vec->vsize = 10;
    vec->currentsize = 0;

}

void vecAdd(struct vector* vec, struct person per){
    if (vec->currentsize == vec->vsize)
    {
        vec->p = (struct vector*) raelloc(vec->p, (vec->vsize * 2) * sizeof(struct vector));  //когда место в вектора закачивается, расширяем его в 2 раза
    }
    vec->currentsize += 1;
    strcpy(vec->p[vec->currentsize].name, per.name);
    strcpy(vec->p[vec->currentsize].checkname, per.checkname);
    strcpy(vec->p[vec->currentsize].tel, per.tel);
    strcpy(vec->p[vec->currentsize].chektel, per.chektel);
    strcpy(vec->p[vec->currentsize].id, per.id);
}

int main(int argc, char *argv[])
{
    struct person per;
    struct vector book;
    char command[30];
    char name[50];
    char tel[20];
    int j, i, currentID = 0;
    FILE *file;
    vecInit(&book);

    if (file == NULL)
    {

        printf("new file created \n");
    }else
    {
        file = fopen(argv[1], "r");
        while (!EOF)
        {

            fscanf(file, "%d %s",  per.id, per.name);
            read(per.tel, per.chektel);
            strcpy(per.checkname, per.name);
            toLowerCase(per.checkname);
            currentID = per.id + 1;
            vecAdd(&book, per);
        }
    }
    file = fopen(argv[1], "w");


    while(1){
        scanf("%s", command);
        if (!strcmp(command, "create")){

            scanf("%s \n", per.name);
            strcpy(per.checkname, per.name);
            toLowerCase(per.checkname);
            read(per.tel, per.chektel);
            currentID += 1;
            fprintf(file, "%d %s %s \n", currentID, per.name, per.tel);
            printf("%d %s %s %s %s \n", currentID, per.name, per.checkname, per.tel, per.chektel);


        }else if(!strcmp(command, "exit")){
            //for (j = 0; j <= i; j++){
                //printf("%s %s \n", book.p[j].name, book.p[j].tel);
            //}
            break;
         }else if (!strcmp(command, "copy")){
            scanf("%s %s", per.name, per.tel);
            strcpy(per.checkname, per.name);
            printf("%d \n", strlen(per.tel));
            toLowerCase(per.checkname);
            printf("%s \n", per.checkname);
        }else if (!strcmp(command, "tr")){

            read(per.tel, per.chektel);
            printf("%s %s \n", per.tel, per.chektel);
        }else if (!strcmp(command, "print"))
        {
            for (i = 0; i < book.currentsize; i++)
            {
                printf("%d %s %s %s %s \n",book.p[i].id, book.p[i].name,
                        book.p[i].checkname, book.p[i].tel, book.p[i].chektel);
            }
        }

    }
    return 0;
}
