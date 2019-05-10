/*
** EPITECH PROJECT, 2019
** Sort Word
** File description:
** Sort word principal .c
*/

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"
#define NB_WORDS stat_sentence[1]

char **sentence_to_wordsbis(char *sentence, int *stat_sentence)
{
    char **words = malloc(sizeof(char *) * NB_WORDS + 1);
    int i = 0;
    int j = 5;
    int which_word = 0;

    for (; sentence[j] != '\0'; j++) {
        if (sentence[j] != ':') {
            i++;
        }
        else {
            words[which_word] = fill_word(sentence, words[which_word], i, j);
            i = 0;
            which_word++;
        }
    }
    return (words);
}

int *count_charactbis(char *sentence)
{
    int count_words = 1;
    int *stat_sentence = malloc(sizeof(int) * 2);
    int i = 5;

    for (; sentence[i] != '\0'; i++) {
        if (sentence[i] == ':') {
            if (sentence[i + 1] != ':' && sentence[i + 2] != '\0')
                count_words++;
        }
    }
    stat_sentence[0] = i;
    NB_WORDS = count_words;
    return (stat_sentence);

}

void split_path(char *str, char ***word_array)
{
    int *stat_sentence = count_charactbis(str);

    *word_array = sentence_to_wordsbis(str, stat_sentence);
    (*word_array)[NB_WORDS - 1] = NULL;
}
