/*
** queue.h for queue in /home/artha/CPE_2016_Lemin
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Apr 30 14:11:04 2017 dylan renard
** Last update Sun Apr 30 23:10:45 2017 dylan renard
*/

#ifndef QUEUE_H_
# define QUEUE_H_
#include "list.h"
#include "tree.h"

typedef		t_ld t_queue;

t_queue		*new_queue(void);
void		enqueue(t_queue *, void *);
struct s_node	*value_of_queue(t_queue *);
void		dequeue(t_queue *);

#endif /* !QUEUE_H_ */
