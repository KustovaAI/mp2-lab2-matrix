#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);
	TMatrix<int> a(m);
	EXPECT_EQ(m, a);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(3);
	TMatrix<int> a(m);
	EXPECT_NE(&m[0], &a[0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(4);
	EXPECT_EQ(4, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(4);
	EXPECT_NO_THROW(m[0][0] = 1);
	m[1][1] = 5;
	EXPECT_EQ(5, m[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(4);
	EXPECT_ANY_THROW(m[-1][0] = 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(4);
	EXPECT_ANY_THROW(m[1][10] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][1] = 4;
	ASSERT_NO_THROW(m = m);

}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> a(2), b(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][1] = 3;
	EXPECT_NO_THROW(b = a);
	b = a;
	EXPECT_EQ(a[0][0], b[0][0]);
	EXPECT_EQ(a[0][1], b[0][1]);
	EXPECT_EQ(a[1][1], b[1][1]);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> a(4), b(2);
	b = a;
	EXPECT_EQ(4, b.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> a(4), b(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][1] = 3;
	EXPECT_NO_THROW(b = a);
	b = a;
	EXPECT_EQ(a[0][1], b[0][1]);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> a(2), b(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][1] = 3;
	b[0][0] = 1;
	b[0][1] = 2;
	b[1][1] = 3;
	EXPECT_TRUE(a == b);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][1] = 3;
	EXPECT_TRUE(a == a);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
 	TMatrix<int> a(2), b(3);
	EXPECT_FALSE(a == b);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> a(2), b(2), c(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][1] = 3;
	b[0][0] = -1;
	b[0][1] = 5;
	b[1][1] = 6;
	EXPECT_NO_THROW(a + b);
	c = a + b;
	EXPECT_EQ(0, c[0][0]);
	EXPECT_EQ(7, c[0][1]);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> a(5), b(6);
	ASSERT_ANY_THROW(a + b);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> a(2), b(2), c(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][1] = 3;
	b[0][0] = -1;
	b[0][1] = 5;
	b[1][1] = 6;
	EXPECT_NO_THROW(a - b);
	c = a - b;
	EXPECT_EQ(2, c[0][0]);
	EXPECT_EQ(-3, c[0][1]);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> a(5), b(6);
	ASSERT_ANY_THROW(a - b);
}

