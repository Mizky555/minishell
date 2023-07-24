/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_spliter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:25:19 by tliangso          #+#    #+#             */
/*   Updated: 2023/05/31 21:27:27 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



static size_t	get_token_size(char *line) //วัดความยาวของ token โดยดัก space กับ ',"
{
	size_t	len;
	char	c;

	len = 0;
	c = 0;//ไว้เก็บค่า ',"
	while (*line && (*line != ' ' || c != 0)) // ไม่หมดบรรทัดและ(หยุดเมื่อspaceหรือ เจอ ",'||)
	{
		if (c == 0 && (*line == '\'' || *line == '\"')) // เมื่อเจอ ',"" แรกจะวนจนกว่าจะเจอตัวปิด else if
			c = *line; 
		else if (*line == c) //เข้าเมื่อเจอ '," ตัวปิด
			c = 0;
		
		line++;
		len++;
	}
	return (len);
}




static char	*get_token(char *line, int *error)
{
	char	*token;
	int		i;
	char	c;

	i = 0;
	c = 0;
	token = (char *)malloc(get_token_size(line) + 1);
	if (!token)
		return (NULL);
	while (*line && (*line != ' ' || c))
	{
		if (c == 0 && (*line == '\'' || *line == '\"'))
			c = *line;
		else if (c == *line)
			c = 0;
		token[i++] = *line++;
	}
	token[i] = '\0';
	if (c != 0)
	{
		free(token);
		*error = 1;
		return (NULL);
	}

	return (token);
}

bool	space_spliter(char *line, t_env *env)
{
	t_token	*token;
	int		error;

	error = 0; // จะโดนเปลี่ยนใน get_token
	skip_whitespace(&line);
	while (*line)
	{
		skip_whitespace(&line);
		token = token_new(get_token(line, &error), EMPTY);
		if (token == NULL)
		{
			if (error == 1)
				ft_putstr_fd("miniopal: parse error\n", 2);
			return (token_clear(&env->token));
		}
		token_addback(&env->token, token);
		if (!*line)
			break ;
		// printf("%s\n", line);
		line = line + ft_strlen(token->token);
		skip_whitespace(&line);
	}
	return (EXIT_SUCCESS);
}

// bool space_spliter(char *line, t_env *env)
// {
// 	t_token	*token;
// 	int		error;

// 	error = 0; // จะโดนเปลี่ยนใน get_token
// 	skip_whitespace(&line);
// 	while (*line)
// 	{
// 		skip_whitespace(&line);
// 		token = token_new(get_token(line, &error), EMPTY);
// 		if (token == NULL)
// 		{
// 			if (error == 1)
// 				ft_putstr_fd("minishell: parse error\n", 2);
// 			return (token_clear(&env->token));
// 		}
// 		token_addback(&env->token, token);
// 		if (!*line)
// 			break ;
// 		// printf("%s\n", line);
// 		line = line + ft_strlen(token->token);
// 		skip_whitespace(&line);
// 	}
// 	return (EXIT_SUCCESS);
// }


// bool	space_spliter(char *line, t_env *env)
// {
// 	t_token	*token;
// 	int		error;

// 	error = 0; // จะโดนเปลี่ยนใน get_token
// 	skip_whitespace(&line);
// 	while (*line)
// 	{
// 		skip_whitespace(&line);
// 		token = token_new(get_token(line, &error), EMPTY);
// 		if (token == NULL)
// 		{
// 			if (error == 1)
// 				ft_putstr_fd("minishell: parse error\n", 2);
// 			return (token_clear(&env->token));
// 		}
// 		token_addback(&env->token, token);
// 		if (!*line)
// 			break ;
// 		// printf("%s\n", line);
// 		line = line + ft_strlen(token->token);
// 		skip_whitespace(&line);
// 	}
// 	return (EXIT_SUCCESS);
// }
// static char	*get_token(char *line, int *error)
// {
// 	char	*token;
// 	int		i;
// 	char	c;
// 	char	v;

// 	i = 0;
// 	c = 0;
// 	v = 0;
// 	token = (char *)malloc(get_token_size(line) + 1);
// 	if (!token)
// 		return (NULL);
// 		printf("\n\n\nHI\n\n\n");
// 	while ((*line && *line != ' ') || (c != 0 || v != 0)) // ไม่หมดบรรทัดและ(หยุดเมื่อspaceหรือ เจอ ",'||)
// 	{
// 		if (*line == '\'' || *line == '\"') // เมื่อเจอ ',"" แรกจะวนจนกว่าจะเจอตัวปิด else if
// 		{
// 			c = *line;
// 			token[i++] = *line++;
// 			while (*line && (*line != ' ' || c != 0)) // ไม่หมดบรรทัดและ(หยุดเมื่อspaceหรือ เจอ ",'||)
// 			{
// 				token[i++] = *line++;
// 				if (*line == c) //เข้าเมื่อเจอ '," ตัวปิด
// 					c = 0;
// 			}
// 		} 
// 		else if (*line == '>' || *line == '<') // เมื่อเจอ '," แรกจะวนจนกว่าจะเจอตัวปิด else if
// 		{
// 			c = *line;
// 			token[i++] = *line++;
// 			while (*line && (*line != ' ' || v != 0)) // ไม่หมดบรรทัดและ(หยุดเมื่อspaceหรือ เจอ ",'||)
// 			{
// 				token[i++] = *line++;
// 				if (*line == v) //เข้าเมื่อเจอ '," ตัวปิด
// 					v = 0;
// 			}
// 		}
// 		token[i++] = *line++;
// 	}
// 	token[i] = '\0';
// 	if (c != 0 || v != 0)
// 	{
// 		free(token);
// 		*error = 1;
// 		return (NULL);
// 	}
// 	return (token);
// }

// static size_t	get_token_size(char *line) //วัดความยาวของ token โดยดัก space กับ ',"
// {
// 	size_t	len;
// 	char	c;
// 	char	v;

// 	len = 0;
// 	c = 0;//ไว้เก็บค่า ',"
// 	v = 0;// ไว้เก็บค่า >,<
// 	while (*line && *line != ' ' && c != 0 && v != 0) // ไม่หมดบรรทัดและ(หยุดเมื่อspaceหรือ เจอ ",'||)
// 	{
// 		if (c == 0 && (*line == '\'' || *line == '\"')) // เมื่อเจอ ',"" แรกจะวนจนกว่าจะเจอตัวปิด else if
// 		{
// 			c = *line;
// 			while (*line && (*line != ' ' || c != 0)) // ไม่หมดบรรทัดและ(หยุดเมื่อspaceหรือ เจอ ",'||)
// 			{
// 				line++;
// 				len++;
// 				if (*line == c) //เข้าเมื่อเจอ '," ตัวปิด
// 					c = 0;
// 			}
// 		} 
// 		else if (v == 0 && (*line == '>' || *line == '<')) // เมื่อเจอ '," แรกจะวนจนกว่าจะเจอตัวปิด else if
// 		{
// 			c = *line;
// 			while (*line && (*line != ' ' || v != 0)) // ไม่หมดบรรทัดและ(หยุดเมื่อspaceหรือ เจอ ",'||)
// 			{
// 				line++;
// 				len++;
// 				if (*line == v) //เข้าเมื่อเจอ '," ตัวปิด
// 					v = 0;
// 			}
// 		} 
// 		line++;
// 		len++;
// 	}
// 	return (len);
// }