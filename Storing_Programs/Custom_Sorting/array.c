//  Sort an array of structures (e.g., students by marks, employees by salary)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure for students
struct Student
{
    char name[50];
    int marks;
};

// Comparator function for a qsort to sort by marks in ascending order
int Comparator(const void *a, const void *b)
{
    struct Student *StudentA = (struct Student *)a;
    struct Student *StudentB = (struct Student *)b;

    return StudentA->marks - StudentB->marks;
}

int displayStudents(struct Student Students[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Name:%s, Marks:%d\n", Students[i].name, Students[i].marks);
    }
}

int main()
{
    // Array of students
    struct Student students[] = 
    {
        {"Alice", 85},
        {"Bob", 72},
        {"Charlie", 90},
        {"Dave", 65},
        {"Eve", 78}
    };

    int size = sizeof(students) / sizeof(students[0]);

    printf("Before sorting:\n");
    displayStudents(students, size);

    // Sort the array using qsort
    qsort(students, size, sizeof(struct Student), Comparator);

    printf("\nAfter sorting by marks (ascending):\n");
    displayStudents(students, size);

}