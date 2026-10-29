#include <stdio.h>

int main()
{
    int b[10], p[10], alloc[10];
    int nb, np, i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter block sizes:\n");
    for(i = 0; i < nb; i++)
        scanf("%d", &b[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter process sizes:\n");
    for(i = 0; i < np; i++)
    {
        scanf("%d", &p[i]);
        alloc[i] = -1;
    }

    for(i = 0; i < np; i++)
    {
        for(j = 0; j < nb; j++)
        {
            if(b[j] >= p[i])
            {
                alloc[i] = j;
                b[j] -= p[i];
                break;
            }
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for(i = 0; i < np; i++)
    {
        printf("%d\t%d\t", i + 1, p[i]);
        if(alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
