#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hash_tables.h"


HashTable* New_Table(long int numbers, const hash_func_type hash_func){

    HashTable* table = malloc(sizeof(HashTable));
    
    table->numbers = numbers;
    table->size = 0;
    table->collisions = 0;
    table->hash_func = hash_func;

    table->out = calloc(table->numbers, sizeof(Hash));

    return table;

}

HashTable* Find_Slot(HashTable *table, char *key, long int id){

    while (table->out[id].key != NULL) {
        if (strcmp(table->out[id].key, key) == 0) {
            return &table->out[id];
        }
        else id ++;

        if (id >= table->numbers) {
            id = 0;
        }
    }
    return &table->out[id];
}


int Find(HashTable *table, char *key){

    long int id = table->hash_func(key) % table->numbers;

    for (int i = 0; i < table->numbers; i++) {
        long probe = (id + i) % table->numbers;
        Hash* entry = &table->out[probe];

        if (entry->key == NULL) {
            return -1;  
        }

        if (strcmp(entry->key, key) == 0) {
            return probe;  
        }
    }

    return -1;  
}


void Free_Table(HashTable *table){
    free(table->out);
    free(table);
}


void Remove_By_Key(HashTable *table, char *key){
    
    long int id = table->hash_func(key) % table->numbers;
    
    for( int i = 0; i < table->numbers; i++){
        
        long probe = (id + i) % table->numbers;
        Hash* entry = &table->out[probe];

        if(entry->key == NULL){
            printf("\nNothing to delete with this key\n");
            return;
        }
        if(strcmp(entry->key, key) == 0){
            entry->key = NULL;
            entry->value = NULL;
            printf("\nElement was sucessfully deleted\n");
            return;
        }
    }
    printf("After probing, key wasnt found\n");

}

void Increase_Table(HashTable* table, char* key, void* value){
    if(table->size >= table->numbers - 1){
        printf("Table is already full");
        return;
    }

    long int id = table->hash_func(key) % table->numbers;
    
    if(table->out[id].key != NULL && strcmp(table->out[id].key, key) != 0){
        table->collisions++;
    }

    Hash* entry = Find_Slot(table, key, id);
    entry->key = key;
    entry->value = value;
    table->size++;
}


