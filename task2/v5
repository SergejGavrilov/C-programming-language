#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



typedef struct {
    char *name;
    char *phone;
    int id;
} Person;

typedef struct {
    Person *people;
    int length;
    int lasID;
} Notebook;

Notebook book;

char *name_of_file;

char *getname(FILE *file) {
    char *name = NULL;
    int current_len = 0;
    int c = fgetc(file);
    int size = 1;
    while (c != EOF) {
        if (!isspace(c)) {
            if (isalpha(c)) {
                if (current_len + 1 == size) {
                    size *= 2;
                    name = realloc(name, size * sizeof(char));
                }
                name[current_len++] = tolower(c);
                name[current_len] = '\0';
            } else
                return NULL;
        } else if (current_len > 0) break;
        c = fgetc(file);
    }
    return name;
}


char *getphone(FILE *file) {
    char *phone = NULL;
    int current_len = 0;
    int c = fgetc(file);
    int size = 1;
    int brackets = 2;   //only two brackets allowed once in a phone number
    while (c != EOF) {
        if (!isspace(c)) {
            if (isdigit(c)) {
                if (current_len + 1 == size) {
                    size *= 2;
                    phone = realloc(phone, size * sizeof(char));
                }
                phone[current_len++] = c;
                phone[current_len] = '\0';
            } else if ((current_len > 0 && c == '+') || (brackets != 2 && c == '(') || (brackets != 1 && c == ')') ||
                        (current_len == 0 && c != '+') || (c == '-' && phone[current_len - 2] == '-'))
               return NULL;
            else if (c == '(')
                brackets = 1;
            else if (c == ')')
                brackets = 0;
        } else if (current_len > 0) break;
        c = fgetc(file);
    }
    return phone;
}

void writeToFile(int id, char* name, char* phone) {
    FILE *file = fopen(name_of_file, "w");
    int i;
    for (i = 0; i < book.length; i++) {
        fprintf(file, "%d %s %s\n", book.people[i].id, book.people[i].name, book.people[i].phone);
    }
    fclose(file);
}


void create(FILE *file, int id) {
    char *name = getname(file);
    char *phone = getphone(file);
    if (id > book.lasID) book.lasID = id;
    book.people = (Person *) realloc(book.people, (book.length + 1) * sizeof(Person));
    book.people[book.length].name = name;
    book.people[book.length].phone = phone;
    book.people[book.length].id = id;
    book.length += 1;
    writeToFile(id, name, phone);

}

int issubstr(char *str1, char *str2) {
    return (int)(strstr(str1, str2) != NULL);
}

void find(FILE *file) {
    int c = fgetc(file);
    while (c != EOF && !isspace(c)) {
        c = fgetc(file);
    }
    char *token;
    if (isalpha(c)) {
        ungetc(c, file);
        token = getname(file);
    } else {
        ungetc(c, file);
        token = getphone(file);
    }
    int i = 0;
    for (i = 0; i < book.length; i++) {
        if (issubstr(token, book.people[i].name) || (!strcmp(token, book.people[i].phone))) {
            printf("%d %s %s", book.people[i].id, book.people[i].name, book.people[i].phone);
            break;
        }
    }
}


int main(int argc, char **argv) {

    name_of_file = (argc > 1) ? argv[1] : "book.txt";
    FILE *file = fopen(name_of_file, "a+");
    if (file == NULL) {
        printf("Error: could not open file %s \n", name_of_file);
        fflush(stdout);
    }
    rewind(file);

    int id;
    book.lasID  =0;
    book.people = NULL;
    book.length = 0;
    while (fscanf(file, "%d", &id) != EOF) {
        create(file, id);
    }
    fclose(file);
    char cmd[6];
    while (1) {
        scanf("%s", cmd);
        if (!strcmp(cmd, "find")) {
            find(file);
        } else if (!strcmp(cmd, "create")) {
            create(stdin, book.lasID + 1);

        } else if (!strcmp(cmd, "exit")) {
            break;
        }
    }
    return 0;
}
