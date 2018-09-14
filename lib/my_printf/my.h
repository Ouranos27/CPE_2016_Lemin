/*
** my.h for printf in /home/amaury.bernard/PSU_2016_my_printf
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.net>
** 
** Started on  Wed Nov  9 13:49:36 2016 Amaury Bernard
** Last update Thu Feb  2 14:46:12 2017 Amaury Bernard
*/

#ifndef MY_H_
# define MY_H_
# define NB_FLAGS 12
# include <stdarg.h>

typedef struct	s_flags
{
  char		c;
  void		(*ftn)(va_list, int *);
}		t_flags;

int	my_printf(char *str, ...);
int	my_strlen(char *);
void	my_putstr(char *, int *);
void	my_putstr_err(char *, int *);
void	my_putchar(char c, int *);
void    my_put_nbr(long long nb, int *);
int	my_nbr_digits_hex(long long nb);
void	my_put_hex(long long nb, char *hex, int *);
void	my_put_adr(long long nb, int *);
void    my_dec_put_in_bin(unsigned long long nb, int *);
void    my_dec_put_in_oct(unsigned long long nb, int *);
void	my_putstr_all(char *str, int *);
void	flag_s(va_list, int *);
void	flag_S(va_list, int *);
void	flag_c(va_list, int *);
void	flag_d(va_list, int *);
void	flag_p(va_list, int *);
void	flag_x(va_list, int *);
void	flag_X(va_list, int *);
void	flag_b(va_list, int *);
void	flag_o(va_list, int *);
void	flag_mod(va_list, int *);
void	flag_e(va_list, int *);

#endif /* !MY_H_ */
