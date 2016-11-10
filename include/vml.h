/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vml.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:13:36 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/10 18:49:59 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VML_H
# define VML_H

# include <math.h>
# define TO_RADIAN(x)	(x * M_PI / 180.f)
# define VEC2			struct s_vec2
# define VEC3			struct s_vec3
# define VEC4			struct s_vec4
# define MAT2			struct s_mat2
# define MAT3			struct s_mat3
# define MAT4			struct s_mat4
# define RAY			struct s_ray
# define INTERSECT		struct s_intersect
# define PRIMITIVE		struct s_primitive
# define FRUSTUM		VEC4
# define FLOAT_ZERO		1E-6
# define DOUBLE_ZERO	0.000001
# define PRIM_TYPE		enum e_prim_type

typedef struct	s_vec2
{
	float		x;
	float		y;
}				t_vec2;

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct	s_vec4
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vec4;

typedef struct	s_mat2
{
	float		m[4];
}				t_mat2;

typedef struct	s_mat3
{
	float		m[9];
}				t_mat3;

typedef struct	s_mat4
{
	float		m[16];
}				t_mat4;

enum e_prim_type
{
	sphere = 0x1,
	plane = 0x3,
	cylinder = 0x3,
	capped_cylinder = 0x31,
	cone = 0x4,
	capped_cone = 0x41
};

typedef	struct	s_primitive
{
	PRIM_TYPE	type;
	float		radius;
	float		radius2;
	float		size;
	t_vec3		position;
	t_vec3		direction;
}				t_primitive;

typedef struct	s_ray
{
	VEC3		origin;
	VEC3		direction;
}				t_ray;

typedef struct	s_intersect
{
	char		intersects;
	float		distance[2];
	VEC3		position;
	VEC3		normal;
}				t_intersect;

/*
** Variable creation functions
*/

VEC3			new_vec3(float x, float y, float z);
VEC4			new_vec4(float x, float y, float z, float w);
MAT2			new_mat2(VEC2 a, VEC2 b);
MAT3			new_mat3(VEC3 a, VEC3 b, VEC3 c);
MAT4			new_mat4(VEC4 a, VEC4 b, VEC4 c, VEC4 d);
FRUSTUM			new_frustum(float left, float right, float bottom, float top);
RAY				new_ray(VEC3 origin, VEC3 direction);
INTERSECT		new_intersect();

/*
** Vectorial operations (in alphabetic order)
*/

VEC2			vec2_add(VEC2 v, VEC2 v1);
VEC3			vec3_add(VEC3 v, VEC3 v1);
VEC4			vec4_add(VEC4 v, VEC4 v1);
VEC3			vec3_cross(VEC3 v, VEC3 v1);
VEC2			vec2_div(VEC2 v, VEC2 v1);
VEC3			vec3_div(VEC3 v, VEC3 v1);
VEC4			vec4_div(VEC4 v, VEC4 v1);
float			vec2_dot(VEC2 v1, VEC2 v2);
float			vec3_dot(VEC3 v1, VEC3 v2);
float			vec4_dot(VEC4 v1, VEC4 v2);
VEC2			vec2_fadd(VEC2 v, float d);
VEC3			vec3_fadd(VEC3 v, float d);
VEC4			vec4_fadd(VEC4 v, float d);
VEC2			vec2_fdiv(VEC2 v, float d);
VEC3			vec3_fdiv(VEC3 v, float d);
VEC4			vec4_fdiv(VEC4 v, float d);
float			vec2_length(VEC2 v);
float			vec3_length(VEC3 v);
float			vec4_length(VEC4 v);
VEC2			vec2_mult(VEC2 v1, VEC2 v2);
VEC3			vec3_mult(VEC3 v1, VEC3 v2);
VEC4			vec4_mult(VEC4 v1, VEC4 v2);
VEC2			vec2_negate(VEC2 v);
VEC3			vec3_negate(VEC3 v);
VEC4			vec4_negate(VEC4 v);
VEC2			vec2_normalize(VEC2 v);
VEC3			vec3_normalize(VEC3 v);
VEC4			vec4_normalize(VEC4 v);
VEC2			vec2_proj(VEC2 v, VEC2 v1);
VEC3			vec3_proj(VEC3 v, VEC3 v1);
VEC4			vec4_proj(VEC4 v, VEC4 v1);
VEC2			vec2_scale(VEC2 v, float f);
VEC3			vec3_scale(VEC3 v, float f);
VEC4			vec4_scale(VEC4 v, float f);
VEC2			vec2_sub(VEC2 v, VEC2 v1);
VEC3			vec3_sub(VEC3 v, VEC3 v1);
VEC4			vec4_sub(VEC4 v, VEC4 v1);
VEC3			mat3_mult_vec3(MAT3 m, VEC3 v);
VEC3			mat4_mult_vec3(MAT4 m, VEC3 v);
VEC4			mat4_mult_vec4(MAT4 m, VEC4 v);
VEC2			vec3_to_vec2(VEC3 v);
VEC3			vec2_to_vec3(VEC2 v);
VEC3			vec4_to_vec3(VEC4 v);
VEC4			vec3_to_vec4(VEC3 v);

/*
** Interpolation functions
*/

VEC3			vec3_interp(float (*interp_function)(float, float, float),
				VEC3 start, VEC3 end, float percent);
VEC4			vec4_interp(float (*interp_function)(float, float, float),
				VEC4 start, VEC4 end, float percent);
float			linear(float start, float end, float percent);
float			cubic(float start, float end, float percent);

/*
** Matrix operations
*/

MAT4			mat4_identity(void);
MAT4			mat4_zero(void);
MAT3			mat3_identity(void);
MAT3			mat3_zero(void);
MAT2			mat2_inverse(const MAT2 m);
MAT3			mat3_inverse(const MAT3 m);
MAT4			mat4_inverse(const MAT4 m);
MAT2			mat2_transpose(const MAT2 m);
MAT3			mat3_transpose(const MAT3 m);
MAT4			mat4_transpose(const MAT4 m);
MAT2			mat2_cofactor(const MAT2 m);
MAT3			mat3_cofactor(const MAT3 m);
MAT4			mat4_cofactor(const MAT4 m);
MAT2			mat2_adjugate(const MAT2 m);
MAT3			mat3_adjugate(const MAT3 m);
MAT4			mat4_adjugate(const MAT4 m);
MAT2			mat2_minors(const MAT2 m);
MAT3			mat3_minors(const MAT3 m);
MAT4			mat4_minors(const MAT4 m);
MAT2			mat2_fmult(MAT2 m, float f);
MAT3			mat3_fmult(MAT3 m, float f);
MAT4			mat4_fmult(MAT4 m, float f);
MAT2			mat2_mult_mat2(MAT2 m, MAT2 m1);
MAT3			mat3_mult_mat3(MAT3 m, MAT3 m1);
MAT4			mat4_mult_mat4(MAT4 m, MAT4 m1);
MAT4			mat4_combine(MAT4 m, MAT4 m1, MAT4 m2);
float			mat2_determinant(MAT2 m);
float			mat3_determinant(MAT3 m);
float			mat4_determinant(MAT4 m);
MAT3			mat4_to_mat3(MAT4 m);
MAT4			mat3_to_mat4(MAT3 m);

/*
** 3D/2D-related matrices creation
*/

MAT2			mat2_rotation(float angle);
MAT3			mat3_rotation(VEC3 axis);
MAT4			mat4_rotation(VEC3 axis);
MAT2			mat2_scale(VEC2 scale);
MAT3			mat3_scale(VEC3 scale);
MAT4			mat4_scale(VEC3 scale);
MAT4			mat4_lookat(VEC3 eye, VEC3 target, VEC3 up);
MAT4			mat4_perspective(float fov, float aspect,
				float z_near, float z_far);
MAT4			mat4_orthographic(FRUSTUM frustum,
				float z_near, float z_far);
MAT4			mat4_translate(VEC3 translation);

/*
** Ray-tracing related functions
*/

INTERSECT		intersect_sphere(PRIMITIVE s, RAY r);
INTERSECT		intersect_cylinder(t_primitive cp, RAY r);
INTERSECT		intersect_plane(t_primitive cp, RAY r);
VEC3			intersect_compute_position(RAY r, float distance);
char			intersect_test(float t[2]);
char			solve_quadratic(float a, float b, float c, float *t);
float			find_closest(float t[2]);
VEC3			cylinder_normal(VEC3 position, PRIMITIVE p);
VEC3			sphere_normal(VEC3 position, PRIMITIVE p);
VEC3			plane_normal(VEC3 position, PRIMITIVE p);
VEC3			cone_normal(VEC3 position, PRIMITIVE p);

char			float_equal(float a, float b);

#endif
