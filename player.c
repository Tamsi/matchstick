/*
** player.c for  in /home/tbesson/projet_cpe/CPE_2016_matchstick
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Tue Feb 14 17:56:48 2017 Tamsi Besson
** Last update Thu Feb 16 14:16:41 2017 Tamsi Besson
*/

#include "my.h"

int parse_map(char **map)
{
  int i;
  int j;
  int count;

  i = 0;
  count = 0;
  while (map[i])
    {
      j = 0;
      while (map[i][j] != '\0')
        {
          if (map[i][j] == '|')
            count++;
          j++;
        }
      i++;
    }
  return (count);
}

void matches_remover(char **map, int line, int matches)
{
  int count;
  int i;

  i = 0;
  count = 0;
  while (count < matches)
    {
      if (map[line][i] == '|')
        {
          count++;
          map[line][i] = ' ';
        }
      i++;
    }
  my_putstr("Player removed ");
  my_put_nbr(matches);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  write(1, "\n", 1);
}

void play(char **map, char *total_map)
{
  char *line;
  char *matches;
  int l;
  int m;

  my_putstr("Your turn:\nLine: ");
  line = get_next_line(0);
  l = my_getnbr(line);
  my_putstr("Matches: ");
  matches = get_next_line(0);
  m = my_getnbr(matches);
  matches_remover(map, l, m);
  disp_map(map);
  write(1, "\n", 1);
}
