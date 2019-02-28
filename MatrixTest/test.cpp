#include "MatrixLib.h"
#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_size)
{
	ASSERT_NO_THROW(TMatrix<int> m(3));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_size)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-3));
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(3);

	EXPECT_EQ(3, m.GetSize());
}

TEST(TMatrix, can_copy_matrix)
{
	TMatrix<int> m(3);

	ASSERT_NO_THROW(TMatrix<int> Matr(m));
}

TEST(Matrix, can_assign_matrix)
{
  TMatrix <int> m1(2), m2(3);
  m1 = m2;
  ASSERT_TRUE(m1 == m2);
}


TEST(Matrix, equality_matrix_true)
{
	TMatrix <int> m1(2), m2(2);
	for (int i = 0; i < m1.GetSize(); i++)
		for (int j = i; j < m1.GetSize() - i; j++)
		{
			m1[i][j] = i;
			m2[i][j] = i;
		}
	ASSERT_TRUE(m1 == m2);
}

TEST(Matrix, equality_matrix_false)
{
	TMatrix <int> m1(3), m2(3);
	for (int i = 0; i < m1.GetSize(); i++)
		for (int j = 0; j < m1.GetSize() - i ; j++)
		{
			m1[i][j] = i;
			m2[i][j] = 5*i;
		}
	ASSERT_FALSE(m1 == m2);
}

TEST(TMatrix, inequality_matrix_true)
{
	TMatrix <int> m1(3), m2(3);

	for (int i = 0; i < m1.GetSize(); i++)
		for (int j = 0; j < m2.GetSize() - i; j++)
		{
			m1[i][j] = i;
			m2[i][j] = i + 1;
		}

	ASSERT_TRUE(m1 != m2);
}

TEST(TMatrix, inequality_matrix_false)
{
	TMatrix <int> m1(3), m2(3);

	for (int i = 0; i < m1.GetSize(); i++)
		for (int j = 0; j < m2.GetSize() - i; j++)
		{
			m1[i][j] = i;
			m2[i][j] = i;
		}

	ASSERT_FALSE(m1 != m2);
}

TEST(Matrix, can_add_matrices)
{
  TMatrix<int> m1(3);
  TMatrix<int> m2(3);
  TMatrix<int> m3(3);

  m1[0][1] = 1;
  m2[0][1] = 1;
  m3[0][1] = 2;

  EXPECT_EQ(m3, m1 + m2);
}

TEST(Matrix, thorws_when_add_matrices_with_different_size)
{
	TMatrix <int> m1(1), m2(7);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(Matrix, can_subtract_matrices)
{
	TMatrix <int> m1(3);
	TMatrix <int> m2(3);
	TMatrix <int> m3(3);

	m1[1][2] = 2;
	m2[1][2] = 1;
	m3 = m1 - m2;

	EXPECT_EQ(m3[1][2], 1);
}


TEST(TMatrix, throws_when_subtract_matrices_with_different_size)
{
	TMatrix <int> m1(7);
	TMatrix <int> m2(3);

	ASSERT_ANY_THROW(m1 - m2);
}

TEST(TMatrix, can_multiply_matrices)
{
	TMatrix <int> m1(2), m2(2), m(2);

	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;
	m2[0][0] = 5;
	m2[0][1] = 4;
	m2[1][0] = 3;
	m[0][0] = 5;
	m[0][1] = 10;
	m[1][0] = 9;

	ASSERT_TRUE(m == (m1 * m2));
}

TEST(Matrix, thorws_when_multiply_matrices_with_different_size)
{
	TMatrix <int> m1(7), m2(8);
	ASSERT_ANY_THROW(m1 * m2);
}

TEST(TMatrix, can_divide_matrix)
{
	TMatrix<int> m1(2), m2(2), m(2);

	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 1;
	m2[0][0] = 1;
	m2[0][1] = 1;
	m2[1][0] = 1;
	m[0][0] = 1;
	m[0][1] = 1;
	m[1][0] = 1;
	ASSERT_TRUE(m == (m1 / m2));
}

