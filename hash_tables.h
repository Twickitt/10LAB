#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include "Structures.h"



HashTable* New_Table(long int numbers, const hash_func_type hash_func);

HashTable* Find_Slot(HashTable *table, char *key, long int id);

int Find(HashTable *table, char *key);

void Remove_By_Key(HashTable *table, char *key);

void Increase_Table(HashTable* table, char* key, void* value);

void Free_Table(HashTable *table);


#endif