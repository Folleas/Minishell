/*
** EPITECH PROJECT, 2019
** Minishell
** File description:
** Additional builtins for Minishell
*/

#include "minishell.h"

int build_cd(char const *path)
{
    if (chdir(path) == -1)
        return (84);
    return (0);
}

void build_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i], 1);
        my_putstr("\n", 1);
    }
    return;
}

char **build_setenv(char **env, char **input)
{
    int i = 0;
    char **new_env = NULL;

    while(env[i] != NULL)
        i++;
    new_env = my_realloc_char_darray(env, i, i + 1);
    new_env[i] = my_strcat(my_strcat(input[1], "=", 0), input[2], 0);
    new_env = my_realloc_char_darray(new_env, i, i + 1);
    new_env[i] = NULL;
    return (new_env);
}

int check_exit(char *input)
{
    if (my_strcmp(input, "exit")) {
        my_putstr("exit\n", 1);
        return (1);
    }
    return (0);
}