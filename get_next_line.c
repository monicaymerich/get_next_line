/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maymeric <maymeric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:13:37 by maymeric          #+#    #+#             */
/*   Updated: 2024/05/09 15:00:11 by maymeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	manage_list(t_list **list) //BORRA els chars que a hem cuardat fins al '\n'
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buf == NULL || clean_node == NULL)
		return ;
	last_node = find_last_node(*list);
}

char	*get_line(t_list *list)
{
	int		len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	join_str(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		return ;
	else
		last_node->next = new_node;
	new_node->str = buf;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		c_read;
	char	*buf;

	while(find_newline(*list) == 0)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		c_read = read(fd, buf, BUFFER_SIZE);
		if (!c_read)
		{
			free(buf);
			return ;
		}
		buf[c_read] = '\0';
		join_str(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	*list = NULL;
	if (!fd || fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0) 
		return (NULL);
	create_list(&list, fd);
	if(list == NULL)
		return (NULL);
	next_line = get_line(list);
	manage_list(&list);
	return (next_line);
}
