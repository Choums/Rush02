/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 11:58:22 by adupuy            #+#    #+#             */
/*   Updated: 2020/07/19 12:25:21 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*int		ft_strlen(char *str)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	if (str[i] == '0')
	{
		while (str[i] == '0')
			i++;
	}
	while (str[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}*/

char	*ft_new(char *str, int len)
{
	char	*new;
	int		i;

	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
//	new[i] = str[i];
//	i++;
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_new2(char c, int len)
{
	char *new;
	int i;

	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	new[i] = c;
	i++;
	while (i < len)
	{
		new[i] = '0';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_split(char *str)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (str == 0)
		return (NULL);
	if (!(split = malloc(sizeof(char*) * (100))))
		return (NULL);
//	if (str[i] == '0')
//	{
//		while (str[i] == '0')
//			i++;
//	}
//	while (str[i] != '\0')
//	{
	if (str[i] != '0')
	{
		split[j] = ft_new(&str[i], 1);
		j++;
		split[j] = ft_new2('1', 3);
		j++;
		i++;
		k++;
	}
	else
		i++;
	if (str[i] == '1' || (str[i] > '1' && str[i + 1] == '0'))
	{
		split[j] = ft_new(&str[i], 2);
		j++;
	}
	if (str[i] == '0' && str[i + 1] != '0')
	{
		split[j] = ft_new(&str[i + 1], 1);
		j++;
	}
//	if (str[i] == '0' && str[i + 1] == '0' && str[i - 1] == '0')
//	{
//		split[j] = ft_new(&str[i + 1], 1);
//		j++;
//	}
	if (str[i] > '1' && str[i + 1] != '0')
	{
		split[j] = ft_new2(str[i], 2);
		j++;
		i++;
		split[j] = ft_new(&str[i], 1);
		j++;
	}
	split[j] = NULL;
	return (split);
}

