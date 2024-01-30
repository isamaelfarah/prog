#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Person {
    char name[50];
    char fatherName[50];
    char nationality[20];
    char email[50];
    char phone[15];
    char adres[50];
};

void start();
void back();
void addRecord(FILE *file);
void listRecord(FILE *file);
void editRecord(FILE *file);
void deleteRecord(FILE *file);
void searchRecord(FILE *file);

void menu() {
    int choice;

    do {
         printf("=====================\n");
        printf("\n[1]. Add Record \n[2]. List Records \n[3]. Edit Record\n[4]. Delete Record\n[5]. Search Record\n[6]. Exit\n");
        printf("=====================\n");
         printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
            system("clear");
                addRecord(NULL);
                break;
            case 2:
              system("clear");
                listRecord(NULL);
                break;
            case 3:
              system("clear");
                editRecord(NULL);
                break;
            case 4:
            system("clear");
                deleteRecord(NULL);
                break;
            case 5:
            system("clear");
                searchRecord(NULL);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (1);
}

void start() {
    printf("Starting...\n");
    menu();
}

void back() {
    printf("Going back...\n");
    start();
}

void addRecord(FILE *file) {
    struct Person person;
    FILE *contactFile = fopen("contacts.txt", "a");

    if (contactFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

     printf("Enter first name: ");
      scanf("%s", person.name);
     printf("Enter last name: ");
     scanf("%s", person.fatherName);
     printf("Enter phone number: ");
     scanf("%s", person.phone);
     printf("Enter gender (M/F): ");
     scanf("%s", person.nationality);
     printf("Enter email: ");
     scanf("%s", person.email);
     printf("Enter address: ");
     scanf("%s", person.adres);

    fprintf(contactFile, "%s %s %s %s %s %s\n", person.name, person.fatherName,person.phone, person.nationality, person.email,person.adres);
    fclose(contactFile);

    printf("Record added successfully.\n");
    menu();
}

void listRecord(FILE *file) {
    struct Person person;
    FILE *contactFile = fopen("contacts.txt", "r");

    if (contactFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nRecords:\n");
    while (fscanf(contactFile, "%s %s %s %s %s %s\n", person.name, person.fatherName,person.phone, person.nationality, person.email,person.adres) != EOF) {
        printf("=====================\n"); 
         printf("Name: %s %s\n phone number:  %s\n gender: %s\n Email: %s\n address: %s\n",person.name, person.fatherName,person.phone, person.nationality, person.email,person.adres);
          
    }


    fclose(contactFile);
    menu();
}
void editRecord(FILE *file) {
    struct Person person;
    char searchName[50];
    FILE *tempFile = fopen("temp.txt", "w");
    FILE *contactFile = fopen("contacts.txt", "r");

    if (contactFile == NULL || tempFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter the name of the person to edit: ");
    scanf("%s", searchName);

    while (fscanf(contactFile, "%s %s %s %s %s %s",  person.name, person.fatherName,person.phone, person.nationality, person.email,person.adres) != EOF) {
        if (strcmp(person.name, searchName) == 0) {
            printf("Enter new first name for %s: ", searchName);
            scanf("%s", person.name);
            printf("Enter new last name for %s: ", searchName);
            scanf("%s", person.fatherName);
            printf("Enter new phone number for %s: ", searchName);
            scanf("%s", person.phone);
            printf("Enter new gender for %s: ", searchName);
            scanf("%s", person.nationality);
            printf("Enter new email for %s: ", searchName);
            scanf("%s", person.email);
            printf("Enter new address for %s: ", searchName);
            scanf("%s", person.adres);

        }
        fprintf(tempFile, "%s %s %s %s %s %s",  person.name, person.fatherName,person.phone, person.nationality, person.email,person.adres);
    }

    fclose(contactFile);
    fclose(tempFile);

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    printf("Record edited successfully.\n");
    menu();
}

void deleteRecord(FILE *file) {
    struct Person person;
    char searchName[50];
    FILE *tempFile = fopen("temp.txt", "w");
    FILE *contactFile = fopen("contacts.txt", "r");

    if (contactFile == NULL || tempFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter the name of the person to delete: ");
    scanf("%s", searchName);

    while (fscanf(contactFile, "%s %s %s %s %s %s",  person.name, person.fatherName,person.phone, person.nationality, person.email,person.adres) != EOF) {
        if (strcmp(person.name, searchName) != 0) {
            fprintf(tempFile, "%s %s %s %s %s %s",  person.name, person.fatherName,person.phone, person.nationality, person.email,person.adres);
        }
    }

    fclose(contactFile);
    fclose(tempFile);

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    printf("Record deleted successfully.\n");
    menu();
}

void searchRecord(FILE *file) {
    struct Person person;
    char searchName[50];
    FILE *contactFile = fopen("contacts.txt", "r");

    if (contactFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter the name of the person to search: ");
    scanf("%s", searchName);

    while (fscanf(contactFile, "%s %s %s %s %s %s",person.name, person.fatherName,person.phone, person.nationality, person.email,person.adres) != EOF) {
        if (strcmp(person.name, searchName) == 0) {
            printf("Name: %s %s\n phone number:  %s\n gender: %s\n Email: %s\n address: %s\n",person.name, person.fatherName,person.phone, person.nationality, person.email,person.adres);
            fclose(contactFile);
            menu();
            return;
        }
    }

    fclose(contactFile);
    printf("Record not found.\n");
    menu();
}

int main() {
    start();
    return 0;
}
