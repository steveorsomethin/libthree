#include <math.h>
#include <stdlib.h>
#include "internal.h"

//NOTE: All matrices are column-order when accesing their raw elements
struct three_mat4 three_mat4(float n11, float n12, float n13, float n14,
				float n21, float n22, float n23, float n24,
				float n31, float n32, float n33, float n34,
				float n41, float n42, float n43, float n44)
{
	struct three_mat4 result;
	three_mat4_set(&result,
			n11, n12, n13, n14,
			n21, n22, n23, n24,
			n31, n32, n33, n34,
			n41, n42, n43, n44);

	return result;
}

void three_mat4_set(struct three_mat4 *mat,
			float n11, float n12, float n13, float n14,
			float n21, float n22, float n23, float n24,
			float n31, float n32, float n33, float n34,
			float n41, float n42, float n43, float n44)
{
	float *el = &(mat->el[0]);

	el[0] = n11; el[4] = n12; el[8] = n13; el[12] = n14;
	el[1] = n21; el[5] = n22; el[9] = n23; el[13] = n24;
	el[2] = n31; el[6] = n32; el[10] = n33; el[14] = n34;
	el[3] = n41; el[7] = n42; el[11] = n43; el[15] = n44;
}

struct three_mat4 three_mat4_identity()
{
	return three_mat4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

int three_mat4_eq(struct three_mat4 const *a, struct three_mat4 const *b)
{
	const float *m1 = &(a->el[0]);
	const float *m2 = &(b->el[0]);

	for (int i = 0; i < 16; i++) {
		if (m1[i] != m2[i]) {
			return 0;
		}
	}

 	return 1;
}

int three_mat4_fuzzy_eq(struct three_mat4 const *a, struct three_mat4 const *b, const float tolerance)
{
	const float *m1 = &(a->el[0]);
	const float *m2 = &(b->el[0]);

	for (int i = 0; i < 16; i++) {
		if (fabs(m1[i] - m2[i]) > tolerance) {
			return 0;
		}
	}

 	return 1;
}

void three_mat4_look_at(struct three_mat4 *mat,
			struct three_vec3 const *eye,
			struct three_vec3 const *target,
			struct three_vec3 const *up)
{
	float *m = &(mat->el[0]);
	struct three_vec3 x, y, z;

	z = *eye;
	three_vec3_sub(&z, target);
	three_vec3_normalize(&z);

	if (three_vec3_length(&z) == 0.0f) {
		z.z = 1.0f;
	}

	x = *up;
	three_vec3_cross(&x, &z);
	three_vec3_normalize(&x);

	if (three_vec3_length(&x) == 0.0f) {
		z.x += 0.0001;
		x = *up;
		three_vec3_cross(&x, &z);
		three_vec3_normalize(&x);
	}

	y = z;
	three_vec3_cross(&y, &x);

	m[0] = x.x; m[1] = x.y; m[2] = x.z;
	m[4] = y.x; m[5] = y.y; m[6] = y.z;
	m[8] = z.x; m[9] = z.y; m[10] = z.z;
}

void three_mat4_mul(struct three_mat4 *a, struct three_mat4 const *b)
{
	float *m1 = &(a->el[0]);
	const float *m2 = &(b->el[0]);

	float a11 = m1[0], a12 = m1[4], a13 = m1[8], a14 = m1[12];
	float a21 = m1[1], a22 = m1[5], a23 = m1[9], a24 = m1[13];
	float a31 = m1[2], a32 = m1[6], a33 = m1[10], a34 = m1[14];
	float a41 = m1[3], a42 = m1[7], a43 = m1[11], a44 = m1[15];

	float b11 = m2[0], b12 = m2[4], b13 = m2[8], b14 = m2[12];
	float b21 = m2[1], b22 = m2[5], b23 = m2[9], b24 = m2[13];
	float b31 = m2[2], b32 = m2[6], b33 = m2[10], b34 = m2[14];
	float b41 = m2[3], b42 = m2[7], b43 = m2[11], b44 = m2[15];

	m1[0] = a11 * b11 + a12 * b21 + a13 * b31 + a14 * b41;
	m1[4] = a11 * b12 + a12 * b22 + a13 * b32 + a14 * b42;
	m1[8] = a11 * b13 + a12 * b23 + a13 * b33 + a14 * b43;
	m1[12] = a11 * b14 + a12 * b24 + a13 * b34 + a14 * b44;

	m1[1] = a21 * b11 + a22 * b21 + a23 * b31 + a24 * b41;
	m1[5] = a21 * b12 + a22 * b22 + a23 * b32 + a24 * b42;
	m1[9] = a21 * b13 + a22 * b23 + a23 * b33 + a24 * b43;
	m1[13] = a21 * b14 + a22 * b24 + a23 * b34 + a24 * b44;

	m1[2] = a31 * b11 + a32 * b21 + a33 * b31 + a34 * b41;
	m1[6] = a31 * b12 + a32 * b22 + a33 * b32 + a34 * b42;
	m1[10] = a31 * b13 + a32 * b23 + a33 * b33 + a34 * b43;
	m1[14] = a31 * b14 + a32 * b24 + a33 * b34 + a34 * b44;

	m1[3] = a41 * b11 + a42 * b21 + a43 * b31 + a44 * b41;
	m1[7] = a41 * b12 + a42 * b22 + a43 * b32 + a44 * b42;
	m1[11] = a41 * b13 + a42 * b23 + a43 * b33 + a44 * b43;
	m1[15] = a41 * b14 + a42 * b24 + a43 * b34 + a44 * b44;
}

void three_mat4_mul_scalar(struct three_mat4 *a, const float scalar)
{
	float *el = &(a->el[0]);

	el[0] *= scalar; el[4] *= scalar; el[8] *= scalar; el[12] *= scalar;
	el[1] *= scalar; el[5] *= scalar; el[9] *= scalar; el[13] *= scalar;
	el[2] *= scalar; el[6] *= scalar; el[10] *= scalar; el[14] *= scalar;
	el[3] *= scalar; el[7] *= scalar; el[11] *= scalar; el[15] *= scalar;
}

void three_mat4_mul_vec3(struct three_mat4 const *m, struct three_vec3 *v)
{
	const float *el = &(m->el[0]);

	float vx = v->x;
	float vy = v->y;
	float vz = v->z;

	float d = 1 / (el[3] * vx + el[7] * vy + el[11] * vz + el[15]);

	v->x = (el[0] * vx + el[4] * vy + el[8] * vz + el[12]) * d;
	v->y = (el[1] * vx + el[5] * vy + el[9] * vz + el[13]) * d;
	v->z = (el[2] * vx + el[6] * vy + el[10] * vz + el[14]) * d;
}

void three_mat4_mul_vec4(struct three_mat4 const *m, struct three_vec4 *v)
{
	const float *el = &(m->el[0]);

	float vx = v->x;
	float vy = v->y;
	float vz = v->z;
	float vw = v->w;

	v->x = el[0] * vx + el[4] * vy + el[8] * vz + el[12] * vw;
	v->y = el[1] * vx + el[5] * vy + el[9] * vz + el[13] * vw;
	v->z = el[2] * vx + el[6] * vy + el[10] * vz + el[14] * vw;
	v->w = el[3] * vx + el[7] * vy + el[11] * vz + el[15] * vw;
}

void three_mat4_rotate_axis(struct three_mat4 const *m, struct three_vec3 *v)
{
	const float *el = &(m->el[0]);

	float vx = v->x;
	float vy = v->y;
	float vz = v->z;

	v->x = vx * el[0] + vy * el[4] + vz * el[8];
	v->y = vx * el[1] + vy * el[5] + vz * el[9];
	v->z = vx * el[2] + vy * el[6] + vz * el[10];

	three_vec3_normalize(v);
}
