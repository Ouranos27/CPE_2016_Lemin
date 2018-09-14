/*
** list.h for lib in /home/artha/CPE-2016-Pushswap
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Fri Feb 24 09:16:08 2017 dylan renard
** Last update Fri Feb 24 09:55:05 2017 dylan renard
*/

#ifndef LIST_H_
# define LIST_H_
# define LA	0
# define LB	1
# define TRUE	1
# define FALSE	0

typedef struct		s_ld
{
  struct s_list		*next;
  struct s_list		*end;
}			t_ld;

typedef struct		s_list
{
  void			*data;
  struct s_list		*prev;
  struct s_list		*next;
}			t_list;

t_ld	*new_list(void);
int	is_empty_list(t_ld *);
t_ld	*push_end_list(t_ld *, void *);
t_ld	*push_begin_list(t_ld *, void *);
t_ld	*rot_fl_list(t_ld *);
t_ld	*rot_lf_list(t_ld *);
t_ld	*rot_list(t_ld *);
t_ld	*pop_list(t_ld *);
void	list_map(t_ld *);
void	free_list(t_ld *);

#endif /* !LIST_H_ */
