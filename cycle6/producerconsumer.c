#include <stdio.h>
#include <stdlib.h>
int semaphore = 1, full = 0, empty = 3, processid = 0;
int wait(int semaphore)
{
    return (--semaphore);
}
int signal(int semaphore)
{
    return (++semaphore);
}
void producer()
{
    semaphore = wait(semaphore);
    full = full + 1;
    empty = empty - 1;
    processid++;
    printf("\nproducer produces the item %d", processid);
    semaphore = signal(semaphore);
}
void consumer()
{
    semaphore = wait(semaphore);
    full = full - 1;
    empty = empty + 1;
    printf("\n consumer consumes item %d", processid);
    processid--;
    semaphore = signal(semaphore);
}
int main()
{
    int n;
    printf("\n1.Run Producer\n2.Run Consumer\n3.Exit\n");
    while (1)
    {
        printf("\nenter your choice");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if ((semaphore == 1) && (empty != 0))
            {
                producer();
            }
            else if (semaphore == 0)
            {
                printf("the process is already in critical section and it is using the memory");
            }
            else
            {
                printf("The buffer is full");
            }
            break;
        case 2:
            if ((semaphore == 1) && (full != 0))
            {
                consumer();
            }
            else if (semaphore == 0)
            {
                printf("the process is already  in critical section and it is using cpu memory resources");
            }
            else
            {
                printf("the buffer is empty");
            }
            break;
        case 3:
            exit(0);
            break;
        }
    }
}