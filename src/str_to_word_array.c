/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** str_to_word_array.c
*/

#include <stdlib.h>
#include <stdio.h>

char **my_realloc_char_darray(char **darray, int size, int new_size)
{
    char **new_darray = malloc(sizeof(char *) * new_size);

    for (int i = 0; i != size; i++) {
        new_darray[i] = darray[i];
    }
    // free(darray);
    return (new_darray);
}

char *my_realloc_char_array(char *array, int size, int new_size)
{
    char *new_array = malloc(sizeof(char) * (new_size + 1));

    for (int i = 0; i != size; i++) {
        new_array[i] = array[i];
    }
    free(array);
    return (new_array);
}

char *take_word_from_str(char *str, int tag)
{
    char *word = NULL;
    int count = 0;

    for (int i = tag; str[i] != ' ' && str[i] != '\t' && str[i] != '\0'; i++) {
        word = my_realloc_char_array(word, count, count + 1);
        if (str[i] != '\n')
            word[count++] = str[i];
    }
    word[count] = '\0';
    return (word);
}

char **str_to_word_array(char *str)
{
    char **word_array = NULL;
    int nb_words = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i + 1] != '\0') {
            if (i == 0) {
                word_array = my_realloc_char_darray(word_array, nb_words, nb_words + 1);
                word_array[nb_words++] = take_word_from_str(str, i);
            }
            else if (str[i - 1] == ' ' || str[i - 1] == '\t') {
                word_array = my_realloc_char_darray(word_array, nb_words, nb_words + 1);
                word_array[nb_words++] = take_word_from_str(str, i);
            }
        }
    }
    return (word_array);
}