void bubble_sort(int* unsorted_array, int arr_len)
{
	/**
	* @brief Sort unsorted input array based on bubble sort algorithm.
	* @param unsorted_array Unsorted input array
	* @param arr_len Length of unsorted input array
	*/
	int outer_loop, inner_loop;
	int temp;
	for (outer_loop = 0; outer_loop<arr_len - 1; outer_loop++)
	{		
		for (inner_loop = 0; inner_loop<arr_len - 1 - outer_loop; inner_loop++)
		{
			/*swap elements if next element is smaller*/
			if (unsorted_array[inner_loop] > unsorted_array[inner_loop + 1])
			{
				temp = unsorted_array[inner_loop];
				unsorted_array[inner_loop] = unsorted_array[inner_loop + 1];
				unsorted_array[inner_loop + 1] = temp;
			}
		}
	}
}