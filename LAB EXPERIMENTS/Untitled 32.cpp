#include <stdio.h>

int main()
{
    int pages[50], frames[10], time[10];
    int n, f, i, j, faults = 0, hit;
    int counter = 0, lru;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        hit = 0;
        counter++;

        for (j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                hit = 1;
                time[j] = counter;
                break;
            }
        }

        if (!hit)
        {
            lru = 0;

            for (j = 1; j < f; j++)
            {
                if (frames[j] == -1 ||
                    (frames[lru] != -1 && time[j] < time[lru]))
                    lru = j;
            }

            frames[lru] = pages[i];
            time[lru] = counter;
            faults++;
        }

        printf("\nPage %d: ", pages[i]);

        for (j = 0; j < f; j++)
        {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }

        if (hit)
            printf("Hit");
        else
            printf("Page Fault");
    }

    printf("\n\nTotal Page Faults = %d\n", faults);

    return 0;
}
