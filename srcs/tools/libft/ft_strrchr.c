/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:46:54 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/27 00:18:42 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
//        The  strchr()  function  returns a pointer to the first occur‐
//        rence of the character c in the string s.
//
//        The strrchr() function returns a pointer to  the  last  occur‐
//        rence of the character c in the string s.
//
//        The  strchrnul() function is like strchr() except that if c is
//        not found in s, then it returns a pointer to the null byte  at
//        the end of s, rather than NULL.
//
//        Here  "character"  means  "byte";  these functions do not work
//        with wide or multibyte characters.
//
// RETURN VALUE
//        The strchr() and strrchr() functions return a pointer  to  the
//        matched  character or NULL if the character is not found.  The
//        terminating null byte is considered part  of  the  string,  so
//        that  if  c  is  specified  as  '\0', these functions return a
//        pointer to the terminator.
//
//        The strchrnul() function returns  a  pointer  to  the  matched
//        character,  or  a  pointer  to  the  null byte at the end of s
//        (i.e., s+strlen(s)) if the character is not found.
#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + len);
	while (len)
		if (*(s + --len) == (char)c)
			return (s + len);
	return (NULL);
}
