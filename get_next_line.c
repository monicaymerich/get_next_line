/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maymeric <maymeric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:13:37 by maymeric          #+#    #+#             */
/*   Updated: 2024/03/23 17:48:11 by maymeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	manage_list(t_list **list)

char	*get_line(t_list *list)
{
	int		len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	len =
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

/*
void	func_exemple()
{
	static int x = 0; //Sol s'inicialitza una vegada tot i que la cridis més cops
	printf("%d\n", x);
	x = x + 1;
}
*/
//cada cop que es cridi a la funció x valdrà una mes