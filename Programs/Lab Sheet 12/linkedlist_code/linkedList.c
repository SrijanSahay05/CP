#include "linkedList.h"

void printNode(NODE n1){
    printf("%d\n", n1->ele);    
}

void printList(LIST l1){
    NODE temp = l1->head;
    while(temp != NULL){
        printNode(temp);
        temp = temp->next;
    }
}

LIST createNewList(){
    LIST l1 = (LIST)malloc(sizeof(struct linked_list));
    l1->count = 0;
    l1->head = NULL;
    return l1;
}

NODE createNewNode(int value){
    NODE n1 = (NODE)malloc(sizeof(struct node));
    n1->ele = value;
    n1->next = NULL;
    return n1;
}


void insertNodeIntoList(NODE n1, LIST l1){
    n1->next = l1->head;
    l1->head = n1;
    l1->count++;
}

void insertNodeAtEnd(NODE n1, LIST l1){
    NODE temp = l1->head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n1;
    l1->count++;
}


NODE search(LIST l1, int value){
    NODE temp = l1->head;
    while(temp != NULL){
        if(temp->ele == value){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void insertAfter(int searchEle, NODE n1, LIST l1){
    NODE temp = l1->head;
    while(temp != NULL){
        if(temp->ele == searchEle){
            n1->next = temp->next;
            temp->next = n1;
            l1->count++;
            return;
        }
        temp = temp->next;
    }
}

void removeFirstNode(LIST l1){
    if(l1->head == NULL){
        return;
    }
    NODE temp = l1->head;
    l1->head = temp->next;  
    free(temp);
    l1->count--;
}

void removeLastNode(LIST l1){
    if(l1->head == NULL){
        return;
    }
    NODE temp = l1->head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    l1->count--;
}

void removeElem(int value, LIST l1){
    if(l1->head == NULL){
        return;
    }
    NODE temp = l1->head;
    while(temp != NULL){
        if(temp->ele == value){
            temp->next = temp->next->next;
            l1->count--;
            return;
        }
        temp = temp->next;
    }
}