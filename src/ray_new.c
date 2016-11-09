/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:57:51 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/09 21:22:53 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

RAY			new_ray(VEC3 origin, VEC3 direction)
{
	return ((RAY){origin, direction});
}

INTERSECT	new_intersect()
{
	return ((INTERSECT){
		0, {0, 0}, (VEC3){0, 0, 0}, (VEC3){0, 0, 0}
	});
}
