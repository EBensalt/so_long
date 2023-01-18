/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:02:52 by ebensalt          #+#    #+#             */
/*   Updated: 2022/05/30 17:09:07 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_my_strrchr(const char *s, int c)
{
	char	a;
	int		b;

	a = (char)c;
	b = 0;
	while (s[b] != '\0')
		b++;
	while (b > 0)
	{
		if (s[b] == a)
			return ((char *)s + b);
		b--;
	}
	if (s[b] == a)
		return ((char *)s + b);
	return (0);
}
