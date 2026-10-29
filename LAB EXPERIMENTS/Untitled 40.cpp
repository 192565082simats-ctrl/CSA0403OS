#include <stdio.h>

int main()
{
    int choice;

    printf("File Access Permission\n");
    printf("1. Owner\n");
    printf("2. Group\n");
    printf("3. Others\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("User Type: Owner\n");
            printf("Read, Write and Execute permissions\n");
            break;

        case 2:
            printf("User Type: Group\n");
            printf("Read, Write and Execute permissions\n");
            break;

        case 3:
            printf("User Type: Others\n");
            printf("Read, Write and Execute permissions\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}
