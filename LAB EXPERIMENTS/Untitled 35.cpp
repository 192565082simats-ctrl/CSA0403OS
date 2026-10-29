#include <stdio.h>

int main()
{
    int index[20], n, i;

    printf("Enter number of blocks in the file: ");
    scanf("%d", &n);

    printf("Enter the index block number: ");
    int indexBlock;
    scanf("%d", &indexBlock);

    printf("Enter the file block numbers:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &index[i]);

    printf("\nIndexed File Allocation\n");
    printf("Index Block: %d\n", indexBlock);
    printf("File Block\tBlock Number\n");

    for (i = 0; i < n; i++)
        printf("%d\t\t%d\n", i + 1, index[i]);

    return 0;
}
