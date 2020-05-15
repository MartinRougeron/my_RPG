/*
** EPITECH PROJECT, 2019
** get next line
** File description:
** get next line
*/

#include "unistd.h"
#include "fcntl.h"
#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "my.h"

char *my_strcpy1(char *str, char *add)
{
    int sizestr = 0;
    int sizeadd = 0;
    char *res;
    int i;

    for (int i = 0; str[i] != 0; i++, sizestr++);
    for (int i = 0; add[i] != 0; i++, sizeadd++);
    res = my_malloc(sizeof(char) * (sizestr + sizeadd + 1));
    for (i = 0; str[i] != 0; i++)
        res[i] = str[i];
    for (int y = 0; add[y] != 0; i++, y++)
        res[i] = add[y];
    return res;
}

char *checkreturn(char *buff, char *res, int *size, char *morechar)
{
    char *temp = my_malloc(*size + 1);

    for (int i = 0; buff[i] != 0; i++) {
        temp[i] = (buff[i] == '\n') ? 0 : buff[i];
        if (buff[i] == '\n') {
            res = my_strcpy1(res, temp);
            for (int y = 0; buff[i + 1 + y] != 0; y++)
                morechar[y] = buff[i + 1 + y];
            *size = -1;
            break;
        }
    }
    return res;
}

int checkmorechar(char *res, char *morechar)
{
    int i = 0;
    int size;

    for (i = 0; morechar[i] != 0; i++) {
        res[i] = (morechar[i] != '\n') ? morechar[i] : 0;
        if (morechar[i] == '\n') {
            for (size = 0; morechar[size] != 0; size++);
            for (int y = 0; y != size; y++)
                morechar[y] = morechar[y + i + 1];
            clearmorechar();
            return 1;
        }
    }
    for (size = 0; morechar[size] != 0; size++);
    for (int y = 0; y != size; y++)
        morechar[y] = morechar[y + i + 1];
    clearmorechar();
    return 0;
}

int errorcase(int fd, char *res)
{
    if (res == NULL)
        return 1;
    if (fd <= 0)
        return 1;
    if (READ_SIZE <= 0)
        return 1;
    return 0;
}

char *get_next_line(int fd)
{
    int size = READ_SIZE;
    char *buff;
    char *res = my_malloc(READ_SIZE + 1);
    static char morechar[READ_SIZE + 1];

    if (errorcase(fd, res) == 1)
        return NULL;
    if (checkmorechar(res, morechar) != 0)
        return res;
    while (size == READ_SIZE) {
        buff = my_malloc(sizeof(char) * (READ_SIZE + 1));
        size = read(fd, buff, READ_SIZE);
        if (res[0] == 0 && size == 0)
            return NULL;
        res = checkreturn(buff, res, &size, morechar);
        if (size == -1)
            break;
        res = my_strcpy1(res, buff);
    }
    return res;
}