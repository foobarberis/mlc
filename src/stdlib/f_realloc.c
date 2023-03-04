/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_realloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:37:08 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/04 13:47:38 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlc.h"

/**
 * @brief Reall
 * @param p The binary stream.
 * @param ss Size of source.
 * @param n New size.
 * @return
 */
void		*f_realloc(void *p, size_t sp, size_t n)
{
	void *new;

	new = malloc(n);
	if (!new)
		return (NULL);
	if (sp > n)
	f_memmove
}
