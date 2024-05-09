/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maymeric <maymeric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:15:33 by maymeric          #+#    #+#             */
/*   Updated: 2024/05/09 15:00:09 by maymeric         ###   ########.fr       */
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


int	len_to_newline(t_list *list)
{
	int	i;
	int	len;

	if (NULL == list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
}

void	copy_str(t_list *list, char *str)
{
	int	i;
	int	k;

	if (NULL == list)
		return ;
	k = 0;
	while (list)
	{
			i = 0;
			while (list->str[i])
			{
				if (list->str[i] = '\n')
				{
					str[k++] = '\n';
					str[k] = '\0';
					return ;
				}
				str[k++] = list->str[i++];
			}
			list = list->next;
	}
	str[k] = '\0';
}

t_list	find_last_node(t_list *list)
{

}
