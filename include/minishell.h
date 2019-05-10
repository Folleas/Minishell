/*
** EPITECH PROJECT, 2019
** Minishell
** File description:
** Minishell's header
*/

#ifndef MINISHELL
#define MINISHELL

#define TRUE 1
#define FALSE 0

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

//sentence_to_word.c
char **str_to_word_array(char *str);
char *take_word_from_str(char *str, int tag);
char *my_realloc_char_array(char *array, int size, int new_size);
char **my_realloc_char_darray(char **array, int size, int new_size);
char **sentence_to_wordsbis(char *sentence, int *stat_sentence);
int *count_charactbis(char *sentence);
void split_path(char *str, char ***word_array);
char *fill_word(char *sentence, char *word, int nb_letters, int pars);

//simple_functions.c
int my_strlen_param(char *str, char param);
void my_putstr(char *str, int exit);
int my_strcmp(char *str1, char *str2);
char *my_strcat(char *str, char *strbis, int choice);
int my_strlen(char *str);

//minishell.c
int minishell();

//path_handling.c
int find_path(char **env);
int find_func(char **paths, char **input, char ***env);
void exec_funct(char *path, char **args, char **env);
void manage_exec_errors(pid_t pid);

//added_buildtins.c
int build_cd(char const *path);
int test_builtins(char **input, char ***env);
int check_exit(char *input);
char **build_setenv(char **env, char **input);
void build_env(char **env);

#endif
