/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   browse_paths.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/16 16:45:06 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/23 16:28:19 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	**create_list_files(t_ls *ls, t_file **paths, int *nbr, t_max *max)
{
	int				i;
	int				y;
	t_file			**files;

	i = -1;
	while (++i < ls->nbr_paths)
		if (paths[i] && (ls->o_d || !S_ISDIR(paths[i]->s.st_mode)))
			(*nbr)++;
	files = NULL;
	if (!(*nbr) || !(files = (t_file**)ft_memalloc(sizeof(t_file*) * (*nbr))))
		return (NULL);
	init_max(max);
	i = -1;
	y = 0;
	while (++i < ls->nbr_paths)
		if (paths[i] && (ls->o_d || !S_ISDIR(paths[i]->s.st_mode)))
		{
			files[y] = paths[i];
			get_max(ls, files[y++], max);
		}
	return (files);
}

int		print_files(t_ls *ls, t_file **paths)
{
	t_max			max;
	int				nbr_file;
	t_file			**files;

	nbr_file = 0;
	if (!(files = create_list_files(ls, paths, &nbr_file, &max)))
		return (0);
	max.nbr_line = max_nbr_line(max);
	print_folder(ls, files, &max, nbr_file);
	if (!ls->o_l)
		ft_putchar('\n');
	ft_memdel((void**)&(files));
	return (nbr_file);
}

void	print_folders(t_ls *ls, t_file **paths, int nbr_file)
{
	int				i;

	i = -1;
	while (++i < ls->nbr_paths)
	{
		if (paths[i] && S_ISDIR(paths[i]->s.st_mode))
		{
			nbr_file++;
			if (ls->nbr_paths != 1)
				print_pathname(paths[i]->path);
			browse_folder(ls, ft_strdup(paths[i]->path));
			if (ls->nbr_paths != nbr_file)
				ft_putchar('\n');
		}
	}
}

void	browse_paths(t_ls *ls, t_file **paths)
{
	int				i;
	int				nbr_file;
	int				nbr_null;

	nbr_file = print_files(ls, paths);
	i = -1;
	nbr_null = 0;
	while (++i < ls->nbr_paths)
		if (!paths[i])
			nbr_null++;
	if (nbr_file && nbr_file + nbr_null < ls->nbr_paths)
		ft_putchar('\n');
	if (ls->o_d)
		return ;
	print_folders(ls, paths, nbr_file + nbr_null);
}
