/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:31:53 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/02 18:27:01 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (!dsize)
		return (len);
	i = 0;
	while (src[i] && i < dsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dsize)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dsize <= dst_len)
		return (dsize + src_len);
	ft_strlcpy(dst + dst_len, src, dsize - dst_len);
	return (dst_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*ans;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ans = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ans)
		return (NULL);
	ft_strlcpy(ans, s1, s1_len + 1);
	ft_strlcat(ans, s2, s1_len + s2_len + 1);
	return (ans);
}
