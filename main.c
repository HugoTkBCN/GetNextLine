#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}


int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    char *s = get_next_line(fd);

    while (s) {
        my_putstr(s);
        my_putchar('\n');
        free(s);
        s = get_next_line(fd);
    }
    close(fd);
    return (0);
}
