#include <stdio.h>
#include <stdint.h>
#include "list.h"

const int hfarraysize = 6;

struct HashTable_ {
	List** Hashed;
	unsigned size;
	size_t (*hashf)(int);
};

typedef struct HashTable_ HashTable;

HashTable* initHashTable(unsigned size_hash);

void regHashFunc(HashTable* hash, size_t (*newHashf)(int));
	
void registerNew(HashTable* hash, int num);

void clearTable(HashTable* hash);

void remove(HashTable* hash, int data);

void dumpToFile(HashTable* hash, const char* filename);

size_t h0(int num);

size_t h1(int num);

size_t h2(int num);

size_t h3(int num);

size_t h4(int num);

size_t h5(int num);

size_t (*hashfuncs[hfarraysize])(int) = {&h0, &h1, &h2, &h3, &h4, &h5};
#include "hash.cpp"

