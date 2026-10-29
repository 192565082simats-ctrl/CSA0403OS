#include <stdio.h>
#include <unistd.h>

int main()
{
    char buffer[100];
    ssize_t n;

    printf("Enter a message: ");
    fflush(stdout);

    n = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);

    if (n < 0)
    {
        perror("Read failed");
        return 1;
    }

    if (n > 0 && buffer[n - 1] == '\n')
        n--;

    write(STDOUT_FILENO, "You entered: ", 13);
    write(STDOUT_FILENO, buffer, n);
    write(STDOUT_FILENO, "\n", 1);

    return 0;
}
3
