#include <stdio.h>

int main()
{
    FILE *fp;
    char text[100];
    int choice;

    printf("1. Create/Write File\n");
    printf("2. Read File\n");
    printf("3. Append File\n");
    printf("4. Exit\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                fp = fopen("sample.txt", "w");
                if (fp == NULL)
                {
                    printf("File creation failed\n");
                    break;
                }
                printf("Enter text: ");
                fgets(text, sizeof(text), stdin);
                fputs(text, fp);
                fclose(fp);
                printf("File created and written successfully\n");
                break;

            case 2:
                fp = fopen("sample.txt", "r");
                if (fp == NULL)
                {
                    printf("File not found\n");
                    break;
                }
                printf("File contents:\n");
                while (fgets(text, sizeof(text), fp) != NULL)
                    printf("%s", text);
                fclose(fp);
                printf("\n");
                break;

            case 3:
                fp = fopen("sample.txt", "a");
                if (fp == NULL)
                {
                    printf("File opening failed\n");
                    break;
                }
                printf("Enter text to append: ");
                fgets(text, sizeof(text), stdin);
                fputs(text, fp);
                fclose(fp);
                printf("Text appended successfully\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
