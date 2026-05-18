/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:19:45 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/30 16:00:15 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mathft.h>

t_vec2	vec2_normalize(t_vec2 u)
{
	t_vec2	w;
	double	u_norm;
	double	inv;

	u_norm = vec2_length(u);
	if (u_norm == 0.0f)
		return (u);
	inv = 1.0 / u_norm;
	w.x = u.x * inv;
	w.y = u.y * inv;
	return (w);
}
