/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   file_cmp.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/13 05:14:31 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/24 15:50:43 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int			cmp_time_t(t_file *file1, t_file *file2)
{
	if (file1->s.st_mtime < file2->s.st_mtime)
		return (1);
	else if (file1->s.st_mtime > file2->s.st_mtime)
		return (-1);
	else if (!ft_strlen(file1->name) || !ft_strlen(file2->name))
		return (ft_strcmp(file1->path, file2->path));
	return (ft_strcmp(file1->name, file2->name));
}

int			cmp_time_u(t_file *file1, t_file *file2)
{
	if (file1->s.st_atime < file2->s.st_atime)
		return (1);
	else if (file1->s.st_atime > file2->s.st_atime)
		return (-1);
	else if (!ft_strlen(file1->name) || !ft_strlen(file2->name))
		return (ft_strcmp(file1->path, file2->path));
	return (ft_strcmp(file1->name, file2->name));
}

int			file_cmp(t_ls *ls, t_file *file1, t_file *file2)
{
	int		rev;

	rev = (ls->o_r) ? -1 : 1;
	if (ls->o_u && ls->o_t)
		return (cmp_time_u(file1, file2) * rev);
	if (ls->o_t)
		return (cmp_time_t(file1, file2) * rev);
	else if (!ft_strlen(file1->name) || !ft_strlen(file2->name))
		return (ft_strcmp(file1->path, file2->path) * rev);
	else
		return (ft_strcmp(file1->name, file2->name) * rev);
}

void		merge(t_ls *ls, t_file **arr, t_merge d)
{
	t_file	*tab1[d.n1];
	t_file	*tab2[d.n2];

	d.i = -1;
	while (++d.i < d.n1)
		tab1[d.i] = arr[d.l + d.i];
	d.j = -1;
	while (++d.j < d.n2)
		tab2[d.j] = arr[d.m + 1 + d.j];
	d.i = 0;
	d.j = 0;
	d.k = d.l;
	while (d.i < d.n1 && d.j < d.n2)
	{
		if (tab1[d.i] && tab2[d.j] && file_cmp(ls, tab1[d.i], tab2[d.j]) <= 0)
			arr[d.k] = tab1[d.i++];
		else
			arr[d.k] = tab2[d.j++];
		d.k++;
	}
	while (d.i < d.n1)
		arr[d.k++] = tab1[d.i++];
	while (d.j < d.n2)
		arr[d.k++] = tab2[d.j++];
}

void		merge_sort(t_ls *ls, t_file **arr, int l, int r)
{
	t_merge		d;
	int			m;

	if (l < r)
	{
		m = l + (r - l) / 2;
		merge_sort(ls, arr, l, m);
		merge_sort(ls, arr, m + 1, r);
		d.l = l;
		d.m = m;
		d.r = r;
		d.n1 = d.m - d.l + 1;
		d.n2 = d.r - d.m;
		merge(ls, arr, d);
	}
}
