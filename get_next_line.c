/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:57:30 by mmasarov          #+#    #+#             */
/*   Updated: 2023/11/06 09:24:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*file;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_file(&file), NULL);
	line = NULL;
	read_and_stash(fd, &file);
	if (file == NULL)
		return (NULL);
	ft_extract_line(file, &line);
	ft_clean_file(&file);
	if (line == NULL || line[0] == '\0')
	{
		if (line)
			free (line);
		free_file(&file);
		file = NULL;
		return (NULL);
	}
	return (line);
}

void	ft_extract_line(t_list *file, char **line)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (file == NULL)
		return ;
	ft_malloc_line(line, file);
	if (*line == NULL)
		return ;
	while (file)
	{
		i = 0;
		while (file -> content[i])
		{
			if (file -> content[i] == '\n')
			{
				(*line)[j++] = file -> content[i];
				break ;
			}
			(*line)[j++] = file -> content[i++];
		}
		file = file -> next;
	}
	(*line)[j] = '\0';
}

void	ft_malloc_line(char **line, t_list *file)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (file)
	{
		i = 0;
		while (file -> content[i])
		{
			if (file -> content[i] == '\n')
			{
				len++;
				break ;
			}
			i++;
			len++;
		}
		file = file->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	ft_clean_file(t_list **file)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	j = 0;
	i = 0;
	clean_node = malloc(sizeof(t_list));
	if (clean_node == NULL)
		return (free_file(file));
	clean_node -> next = NULL;
	last = ft_get_last(*file);
	while (last -> content[i] && last -> content[i] != '\n')
		i++;
	if (last -> content && last -> content[i] == '\n')
		i++;
	clean_node -> content = malloc(sizeof(char) * ((ft_strlen(last -> content)
					- i) + 1));
	if (clean_node -> content == NULL)
		return (free(clean_node), free_file(file));
	while (last -> content[i])
		clean_node -> content[j++] = last -> content[i++];
	clean_node -> content[j] = '\0';
	free_file(file);
	*file = clean_node;
}

void	free_file(t_list **file)
{
	t_list	*current;
	t_list	*next;

	current = *file;
	while (current)
	{
		free(current -> content);
		next = current -> next;
		free(current);
		current = next;
	}
	*file = NULL;
}
