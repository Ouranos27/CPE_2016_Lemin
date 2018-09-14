/*
** my_strlen.c for my_strlen in /home/amaury/delivery/usefull
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Thu Dec 22 19:26:18 2016 Amaury Bernard
** Last update Tue Jan 10 16:33:20 2017 Amaury Bernard
*/

int	my_strlen(char *str)
{
  return (*str ? (1 + my_strlen(++str)) : 0);
}
