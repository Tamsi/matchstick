/*
** error.c for  in /home/tbesson/projet_cpe/CPE_2016_matchstick
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Wed Feb 22 16:14:43 2017 Tamsi Besson
** Last update Wed Feb 22 16:14:50 2017 Tamsi Besson
*/

#include "my.h"

int line_error(int line, char *total_map)
{
  if (line > my_getnbr(total_map) || line == 0)
  {
    my_putstr("Error: this line is out of range\n");
    return (1);
  }
  return (0);
}

int matches_error(int matches, char **map, char *max_matches, int line)
{
  if (matches > parse_mapline(map, line))
  {
    my_putstr("Error: not enough matches on this line\n");
    return (1);
  }
  if (matches == 0)
  {
    my_putstr("Error: you have to remove at least one match\n");
    return (1);
  }
  if (max_matches != NULL)
    if (matches > my_getnbr(max_matches))
    {
      my_putstr("Error: you cannot remove more than ");
      my_putstr(max_matches);
      my_putstr(" matches per turn\n");
      return (1);
    }
  return (0);
}