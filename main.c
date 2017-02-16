/*
** main.c for  in /home/tbesson/projet_cpe/CPE_2016_matchstick
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Tue Feb 14 12:25:08 2017 Tamsi Besson
** Last update Thu Feb 16 14:16:35 2017 Tamsi Besson
*/

#include "my.h"

char **malloc_map2d(int size, int len, char **map)
{
  int i;

  i = 0;
  map = malloc (100 * sizeof(char *));
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
  return ((char **)map);
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

int main(int ac, char **av)
{
  char **map;

  if (ac <= 1)
    return (84);
  map = create_map(my_getnbr(av[1]));
  disp_map(map);
  play(map, av[1]);
  return (0);
}
