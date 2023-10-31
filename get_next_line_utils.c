/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:58:14 by mmasarov          #+#    #+#             */
/*   Updated: 2023/10/31 10:44:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_and_stash(int fd, t_list **file)
{
	char	*buffer;
	int		was_read;

	was_read = 1;
	while (!find_newline(*file) && was_read != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		was_read = (int)read(fd, buffer, BUFFER_SIZE);
		if ((*file == NULL && was_read == 0) || was_read == -1)
		{
			free(buffer);
			return ;
		}
		buffer[was_read] = '\0';
		add_to_file(file, buffer, was_read);
		free(buffer);
	}
}

int	find_newline(t_list *file)
{
	int		i;
	t_list	*current;

	if (file == NULL)
		return (0);
	current = ft_get_last(file);
	i = 0;
	while (current -> content[i])
	{
		if (current -> content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_get_last(t_list *file)
{
	t_list	*current;

	current = file;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	add_to_file(t_list **file, char *buffer, int was_read)
{
	int		i;
	t_list	*new_node;
	t_list	*last;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node -> next = NULL;
	new_node -> content = malloc(sizeof(char) * (was_read + 1));
	if (new_node -> content == NULL)
		return ;
	i = 0;
	while (buffer[i] && i < was_read)
	{
		new_node -> content[i] = buffer[i];
		i++;
	}
	new_node -> content[i] = '\0';
	if (*file == NULL)
	{
		*file = new_node;
		return ;
	}
	last = ft_get_last(*file);
	last -> next = new_node;
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
