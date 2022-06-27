int partition(int *array, int start, int end)
{
	/**
	* @brief This function find the correct position for pivot element 
	* 	such that all elements left to pivot are smaller and all elements right to pivot are larger then pivot.
	* @param array Source array	
	* @param start Start index of array	
	* @param end End index of array
	* @retval pivot_idx 
	*/
	// This function takes first element as pivot
	int pivot, pivot_idx = 0;
	int up_idx, down_idx;
	int temp;
	pivot = array[start];
	up_idx = start + 1;
	down_idx = end;

	while (up_idx <= down_idx)
	{
		// Compare pivot with array elements and update indexs
		while ((array[up_idx] < pivot) && (up_idx <= end))
		{
			up_idx++;
		}

		while ((array[down_idx] >= pivot) && (down_idx > start))
		{
			down_idx--;
		}
		// Due to below swapping, quick sort is a unstable sort
		if (up_idx < down_idx)
		{
			temp = array[up_idx];
			array[up_idx] = array[down_idx];
			array[down_idx] = temp;
			up_idx++;
			down_idx--;
		}
		else
		{
			break;
		}
	}

	array[start] = array[down_idx];
	array[down_idx] = pivot;

	pivot_idx = down_idx;
	return pivot_idx;
}