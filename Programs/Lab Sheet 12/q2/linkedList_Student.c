#include "linkedList_Student.h"

List* createNewList() {
    List* newList = (List*)malloc(sizeof(List));
    if (newList == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newList->head = NULL;
    newList->count = 0;
    return newList;
}

Node* createNewNode(StudentRecord student) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = student;
    newNode->next = NULL;
    return newNode;
}

void insertNodeAtStart(List* list, StudentRecord student) {
    if (list == NULL) return;
    
    Node* newNode = createNewNode(student);
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void insertNodeAtEnd(List* list, StudentRecord student) {
    if (list == NULL) return;

    Node* newNode = createNewNode(student);
    
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->count++;
}

void insertNodeAfterElem(List* list, char* searchID, StudentRecord student) {
    if (list == NULL || list->head == NULL) return;

    Node* current = list->head;
    while (current != NULL && strcmp(current->data.ID, searchID) != 0) {
        current = current->next;
    }
    
    if (current != NULL) {
        Node* newNode = createNewNode(student);
        newNode->next = current->next;
        current->next = newNode;
        list->count++;
    }
}

void removeNodeAtStart(List* list) {
    if (list == NULL || list->head == NULL) return;

    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->count--;
}

void removeNodeAtEnd(List* list) {
    if (list == NULL || list->head == NULL) return;

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
    } else {
        Node* current = list->head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    list->count--;
}

void removeElement(List* list, char* searchID) {
    if (list == NULL || list->head == NULL) return;

    if (strcmp(list->head->data.ID, searchID) == 0) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->count--;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL && strcmp(current->next->data.ID, searchID) != 0) {
        current = current->next;
    }

    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
        list->count--;
    }
}

void printStudentRecord(StudentRecord student) {
    printf("ID: %s\n", student.ID);
    printf("Name: %s\n", student.Name);
    printf("Department: %s\n", student.Dept);
    printf("Math Marks: %d\n", student.math_marks);
    printf("Physics Marks: %d\n", student.phy_marks);
    printf("Chemistry Marks: %d\n", student.chem_marks);
    printf("-------------------\n");
}

void printList(List* list) {
    if (list == NULL) {
        printf("List is NULL\n");
        return;
    }

    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* current = list->head;
    while (current != NULL) {
        printStudentRecord(current->data);
        current = current->next;
    }
}

int find(List* list, char* searchID) {
    if (list == NULL || list->head == NULL) return 0;

    Node* current = list->head;
    while (current != NULL) {
        if (strcmp(current->data.ID, searchID) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
} 