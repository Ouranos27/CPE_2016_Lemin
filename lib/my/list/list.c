/*
** list.c for list in /home/artha/pushswap
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Wed Nov  9 19:39:22 2016 dylan renard
** Last update Fri Feb 24 09:25:22 2017 dylan renard
*/

#include "list.h"
#include <stdlib.h>

t_ld		*new_list(void)
{
  t_ld	*list;

  if ((list = malloc(sizeof(t_ld))) == NULL)
    return (NULL);
  list->next = NULL;
  list->end = NULL;
  return (list);
}

int		is_empty_list(t_ld *list)
{
  if (list->next == NULL)
    return (TRUE);
  else
    return (FALSE);
}

t_ld		*push_end_list(t_ld *list, int number)
{
  t_list	*elem;
  t_list	*begin;

  begin = list->next;
  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  elem->number = number;
  elem->next = NULL;
  elem->prev = list->end;
  if (is_empty_list(list))
    {
      list->next = elem;
      list->end = elem;
      return (list);
    }
  list->end = elem;
  elem = elem->prev;
  elem->next = list->end;
  return (list);
}

t_ld		*push_begin_list(t_ld *list, int number)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  if (list->next == NULL)
    list->end = elem;
  elem->number = number;
  elem->next = list->next;
  list->next = elem;
  return (list);
}
