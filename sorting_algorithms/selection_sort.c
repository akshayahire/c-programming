void selection_sort(int* unsorted_array, int arr_len)
{
	/**
	* @brief Sort unsorted input array based on selection sort algorithm.
	* @param unsorted_array Unsorted input array
	* @param arr_len Length of unsorted input array
	*/
	int outer_loop, inner_loop;
	int min_idx, temp;
	for (outer_loop = 0; outer_loop < arr_len; outer_loop++)
	{
		// outer_loop is the starting location of unsorted array
		min_idx = outer_loop; // With each pass unsorted array index in increased by one
		for (inner_loop = outer_loop + 1; inner_loop < arr_len; inner_loop++)
		{
			if (unsorted_array[inner_loop] < unsorted_array[min_idx])
			{
				min_idx = inner_loop;
			}
		}
		if (outer_loop != min_idx) // That means it does not found another minimum number in the above for loop
		{
			// Swap elements
			temp = unsorted_array[outer_loop];
			unsorted_array[outer_loop] = unsorted_array[min_idx];
			unsorted_array[min_idx] = temp;
		}
	}
}