#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hash_tables.h"






HashTable* New_Table(const long numbers, const hash_func_type hash_func) {
    HashTable* hash_table = malloc(sizeof(HashTable));
    hash_table->numbers = numbers;
    hash_table->hash_func = hash_func;
    hash_table->size = 0;
    hash_table->collisions = 0;

    hash_table->out = calloc(hash_table->numbers, sizeof(Hash));
    return hash_table;
}

void Free_Table(HashTable* hash_table) {
    free(hash_table->out);
    free(hash_table);
}

Hash* Find_Slot(HashTable* hash_table, long idx, char* key) {
    while (hash_table->out[idx].key != NULL) {
        if (strcmp(hash_table->out[idx].key, key) == 0) {
            return &hash_table->out[idx];
        }
        ++idx;

        if (idx >= hash_table->numbers) {
            idx = 0;
        }
    }
    return &hash_table->out[idx];
}

void Increase_Table(HashTable* hash_table, char* key, void* value) {
    if (hash_table->size >= hash_table->numbers - 1) {
        fprintf(stderr, "Hash table is full!\n");
        exit(0);
    }

    long idx = hash_table->hash_func(key) % hash_table->numbers;
    if (hash_table->out[idx].key != NULL && strcmp(hash_table->out[idx].key, key) != 0) {
        hash_table->collisions++;
    }

    Hash* entry = Find_Slot(hash_table, idx, key);
    entry->key = key;
    entry->value = value;
    hash_table->size++;
}

void* Find(HashTable* hash_table, char* key) {
    long idx = hash_table->hash_func(key) % hash_table->numbers;
    const Hash* entry = Find_Slot(hash_table, idx, key);
    return entry->value;
}







// HashTable* New_Table(long int numbers, const hash_func_type hash_func){


//     HashTable* table = malloc(sizeof(HashTable));

    
//     table->numbers = numbers;
//     table->size = 0;
//     table->collisions = 0;
//     table->hash_func = hash_func;

//     table->out = calloc(numbers, sizeof(Hash));

//     return table;

// }

// Hash* Find_Slot(HashTable *table, char *key, long int id){

//     long int start_id = id;

//     do{
//         if(table->out[id].key == NULL || strcmp(table->out[id].key, key) == 0)
//             return &table->out[id];

//         id = (id+1) % table->numbers;
//         table->collisions++;
//     } while(id != start_id);

//     return NULL;


// }


// int Find(HashTable *table, char *key){

//     long int id = table->hash_func(key) % table->numbers;

//     for (int i = 0; i < table->numbers; i++) {
//         long probe = (id + i) % table->numbers;
//         Hash* entry = &table->out[probe];

//         if (entry->key == NULL) 
//             return -1;  
        

//         if (strcmp(entry->key, key) == 0) 
//             return probe;  
//     }
//     return - 1;
// }


// void Free_Table(HashTable *table){
//     free(table->out);
//     free(table);
// }


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

// void Increase_Table(HashTable* table, char* key, void* value){
//     if(table->size >= table->numbers){
//         printf("Table is already full");
//         return;
//     }

//     long int id = table->hash_func(key) % table->numbers;
//     Hash* entry = Find_Slot(table, key, id);

//     if(entry == NULL){
//         printf("\nTable overflow\n");
//         return;
//     }

//     if(entry->key == NULL){
//         entry->key = strdup(key);
//         entry->value = value;
//         table->size++;
//     }
//     else
//         entry->value=value;
// }


