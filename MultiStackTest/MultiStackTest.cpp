#include "..//MultiStackLib/MultiStack.h"
#include "..//gtest/gtest.h"


TEST(MStack, can_create_multistack)
{
	ASSERT_NO_THROW(TMStack<int> MStack(3, 4));
}

TEST(MStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TMStack<int> MStack(3, -2));
}

TEST(MStack, can__copy_multistack)
{
	TMStack<int> MStack(2,3);
	ASSERT_NO_THROW(TMStack<int> MS(MStack));
}
TEST(MStack, can_get_size)
{
	TMStack<int> MStack(2, 3);
	ASSERT_EQ(MStack.GetSize(), 3);
}
TEST(MStack, can_set)
{
	TMStack<int> MStack(2, 3);

	ASSERT_NO_THROW(MStack.Set(1, 2));
}

TEST(MStack, can_get)
{
	TMStack<int> MStack(2, 3);
	MStack.Set(1, 2);
	EXPECT_EQ(2, MStack.Get(1));
}

TEST(MStack, can_check_is_empty_true)
{
	TMStack<int> MStack(5, 15);
	ASSERT_TRUE(MStack.ISEmpty(1));
}

TEST(MStack, can_check_is_empty_false)
{
	TMStack<int> MStack(5, 15);
	MStack.Set(1, 1);
	ASSERT_FALSE(MStack.IsEmpty(1));
}

TEST(MStack, can_check_is_full_true)
{
	TMStack<int> MStack(3, 15);
	MStack.Set(1, 1);
	MStack.Set(1, 2);
	MStack.Set(1, 3);
	EXPECT_EQ(1, MStack.IsFull(1));
}

TEST(MStack, can_check_is_full_false)
{
	TMStack<int> MStack(5, 15);
	MStack.Set(1, 1);
	MStack.Set(1, 2);
	MStack.Set(1, 3);
	ASSERT_FALSE(MStack.IsFull(1));
}

TEST(MStack, can_repack)
{
	TMStack<int> MStack(2, 6);
	MStack.Set(0, 1);
	MStack.Set(0, 2);
	MStack.Set(0, 3);
	ASSERT_NO_THROW(MStack.Set(0, 5));
}


