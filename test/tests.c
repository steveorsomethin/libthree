#include <stdio.h>
#include <assert.h>
#include <three.h>
#include "tests.h"

/*
* three_vec3
*/

#define DEFAULT_VEC3 {10.0f, 20.0f, 30.0f}

TEST(three_vec3_length_sq)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;

	float result = three_vec3_length_sq(&vec1);

	TEST_ASSERT(result == 1400.0f);
}

TEST(three_vec3_length)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;

	float result = three_vec3_length(&vec1);

	TEST_ASSERT(result == 37.4165738677f);
}

TEST(three_vec3_length_manhattan)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;

	float result = three_vec3_length_manhattan(&vec1);

	TEST_ASSERT(result == 60.0f);
}

TEST(three_vec3_add)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 vec2 = {9.0f, 18.0f, 27.0f};
	struct three_vec3 assert_vec = {19.0f, 38.0f, 57.0f};
	three_vec3_add(&vec1, &vec2);
	
	TEST_ASSERT(three_vec3_eq(&vec1, &assert_vec));
}

TEST(three_vec3_add_scalar)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 assert_vec = {15.0f, 25.0f, 35.0f};
	three_vec3_add_scalar(&vec1, 5.0f);
	
	TEST_ASSERT(three_vec3_eq(&vec1, &assert_vec));
}

TEST(three_vec3_sub)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 vec2 = {9.0f, 18.0f, 27.0f};
	struct three_vec3 assert_vec = {1.0f, 2.0f, 3.0f};
	three_vec3_sub(&vec1, &vec2);
	
	TEST_ASSERT(three_vec3_eq(&vec1, &assert_vec));
}

TEST(three_vec3_mul)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 vec2 = {1.0f, 2.0f, 3.0f};
	struct three_vec3 assert_vec = {10.0f, 40.0f, 90.0f};
	three_vec3_mul(&vec1, &vec2);
	
	TEST_ASSERT(three_vec3_eq(&vec1, &assert_vec));
}

TEST(three_vec3_mul_scalar)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 assert_vec = {20.0f, 40.0f, 60.0f};
	three_vec3_mul_scalar(&vec1, 2.0f);
	
	TEST_ASSERT(three_vec3_eq(&vec1, &assert_vec));
}

TEST(three_vec3_div)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 vec2 = {5.0f, 4.0f, 3.0f};
	struct three_vec3 assert_vec = {2.0f, 5.0f, 10.0f};
	three_vec3_div(&vec1, &vec2);
	
	TEST_ASSERT(three_vec3_eq(&vec1, &assert_vec));
}

TEST(three_vec3_div_scalar)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 assert_vec = {5.0f, 10.0f, 15.0f};
	three_vec3_div_scalar(&vec1, 2.0f);
	
	TEST_ASSERT(three_vec3_eq(&vec1, &assert_vec));
}

TEST(three_vec3_div_scalar_by_zero)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 assert_vec = {0.0f, 0.0f, 0.0f};
	three_vec3_div_scalar(&vec1, 0.0f);
	
	TEST_ASSERT(three_vec3_eq(&vec1, &assert_vec));
}

TEST(three_vec3_negate)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 assert_vec = {-10.0f, -20.0f, -30.0f};
	three_vec3_negate(&vec1);
	
	TEST_ASSERT(three_vec3_eq(&vec1, &assert_vec));
}

TEST(three_vec3_dot)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 vec2 = {2.0f, 2.0f, 2.0f};

	float result = three_vec3_dot(&vec1, &vec2);

	TEST_ASSERT(result == 120.0f);
}

TEST(three_vec3_normalize)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 assert_vec = {0.2672612419124244f, 0.5345224838248488f, 0.8017837257372731f};
	three_vec3_normalize(&vec1);
	
	TEST_ASSERT(three_vec3_eq(&vec1, &assert_vec));
}

TEST(three_vec3_set_length)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 assert_vec = {0.5345224838248488f, 1.0690449676496976, 1.6035674514745462};
	three_vec3_set_length(&vec1, 2.0f);
	
	TEST_ASSERT(three_vec3_eq(&vec1, &assert_vec));
}

TEST(three_vec3_lerp)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 vec2 = {1.0f, 2.0f, 3.0f};
	struct three_vec3 assert_vec = {-8.0f, -16.0f, -24.0f};
	three_vec3_lerp(&vec1, &vec2, 2.0f);
	
	TEST_ASSERT(three_vec3_eq(&vec1, &assert_vec));
}

TEST(three_vec3_cross)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 vec2 = {1.0f, 2.0f, 3.0f};
	struct three_vec3 assert_vec = {0.0f, 0.0f, 0.0f};
	three_vec3_cross(&vec1, &vec2);

	TEST_ASSERT(three_vec3_eq(&vec1, &assert_vec));
}

TEST(three_vec3_angle_to)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 vec2 = {1.0f, 2.0f, 3.0f};
	float result = three_vec3_angle_to(&vec1, &vec2);

	TEST_ASSERT(result == 0.0f);
}

TEST(three_vec3_distance_to_sq)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 vec2 = {1.0f, 2.0f, 3.0f};
	float result = three_vec3_distance_to_sq(&vec1, &vec2);

	TEST_ASSERT(result == 1134.0f);
}

TEST(three_vec3_distance_to)
{
	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 vec2 = {1.0f, 2.0f, 3.0f};
	float result = three_vec3_distance_to(&vec1, &vec2);

	TEST_ASSERT(result == 33.67491648096547f);
}

TEST(three_vec3_fuzzy_eq)
{
	struct three_vec3 vec1 = {1.0f, 2.0f, 3.0f};
	struct three_vec3 vec2 = {1.1f, 2.1f, 3.1f};
	int result = three_vec3_fuzzy_eq(&vec1, &vec2, 0.2f) && !three_vec3_fuzzy_eq(&vec1, &vec2, 0.05f);

	TEST_ASSERT(result);
}

TEST(three_vec3_is_zero)
{
	struct three_vec3 vec1 = {0.0f, 0.0f, 0.0f};

	TEST_ASSERT(three_vec3_is_zero(&vec1));
}

/*
* three_vec4
*/
#define DEFAULT_VEC4 {10.0f, 20.0f, 30.0f, 40.0f}

TEST(three_vec4_length_sq)
{
	struct three_vec4 vec1 = DEFAULT_VEC4;

	float result = three_vec4_length_sq(&vec1);

	TEST_ASSERT(result == 3000.0f);
}

TEST(three_vec4_length)
{
	struct three_vec4 vec1 = DEFAULT_VEC4;

	float result = three_vec4_length(&vec1);
	
	TEST_ASSERT(result == 54.772255f);
}

TEST(three_vec4_length_manhattan)
{
	struct three_vec4 vec1 = DEFAULT_VEC4;

	float result = three_vec4_length_manhattan(&vec1);
	
	TEST_ASSERT(result == 100.0f);
}

TEST(three_vec4_add)
{
	struct three_vec4 vec1 = DEFAULT_VEC4;
	struct three_vec4 vec2 = {9.0f, 18.0f, 27.0f, 36.0f};
	struct three_vec4 assert_vec = {19.0f, 38.0f, 57.0f, 76.0f};
	three_vec4_add(&vec1, &vec2);
	
	TEST_ASSERT(three_vec4_eq(&vec1, &assert_vec));
}

TEST(three_vec4_sub)
{
	struct three_vec4 vec1 = DEFAULT_VEC4;
	struct three_vec4 vec2 = {9.0f, 18.0f, 27.0f, 36.0f};
	struct three_vec4 assert_vec = {1.0f, 2.0f, 3.0f, 4.0f};
	three_vec4_sub(&vec1, &vec2);
	
	TEST_ASSERT(three_vec4_eq(&vec1, &assert_vec));
}

TEST(three_vec4_mul_scalar)
{
	struct three_vec4 vec1 = DEFAULT_VEC4;
	struct three_vec4 assert_vec = {20.0f, 40.0f, 60.0f, 80.0f};
	three_vec4_mul_scalar(&vec1, 2.0f);
	
	TEST_ASSERT(three_vec4_eq(&vec1, &assert_vec));
}

TEST(three_vec4_div_scalar)
{
	struct three_vec4 vec1 = DEFAULT_VEC4;
	struct three_vec4 assert_vec = {5.0f, 10.0f, 15.0f, 20.0f};
	three_vec4_div_scalar(&vec1, 2.0f);
	
	TEST_ASSERT(three_vec4_eq(&vec1, &assert_vec));
}

TEST(three_vec4_div_scalar_by_zero)
{
	struct three_vec4 vec1 = DEFAULT_VEC4;
	struct three_vec4 assert_vec = {0.0f, 0.0f, 0.0f, 1.0f};
	three_vec4_div_scalar(&vec1, 0.0f);
	
	TEST_ASSERT(three_vec4_eq(&vec1, &assert_vec));
}

TEST(three_vec4_negate)
{
	struct three_vec4 vec1 = DEFAULT_VEC4;
	struct three_vec4 assert_vec = {-10.0f, -20.0f, -30.0f, -40.0f};
	three_vec4_negate(&vec1);
	
	TEST_ASSERT(three_vec4_eq(&vec1, &assert_vec));
}

TEST(three_vec4_dot)
{
	struct three_vec4 vec1 = DEFAULT_VEC4;
	struct three_vec4 vec2 = {2.0f, 2.0f, 2.0f, 2.0f};

	float result = three_vec4_dot(&vec1, &vec2);

	TEST_ASSERT(result == 200.0f);
}

TEST(three_vec4_normalize)
{
	struct three_vec4 vec1 = DEFAULT_VEC4;
	struct three_vec4 assert_vec =
		{0.18257418583505536f, 0.3651483716701107f, 0.5477225575051661f, 0.7302967433402214f};
	three_vec4_normalize(&vec1);
	
	TEST_ASSERT(three_vec4_eq(&vec1, &assert_vec));
}

TEST(three_vec4_set_length)
{
	struct three_vec4 vec1 = DEFAULT_VEC4;
	
	struct three_vec4 assert_vec = {0.3651483716701107f, 0.7302967433402214f, 1.0954451150103321f, 1.4605934866804429f};
	three_vec4_set_length(&vec1, 2.0f);
	
	TEST_ASSERT(three_vec4_eq(&vec1, &assert_vec));
}

TEST(three_vec4_lerp)
{
	struct three_vec4 vec1 = DEFAULT_VEC4;
	struct three_vec4 vec2 = {1.0f, 2.0f, 3.0f, 4.0f};
	struct three_vec4 assert_vec = {-8.0f, -16.0f, -24.0f, -32.0f};
	three_vec4_lerp(&vec1, &vec2, 2.0f);
	
	TEST_ASSERT(three_vec4_eq(&vec1, &assert_vec));
}

TEST(three_vec4_fuzzy_eq)
{
	struct three_vec4 vec1 = {1.0f, 2.0f, 3.0f, 4.0f};
	struct three_vec4 vec2 = {1.1f, 2.1f, 3.1f, 4.1f};
	int result = three_vec4_fuzzy_eq(&vec1, &vec2, 0.2f) && !three_vec4_fuzzy_eq(&vec1, &vec2, 0.05f);

	TEST_ASSERT(result);
}

/*
* three_mat4
*/
#define DEFAULT_MAT4				\
	three_mat4(						\
		1.0f, 2.0f, 3.0f, 4.0f,		\
		5.0f, 6.0f, 7.0f, 8.0f,		\
		9.0f, 10.0f, 11.0f, 12.0f,	\
		13.0f, 14.0f, 15.0f, 16.0f	\
	)

TEST(three_mat4_identity)
{
	struct three_mat4 mat1 = three_mat4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	struct three_mat4 mat2 = three_mat4_identity();

	TEST_ASSERT(three_mat4_eq(&mat1, &mat2));
}

TEST(three_mat4_fuzzy_eq)
{
	struct three_mat4 mat1 = three_mat4_identity();

	struct three_mat4 mat2 = three_mat4(
		1.1f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.1f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.1f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.1f
	);

	TEST_ASSERT(three_mat4_fuzzy_eq(&mat1, &mat2, 0.2f) && !three_mat4_fuzzy_eq(&mat1, &mat2, 0.05f));
}

TEST(three_mat4_look_at)
{
	struct three_mat4 mat1 = three_mat4_identity();
	struct three_mat4 assert_mat = three_mat4(
		-0.7071067690849304f, -0.40824830532073975f, -0.5773502588272095f, 0.0f,
		0.0f, 0.8164966106414795f, -0.5773502588272095f, 0.0f,
		0.7071067690849304f, -0.40824830532073975f, -0.5773502588272095f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);

	struct three_vec3 eye = {0.0f, 0.0f, 0.0f};
	struct three_vec3 target = {1.0f, 1.0f, 1.0f};
	struct three_vec3 up = {0.0f, 1.0f, 0.0f};

	three_mat4_look_at(&mat1, &eye, &target, &up);

	TEST_ASSERT(three_mat4_fuzzy_eq(&mat1, &assert_mat, 0.0001f));
}

TEST(three_mat4_mul)
{
	struct three_mat4 mat1 = DEFAULT_MAT4;

	struct three_mat4 mat2 = mat1;
	struct three_mat4 assert_mat = three_mat4(
		90.0f, 100.0f, 110.0f, 120.0f,
		202.0f, 228.0f, 254.0f, 280.0f,
		314.0f, 356.0f, 398.0f, 440.0f,
		426.0f, 484.0f, 542.0f, 600.0f
	);

	three_mat4_mul(&mat1, &mat2);

	TEST_ASSERT(three_mat4_fuzzy_eq(&mat1, &assert_mat, 0.1f));
}

TEST(three_mat4_mul_scalar)
{
	struct three_mat4 mat1 = DEFAULT_MAT4;

	struct three_mat4 assert_mat = three_mat4(
		2.0f, 4.0f, 6.0f, 8.0f,
		10.0f, 12.0f, 14.0f, 16.0f,
		18.0f, 20.0f, 22.0f, 24.0f,
		26.0f, 28.0f, 30.0f, 32.0f
	);

	three_mat4_mul_scalar(&mat1, 2.0f);

	TEST_ASSERT(three_mat4_fuzzy_eq(&mat1, &assert_mat, 0.1f));
}

TEST(three_mat4_mul_vec3)
{
	struct three_mat4 mat1 = DEFAULT_MAT4;

	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 assert_vec = {0.1643835616438356f, 0.4429223744292237f, 0.7214611872146118f};

	three_mat4_mul_vec3(&mat1, &vec1);

	TEST_ASSERT(three_vec3_fuzzy_eq(&vec1, &assert_vec, 0.1f));
}

TEST(three_mat4_mul_vec4)
{
	struct three_mat4 mat1 = DEFAULT_MAT4;

	struct three_vec4 vec1 = DEFAULT_VEC4;
	struct three_vec4 assert_vec = {300.0f, 700.0f, 1100.0f, 1500.0f};

	three_mat4_mul_vec4(&mat1, &vec1);

	TEST_ASSERT(three_vec4_fuzzy_eq(&vec1, &assert_vec, 0.1f));
}

TEST(three_mat4_rotate_axis)
{
	struct three_mat4 mat1 = DEFAULT_MAT4;

	struct three_vec3 vec1 = DEFAULT_VEC3;
	struct three_vec3 assert_vec = {0.18905114525312228f, 0.5131388228299033f, 0.8372265004066844f};

	three_mat4_rotate_axis(&mat1, &vec1);

	TEST_ASSERT(three_vec3_fuzzy_eq(&vec1, &assert_vec, 0.1f));
}

TEST(three_mat4_cross_vec4)
{
	struct three_mat4 mat1 = DEFAULT_MAT4;

	struct three_vec4 vec1 = DEFAULT_VEC4;
	struct three_vec4 vec2;
	struct three_vec4 assert_vec = {300.0f, 700.0f, 1100.0f, 1500.0f};

	three_mat4_cross_vec4(&mat1, &vec1, &vec2);

	TEST_ASSERT(three_vec4_fuzzy_eq(&vec2, &assert_vec, 0.1f));
}

TEST(three_mat4_determinant)
{
	struct three_mat4 mat1 = three_mat4(
		11.0f, 12.0f, 0.0f, 14.0f,
		21.0f, 22.0f, 0.0f, 24.0f,
		31.0f, 3.0f, 3.0f, 0.0f,
		41.0f, 4.0f, 4.0f, 0.0f
	);

	float result = three_mat4_determinant(&mat1);

	TEST_ASSERT(result == 20.0f);
}

TEST(three_mat4_transpose)
{
	struct three_mat4 mat1 = DEFAULT_MAT4;

	struct three_mat4 assert_mat = three_mat4(
		1.0f, 5.0f, 9.0f, 13.0f,
		2.0f, 6.0f, 10.0f, 14.0f,
		3.0f, 7.0f, 11.0f, 15.0f,
		4.0f, 8.0f, 12.0f, 16.0f
	);

	three_mat4_transpose(&mat1);

	TEST_ASSERT(three_mat4_fuzzy_eq(&mat1, &assert_mat, 0.1f));
}

TEST(three_mat4_get_pos)
{
	struct three_mat4 mat1 = DEFAULT_MAT4;

	struct three_vec3 vec1;
	struct three_vec3 assert_vec = {4.0f, 8.0f, 12.0f};

	three_mat4_get_pos(&mat1, &vec1);

	TEST_ASSERT(three_vec3_fuzzy_eq(&vec1, &assert_vec, 0.1f));
}

TEST(three_mat4_set_pos)
{
	struct three_mat4 mat1 = DEFAULT_MAT4;

	struct three_vec3 vec1 = {8.0f, 16.0f, 24.0f};

	struct three_mat4 assert_mat = three_mat4(
		1.0f, 2.0f, 3.0f, 8.0f,
		5.0f, 6.0f, 7.0f, 16.0f,
		9.0f, 10.0f, 11.0f, 24.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);

	three_mat4_set_pos(&mat1, &vec1);

	TEST_ASSERT(three_mat4_fuzzy_eq(&mat1, &assert_mat, 0.1f));
}

TEST(three_mat4_get_col_x)
{
	struct three_mat4 mat1 = DEFAULT_MAT4;

	struct three_vec3 vec1;
	struct three_vec3 assert_vec = {1.0f, 5.0f, 9.0f};

	three_mat4_get_col_x(&mat1, &vec1);

	TEST_ASSERT(three_vec3_fuzzy_eq(&vec1, &assert_vec, 0.1f));
}

TEST(three_mat4_get_col_y)
{
	struct three_mat4 mat1 = DEFAULT_MAT4;

	struct three_vec3 vec1;
	struct three_vec3 assert_vec = {2.0f, 6.0f, 10.0f};

	three_mat4_get_col_y(&mat1, &vec1);

	TEST_ASSERT(three_vec3_fuzzy_eq(&vec1, &assert_vec, 0.1f));
}

TEST(three_mat4_get_col_z)
{
	struct three_mat4 mat1 = DEFAULT_MAT4;

	struct three_vec3 vec1;
	struct three_vec3 assert_vec = {3.0f, 7.0f, 11.0f};

	three_mat4_get_col_z(&mat1, &vec1);

	TEST_ASSERT(three_vec3_fuzzy_eq(&vec1, &assert_vec, 0.1f));
}

int main()
{
	START_TESTS

		//Vector
		TEST_ADD(three_vec3_length_sq)
		TEST_ADD(three_vec3_length)
		TEST_ADD(three_vec3_length_manhattan)
		TEST_ADD(three_vec3_add)
		TEST_ADD(three_vec3_add_scalar)
		TEST_ADD(three_vec3_sub)
		TEST_ADD(three_vec3_mul)
		TEST_ADD(three_vec3_mul_scalar)
		TEST_ADD(three_vec3_div)
		TEST_ADD(three_vec3_div_scalar)
		TEST_ADD(three_vec3_div_scalar_by_zero)
		TEST_ADD(three_vec3_negate)
		TEST_ADD(three_vec3_dot)
		TEST_ADD(three_vec3_normalize)
		TEST_ADD(three_vec3_set_length)
		TEST_ADD(three_vec3_lerp)
		TEST_ADD(three_vec3_cross)
		TEST_ADD(three_vec3_angle_to)
		TEST_ADD(three_vec3_distance_to_sq)
		TEST_ADD(three_vec3_distance_to)
		TEST_ADD(three_vec3_fuzzy_eq)
		TEST_ADD(three_vec3_is_zero)
		TEST_ADD(three_vec4_length_sq)
		TEST_ADD(three_vec4_length)
		TEST_ADD(three_vec4_length_manhattan)
		TEST_ADD(three_vec4_add)
		TEST_ADD(three_vec4_sub)
		TEST_ADD(three_vec4_mul_scalar)
		TEST_ADD(three_vec4_div_scalar)
		TEST_ADD(three_vec4_div_scalar_by_zero)
		TEST_ADD(three_vec4_negate)
		TEST_ADD(three_vec4_dot)
		TEST_ADD(three_vec4_normalize)
		TEST_ADD(three_vec4_set_length)
		TEST_ADD(three_vec4_lerp)
		TEST_ADD(three_vec4_fuzzy_eq)

		//Matrix
		TEST_ADD(three_mat4_identity)
		TEST_ADD(three_mat4_fuzzy_eq)
		TEST_ADD(three_mat4_look_at)
		TEST_ADD(three_mat4_mul)
		TEST_ADD(three_mat4_mul_scalar)
		TEST_ADD(three_mat4_mul_vec3)
		TEST_ADD(three_mat4_mul_vec4)
		TEST_ADD(three_mat4_rotate_axis)
		TEST_ADD(three_mat4_cross_vec4)
		TEST_ADD(three_mat4_determinant)
		TEST_ADD(three_mat4_transpose)
		TEST_ADD(three_mat4_get_pos)
		TEST_ADD(three_mat4_set_pos)
		TEST_ADD(three_mat4_get_col_x)
		TEST_ADD(three_mat4_get_col_y)
		TEST_ADD(three_mat4_get_col_z)

	END_TESTS

	return 0;
}
