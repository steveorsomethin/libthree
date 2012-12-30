#include <math.h>
#include <stdlib.h>
#include "internal.h"

/*
* three_vec3
*/
float three_vec3_length_sq(struct three_vec3 const *a)
{
	return three_vec3_dot(a, a);
}

float three_vec3_length(struct three_vec3 const *a)
{
	return sqrt(three_vec3_length_sq(a));
}

float three_vec3_length_manhattan(struct three_vec3 const *a)
{
	return fabs(a->x) + fabs(a->y) + fabs(a->z);
}

void three_vec3_add(struct three_vec3 *a, struct three_vec3 const *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
}

void three_vec3_add_scalar(struct three_vec3 *a, const float s)
{
	a->x += s;
	a->y += s;
	a->z += s;
}

void three_vec3_sub(struct three_vec3 *a, struct three_vec3 const *b)
{
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
}

void three_vec3_mul(struct three_vec3 *a, struct three_vec3 const *b)
{
	a->x *= b->x;
	a->y *= b->y;
	a->z *= b->z;
}

void three_vec3_mul_scalar(struct three_vec3 *a, const float s)
{
	a->x *= s;
	a->y *= s;
	a->z *= s;
}

void three_vec3_div(struct three_vec3 *a, struct three_vec3 const *b)
{	
	a->x /= b->x;
	a->y /= b->y;
	a->z /= b->z;
}

void three_vec3_div_scalar(struct three_vec3 *a, const float s)
{
	if (s == 0.0f) {
		a->x = 0.0f;
		a->y = 0.0f;
		a->z = 0.0f;
	} else {
		a->x /= s;
		a->y /= s;
		a->z /= s;
	}
}

void three_vec3_negate(struct three_vec3 *a)
{
	three_vec3_mul_scalar(a, -1.0f);
}

float three_vec3_dot(struct three_vec3 const *a, struct three_vec3 const *b)
{
	return a->x * b->x + a->y * b->y + a->z * b->z;
}

void three_vec3_normalize(struct three_vec3 *a)
{
	three_vec3_div_scalar(a, three_vec3_length(a));
}

void three_vec3_set_length(struct three_vec3 *a, const float l)
{
	three_vec3_normalize(a);
	three_vec3_mul_scalar(a, l);
}

void three_vec3_lerp(struct three_vec3 *a, struct three_vec3 const *b, const float alpha)
{
	a->x += ( b->x - a->x ) * alpha;
	a->y += ( b->y - a->y ) * alpha;
	a->z += ( b->z - a->z ) * alpha;
}

void three_vec3_cross(struct three_vec3 *a, struct three_vec3 const *b)
{
	float x = a->y * b->z - a->z * b->y;
	float y = a->z * b->x - a->x * b->z;
	float z = a->x * b->y - a->y * b->x;

	a->x = x; 
	a->y = y; 
	a->z = z;
}

float three_vec3_angle_to(struct three_vec3 *a, struct three_vec3 const *b)
{
	return acos(three_vec3_dot(a, b) / three_vec3_length(a) / three_vec3_length(b));
}

float three_vec3_distance_to_sq(struct three_vec3 const *a, struct three_vec3 const *b)
{
	struct three_vec3 tmp_vec = *a;
	three_vec3_sub(&tmp_vec, b);
	return three_vec3_length_sq(&tmp_vec);
}

float three_vec3_distance_to(struct three_vec3 const *a, struct three_vec3 const *b)
{
	return sqrt(three_vec3_distance_to_sq(a, b));
}

int three_vec3_is_zero(struct three_vec3 const *a)
{
	return three_vec3_length_sq(a) < 0.0001f;
}

int three_vec3_eq(struct three_vec3 const *a, struct three_vec3 const *b)
{
	return a->x == b->x && a->y == b->y && a->z == b->z;
}

int three_vec3_fuzzy_eq(struct three_vec3 const *a, struct three_vec3 const *b, const float tolerance)
{
	return !(fabs(a->x - b->x) > tolerance ||
		fabs(a->y - b->y) > tolerance ||
		fabs(a->z - b->z) > tolerance);
}

/*
* three_vec4
*/
float three_vec4_length_sq(struct three_vec4 const *a)
{
	return three_vec4_dot(a, a);
}

float three_vec4_length(struct three_vec4 const *a)
{
	return sqrt(three_vec4_length_sq(a));
}

float three_vec4_length_manhattan(struct three_vec4 const *a)
{
	return fabs(a->x) + fabs(a->y) + fabs(a->z) + fabs(a->w);
}

void three_vec4_add(struct three_vec4 *a, struct three_vec4 const *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
	a->w += b->w;
}

void three_vec4_sub(struct three_vec4 *a, struct three_vec4 const *b)
{
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
	a->w -= b->w;
}

void three_vec4_mul_scalar(struct three_vec4 *a, const float s)
{
	a->x *= s;
	a->y *= s;
	a->z *= s;
	a->w *= s;
}

void three_vec4_div_scalar(struct three_vec4 *a, const float s)
{
	if (s == 0.0f) {
		a->x = 0.0f;
		a->y = 0.0f;
		a->z = 0.0f;
		a->w = 1.0f;
	} else {
		a->x /= s;
		a->y /= s;
		a->z /= s;
		a->w /= s;
	}
}

void three_vec4_negate(struct three_vec4 *a)
{
	three_vec4_mul_scalar(a, -1.0f);
}

float three_vec4_dot(struct three_vec4 const *a, struct three_vec4 const *b)
{
	return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}

void three_vec4_normalize(struct three_vec4 *a)
{
	three_vec4_div_scalar(a, three_vec4_length(a));
}

void three_vec4_set_length(struct three_vec4 *a, const float l)
{
	three_vec4_normalize(a);
	three_vec4_mul_scalar(a, l);
}

void three_vec4_lerp(struct three_vec4 *a, struct three_vec4 const *b, const float alpha)
{
	a->x += ( b->x - a->x ) * alpha;
	a->y += ( b->y - a->y ) * alpha;
	a->z += ( b->z - a->z ) * alpha;
	a->w += ( b->w - a->w ) * alpha;
}

int three_vec4_eq(struct three_vec4 const *a, struct three_vec4 const *b)
{
	return a->x == b->x && a->y == b->y && a->z == b->z && a->w == b->w;
}

int three_vec4_fuzzy_eq(struct three_vec4 const *a, struct three_vec4 const *b, const float tolerance)
{
	return !(fabs(a->x - b->x) > tolerance ||
		fabs(a->y - b->y) > tolerance ||
		fabs(a->z - b->z) > tolerance ||
		fabs(a->w - b->w) > tolerance);
}
