/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_size.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/17 14:14:41 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 21:02:03 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ins_number(char *c, int number, int i, int len)
{
	int		mod;

	mod = 1;
	while (--len >= 0)
	{
		c[i--] = number / mod % 10 + '0';
		mod *= 10;
	}
}

void	print_major_minor(dev_t st_rdev, t_max *max)
{
	char	*c;

	if (!(c = ft_strinit(' ', max->size)))
		return ;
	ins_number(c, major(st_rdev), max->size - max->minor - 2 - 1,
			ft_intlen(major(st_rdev)));
	c[max->size - max->minor - 2] = ',';
	ins_number(c, minor(st_rdev), max->size - 1,
			ft_intlen(minor(st_rdev)));
	ft_putstr(c);
	ft_strdel(&c);
}

void	print_size(off_t st_size, dev_t st_rdev, t_max *max)
{
	char	*c;
	int		i;
	int		size;

	if (!st_size)
		print_major_minor(st_rdev, max);
	else
	{
		size = ft_intlen(st_size);
		if (!(c = ft_strnew(max->size - size)))
			return ;
		i = -1;
		c[max->size - size] = '\0';
		while (++i < max->size - size)
			c[i] = ' ';
		ft_putstr(c);
		ft_strdel(&c);
		ft_putnbr(st_size);
	}
}
