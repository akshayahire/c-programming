void quick_sort(int *array, int start, int end)
{
	/**
	* @brief This function recursively divide array to place the pivot element at correct position.
	* @param array Source array
	* @param start Start index of array	
	* @param end End index of array
	*/
	if (start >= end)
	{
		return;
	}

	int pivot_idx;
	// Find correct placement of pivot element
	pivot_idx = partition(array, start, end);
	// Divide array based on pivot element index
	quick_sort(array, start, pivot_idx - 1);
	quick_sort(array, pivot_idx + 1, end);
}