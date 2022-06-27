void merge(int * array, int * temp_array, int start, int mid, int end)
{
	/**
	* @brief Merge part of arrays defined by start, mid and end indexes to temp_array in ascending order
	* @param array Source array
	* @param temp_array Destination array
	* @param start Start index of array
	* @param mid Mid index of array
	* @param end End index of array
	*/
	int idx_1, idx_2, dest_idx;

	idx_1 = start;
	idx_2 = mid + 1;
	dest_idx = start;
	while ((idx_1 <= mid) && (idx_2 <= end))
	{
		if (array[idx_1] <= array[idx_2])
		{
			temp_array[dest_idx++] = array[idx_1++];
		}
		else
		{
			temp_array[dest_idx++] = array[idx_2++];
		}
	}

	while (idx_1 <= mid)
	{
		temp_array[dest_idx++] = array[idx_1++];
	}

	while (idx_2 <= end)
	{
		temp_array[dest_idx++] = array[idx_2++];
	}
}