#include <stdio.h>
#include <stdlib.h>

int main()
{
    int req[20], n, head, size;
    int i, j, temp, total = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk request sequence:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (req[j] > req[j + 1])
            {
                temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }

    printf("\nHead movement: %d", head);

    for (i = 0; i < n; i++)
    {
        if (req[i] >= head)
        {
            total += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    }

    if (head != size - 1)
    {
        total += (size - 1) - head;
        head = size - 1;
        printf(" -> %d", head);
    }

    total += size - 1;
    head = 0;
    printf(" -> %d", head);

    for (i = 0; i < n; i++)
    {
        if (req[i] < head || req[i] < req[0])
        {
            total += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal head movement = %d cylinders\n", total);

    return 0;
}
