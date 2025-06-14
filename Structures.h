#ifndef STRUCTURES_H
#define STRUCTURES_H




typedef struct{
    char name[30];
    char faculty[30];
    char group[20];
    float GPA;
    int index;
} Student;

typedef unsigned long long hash_type;
typedef hash_type (*hash_func_type)(const char*);

typedef struct Hash{
    
    char *key;
    void *value;

} Hash;

typedef struct HashTable{

    Hash* out;
    hash_func_type hash_func;
    long int size;
    long int numbers;
    long int collisions;
} HashTable;

#endif

