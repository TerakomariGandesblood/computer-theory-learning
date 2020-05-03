//
// Created by kaiser on 19-3-24.
//

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <random>
#include <vector>

#include <gtest/gtest.h>

#include "insertion_sort.h"

class SortTest : public testing::Test {
 protected:
  SortTest() {
    std::default_random_engine e{std::random_device{}()};
    constexpr std::size_t kSize{10000};
    arr_.reserve(kSize);
    std::generate_n(std::back_inserter(arr_), kSize, e);
  }

  std::vector<std::int32_t> arr_;
};

TEST_F(SortTest, InsertionSortTest) {
  InsertionSort(arr_);
  ASSERT_TRUE(std::is_sorted(std::begin(arr_), std::end(arr_)));
}

TEST_F(SortTest, StdSortTest) {
  std::sort(std::begin(arr_), std::end(arr_));
  ASSERT_TRUE(std::is_sorted(std::begin(arr_), std::end(arr_)));
}
