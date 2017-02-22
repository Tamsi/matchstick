/*
** map.c for  in /home/tbesson/projet_cpe/CPE_2016_matchstick
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Wed Feb 22 16:11:29 2017 Tamsi Besson
** Last update Wed Feb 22 16:11:30 2017 Tamsi Besson
*/

#include "my.h"

char **malloc_map2d(int size, int len, char **map)
{
  int i;

  i = 0;
  map = malloc (102 * sizeof(char *));
  while (i < size + 1)
    {
      map[i] = malloc (len * sizeof(char) + 1);
      i++;
    }
  return (map);
}

char *first_line(int len)
{
  char *str;
  int i;

  str = malloc((len + 2) * sizeof(char));
  i = 0;
  while (i < len + 2)
    {
      str[i] = '*';
      i++;
    }
  return (str);
}

char **create_map(int size)
{
  int i;
  int j;
  int len;
  int spaces;
  char **map;

  i = 1;
  len = (size * 2 - 1);
  spaces = size;
  map = malloc_map2d(size, len, map);
  map[0] = first_line(len);
  while (i < size + 1)
    {
      map[i][0] = '*';
      j = 1;
      while (j < len + 1)
        {
          if (j < spaces || j > len - spaces + 1)
            map[i][j] = ' ';
          else
            map[i][j] = '|';
          j++;
        }
      map[i][j] = '*';
      spaces--;
      i++;
    }
  map[i] = map[0];
  return (map);
}

void disp_map(char **map)
{
  int i;

  i = 0;
  while (map[i] != NULL)
    {
      my_putstr(map[i]);
      write(1, "\n", 1);
      i++;
    }
}