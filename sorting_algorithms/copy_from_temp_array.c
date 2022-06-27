void copy_from_temp_array(int * array, int * temp_array, int start_idx, int end_idx)
{
	/**
	* @brief Copy temp_array (source) to array (destination)
	* @param array Destination array
	* @param temp_array Source array
	* @param start_idx Start index
	* @param end_idx End index
	*/
	int index;
	for (index = start_idx; index <= end_idx; index++)
	{
		array[index] = temp_array[index];
	}
}