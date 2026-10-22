#include <stdio.h>
#include <string.h>

int main()
{
    char files[20][30], name[30];
    int n = 0, choice, i, found;

    while (1)
    {
        printf("\n1. Create File");
        printf("\n2. Search File");
        printf("\n3. Display Files");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter file name: ");
                scanf("%29s", name);

                found = 0;
                for (i = 0; i < n; i++)
                    if (strcmp(files[i], name) == 0)
                        found = 1;

                if (found)
                    printf("File already exists!\n");
                else if (n < 20)
                {
                    strcpy(files[n++], name);
                    printf("File created successfully.\n");
                }
                else
                    printf("Directory is full.\n");
                break;

            case 2:
                printf("Enter file name to search: ");
                scanf("%29s", name);

                found = 0;
                for (i = 0; i < n; i++)
                    if (strcmp(files[i], name) == 0)
                        found = 1;

                if (found)
                    printf("File found.\n");
                else
                    printf("File not found.\n");
                break;

            case 3:
                printf("Files in directory:\n");
                for (i = 0; i < n; i++)
                    printf("%s\n", files[i]);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
