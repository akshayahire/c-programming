void insertion_sort(int* unsorted_array, int arr_len)
{
	/**
	* @brief Sort unsorted input array based on insertion sort algorithm.
	* @param unsorted_array Unsorted input array
	* @param arr_len Length of unsorted input array
	*/
	int outer_loop, inner_loop;
	int temp, first_element;

	for (outer_loop = 1; outer_loop < arr_len; outer_loop++)
	{
		// Select unsorted element
		first_element = unsorted_array[outer_loop];
		for (inner_loop = outer_loop; (inner_loop >= 1) && (first_element < unsorted_array[inner_loop - 1]); inner_loop--)
		{
			// Shift large elements to right side	
			unsorted_array[inner_loop] = unsorted_array[inner_loop - 1];
		}
		// Shift unsorted element so that all previous index elements are in ascending order
		unsorted_array[inner_loop] = first_element;
	}
}