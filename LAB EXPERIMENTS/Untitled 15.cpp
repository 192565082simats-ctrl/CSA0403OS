#include <stdio.h>
#include <string.h>

char users[10][20];
char files[10][10][20];
int userCount = 0, fileCount[10] = {0};

int main()
{
    int choice, i, j, u, found;
    char user[20], file[20];

    while (1)
    {
        printf("\n1. Create User");
        printf("\n2. Create File");
        printf("\n3. Search File");
        printf("\n4. Display Files");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (userCount >= 10)
                {
                    printf("User limit reached\n");
                    break;
                }

                printf("Enter username: ");
                scanf("%19s", user);

                found = 0;
                for (i = 0; i < userCount; i++)
                    if (strcmp(users[i], user) == 0)
                        found = 1;

                if (found)
                    printf("User already exists\n");
                else
                {
                    strcpy(users[userCount], user);
                    userCount++;
                    printf("User created successfully\n");
                }
                break;

            case 2:
                printf("Enter username: ");
                scanf("%19s", user);

                u = -1;
                for (i = 0; i < userCount; i++)
                    if (strcmp(users[i], user) == 0)
                        u = i;

                if (u == -1)
                {
                    printf("User not found\n");
                    break;
                }

                if (fileCount[u] >= 10)
                {
                    printf("Directory is full\n");
                    break;
                }

                printf("Enter filename: ");
                scanf("%19s", file);

                found = 0;
                for (j = 0; j < fileCount[u]; j++)
                    if (strcmp(files[u][j], file) == 0)
                        found = 1;

                if (found)
                    printf("File already exists\n");
                else
                {
                    strcpy(files[u][fileCount[u]], file);
                    fileCount[u]++;
                    printf("File created successfully\n");
                }
                break;

            case 3:
                printf("Enter username: ");
                scanf("%19s", user);
                printf("Enter filename: ");
                scanf("%19s", file);

                u = -1;
                for (i = 0; i < userCount; i++)
                    if (strcmp(users[i], user) == 0)
                        u = i;

                found = 0;
                if (u != -1)
                    for (j = 0; j < fileCount[u]; j++)
                        if (strcmp(files[u][j], file) == 0)
                            found = 1;

                if (found)
                    printf("File found\n");
                else
                    printf("File not found\n");
                break;

            case 4:
                for (i = 0; i < userCount; i++)
                {
                    printf("\nUser: %s\n", users[i]);
                    for (j = 0; j < fileCount[i]; j++)
                        printf("  %s\n", files[i][j]);
                }
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
