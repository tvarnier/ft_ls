/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_nlink.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/17 14:11:50 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 11:18:08 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_nlink(nlink_t nlink, int max_nlink, int size)
{
	char	*c;
	int		i;

	if (!(c = ft_strinit(' ', max_nlink - size)))
		return ;
	i = -1;
	c[max_nlink - size] = '\0';
	while (++i < max_nlink - size)
		c[i] = ' ';
	ft_putstr(c);
	ft_strdel(&c);
	ft_putnbr(nlink);
}
