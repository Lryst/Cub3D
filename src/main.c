/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:22:52 by lryst             #+#    #+#             */
/*   Updated: 2020/02/21 17:05:52 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strsame(char *s1, char *s2)
{
	int i;
	int j;
    int a;
    char *tab;
	

	i = 0;
    j = 0;
    a = 0;
    if (!(tab = (char*)malloc(sizeof(char) * 4000)))
        return (0);
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i])
	{
        printf("i -> %d\n", i);
		j = 0;
		while (s1[i] == s2[j])
        {
            tab[a] = s1[i];
            a++;
			i++;
        }
		while (s1[i] != s2[j])
        {
            if (s2[j] == '\0')
            {
                j = 0;
                i++;
            }
            else
			    j++;
        }	
	}
    printf("tab -> %s\n", tab);
    free(tab);
    tab = NULL;
	return (1);
}

int main(int ac, char **av)
{
    /*if (ac != 2)
        return (0);
    parsing(open(av[1], O_RDONLY));
    //printf("%d\n", atoi("223,45,0"));
    //system("leaks a.out");*/
    if (ac > 0)
    {
        ft_strsame(av[1], av[2]);
    }
    return (0);
}