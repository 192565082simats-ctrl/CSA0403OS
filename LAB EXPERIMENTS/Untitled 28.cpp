#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[100], pattern[100], line[500];
    int found = 0;

    printf("Enter filename: ");
    scanf("%99s", filename);

    printf("Enter word to search: ");
    scanf("%99s", pattern);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (strstr(line, pattern) != NULL)
        {
            printf("%s", line);
            found = 1;
        }
    }

    if (!found)
        printf("Pattern not found\n");

    fclose(fp);
    return 0;
}
