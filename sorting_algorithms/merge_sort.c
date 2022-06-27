void merge_sort(int * array, int * temp_array, int start, int end)
{
	/**
	* @brief This function calls itself recursively to divide the array till size become one and then merge them.
	* @param array Source array
	* @param temp_array Temporary array used for sorting
	* @param start Start index of array	
	* @param end End index of array
	*/
	if (start < end)
	{
		int mid;
		mid = start + ((end - start) / 2);
		// Divide 1st half of array
		merge_sort(array, temp_array, start, mid);
		// Divide 2st half of array
		merge_sort(array, temp_array, mid + 1, end);
		// Merge both halves in ascending order
		merge(array, temp_array, start, mid, end);
		copy_from_temp_array(array, temp_array, start, end);
	}
}