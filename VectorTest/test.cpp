#include <gtest.h>
#include "../VectorLib/VectorLib.h"

TEST(TVector, can_create_vector_with_positive_size)
{
	ASSERT_NO_THROW(TVector<int> V(3));
}

TEST(TVector, throws_when_create_vector_with_negative_size)
{
	ASSERT_ANY_THROW(TVector<int> V(-3));
}

TEST(TVector, can_copy_vector)
{
	TVector<int> V1(10);

	ASSERT_NO_THROW(TVector<int> V2(V1));
}

TEST(TVector, can_get_size)
{
	TVector<int> V(5);

	EXPECT_EQ(3, V.GetSize());
}

TEST(TVector, can_assign_vector)
{
	TVector <int> V1(5), V2(5);
	V1 = V2;
	ASSERT_NO_THROW(V1 == V2);
}

TEST(TVector, can_compare_different_vectors_true)
{
	TVector <int> V1(5), b(5);

	for (int i = 0; i < V1.GetSize(); i++)
	{
		V1[i] = i;
		V2[i] = i;
	}

	ASSERT_FALSE(V1!= V2);
}

TEST(TVector, can_compare_different_vectors_false)
{
	TVector <int> V1(5), V2(5);

	for (int i = 0; i < V1.GetSize(); i++)
	{
		V1[i] = i;
		V2[i] = i * i;
	}

	ASSERT_TRUE(V1!= V2);
}

TEST(TVector, can_compare_different_vectors_false_with_different_size)
{
	TVector <int> V1(1), V2(2);

	ASSERT_TRUE(V1!= V2);
}

TEST(TVector, throw_when_add_vectors_with_not_equal_size)
{
	TVector<int> V1(1);
	TVector<int> V2(2);

	ASSERT_ANY_THROW(V1 + V2);
}

TEST(TVector, throw_when_subtract_vectors_with_not_equal_size)
{
	TVector<int> V1(2);
	TVector<int> V2(1);

	ASSERT_ANY_THROW(V1 - V2);
}

TEST(TVector, can_increase)
{
	TVector<int> V(3);

	ASSERT_NO_THROW(V++);
}

TEST(TVector, can_add_number)
{
	TVector<int> V(3);

	ASSERT_NO_THROW(V + 1);
}

TEST(TVector, can_subtract_number)
{
	TVector<int> V(3);

	ASSERT_NO_THROW(V - 1);
}


TEST(TVector, can_decrease)
{
	TVector<int> V(3);

	ASSERT_NO_THROW(V--);
}


TEST(TVector, can_multiply_vector_to_number)
{
	TVector<int> V(3);

	ASSERT_NO_THROW(V * 5);
}


TEST(TVector, can_add_vectors)
{
	TVector<int> V1(2), V2(2), res(2);
	V1[0] = 1;
	V1[1] = 2;
	V2[0] = 1;
	V2[1] = 2;
	res[0] = V1[0] + V2[0];
	res[1] = V1[1] + V2[1];
	ASSERT_TRUE((V1+V2)==res);
}

TEST(TVector, can_subtract_vectors)
{
	TVector<int> V1(2), V2(2), res(2);
	V1[0] = 2;
	V1[1] = 1;
	V2[0] = 1;
	V2[1] = 0;
	res[0] = V1[0] - V2[0];
	res[1] = V1[1] - V2[1];
	ASSERT_TRUE((V1 - V2) == res);
}


TEST(Vector, can_multiply_vectors)
{
	TVector<int> V1(2), V2(2), res(2);
	V1[0] = 2;
	V1[1] = 1;
	V2[0] = 1;
	V2[1] = 2;
	for (i = 0; i < 2; i++)
		res += V1[i] * V2[i];
	ASSERT_EQ(res, V1*V2);
}
