/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maymeric <maymeric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:15:33 by maymeric          #+#    #+#             */
/*   Updated: 2024/03/23 17:46:37 by maymeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(t_list *list)
{
	int i;
	int newline;

	i = 0;
	newline = 0;
	while (list->str[i])
	{
		if (list->str[i] != '\n')
		{
			newline = -1;
			return (newline);
		}
		i++;
	}
	return (newline);
}

t_list	find_last_node(t_list *list)
{
	while(list->next)
		list = list->next;
	return (list);
}
