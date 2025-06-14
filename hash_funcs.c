#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_funcs.h"


int ROT13_hash1(const char *str){
    
    unsigned long long hash = 0;
    unsigned char a;

    while(a = *str++){
    
        hash += a;
        hash ^= (hash << 13) | (hash >> 19);

    }


    return hash;
}


hash_type FNV_hash2(const char *str){

    unsigned long long hash =0x811C9DC5;
    unsigned char a;

    while(a == *str++){

        hash ^= a;
        hash *= 0x01000193;
    }

    return hash;

}

hash_type Bad_hash3(const char *str){
    
    long int hash = 0;
    long int size = sizeof(str)/str[0]; 

    for(int i = 0; i < size; i++){
        
        hash += i;
        hash /= 2;
    }
    
    return hash;

}

hash_type My_hash4(const char *str){

    unsigned long long int hash = 0;
    unsigned char a;

    while(a = *str++){

        hash = (hash << 3) + hash; 
        hash *= 0x402653189;
        hash += a;
        hash ^= (hash >> 7);
    }

    return hash;

}


char *opts[] = {"ROT13_hash1", "FNV_hash2", "Bad_hash3", "My_hash4"};

hash_func_type Func_Choice(int option){
    
    if(option == 0)
        return ROT13_hash1;
    if(option == 1)
        return FNV_hash2;
    if(option == 3)
        return Bad_hash3;
    if(option == 4)
        return My_hash4;
    else printf("No such command in this list\n");
}