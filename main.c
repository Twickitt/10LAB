#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "hash_funcs.h"
#include "hash_tables.h"
#include "Generate_And_Print_List.h"

#define KEYSIZE 200

int main(){

    char key[KEYSIZE];
    int count, choice;
    
    
    while (1) {
        printf("Enter positive number of Students you want to generate: ");
        if (scanf("%d", &count) != 1) {
            printf("You cant enter non digits\n");
            while (getchar() != '\n'); 
            continue;
        }
        if (count <= 0 || count > 1000000) {
            printf("Number must be in range (0;1000000)\n");
            continue;
        }
        break;
    }
    
    
    
    Student* s = malloc(sizeof(Student)*count);

    if(!s){
        printf("\nMemorry allocation error");
        return 1;
    }

    Generate_List(s, count);
    printf("\nGenerated list of students\n");
    Print_List(s, count);

    
    HashTable* table = NULL;
    
    Student *student = NULL;



    do {
        printf("\n0. ROT13_hash1\n");
        printf("1. FNV_hash2\n");
        printf("2. Bad_hash3\n");
        printf("3. My_hash4\n");
        printf("4. Exit\n");
        printf("Select Action: ");

        if (scanf("%d", &choice) != 1) {
            printf("You can't enter non-digits\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice < 0 || choice > 4) {
            printf("You entered wrong number\n");
            continue;
        }

        if (choice == 4)
            break;

        if(table)
            Free_Table(table);

        table = New_Table(count*2, Func_Choice(choice));

        for (int i = 0; i < count; i++) 
            Increase_Table(table, s[i].name, &s[i]);

        getchar();

        printf("\nEnter key to search: ");
        fgets(key, KEYSIZE, stdin);
        key[strcspn(key, "\n")] = '\0';

        float sec_4_search;
        clock_t start, end;
        start = clock();

        student = Find(table, key);

        end = clock();
        sec_4_search = (float)(end - start)/CLOCKS_PER_SEC;

        
        printf("Selected hash function and key: %s, %s\n\n", opts[choice], key);
        printf("Rec: ");
        if(student == NULL)
            printf("Nothing found with this key\n");

        else
            printf("%-25s | %-15s | %-11s | %-5.2f\n", student->name, student->faculty, student->group, student->GPA);
        

        printf("\nCollision: %ld\n", table->collisions);
        printf("\nSearching complited within %.4f\n", sec_4_search);


    } while (1);

    free(s);
        
    if(table!= NULL){    
        Free_Table(table);
        table = NULL;
    }
    return 0;
}



