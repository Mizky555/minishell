/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_define.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:19:34 by tliangso          #+#    #+#             */
/*   Updated: 2023/05/31 10:19:50 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_DEFINE_H
# define MINISHELL_DEFINE_H

# define EMPTY 0
# define CMD 256
# define ARG 512
# define TRUNC 1 //>
# define APPEND 2//>>
# define INPUT 4//<
# define HEREDOC 8//<<
# define FPATH 16
# define PIPE 32//|
# define OPEN_P 64
# define CLOSE_P 128

# define SINGLE_Q 1
# define DOUEBLE_Q 2

#endif