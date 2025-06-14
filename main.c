#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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




    do {
        printf("\n1. Linear Search\n");
        printf("2. Binary Tree Search\n");
        printf("3. Red Black Search\n");
        printf("4. Linear Search With Any Case\n");
        printf("5. Binary Tree Search With Any Case\n");
        printf("0. Exit\n");
        printf("Select Action: ");

        if (scanf("%d", &choice) != 1) {
            printf("You can't enter non-digits\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice < 0 || choice > 5) {
            printf("You entered wrong number\n");
            continue;
        }

        if (choice == 0)
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
        int x = Find(table, key);
        
        if (x != -1)
            printf("First appearance of the key \'%s\' is in the index=%d\n", key, x);
        else    
            printf("There is nothing with such key in this list\n");


    } while (1);

    free(s);
    Free_Table(table);

}



