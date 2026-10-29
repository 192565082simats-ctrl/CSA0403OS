#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[100];
    char text[] = "Hello UNIX System Calls";

    fd = open("sample.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("File creation failed");
        return 1;
    }

    write(fd, text, sizeof(text) - 1);
    close(fd);

    fd = open("sample.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("File opening failed");
        return 1;
    }

    int n = read(fd, buffer, sizeof(buffer) - 1);

    if (n == -1)
    {
        perror("File reading failed");
        close(fd);
        return 1;
    }

    buffer[n] = '\0';
    printf("File content: %s\n", buffer);

    close(fd);

    return 0;
}
