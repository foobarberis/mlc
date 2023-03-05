/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_perror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:28:15 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/05 16:32:23 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlc.h"

/**
 * @brief Print the string s to stderr. This function does not behave
 * extactly like perror(3) since it only prints the string provided by the
 * caller and does not print a string corresponding to the last value of errno.
 * @param s The error message.
 */
void	f_perror(const char *s)
{
	if (!s || !*s)
		return ;
	write(STDERR_FILENO, s, f_strlen(s));
}
