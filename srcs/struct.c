/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/13 01:29:21 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/24 16:11:53 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		init_ls(t_ls *ls)
{
	ls->nbr_paths = 0;
	ls->paths = NULL;
	ls->opt = 0;
	ls->o_a = 0;
	ls->o_d = 0;
	ls->o_f = 0;
	ls->o_g = 0;
	ls->o_g_cap = 0;
	ls->o_l = 0;
	ls->o_r = 0;
	ls->o_r_cap = 0;
	ls->o_t = 0;
	ls->o_u = 0;
}

t_file		*create_file(char *name, char *path)
{
	t_file		*file;
	char		*pathname;

	file = NULL;
	if (!(file = (t_file*)ft_memalloc(sizeof(t_file))))
		return (NULL);
	if (!path)
		pathname = ft_strdup(name);
	else if (!ft_strcmp(path, "/"))
		pathname = ft_strjoin(path, name);
	else
		pathname = ft_strrjoin(path, name, '/');
	if (lstat(pathname, &(file->s)) == -1)
	{
		ft_strdel(&(name));
		ft_strdel(&(pathname));
		ft_memdel((void**)&(file));
		return (NULL);
	}
	file->usr = getpwuid(file->s.st_uid);
	file->grp = getgrgid(file->s.st_gid);
	file->path = pathname;
	file->name = name;
	return (file);
}

void		free_files(t_file ***file, int nbr_file)
{
	int		i;

	if (*file)
	{
		i = -1;
		while (++i < nbr_file)
		{
			if ((*file)[i])
			{
				if (((*file)[i])->name)
					ft_strdel(&(((*file)[i])->name));
				if (((*file)[i])->path)
					ft_strdel(&(((*file)[i])->path));
				ft_memdel((void**)&((*file)[i]));
			}
		}
		ft_memdel((void**)&(*file));
	}
}

void		free_ls(t_ls *ls)
{
	if (ls)
	{
		if (ls->paths)
			free_files(&ls->paths, ls->nbr_paths);
	}
}
