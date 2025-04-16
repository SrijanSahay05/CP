#ifndef LINKEDLIST_STUDENT_H
#define LINKEDLIST_STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum lengths for strings
#define MAX_ID_LENGTH 10
#define MAX_NAME_LENGTH 50
#define MAX_DEPT_LENGTH 30

// Structure for student record
typedef struct {
    char ID[MAX_ID_LENGTH];
    char Name[MAX_NAME_LENGTH];
    char Dept[MAX_DEPT_LENGTH];
    int math_marks;
    int phy_marks;
    int chem_marks;
} StudentRecord;

// Structure for a node
typedef struct Node {
    StudentRecord data;
    struct Node* next;
} Node;

// Structure for the linked list
typedef struct {
    Node* head;
    int count;
} List;

// Function declarations
List* createNewList();
Node* createNewNode(StudentRecord student);
void insertNodeAtStart(List* list, StudentRecord student);
void insertNodeAtEnd(List* list, StudentRecord student);
void insertNodeAfterElem(List* list, char* searchID, StudentRecord student);
void removeNodeAtStart(List* list);
void removeNodeAtEnd(List* list);
void removeElement(List* list, char* searchID);
void printStudentRecord(StudentRecord student);
void printList(List* list);
int find(List* list, char* searchID);

#endif 