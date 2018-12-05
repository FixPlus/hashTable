void regHashFunc(HashTable* hash, size_t (*newHashf)(int)){
	hash->hashf = newHashf;
}
	
HashTable* initHashTable(unsigned size_hash){
	HashTable* ret = new HashTable;
	
	if(ret == NULL)
		return NULL;
	
	ret->size = size_hash;
	ret->Hashed = (List**)calloc(ret->size,sizeof(List*));
	for(int i = 0;i < ret->size;i++)
		ret->Hashed[i] = NULL;
	
	return ret;
}

void deleteHashTable(HashTable* hash){
	free(hash->Hashed);
	delete hash;
}
	
void registerNew(HashTable* hash, int num){
	size_t id = (hash->hashf(num))%hash->size;
	if(hash->Hashed[id] == NULL){
		hash->Hashed[id] = initList(num);
		return;
	}
	if(searchNode(hash->Hashed[id],num) == NULL)
		putTail(hash->Hashed[id], num);	
}

void clearTable(HashTable* hash){
	for(int i = 0;i < hash->size;i++){
		clear(hash->Hashed[i]);
		hash->Hashed[i] = NULL;
	}
}

void remove(HashTable* hash, int data){
	int id = hash->hashf(data);
	deleteNode(hash->Hashed[id], searchNode(hash->Hashed[id], data));
}

void dumpToFile(HashTable* hash, const char* filename){
	FILE* out = fopen(filename, "w");
	if(out == NULL) return;
	int temp = 0;
	for(int i = 0;i < hash->size;i++){
		if(hash->Hashed[i] == NULL) temp = 0;
			else
				temp = hash->Hashed[i]->length;
		fprintf(out, "%d;%d\n",i, temp);
	}
	fclose(out);
}

size_t h0(int num){
	return 0;
}

size_t h1(int num){
	size_t ret = 0;
	while(num > 0){
		ret += num%10;
		num /=10;
	}
	return ret;
}

size_t h2(int num){
	while(num > 10){
		num /=10;
	}	
	return num;
}

size_t h3(int num){
	return num;
}

size_t h4(int num){// GNU HASH
	size_t h = 7;
	while(num > 0){
		h = h*33 + num%10;
		num /= 10;
	}
	return h;
}


size_t h5(int num){// ROR FUNC
	size_t h = 0;
	for(int j = 0;j < sizeof(int)*8;j++)
		h |= (1u & num >> j)<<(sizeof(int)*8+j-5)%(sizeof(int)*8);
	
	return h;
}

