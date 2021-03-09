/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   browse_folder.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/18 15:55:38 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/24 16:01:52 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	browse_subs(t_ls *ls, t_file **list, char *path, int nbr_file)
{
	int		i;

	if (list)
	{
		i = -1;
		while (++i < nbr_file)
		{
			if (S_ISDIR(list[i]->s.st_mode)
					&& ft_strcmp(list[i]->name, ".") != 0
					&& ft_strcmp(list[i]->name, "..") != 0)
			{
				ft_putstr("\n");
				print_pathname(list[i]->path);
				if (!ft_strcmp(path, "/"))
					browse_folder(ls, ft_strjoin(path, list[i]->name));
				else
					browse_folder(ls, ft_strrjoin(path,
								list[i]->name, '/'));
			}
		}
	}
}

int		number_files(t_ls *ls, char *path)
{
	DIR				*dir;
	int				nbr;
	struct dirent	*entry;

	if (!(dir = opendir(path)))
		return (error_file(path));
	nbr = 0;
	while ((entry = readdir(dir)) != NULL)
		if ((!ls->o_a && (ft_strlen(entry->d_name) > 0
						&& entry->d_name[0] != '.')) || ls->o_a)
			nbr++;
	closedir(dir);
	return (nbr);
}

t_file	**create_list_folder(t_ls *ls, char *path, int *nbr, t_max *max)
{
	DIR				*dir;
	t_file			**list;
	int				i;
	struct dirent	*entry;

	dir = opendir(path);
	list = NULL;
	if (!(list = (t_file**)ft_memalloc(sizeof(t_file*) * (*nbr))))
		return (NULL);
	i = 0;
	while ((entry = readdir(dir)) != NULL)
		if ((!ls->o_a && (ft_strlen(entry->d_name) > 0
						&& entry->d_name[0] != '.')) || ls->o_a)
		{
			list[i] = NULL;
			if (!(list[i] = create_file(ft_strdup(entry->d_name), path)))
				(*nbr)--;
			else
				get_max(ls, list[i++], max);
		}
	closedir(dir);
	return (list);
}

void	browse_folder(t_ls *ls, char *path)
{
	t_max		max;
	int			nbr_file;
	t_file		**list;

	init_max(&max);
	if (!(nbr_file = number_files(ls, path))
			|| !(list = create_list_folder(ls, path, &nbr_file, &max)))
	{
		ft_strdel(&path);
		return ;
	}
	max.nbr_line = max_nbr_line(max);
	if (!ls->o_f)
		merge_sort(ls, list, 0, nbr_file - 1);
	if (ls->o_l)
		print_total(max.block);
	print_folder(ls, list, &max, nbr_file);
	if (!ls->o_l)
		ft_putchar('\n');
	if (ls->o_r_cap)
		browse_subs(ls, list, path, nbr_file);
	free_files(&list, nbr_file);
	ft_strdel(&path);
}
