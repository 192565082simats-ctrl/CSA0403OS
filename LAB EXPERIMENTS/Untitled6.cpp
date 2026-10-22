#include <stdio.h>
#include <string.h>

char dir[10][20], files[10][10][20];
int dcount = 0, fcount[10] = {0};

int main()
{
    int choice, i, j, d;
    char dname[20], fname[20];

    while (1)
    {
        printf("\n1. Create Directory");
        printf("\n2. Create File");
        printf("\n3. Display Files");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (dcount == 10) {
                    printf("Directory limit reached!\n");
                    break;
                }

                printf("Enter directory name: ");
                scanf("%19s", dname);

                for (i = 0; i < dcount; i++)
                    if (strcmp(dir[i], dname) == 0)
                        break;

                if (i < dcount)
                    printf("Directory already exists!\n");
                else {
                    strcpy(dir[dcount++], dname);
                    printf("Directory created.\n");
                }
                break;

            case 2:
                printf("Enter directory name: ");
                scanf("%19s", dname);

                for (d = 0; d < dcount; d++)
                    if (strcmp(dir[d], dname) == 0)
                        break;

                if (d == dcount) {
                    printf("Directory not found!\n");
                    break;
                }

                if (fcount[d] == 10) {
                    printf("Directory is full!\n");
                    break;
                }

                printf("Enter file name: ");
                scanf("%19s", fname);

                for (j = 0; j < fcount[d]; j++)
                    if (strcmp(files[d][j], fname) == 0)
                        break;

                if (j < fcount[d])
                    printf("File already exists!\n");
                else {
                    strcpy(files[d][fcount[d]++], fname);
                    printf("File created.\n");
                }
                break;

            case 3:
                for (i = 0; i < dcount; i++) {
                    printf("\nDirectory: %s\n", dir[i]);
                    for (j = 0; j < fcount[i]; j++)
                        printf("  %s\n", files[i][j]);
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
