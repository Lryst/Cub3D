/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:50:52 by lryst             #+#    #+#             */
/*   Updated: 2019/11/04 13:00:47 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;
	t_list *lulu;

	tmp = NULL;
	lulu = *lst;
	while (lulu)
	{
		tmp = lulu;
		lulu = lulu->next;
		ft_lstdelone(tmp, del);
	}
	*lst = NULL;
}
