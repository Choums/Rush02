/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 11:50:08 by adupuy            #+#    #+#             */
/*   Updated: 2020/07/19 13:59:12 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strstr(char *str, char *to_find);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strcpy(char *dest, char *src);

void	ft_print_number(char *number)
{
	int j;
	j = 0;
	while (number[j] >= '0' && number[j] <= '9')
		j++;
	while (number[j] == ' ')
		j++;

	if (number[j] == ':')
		j++;
	while (number[j] == ' ')
		j++;
	while (number[j] != '\n')
	{
		ft_putchar(number[j]);
		j++;
	}
	ft_putchar(' ');
}
int main(int argc, char **argv)
{
	int 	k;
	int		fd;
	int		i;
	int		j;
	char	nb[40];
//	char	*nb = malloc(sizeof(char)*15);
	char	*number = malloc(sizeof(char)*1000);
	char	*buffer = malloc(sizeof(char)*1000);
	char	**split;
	char	c;
	int		len;
	char	*num;
	int		o;
	int		l;
	char		*dest;
	
	i = 0;
	j = 0;
//	fd = open("numbers.dict", O_RDONLY);
//	if (fd == -1)
//	{
//		ft_putstr(“Error\n”);
//		return (0);
//		}
	if (argc == 2)
	{
		while (argv[1][i]) //stockage du nombre entre en parametre dans un tab nb
		{
			nb[i] = argv[1][i];
			i++;
		}

		len = ft_strlen(nb);
		dest = malloc(sizeof(char) * (len + 1));
		dest = ft_strcpy(dest, nb);
		if (len == 0)
		{
			dest[i] = '0';
			len = 1;
			fd = open("number.dict", O_RDONLY);
			if (read(fd, buffer, 700) > 0)
			{
				number = ft_strstr(buffer, &dest[i]);
				ft_print_number(number);
			}
		}
		else
		{
			l = 0;
			while (l < len)
			{
				fd = open("numbers.dict", O_RDONLY);
				num = malloc(sizeof(char)*4);
				o = 0;
				num[o] = dest[l];
				o++;
				l++;
				num[o] = dest[l];
				o++;
				l++;
				num[o] = dest[l];
				o++;
				num[o] = '\0';

				split = ft_split(num);
				k = 0;
				if (read(fd, buffer, 700) > 0)
				{
					while (split[k] != '\0')
					{
						number = ft_strstr(buffer, split[k]);
						ft_print_number(number);
						k++;
					}
					free(num);
					free(split);
					close(fd);
				}
				l++;
			}
		//	free(buffer);
		//	free(split);
		}
	}
//	free(nb);
//	free(number);
//	free(buffer);
//	close(fd);
	return (0);
}
