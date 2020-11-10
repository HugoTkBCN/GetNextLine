/*
** EPITECH PROJECT, 2019
** unittest
** File description:
** solostumper 1
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char *get_next_line(int fd);

Test (get_next_line, test_1)
{
    int fd = open("test.txt", O_RDONLY);

    cr_assert_str_eq(get_next_line(fd), "Salut");
    close(fd);
}

Test (get_next_line, test_2)
{
    int fd = open("test.txt", O_RDONLY);

    get_next_line(fd);
    cr_assert_str_eq(get_next_line(fd), NULL);
    close(fd);
}
