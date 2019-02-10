#include <gtest.h>
#include "..//ArrayListLib/TArrayList.h"

TEST(ArrayList, can_create_list)
{
	ASSERT_NO_THROW(TArrayList <int> L());
}

TEST(ArrayList, can_create_list_with_positive_size)
{
	ASSERT_NO_THROW(TArrayList <int> L(5));
}

TEST(ArrayList, throws_when_create_list_with_negative_size)
{
	ASSERT_ANY_THROW(TArrayList <int> List(-5));
}

TEST(ArrayList, can_copy_list)
{
	TArrayList <int> L(5);

	ASSERT_NO_THROW(TArrayList <int> L1(L));
}

TEST(ArrayList, can_put_and_get_begin)
{
	TArrayList <int> L(1);

	L.PutBegin(2);

	ASSERT_EQ(2, L.GetBegin());
}

TEST(ArrayList, can_put_and_get_end)
{
	TArrayList <int> L(2);

	L.PutEnd(1);
	L.PutEnd(2);

	ASSERT_EQ(2, L.GetEnd());
}

TEST(ArrayList, is_full_true)
{
	TArrayList <int> L(1);
	L.PutBegin(2);

	ASSERT_TRUE(L.IsFull());
}

TEST(ArrayList, is_full_false)
{
	TArrayList <int> L(1);

	ASSERT_FALSE(L.IsFull());
}


TEST(ArrayList, is_empty_true)
{
	TArrayList <int> L(1);

	ASSERT_TRUE(L.IsEmpty());
}

TEST(ArrayList, is_empty_false)
{
	TArrayList <int> L(1);
	L.PutBegin(2);

	ASSERT_FALSE(L.IsEmpty());
}


TEST(ArrayList, throws_when_put_elem_begin_or_end_in_full_list)
{
	TArrayList <int> L(1);
	L.PutBegin(2);

	ASSERT_ANY_THROW(L.PutBegin(3));
	ASSERT_ANY_THROW(L.PutEnd(4));
}

TEST(ArrayList, throws_when_get_elem_begin_or_end_in_empty_list)
{
	TArrayList <int> L(1);

	ASSERT_ANY_THROW(L.GetBegin());
	ASSERT_ANY_THROW(L.GetEnd());
}