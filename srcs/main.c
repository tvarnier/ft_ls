/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/12 02:15:42 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 14:07:09 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_ls	ls;

	init_ls(&ls);
	if (ac >= 2 && (ls.opt = check_options(&ls, av + 1, ac - 1)) == -1)
		return (0);
	ls.paths = pr_paths(&ls, ac, av);
	browse_paths(&ls, ls.paths);
	free_ls(&ls);
	return (0);
}
