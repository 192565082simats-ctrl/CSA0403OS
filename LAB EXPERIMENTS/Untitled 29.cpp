#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

int flag[2] = {0, 0};
int turn;
int count = 0;

void *process(void *arg)
{
    int id = *(int *)arg;
    int other = 1 - id;
    int i;

    for (i = 0; i < 5; i++)
    {
        flag[id] = 1;
        turn = other;

        while (flag[other] && turn == other)
            ;

        count++;
        printf("Process %d: Count = %d\n", id, count);

        flag[id] = 0;
    }

    return NULL;
}

int main()
{
    pthread_t p1, p2;
    int id1 = 0, id2 = 1;

    pthread_create(&p1, NULL, process, &id1);
    pthread_create(&p2, NULL, process, &id2);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Final Count = %d\n", count);

    return 0;
}
