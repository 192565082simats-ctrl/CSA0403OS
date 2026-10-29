#include <stdio.h>
#include <stdlib.h>

int main()
{
    int req[20], n, head, size, i, j, temp;
    int total = 0, direction;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk request sequence:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    printf("Enter direction (0 = left, 1 = right): ");
    scanf("%d", &direction);

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

    if (direction == 0)
    {
        for (i = n - 1; i >= 0; i--)
        {
            if (req[i] < head)
            {
                total += abs(head - req[i]);
                head = req[i];
                printf(" -> %d", head);
            }
        }

        total += head;
        head = 0;
        printf(" -> %d", head);

        for (i = 0; i < n; i++)
        {
            if (req[i] >= head)
            {
                total += abs(head - req[i]);
                head = req[i];
                printf(" -> %d", head);
            }
        }
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            if (req[i] > head)
            {
                total += abs(head - req[i]);
                head = req[i];
                printf(" -> %d", head);
            }
        }

        total += (size - 1) - head;
        head = size - 1;
        printf(" -> %d", head);

        for (i = n - 1; i >= 0; i--)
        {
            if (req[i] <= head)
            {
                total += abs(head - req[i]);
                head = req[i];
                printf(" -> %d", head);
            }
        }
    }

    printf("\nTotal head movement = %d cylinders\n", total);

    return 0;
}#include <stdio.h>
#include <stdlib.h>

int main()
{
    int req[20], n, head, size, i, j, temp;
    int total = 0;

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

    total += (size - 1) - head;
    head = size - 1;
    printf(" -> %d", head);

    total += head;
    head = 0;
    printf(" -> %d", head);

    for (i = 0; i < n; i++)
    {
        if (req[i] < head + size && req[i] < 0)
            continue;

        if (req[i] < req[0] && req[i] < 50)
        {
            total += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal head movement = %d cylinders\n", total);

    return 0;
}
