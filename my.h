/*
** my.h for  in /home/tbesson/CPE_2016_getnextline
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Sun Jan 15 12:27:22 2017 Tamsi Besson
** Last update Tue Feb  7 02:06:58 2017 Tamsi Besson
*/
#ifndef MATCHSTICK
#define MATCHSTICK
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

typedef struct s_heap
{
	int id;
	int max;
} t_heap;

long	my_getnbr_getsign(char *);
long	my_getnbr_getsign_rank(char *);
long	my_getnbr(char *);
int my_putstr(char *);
int my_strlen(char *);
int my_strcmp(char *, char *);
int disp_usage();
int parse_mapline(char **, int);
int counter(char **);
int line_error(int, char *);
int nim_sum(char **);
int matches_error(int, char **, char *, int);
int play(char **, char *, char *);
char *my_strcat(char *, char *);
char *my_putnbr_base(int, char*);
char *get_next_line(const int);
char *first_line(int);
char **my_str_to_wordtab(char *, char);
char **malloc_map2d(int, int, char **);
char **create_map(int);
void my_put_nbr(int);
void disp_map(char **);
void ai_play(char **, char *);
t_heap max_line(char **);

#endif //MATCHSTICK