#include "..//MatrixLib/MatrixLib.h"
#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> M(3));
}
