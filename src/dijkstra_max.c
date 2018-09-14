/*
** djikstra.c for djikstra.c in /home/maximed/CPE_2016_Lemin/src
** 
** Made by duhommet maxime
** Login   <maximed@epitech.net>
** 
** Started on  Sat Apr 29 16:54:50 2017 duhommet maxime
** Last update Sun Apr 30 15:35:16 2017 duhommet maxime
*/

#include "lemin.h"

int	first_step(t_graph *graph)
{
  int	tmp;
  int	i;
  int	nb_ants;

  ants = 0;
  while (graph->start[i] != graph->end)
    {
      if ((graph->start[i]->nb_ant) > 0)
	nb_ants++;
      i++;
    }
  return (nb_ants);
}
