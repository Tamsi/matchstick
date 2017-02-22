/*
** algorithm.c for  in /home/tbesson/projet_cpe/CPE_2016_matchstick
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Wed Feb 22 20:05:55 2017 Tamsi Besson
** Last update Wed Feb 22 20:06:05 2017 Tamsi Besson
*/

#include "my.h"

t_heap max_line(char **map)
{
	int j;
  int i;
  int res;
  t_heap line;

  i = 0;
  line.max = 0;
  line.id = 0;
  while (map[i] != NULL)
  {
    j = 0;
    res = 0;
    while (map[i][j] != '\0')
    {
      if (map[i][j] == '|')
        res++;
      j++;
    }
    if (line.max < res)
    {
    	line.id = i;
    	line.max = res;
    }
    i++;
  }
  return (line);
}

int nim_sum(char **map)
{
	int j;
  int i;
  int sum = 0;
  int xor = 0;

  i = 0;
  while (map[i] != NULL)
  {
    j = 0;
    sum = 0;
    while (map[i][j] != '\0')
    {
      if (map[i][j] == '|')
        sum++;
      j++;
    }
    xor = xor ^ sum;
    i++;
  }
  return (xor);
}