//
//  main.cpp
//  Radixsort
//
//  Created by Loc Nguyen on 19.04.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//

#include <cstdlib>		// Needed for rand()

#include "selection_sort.h"
#include "merge_sort.h"
#include "bucket_sort.h"
#include "radix_sort.h"

int
main (int argc, const char *argv[])
{
  std::vector < int >unsorted_list;

  std::cout << "unsorted array: ";
  for (int i = 0; i < 12; i++)
    {
      int rnumber = rand () % 1000;
      unsorted_list.push_back (rnumber);
      std::cout << unsorted_list[i] << "  ";
    }

  // Each of these should work           
  //selection_sort(unsorted_list);
  //merge_sort(unsorted_list);
  //bucket_sort(unsorted_list);
  //radix_sort(unsorted_list);

  std::cout << std::endl << "sorted list   : ";
  for (int i = 0; i < 12; i++)
    {
      std::cout << unsorted_list[i] << "  ";
    }
  std::cout << std::endl;

  return 0;
}
