#ifndef THREE_H
#define THREE_H

//TODO: three_vec2

/*
* three_vec3
*/
struct three_vec3 {
	float x;
	float y;
	float z;
};

float three_vec3_length_sq(struct three_vec3 const *a);

float three_vec3_length(struct three_vec3 const *a);

float three_vec3_length_manhattan(struct three_vec3 const *a);

void three_vec3_add(struct three_vec3 *a, struct three_vec3 const *b);

void three_vec3_add_scalar(struct three_vec3 *a, const float s);

void three_vec3_sub(struct three_vec3 *a, struct three_vec3 const *b);

void three_vec3_mul(struct three_vec3 *a, struct three_vec3 const *b);

void three_vec3_mul_scalar(struct three_vec3 *a, const float s);

void three_vec3_div(struct three_vec3 *a, struct three_vec3 const *b);

void three_vec3_div_scalar(struct three_vec3 *a, const float s);

void three_vec3_negate(struct three_vec3 *a);

float three_vec3_dot(struct three_vec3 const *a, struct three_vec3 const *b);

void three_vec3_normalize(struct three_vec3 *a);

void three_vec3_set_length(struct three_vec3 *a, const float l);

void three_vec3_lerp(struct three_vec3 *a, struct three_vec3 const *b, const float alpha);

void three_vec3_cross(struct three_vec3 *a, struct three_vec3 const *b);

float three_vec3_angle_to(struct three_vec3 *a, struct three_vec3 const *b);

float three_vec3_distance_to_sq(struct three_vec3 const *a, struct three_vec3 const *b);

float three_vec3_distance_to(struct three_vec3 const *a, struct three_vec3 const *b);

int three_vec3_is_zero(struct three_vec3 const *a);

int three_vec3_eq(struct three_vec3 const *a, struct three_vec3 const *b);

int three_vec3_fuzzy_eq(struct three_vec3 const *a, struct three_vec3 const *b, const float tolerance);

//TODO: Create matrix and quaternion functions

// end three_vec3

/*
* three_vec4
*/
struct three_vec4 {
	float x;
	float y;
	float z;
	float w;
};

float three_vec4_length_sq(struct three_vec4 const *a);

float three_vec4_length(struct three_vec4 const *a);

float three_vec4_length_manhattan(struct three_vec4 const *a);

void three_vec4_add(struct three_vec4 *a, struct three_vec4 const *b);

void three_vec4_sub(struct three_vec4 *a, struct three_vec4 const *b);

void three_vec4_mul_scalar(struct three_vec4 *a, const float s);

void three_vec4_div_scalar(struct three_vec4 *a, const float s);

void three_vec4_negate(struct three_vec4 *a);

float three_vec4_dot(struct three_vec4 const *a, struct three_vec4 const *b);

void three_vec4_normalize(struct three_vec4 *a);

void three_vec4_set_length(struct three_vec4 *a, const float l);

void three_vec4_lerp(struct three_vec4 *a, struct three_vec4 const *b, const float alpha);

int three_vec4_eq(struct three_vec4 const *a, struct three_vec4 const *b);

int three_vec4_fuzzy_eq(struct three_vec4 const *a, struct three_vec4 const *b, const float tolerance);

//TODO: Create matrix and quaternion functions

// end three_vec4

/*
* three_mat4
*/
struct three_mat4 {
	float el[16];
};

struct three_mat4 three_mat4(float n11, float n12, float n13, float n14,
							float n21, float n22, float n23, float n24,
							float n31, float n32, float n33, float n34,
							float n41, float n42, float n43, float n44);

void three_mat4_set(struct three_mat4 *mat,
					float n11, float n12, float n13, float n14,
					float n21, float n22, float n23, float n24,
					float n31, float n32, float n33, float n34,
					float n41, float n42, float n43, float n44);

struct three_mat4 three_mat4_identity();

int three_mat4_eq(struct three_mat4 const *a, struct three_mat4 const *b);

int three_mat4_fuzzy_eq(struct three_mat4 const *a, struct three_mat4 const *b, const float tolerance);

void three_mat4_look_at(struct three_mat4 *mat,
						struct three_vec3 const *eye,
						struct three_vec3 const *target,
						struct three_vec3 const *up);

void three_mat4_mul(struct three_mat4 *a, struct three_mat4 const *b);

void three_mat4_mul_scalar(struct three_mat4 *a, const float scalar);

void three_mat4_mul_vec3(struct three_mat4 const *m, struct three_vec3 *v);

void three_mat4_mul_vec4(struct three_mat4 const *m, struct three_vec4 *v);

void three_mat4_rotate_axis(struct three_mat4 const *m, struct three_vec3 *v);

#endif /* THREE_H */