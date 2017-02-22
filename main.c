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

void game_loop(char **map, char **av)
{
  while (1)
  {
    my_putstr("Your turn:\n");
    if (play(map, av[1], av[2]) != 0)
      break;
    if (counter(map) == 0)
    {
      my_putstr("You lost, too bad...\n");
      break;
    }
    write(1, "\n\n", 2);
    my_putstr("AI's turn...\n");
    ai_play(map, av[1]);
    if (counter(map) == 0)
    {
      my_putstr("I lost... snif... but i'll get you next time!!\n");
      break;
    }
    write(1, "\n\n", 1);
  }
}

int counter(char **map)
{
  int j;
  int i;
  int res;

  res = 0;
  i = 0;
  while (map[i] != NULL)
  {
    j = 0;
    while (map[i][j] != '\0')
    {
      if (map[i][j] == '|')
        res++;
      j++;
    }
    i++;
  }
  return (res);
}

int main(int ac, char **av)
{
  char **map;

  if (ac <= 1)
    return (84);
  map = create_map(my_getnbr(av[1]));
  disp_map(map);
  write(1, "\n\n", 2);
  game_loop(map, av);
  return (0);
}
