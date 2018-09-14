/*
** my.h for  in /home/Artha77/CPool_infinadd/src
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Sun Oct 23 15:02:00 2016 dylan renard
** Last update Sun Apr 30 23:17:20 2017 dylan renard
*/

#ifndef MY_H_
# define MY_H_
#include <unistd.h>

int	my_putchar(const char c);
int	my_putchar_fd(const char c, const int fd);
int	my_putchar_name(const char c, const char *name);
int	my_putstr_fd(const char *str, const int fd);
int	my_putstr_name(const char *str, const char *name);
int	my_putstr_name_end(const char *str, const char *name);
int	my_power_it(int, int);
int	my_putstr(const char *str);
int	my_puts(const char *str);
int	my_puts_fd(char *str, const int fd);
int	my_puts_name(char *str, const char *name);
int	int_overflow(char *);
int	my_atoi(char *nb);
int	my_puts_name_end(char *str, const char *name);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_strndup(char *, int n);
char	*tab_to_space(char *str);
char	**my_str_to_wordtab(char *str);
char	*to_string(int nbr);
char	*my_strcat(char *base, char *to_add);
int	xopen(const char *path, const int bitmask);
int	xread(int fd, void *buf, int read_size);
void	*xmalloc(long size);
int	my_strlen(const char *str);
char	*my_strcpy(char *dest, const char *src);
int	my_str_isnum(const char *str);
int	is_bt(char c, char a, char b);
char	*my_strdup(const char *str);
void	my_puterr(const char *s);
char	*my_revstr(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
int	my_put_nbr(int);

#endif /* !MY_H_ */
