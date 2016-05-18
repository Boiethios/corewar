/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:21:56 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/10 17:56:38 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	ft_strsplit_alloc(char const *str, char const *c,
							char ***array)
{
	FT_INIT(size_t, i, 0);
	FT_INIT(size_t, nbr, 0);
	FT_INIT(size_t, size, 0);
	FT_INIT(int, gap, 1);
	while (str[i])
	{
		if (ft_strchr(c, str[i]) == NULL)
		{
			++size;
			if (gap)
			{
				++nbr;
				gap = 0;
			}
		}
		else if (!gap)
			gap = 1;
		++i;
	}
	*array = (char **)malloc((nbr + 1) * sizeof(char *));
	**array = (char *)malloc((size + nbr) * sizeof(char));
	(*array)[nbr] = NULL;
	return (nbr);
}

static inline void		ft_strsplit_write(char const *str, char const *c,
							char **array)
{
	FT_INIT(size_t, i, 0);
	FT_INIT(size_t, j, 0);
	FT_INIT(size_t, n, 0);
	FT_INIT(int, gap, 1);
	while (str[i])
	{
		if (ft_strchr(c, str[i]) == NULL)
		{
			array[0][j++] = str[i];
			if (gap)
			{
				array[n++] = *array + j - 1;
				gap = 0;
			}
		}
		else if (!gap)
		{
			array[0][j++] = '\0';
			gap = 1;
		}
		++i;
	}
}

char					**ft_strsplit(char const *str, char const *c)
{
	FT_INIT(char **, array, NULL);
	ft_strsplit_alloc(str, c, &array);
	ft_strsplit_write(str, c, array);
	return (array);
}
