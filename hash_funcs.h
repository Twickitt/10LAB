#ifndef HASH_FUNCS_H
#define HASH_FUNCS_H

#include "Structures.h"


int ROT13_hash1(const char *str);

hash_type FNV_hash2(const char *str);

hash_type Bad_hash3(const char *str);

hash_type My_hash4(const char *str);

hash_func_type Func_Choice(int option);

char *opts[] = {"ROT13_hash1", "FNV_hash2", "Bad_hash3", "My_hash4"};

#endif