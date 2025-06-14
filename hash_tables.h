#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include "Structures.h"



HashTable* New_Table(const long numbers, const hash_func_type hash_func);

Hash* Find_Slot(HashTable* hash_table, long idx, char* key);

void* Find(HashTable* hash_table, char* key);

void Increase_Table(HashTable* table, char* key, void* value);

void Free_Table(HashTable *table);


#endif