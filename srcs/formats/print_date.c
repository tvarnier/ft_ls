/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_date.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/17 14:15:17 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 11:04:13 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_date(time_t date)
{
	time_t	t;
	char	*c;
	char	*d;
	int		verif;

	if (!(c = ft_strinit(' ', 12)))
		return ;
	d = ctime(&date);
	t = time(NULL);
	c[0] = d[4];
	c[1] = d[5];
	c[2] = d[6];
	c[4] = d[8];
	c[5] = d[9];
	verif = (t - date >= 15778800);
	c[7] = (verif) ? ' ' : d[11];
	c[8] = (verif) ? d[20] : d[12];
	c[9] = (verif) ? d[21] : ':';
	c[10] = (verif) ? d[22] : d[14];
	c[11] = (verif) ? d[23] : d[15];
	ft_putstr(c);
	ft_strdel(&c);
}
