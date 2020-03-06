/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:07:02 by lryst             #+#    #+#             */
/*   Updated: 2020/02/26 09:55:12 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_word(char const *s, char c)
{
	int		n;
	int		i;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		s[i] != '\0' ? n++ : 0;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (n);
}

static char			*ft_fill(char const *s, char c, int i, char *tab)
{
	int		k;
	char	*word;

	k = i;
	while (s[k] != c && s[k] != '\0')
		k++;
	word = (char *)malloc(sizeof(char) * (k + 1));
	if (!word)
		return (NULL);
	k = 0;
	while (s[i] != c && s[i] != '\0')
		word[k++] = s[i++];
	word[k] = '\0';
	tab = word;
	return (tab);
}

char				**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		n;
	int		j;

	i = 0;
	n = 0;
	j = -1;
	if (!s)
		return (NULL);
	n = ft_word(s, c);
	if (!(tab = (char **)malloc(sizeof(tab) * (n + 1))))
		return (NULL);
	while (++j < n)
	{
		while (s[i] == c)
			i++;
		tab[j] = ft_fill(s, c, i, tab[j]);
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	tab[j] = 0;
	return (tab);
}
