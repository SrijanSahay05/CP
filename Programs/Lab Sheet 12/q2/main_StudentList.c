#include "linkedList_Student.h"

int main() {
    // Create a new list
    List* studentList = createNewList();

    // Create some student records
    StudentRecord student1 = {
        "2023001",
        "John Doe",
        "Computer Science",
        85,
        90,
        88
    };

    StudentRecord student2 = {
        "2023002",
        "Jane Smith",
        "Electrical",
        92,
        85,
        90
    };

    StudentRecord student3 = {
        "2023003",
        "Bob Johnson",
        "Mechanical",
        78,
        82,
        85
    };

    // Insert students into the list
    insertNodeAtStart(studentList, student1);
    insertNodeAtEnd(studentList, student2);
    insertNodeAfterElem(studentList, "2023001", student3);

    // Print the list
    printf("Initial List:\n");
    printList(studentList);

    // Test find function
    printf("Searching for student with ID 2023002: %s\n", 
           find(studentList, "2023002") ? "Found" : "Not Found");

    // Remove some elements
    removeNodeAtStart(studentList);
    printf("\nAfter removing first node:\n");
    printList(studentList);

    removeElement(studentList, "2023002");
    printf("\nAfter removing student with ID 2023002:\n");
    printList(studentList);

    // Free the list
    while (studentList->head != NULL) {
        removeNodeAtStart(studentList);
    }
    free(studentList);

    return 0;
} 