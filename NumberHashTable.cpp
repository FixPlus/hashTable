#include <stdio.h>
#include <time.h>
#include <string.h>
#include "hash.h"

const int phonesArrSize = 100000;


void fillHashTable(int hashfid, int* data, int sizeofdata, HashTable* target);
char* makeFilename(int id);

int* generateRandomNumArray(int size){
	int* randomArray = (int*)calloc(size,sizeof(int));
	for(int i = 0;i < size;i++)
		randomArray[i] = 4 * phonesArrSize+rand()%phonesArrSize;
	
	return randomArray;
}

int main(){
	srand(time(NULL));
	
	HashTable* phones = initHashTable(phonesArrSize);

	const int arraylen =  phonesArrSize*10;
	
	int* rndArray = generateRandomNumArray(arraylen);
	
	for(int j = 0; j < hfarraysize; j++){
		fillHashTable(j, rndArray, arraylen, phones);
		char* temp = makeFilename(j);
		dumpToFile(phones, temp);
		clearTable(phones);
		free(temp);
	}	
	
	
	deleteHashTable(phones);
	
	printf("Done!\n");
	
	return 0;
}

char* makeFilename(int id){
	char* filename = (char*)calloc(10,sizeof(char));
	filename = strcpy(filename, "phones");
	char strid[10];
	itoa(id,strid,10);
	filename = strcat(filename,strid);
	filename = strcat(filename, ".csv");
	return filename;
}

void fillHashTable(int hashfid, int* data, int sizeofdata, HashTable* target){
		regHashFunc(target, hashfuncs[hashfid]);
		for(int i = 0; i < sizeofdata;i++)
			registerNew(target, data[i]);
}