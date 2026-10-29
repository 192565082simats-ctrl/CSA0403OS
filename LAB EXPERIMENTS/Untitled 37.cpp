#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, head, total = 0;
    int request[20];

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk request sequence:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nFCFS Disk Scheduling\n");
    printf("Head movement: %d", head);

    for (i = 0; i < n; i++)
    {
        total += abs(head - request[i]);
        head = request[i];
        printf(" -> %d", head);
    }

    printf("\nTotal head movement = %d cylinders\n", total);

    return 0;
}
