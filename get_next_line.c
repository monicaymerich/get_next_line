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

int	read_fd(char *buffer, t_list *list)
{
	int		i;
	t_list	*aux;
	
	i = 0;
	if (!buffer)
		return (-1);
	new_node(list);
	while (buffer[i] != '\n' || buffer[i] != '\0')
	{	
		aux->str[i] = buffer[i];
		i++;
	}

	return (i);
}

char	*get_next_line(int fd)
{
	t_list	*list;
	char	buffer[BUFFER_SIZE + 1];
	int		len;

	list = NULL;
	if (!fd || fd < 0) 
		return (NULL);
	if (read(fd, buffer, BUFFER_SIZE) == -1)
		return (NULL);
	len = read_fd(buffer, list);
	if (len == -1)
		return(NULL);
	return ();
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

int	main(void)
{
	char *test;
	int fd = open("test.txt", O_RDONLY);
	test = get_next_line(fd);
}
