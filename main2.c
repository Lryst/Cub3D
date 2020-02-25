#include "cub3d.h"

int	ft_strsame(char *s1, char *s2)
{
	int i;
	int j;	

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i])
	{
        if (s1[i] == ' ')
        i++;
		if (s1[i] == s2[j])
		{
			i++;
			j = 0;
		}
		if (s1[i] != s2[j])
			j++;
		if (s2[j] == '\0')
        {
            write(1, "0\n", 2);
			return (0);
        }
	}
    write(1, "1\n", 2);
	return (1);
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        ft_strsame(av[1], av[2]);
    }
    return (0);
}