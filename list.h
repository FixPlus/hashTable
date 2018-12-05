#include <stdio.h>
#include <stdlib.h>

struct _Node{
	int data;
	struct _Node* prev;
	struct _Node* next;	
};

typedef _Node Node;

struct _List{
	Node* head;
	Node* tail;
	int length;
};

typedef _List List;

Node* initNode(int data, Node* prev, Node* next);
void deleteNode(List* list, Node* el);
void putAfter(List* list,Node* el, int data);
Node* getNode(List* list, unsigned id);
Node* searchNode(List* list, int data);
void putHead(List* list, int data);
void putTail(List* list, int data);
void printList(List* list);
int getNodeId(List* list, Node* el);
void swapNodes(List* list, Node* el1, Node* el2);
List* initList(int data);
void clear(List* list);
void deleteList(List* list);


#include "List.cpp"
