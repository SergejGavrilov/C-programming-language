#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
    char* name;
    char* tel;
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

void read(char* first, char* second)
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
    vec->p = (struct hum*)malloc(10 * sizeof(struct person));
    vec->vsize = 10;
    vec->currentsize = 0;

}

void vecAdd(struct vector *vec, struct person per){
    if (vec->currentsize == vec->vsize){

    }
}
int main(int argc, char *argv[])
{
    struct person per;
    struct vector book;
    char command[30];
    char name[50];
    char tel[20];
    int j, currentID = 0;
    FILE *file;
    vecInit(&book);

    if (file == NULL){

        printf("new file created \n");
    }else{
        while (!EOF)
        {
            file = fopen(argv[1], "r");
            fscanf(file, "%d %s %s", currentID, name, tel);
            book.p[currentID].id = currentID;
            book.p[currentID].name = name;
            book.p[currentID].tel = tel;
        }
    }
    file = fopen(argv[1], "w");

    int i = 0;
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
            printf("%d \n", i);
            i++;

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
        }

    }
    return 0;
}
