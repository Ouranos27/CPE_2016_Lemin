/*
** my_putstr.c for my_putstr in /home/amaury/CPool_Day04
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Thu Oct  6 12:10:23 2016 Amaury Bernard
** Last update Thu Feb  2 14:43:04 2017 Amaury Bernard
*/

#include "unistd.h"
#include "my.h"

void	my_putstr_err(char *str, int *len)
{
  len += write(2, str, my_strlen(str));
}
