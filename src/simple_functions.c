/*
** EPITECH PROJECT, 2019
** Minishell
** File description:
** Simple functions used by Minishell
*/

#include "minishell.h"

int my_strlen_param(char *str, char param)
{
    int i = 0;

    for (; str[i] != param && str[i] != '\0'; i++);
    return (i);
}

void my_putstr(char *str, int exit)
{
    write(exit, str, my_strlen(str));
}

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    while ((str1[i] == str2[i]) && (str1[i] != '\0') && (str2[i] != '\0'))
        i++;
    if (i == my_strlen(str1))
        return (1);
    return (0);
}

char *my_strcat(char *str, char *strbis, int choice)
{
    int j = 0;
    int len_str = my_strlen_param(str, '\0');
    int len_strbis = my_strlen_param(strbis, '\0');
    char *result = malloc(sizeof(char) * (len_str + len_strbis + choice + 1));

    result[len_str + len_strbis + choice] = '\0';
    for (int i = 0; str[i] != '\0'; i++) {
        result[j++] = str[i];
    }
    if (choice == 1)
        result[j++] = '/';
    for (int i = 0; strbis[i] != '\0'; i++) {
        result[j++] = strbis[i];
    }
    return (result);
}
