/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:27:08 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/26 23:57:31 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	skip_whitespace(char **line)
{
	while (ft_isspace(**line) == 1)
		(*line)++;
}
