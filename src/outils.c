#include "../Cub3D.h"

int	ft_strsame(char *s1, char *s2)
{
	int i;
	int j;	

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL || !s1[0] || !s2[0])
		return (0);
	while (s1[i])
	{
		if (s1[i] == s2[j])
		{
			i++;
			j = 0;
		}
		if (s1[i] != s2[j])
			j++;
		if (s2[j] == '\0')
        {
			return (0);
        }
	}
	return (1);
}

/* char	*ft_skip_space_2(char *str, int count)
{
	char *tmp;
	int i;
	int j;

	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(str) - count + 1)))
		return (NULL);
	i = 0;
	while (str[i] == '\t' || str[i] == ' ')
		tmp[j++] = str[i++];
	while (str[i++])
	{
		if (!ft_strspn(ISSPACE, str[i]))
			tmp[j++] = str[i++];
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*ft_skip_space(char *str)
{
	char *tmp;
	int count;
	int i;
	int j;

	j = 0;
	i = 0;
	count = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] == '\t' || str[i] == ' ')
		i++;
	while (str[i++])
	{
		if (ft_strspn(ISSPACE, str[i]))
			count++;
	}
	return (ft_skip_space_2(str, count));
}*/

int		check_position(t_check_struct *ret, t_cub3d *cub)
{
	int i;

	i = 0;
	if (!cub->line)
		return (0);
	while (cub->line[i])
	{
		if (ft_strspn(POSITION, cub->line[i]) == 1)
		{
			++ret->position;
			ret->posY = i;
			cub->orientation = cub->line[i];
			ret->posX = ret->count;
		}
		i++;
	}
	return(1);
}