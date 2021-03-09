/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pr_paths.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 09:51:01 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 20:48:36 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		error_file(char *name)
{
	ft_putstr("ls: ");
	perror(name);
	return (0);
}

t_file	**pr_paths(t_ls *ls, int ac, char **av)
{
	t_file	**paths;
	int		i;

	ls->nbr_paths = (ac - ls->opt - 1 > 0) ? ac - ls->opt - 1 : 1;
	paths = NULL;
	if (!(paths = (t_file**)ft_memalloc(sizeof(t_file*) * ls->nbr_paths)))
		return (NULL);
	if (ac - ls->opt - 1 > 0)
	{
		i = -1;
		while (++i < ls->nbr_paths)
			if (!(paths[i] = create_file(ft_strdup(av[1 + ls->opt + i]), NULL)))
				error_file(av[1 + ls->opt + i]);
		if (!ls->o_f)
			merge_sort(ls, paths, 0, ls->nbr_paths - 1);
	}
	else
		paths[0] = create_file(ft_strdup("."), NULL);
	return (paths);
}
