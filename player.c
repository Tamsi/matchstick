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

int parse_mapline(char **map, int line)
{
  int j;
  int count;

  count = 0;
  j = 0;
  while (map[line][j] != '\0')
  {
    if (map[line][j] == '|')
      count++;
    j++;
  }
  return (count);
}

void matches_remover(char **map, int line, int matches, int player)
{
  int count;
  int i;

  i = my_strlen(map[line]);
  count = 0;
  while (count < matches)
    {
      if (map[line][i] == '|')
        {
          count++;
          map[line][i] = ' ';
        }
      i--;
    }
    if (player == 1)
    {
    	my_putstr("Player removed ");
		  my_put_nbr(matches);
		  my_putstr(" match(es) from line ");
		  my_put_nbr(line);
    }
    else
    {
    	my_putstr("AI removed ");
		  my_put_nbr(matches);
		  my_putstr(" match(es) from line ");
		  my_put_nbr(line);
    }
  write(1, "\n", 1);
  disp_map(map);
}

void ai_play(char **map, char *total_map)
{
	t_heap turn;
	int i;
  int j;
  int res;
  int nim;

  nim = nim_sum(map);
  turn = max_line(map);
  i = 0;
  if (turn.max % 2 != 0)
    turn.max -= 1;
  if (nim != 0)
  {
    printf("%s\n", "rr");
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
      if ((res ^ nim) < res)
      {
        printf("nim = %i, res = %i, xor = %i\n", nim, res, res ^ nim);
        matches_remover(map, i, res ^ nim, 0);
        break;
      }
      i++;
    }
  }
  else
    matches_remover(map, turn.id, turn.max, 0);
}

int parse_gnl(char *str)
{
  int i;

  i = 0;
  if (str == NULL)
    return (1);
  while (str[i])
  {
    if (str[i] < '0' || str[i] > '9')
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (1);
    }
    i++;
  }
  return (0);
}

int play(char **map, char *total_map, char *max_matches)
{
  char *line = NULL;
  char *matches = NULL;
  int l;
  int m;

  while (parse_gnl(line) != 0)
  {
    my_putstr("Line: ");
    line = get_next_line(0);
    if (line == NULL)
      return (-1);
  }
  l = my_getnbr(line);
  if (line_error(l, total_map) != 0)
  {
    play(map, total_map, max_matches);
    return (1);
  }
  while (parse_gnl(matches) != 0)
  {
    my_putstr("Matches: ");
    matches = get_next_line(0);
    if (matches == NULL)
      return (-1);
  }
  m = my_getnbr(matches);
  if (matches_error(m, map, max_matches, l) != 0)
  {
    play(map, total_map, max_matches);
    return (1);
  }
  matches_remover(map, l, m, 1);
  return (0);
}
