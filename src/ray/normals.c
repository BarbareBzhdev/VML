/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:15:01 by gpinchon          #+#    #+#             */
/*   Updated: 2017/01/07 16:54:28 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

VEC3	cylinder_normal(VEC3 position, OBJ p, TRANSFORM *t)
{
	VEC3	co;
	VEC3	vpersp;

	co = vec3_sub(position, t->position);
	vpersp = vec3_sub(co, vec3_proj(co, t->rotation));
	return (vec3_normalize(vec3_add(vpersp, vec3_normalize(vpersp))));
	(void)p;
}

VEC3	sphere_normal(VEC3 position, OBJ p, TRANSFORM *t)
{
	return (vec3_normalize((VEC3){
				(position.x - t->position.x) / p.sphere.radius,
				(position.y - t->position.y) / p.sphere.radius,
				(position.z - t->position.z) / p.sphere.radius
			}));
}

VEC3	plane_normal(VEC3 position, OBJ p, TRANSFORM *t)
{
	return (vec3_normalize(t->rotation));
	(void)p;
	(void)position;
}

VEC3	cone_normal(VEC3 position, OBJ p, TRANSFORM *t)
{
	float	radius;
	VEC3	ctop;
	VEC3	qtop;

	ctop = vec3_sub(position, t->position);
	radius = vec3_dot((ctop), t->rotation);
	qtop = vec3_sub(ctop, vec3_scale(t->rotation, radius));
	return (vec3_normalize(vec3_fdiv(qtop, p.cone.radius)));
}
