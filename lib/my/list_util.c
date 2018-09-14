/*
** list_util.c for list in /home/artha/pushswap
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Wed Nov  9 21:05:57 2016 dylan renard
** Last update Fri Feb 24 23:01:36 2017 dylan renard
*/

#include "my.h"
#include "list.h"
#include <stdlib.h>

void		list_map(t_ld *list)
{
  int		nb_element;
  t_list	*tmp;

  nb_element = 0;
  tmp = list->next;
  while (tmp != NULL)
    {
      if (tmp != NULL)
	{
	  my_putchar('[');
	  my_putchar(']');
	  my_putstr("->");
	  if (tmp->next == NULL)
	    my_putstr("NULL");
	  tmp = tmp->next;
	  nb_element++;
	}
    }
  my_putstr(" taille : ");
  my_put_nbr(nb_element);
}

t_ld		*rot_list(t_ld *list)
{
  t_list	*tmp;
  void		*val;

  tmp = (list->end)->prev;
  if (list != NULL && list->next != list->end)
    {
      val = list->next->data;
      list->next->data = list->end->data;
      list->end->data = val;
      return (list);
    }
  return (list);
}

t_ld		*rot_lf_list(t_ld *list)
{
  t_list	*tmp;

  if (list->end->prev != NULL)
    {
      tmp = list->end;
      list->end = tmp->prev;
      (list->end)->next = NULL;
      tmp->next = list->next;
      list->next = tmp;
      tmp->prev = NULL;
    }
  return (list);
}

t_ld		*rot_fl_list(t_ld *list)
{
  t_list	*tmp;

  if (list->next != list->end)
    {
      tmp = list->next;
      list->next = tmp->next;
      (list->next)->prev = NULL;
      tmp->next = NULL;
      (list->end)->next = tmp;
      tmp->prev = list->end;
      list->end = tmp;
    }
  return (list);
}

t_ld		*swap_list(t_ld *list)
{
  void		*tmp;

  if (list->next != NULL && list->end != NULL)
    {
      tmp = (list->next)->data;
      (list->next)->data = ((list->next)->next)->data;
      ((list->next)->next)->data = tmp;
      return (list);
    }
  return (list);
}
