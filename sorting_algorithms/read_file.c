#include <stdio.h>
#include <stdlib.h>

int* read_file(FILE *stream, int arr_len)
{
	int *buffer;
	buffer = (int *)malloc(arr_len * sizeof(int));
	for (int i = 0; i < arr_len; i++)
	{
		fscanf_s(stream, "%d", &buffer[i]);
	}
	return buffer;
}