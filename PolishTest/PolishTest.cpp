#include "../PolishLib/Polish.h"
#include <gtest.h>


TEST(Polish, can_get_priority)
{
	EXPECT_EQ(GetPriority(')'), 1);
	EXPECT_EQ(GetPriority('('), 1);
	EXPECT_EQ(GetPriority('+'), 2);
	EXPECT_EQ(GetPriority('-'), 2);
	EXPECT_EQ(GetPriority('*'), 3);
	EXPECT_EQ(GetPriority('/'), 3);
}

TEST(Polish, can_check_is_operation)
{
	EXPECT_EQ(IsOperation('+'), true);
	EXPECT_EQ(IsOperation('+'), true);
	EXPECT_EQ(IsOperation('*'), true);
	EXPECT_EQ(IsOperation('/'), true);
	EXPECT_EQ(IsOperation(')'), true);
	EXPECT_EQ(IsOperation('('), true);
	EXPECT_EQ(IsOperation('.'), false);
}

TEST(Polish, can_convert_to_polish)
{
+	char s[] = "14+5";
	TString str(s);
	TQueue<char> A;

	ASSERT_NO_THROW(A = ConvertToPolish(str));
	EXPECT_EQ('{', A.Get());
	EXPECT_EQ('14', A.Get());
	EXPECT_EQ('}', A.Get());
	EXPECT_EQ('{', A.Get());
	EXPECT_EQ('9', A.Get());
	EXPECT_EQ('}', A.Get());
	EXPECT_EQ('+', A.Get());
}
