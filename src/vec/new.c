/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 18:01:08 by gpinchon          #+#    #+#             */
/*   Updated: 2016/12/03 21:59:12 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

t_vec2	new_vec2(float x, float y)
{
	return ((t_vec2){x, y});
}

t_vec3	new_vec3(float x, float y, float z)
{
	return ((t_vec3){x, y, z});
}

t_vec4	new_vec4(float x, float y, float z, float w)
{
	return ((t_vec4){x, y, z, w});
}
