/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   options.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/12 23:54:57 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 14:05:32 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		error_options(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ls [-");
	ft_putstr(OPTIONS);
	ft_putendl("] [file ...]");
	return (-1);
}

void	add_option(t_ls *ls, char o)
{
	if (o == 'a' || o == 'f')
		ls->o_a = 1;
	if (o == 'd')
		ls->o_d = 1;
	if (o == 'f')
		ls->o_f = 1;
	if (o == 'g')
		ls->o_g = 1;
	if (o == 'G')
		ls->o_g_cap = 1;
	if (o == 'l' || o == 'g')
		ls->o_l = 1;
	if (o == 'r')
		ls->o_r = 1;
	if (o == 'R')
		ls->o_r_cap = 1;
	if (o == 't')
		ls->o_t = 1;
	if (o == 'u')
		ls->o_u = 1;
}

int		check_options(t_ls *ls, char **options, int nbr_options)
{
	int		len;
	int		i;
	int		y;
	int		nbr;

	nbr = 0;
	y = -1;
	while (++y < nbr_options)
	{
		if ((len = ft_strlen(options[y])) < 1 || options[y][0] != '-')
			break ;
		else if (ft_strcmp(options[y], "--"))
		{
			i = 0;
			while (++i < len)
				if (!ft_strchr(OPTIONS, options[y][i]))
					return (error_options(options[y][i]));
				else
					add_option(ls, options[y][i]);
		}
		nbr++;
	}
	return (nbr);
}
