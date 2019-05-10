/*
** EPITECH PROJECT, 2019
** Minishell
** File description:
** PATH Handling functions
*/

#include "minishell.h"
#include <string.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int find_path(char **env)
{
    int i = 0;

    for (; env[i] != NULL; i++) {
        if (my_strcmp("PATH=", env[i]) == 1)
            break;
    }
    return (i);
}

void manage_exec_errors(pid_t pid)
{
    int wstatus = 0;

    waitpid(pid, &wstatus, WUNTRACED | WCONTINUED);
    if (WIFSIGNALED(wstatus)) {
        if (WTERMSIG(pid) == SIGSEGV) {
            my_putstr("Segmentation fault", 2);
            exit(SIGSEGV + 128);
        }
        if (WTERMSIG(pid) == SIGFPE) {
            my_putstr("Floating exception", 2);
            exit(SIGFPE + 128);
        }
        if (WTERMSIG(pid) == SIGABRT) {
            my_putstr("Abort", 2);
            exit(SIGABRT + 128);
        }
    }
}

void exec_funct(char *path, char **args, char **env)
{
    pid_t pid = fork();

    if (pid == 0) {
        if (execve(path, args, env) == -1)
            exit(-1);
    }
    else if (pid < 0)
        exit(-1);
    else {
        manage_exec_errors(pid);
    }
}

int test_builtins(char **input, char ***env)
{
    if (my_strcmp(input[0], "cd")) {
        build_cd(input[1]);
        return (0);
    }
    if (my_strcmp(input[0], "env")) {
        build_env(*env);
        return (0);
    }
    if (my_strcmp(input[0], "setenv")) {
        *env = build_setenv(*env, input);
        return (0);
    }
    // if (my_strcmp(input[0], "unsetenv"));
    return (-1);
}

int find_func(char **paths, char **input, char ***env)
{
    int ret = 0;

    for (int i = 0; paths[i] != NULL; i++) {
        if (test_builtins(input, env) == 0)
            return (0);
        else if (access(my_strcat(paths[i], input[0], 1), F_OK) == 0) {
            exec_funct(my_strcat(paths[i], input[0], 1), input, *env);
            return (0);
        }
        else
            ret = 1;
    }
    if (ret == 1) {
        my_putstr(input[0], 2);
        my_putstr(": Command not found.\n", 2);
        return (1);
    }
    return (0);
}
