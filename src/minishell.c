/*
** EPITECH PROJECT, 2019
** Minishell
** File description:
** Minishell's main functions
*/

#include "minishell.h"

int check_empty_input(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\n') {
            return (0);
        }
    }
    return (1);
}

int minishell(char **paths, char **env)
{
    char **tab_input;
    char *input = NULL;
    int bool = TRUE;
    size_t len = 0;

    while (bool == TRUE) {
        my_putstr("Minishell> ", 1);
        if (getline(&input, &len, stdin) == -1)
            return (-1);
        if (check_empty_input(input) == 0) {
            tab_input = str_to_word_array(input);
            if (check_exit(tab_input[0]))
                break;
            find_func(paths, tab_input, &env);
        }
    }
    free(tab_input[0]);
    free(input);
    free(paths);
    return (0);
}

int main(int ac, char **av, char **env)
{
    char **path_array;
    int path_adress = find_path(env);

    (void)av;
    if (ac != 1)
        return (84);
    split_path(env[path_adress], &path_array);
    minishell(path_array, env);
    return (0);
}
