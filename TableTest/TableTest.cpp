#include "TTable.h"
#include <gtest.h>

TEST(Table, can_create_table_with_positive_size)
{
  ASSERT_NO_THROW (TTable<int> t(1));
}
