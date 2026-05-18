/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:08:40 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/30 16:00:15 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mathft.h>

t_vec3	vec3_div(t_vec3	u, long k)
{
	double	inv;
	t_vec3	w;

	if (k == 0)
		return (u);
	inv = 1.0 / k;
	w.x = u.x * inv;
	w.y = u.y * inv;
	w.z = u.z * inv;
	return (w);
}
