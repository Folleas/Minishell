/*
** EPITECH PROJECT, 2019
** Sort Word
** File description:
** Sort word principal .c
*/

#include <stdio.h>
#include <stdlib.h>

char *fill_word(char *sentence, char *word, int nb_letters, int pars)
{
    int i = 0;

    word = malloc(sizeof(char) * nb_letters + 1);
    word[nb_letters] = '\0';
    while (i != nb_letters) {
        if (sentence[i + pars - nb_letters] != ' ' && sentence[i + pars - nb_letters] != '\n') {
            word[i] = sentence[i + pars - nb_letters];
            i += 1;
        }
    }
    return (word);
}

char **sentence_to_words(char *sentence, int nb_words)
{
    char **words = malloc(sizeof(char *) * nb_words);
    int i = 0;
    int j = 0;
    int which_word = 0;

    for (; sentence[j] != '\0'; j++) {
        if (sentence[j] != ' ' && sentence[j] != '\t' && sentence[j] != '\n') {
            i++;
        }
        else if (sentence[j + 1] != ' ' && sentence[j + 1] != '\t' && sentence[j + 1] != '\n') {
            words[which_word] = fill_word(sentence, words[which_word], i, j);
            i = 0;
            which_word++;
        }
    }
    return (words);
}

int count_charact(char *str)
{
    int nb_words = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            if (str[i + 1] != ' ' && str[i + 1] != '\t')
                nb_words++;
        }
    }
    return(nb_words);
}