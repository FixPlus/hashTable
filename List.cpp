
Node* initNode(int data, Node* prev, Node* next){
	Node* el = new Node;
	if(!el) return NULL;
	
	el->data = data;
	el->prev = prev;
	el->next = next;
	return el;
}

void deleteNode(List* list, Node* el){
	
	if(el == NULL) return;
	
	if(list->length == 1)
		return;
	
	if(el->next == NULL)
	{
		el->prev->next = NULL;
		list->tail = el->prev;
	}
	else if(el->prev == NULL)
	{
		el->next->prev = NULL;
		list->head = el->next;
	}
	else{
		el->next->prev = el->prev;
		el->prev->next = el->next;
	}	
	
	list->length--;
	delete el;
}

void putAfter(List* list,Node* el, int data){
	
	if(!el || !list) return;
	
	Node* newOne = initNode(data, el, NULL);
	if(!newOne) return;
	
	if(el->next != NULL){ 
		el->next->prev = newOne;
		newOne->next = el->next;
	}
	else
		list->tail = newOne;
	
	el->next = newOne;
	list->length++;
}

Node* getNode(List* list, unsigned id){
	if(id < list->length){
		Node* temp = list->head;
		for(int i = 0;i < id;i++)
			temp = temp->next;
			swapNodes(list, temp, temp->prev);		
		return temp;
	}
	else
		return NULL;
}

Node* searchNode(List* list, int data){
	if(!list || list->head) return NULL;
	
	Node* temp = list->head;
	
	while(temp->next != NULL){
		if(temp->data == data){ 
			swapNodes(list, temp, temp->prev);
			return temp;
		}
		
		temp = temp->next;
	}
	
	return NULL;
}

void putHead(List* list, int data){
	
	if(!list) return;
	
	putAfter(list, list->head, list->head->data);
	putAfter(list, list->head, data);
	deleteNode(list,list->head);
}

void putTail(List* list, int data){
	if(!list) return;

	putAfter(list,list->tail,data);
}

void printList(List* list){
	if(!list) return;
	
	Node* temp = list->head;
	while(temp){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	
	printf("\n");
}

int getNodeId(List* list, Node* el){
	
	if(!el) return -1;
		
	int id = -1;
	Node* temp = el;
	while(el){
		id++;
		temp = temp->prev;
	}
	
	swapNodes(list, el, el->prev);
	
	return id;
}

void swapNodes(List* list, Node* el1, Node* el2){
	if(!list || !el1 || !el2) return;
	
	//TODO check head/tail change 
			
	
	Node* tmpNext = el1->next;
	Node* tmpPrev = el1->prev;
	el1->next = el2->next;
	el1->prev = el2->prev;
	
	el2->next = tmpNext;
	el2->prev = tmpPrev;
}

List* initList(int data){
	List* list = new List;
	if(!list) return NULL;
	
	list->head = initNode(data,NULL,NULL);
	list->tail = list->head;
	list->length = 1;
	return list;
}

void clear(List* list){
	
	if(!list) return;
	
	while(list->length > 1)
		deleteNode(list,list->head);
	
	delete list->head;
}

void deleteList(List* list){
	if(!list) return;
	clear(list);
	delete list;
}
