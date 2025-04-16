#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node * NODE;
struct node{
	int ele;
	NODE next;
};

typedef struct linked_list * LIST;
struct linked_list{
	int count;
	NODE head;
};

void printNode(NODE n1);
void printList(LIST l1);
LIST createNewList();
NODE createNewNode(int value);
void insertNodeIntoList(NODE n1, LIST l1);
void insertNodeAtEnd(NODE n1, LIST l1);
NODE search(LIST l1, int value);
void insertAfter(int ele, NODE n1, LIST l1);
void removeFirstNode(LIST l1);
void removeLastNode(LIST l1);
void removeElem(int value, LIST l1);



#endif