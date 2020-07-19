/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 10:37:29 by adupuy            #+#    #+#             */
/*   Updated: 2020/07/07 14:33:20 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	if (to_find[i] == '\0')
		return (&str[i]);
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			j += 1;
			while (to_find[j] != '\0' && str[i + j] == to_find[j])
				++j;
			{
				if (to_find[j] == '\0')
					return (&str[i]);
			}
		}
		++i;
	}
	return (0);
}
