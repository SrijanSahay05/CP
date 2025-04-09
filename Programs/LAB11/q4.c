#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

// Structure definition for student record
typedef struct {
    char ID[MAX_LENGTH];
    char Name[MAX_LENGTH];
    char Dept[MAX_LENGTH];
    int math_marks;
    int phy_marks;
    int chem_marks;
} Student;

// Function to sort students based on math marks
void fun3(Student* students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].math_marks < students[j + 1].math_marks) {
                // Swap the students
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number_of_students>\n", argv[0]);
        return 1;
    }

    int num_students = atoi(argv[1]);
    if (num_students <= 0) {
        printf("Please enter a positive number of students\n");
        return 1;
    }

    // Dynamically allocate array of student records
    Student* students = (Student*)malloc(num_students * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input student details
    for (int i = 0; i < num_students; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        
        printf("ID: ");
        scanf("%s", students[i].ID);
        
        printf("Name: ");
        scanf("%s", students[i].Name);
        
        printf("Department: ");
        scanf("%s", students[i].Dept);
        
        printf("Math marks: ");
        scanf("%d", &students[i].math_marks);
        
        printf("Physics marks: ");
        scanf("%d", &students[i].phy_marks);
        
        printf("Chemistry marks: ");
        scanf("%d", &students[i].chem_marks);
    }

    // Sort the array based on math marks
    fun3(students, num_students);

    // Print sorted student records
    printf("\nStudent Records (Sorted by Math Marks):\n");
    printf("ID\tName\tDepartment\tMath\tPhysics\tChemistry\n");
    printf("--------------------------------------------------------\n");
    
    for (int i = 0; i < num_students; i++) {
        printf("%s\t%s\t%s\t\t%d\t%d\t%d\n",
               students[i].ID,
               students[i].Name,
               students[i].Dept,
               students[i].math_marks,
               students[i].phy_marks,
               students[i].chem_marks);
    }

    // Free allocated memory
    free(students);

    return 0;
} 