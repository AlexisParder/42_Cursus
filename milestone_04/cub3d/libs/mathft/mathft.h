/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 10:17:21 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/05 13:40:27 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHFT_H
# define MATHFT_H

# include <math.h>

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

t_vec2	vec2_add(t_vec2 u, t_vec2 v);
t_vec2	vec2_sub(t_vec2 u, t_vec2 v);
t_vec2	vec2_scale(t_vec2 u, long k);
double	vec2_cross(t_vec2 u, t_vec2 v);
double	vec2_dot(t_vec2 u, t_vec2 v);
t_vec2	vec2_div(t_vec2	u, long k);
double	vec2_length(t_vec2 u);
t_vec2	vec2_normalize(t_vec2 u);
double	vec2_dist(t_vec2 u, t_vec2 v);

t_vec3	vec3_add(t_vec3 u, t_vec3 v);
t_vec3	vec3_sub(t_vec3 u, t_vec3 v);
t_vec3	vec3_scale(t_vec3 u, long k);
t_vec3	vec3_cross(t_vec3 u, t_vec3 v);
double	vec3_dot(t_vec3 u, t_vec3 v);
t_vec3	vec3_div(t_vec3	u, long k);
double	vec3_length(t_vec3 u);
t_vec3	vec3_normalize(t_vec3 u);

#endif