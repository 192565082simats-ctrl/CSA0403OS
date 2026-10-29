#include <stdio.h>

struct Student
{
    int roll;
    char name[20];
    float marks;
};

int main()
{
    FILE *fp;
    struct Student s;
    int n, i, pos;

    fp = fopen("student.dat", "wb");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter roll, name and marks: ");
        scanf("%d %19s %f", &s.roll, s.name, &s.marks);
        fwrite(&s, sizeof(s), 1, fp);
    }

    fclose(fp);

    fp = fopen("student.dat", "rb");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    printf("Enter record number to access: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n)
    {
        printf("Invalid record number\n");
    }
    else
    {
        fseek(fp, (long)(pos - 1) * sizeof(s), SEEK_SET);

        if (fread(&s, sizeof(s), 1, fp) == 1)
        {
            printf("\nStudent Record\n");
            printf("Roll Number: %d\n", s.roll);
            printf("Name: %s\n", s.name);
            printf("Marks: %.2f\n", s.marks);
        }
        else
        {
            printf("Error reading record\n");
        }
    }

    fclose(fp);
    return 0;
}
