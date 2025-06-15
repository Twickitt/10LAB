#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hash_tables.h"






HashTable* New_Table(const long numbers, const hash_func_type hash_func) {
    HashTable* table = malloc(sizeof(HashTable));
    table->numbers = numbers;
    table->hash_func = hash_func;
    table->size = 0;
    table->collisions = 0;

    table->out = calloc(table->numbers, sizeof(Hash));
    return table;
}

void Free_Table(HashTable* table) {
    free(table->out);
    free(table);
}

Hash* Find_Slot(HashTable* table, long idx, char* key) {
    while (table->out[idx].key != NULL) {
        if (strcmp(table->out[idx].key, key) == 0) {
            return &table->out[idx];
        }
        ++idx;

        if (idx >= table->numbers) {
            idx = 0;
        }
    }
    return &table->out[idx];
}

void Increase_Table(HashTable* table, char* key, void* value) {
    if (table->size >= table->numbers - 1) {
        fprintf(stderr, "Hash table is full!\n");
        exit(0);
    }

    long idx = table->hash_func(key) % table->numbers;
    if (table->out[idx].key != NULL && strcmp(table->out[idx].key, key) != 0) {
        table->collisions++;
    }

    Hash* entry = Find_Slot(table, idx, key);
    entry->key = key;
    entry->value = value;
    table->size++;
}

void* Find(HashTable* table, char* key) {
    long idx = table->hash_func(key) % table->numbers;
    const Hash* entry = Find_Slot(table, idx, key);
    return entry->value;
}



// void Remove_By_Key(HashTable *table, char *key){
    
//     long int id = table->hash_func(key) % table->numbers;
    
//     for( int i = 0; i < table->numbers; i++){
        
//         long probe = (id + i) % table->numbers;
//         Hash* entry = &table->out[probe];

//         if(entry->key == NULL){
//             printf("\nNothing to delete with this key\n");
//             return;
//         }
//         if(strcmp(entry->key, key) == 0){
//             free(entry->key);
//             free(entry->value);
//             entry->key = NULL;
//             entry->value = NULL;
//             table->size--;
//             printf("\nElement was sucessfully deleted\n");
//             return;
//         }
//     }
//     printf("After probing key wasnt found\n");

// }
