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
            } else {
                printf("Invalid name\n");
                fflush(file);
                return NULL;
            }
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
                       (current_len == 0 && c != '+') || (c == '-' && phone[current_len - 2] == '-')) {
                printf("Invalid phone\n");
                fflush(stdout);
                return NULL;
            }
            else if (c == '(')
                brackets = 1;
            else if (c == ')')
                brackets = 0;
        } else if (current_len > 0) break;
        c = fgetc(file);
    }
    return phone;
}

void writeToFile() {
    FILE *file = fopen(name_of_file, "w");
    int i;
    for (i = 0; i < book.length; i++) {
        fprintf(file, "%d %s %s\n", book.people[i].id, book.people[i].name, book.people[i].phone);
        fflush(file);
    }
    fclose(file);
}


void create(FILE *file, int id) {
    char *name = getname(file);
    char *phone = getphone(file);
    if (name == NULL || phone == NULL) {
        printf("unable to create\n");
        fflush(stdout);
        return;
    }
    if (id > book.lasID) book.lasID = id;
    book.people = (Person *) realloc(book.people, (book.length + 1) * sizeof(Person));
    book.people[book.length].name = name;
    book.people[book.length].phone = phone;
    book.people[book.length].id = id;
    book.length += 1;
   // printf("successfully created\n");
   // fflush(stdout);
    writeToFile();

}

/*void create(FILE *file, int id) {
    char *name = getname(file);
    char *phone = getphone(file);
    if (id > book.lasID) book.lasID = id;
    book.people = (Person *) realloc(book.people, (book.length + 1) * sizeof(Person));
    book.people[book.length].name = name;
    book.people[book.length].phone = phone;
    book.people[book.length].id = id;
    book.length += 1;
    writeToFile();

}
*/
int issubstr(char *str1, char *str2) {
    return (int) (strstr(str1, str2) != NULL);
}

void find(FILE *file) {
    int c = fgetc(file);
    while (c != EOF && isspace(c)) {
        c = fgetc(file);
    }
    ungetc(c, file);
    char *token;
    if (isalpha(c)) {
        token = getname(file);
    } else {
        token = getphone(file);
    }
    if (token == NULL){
        printf("Unable to find");
        fflush(file);
        return;
    }
    int i = 0;
    int found = 0;
    for (i = 0; i < book.length; i++) {
        if (issubstr(book.people[i].name, token) || (!strcmp(token, book.people[i].phone))) {
            printf("%d %s %s\n", book.people[i].id, book.people[i].name, book.people[i].phone);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("couldn't find");
    fflush(stdout);
}

int getID() {
    FILE *file = stdin;
    int c = fgetc(file);
    while (c != EOF && isspace(c)) {
        c = fgetc(file);
    }
    if (isdigit(c)) {
        ungetc(c, file);
        scanf("%d", &c);
        return c;
    }
    return -1;
}

void delete() {
    int id = getID();
    int found = 0;
    int i = 0;
    for (i = 0; i < book.length; i++) {
        if (book.people[i].id == id) {
            found = 1;
            book.length--;
            free(book.people[i].phone);
            free(book.people[i].name);
            /*book.people[i].id = book.people[book.length].id;
            book.people[i].name = book.people[book.length].name;
            book.people[i].phone = book.people[book.length].phone;
            */
            book.people[i].id = book.people[book.length].id;
            book.people[i].name = book.people[book.length].name;
            book.people[i].phone = book.people[book.length].phone;
            book.people = (Person *)realloc(book.people, book.length * sizeof(Person));
            break;
        }

    }
    if (found == 0)
        printf("Unable to find ID\n");
   // else
   //     printf("successfully deleted\n");

    fflush(stdout);
    writeToFile();
}

void change() {
    int id = getID();
    char type[6];
    int c = fgetc(stdin);
    while (c != EOF && isspace(c)) {
        c = fgetc(stdin);
    }
    if (isalpha(c)) {
        ungetc(c, stdin);
        scanf("%s", type);
    }
    int i = 0;
    for (i = 0; i < book.length; i++) {
        if (book.people[i].id == id) {
            char *token;
            if (!strcmp(type, "number")) {
                token = getphone(stdin);
                book.people[i].phone = token;
            }
            else {
                token = getname(stdin);
                book.people[i].name = token;
            }
            writeToFile();
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
    book.lasID = 0;
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
            find(stdin);
        } else if (!strcmp(cmd, "create")) {
            create(stdin, book.lasID + 1);
        } else if (!strcmp(cmd, "delete")) {
            delete();
        } else if(!strcmp(cmd, "change")) {
            change();
        } else if (!strcmp(cmd, "exit")) {
            break;
        }
    }
    return 0;
}
