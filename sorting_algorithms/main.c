#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <string.h>

#define REPEAT 1
#define ALGO_COUNT 6
int main()
{
	FILE *stream;
	int arr_len;
	errno_t err;
	// Read input data
	err = fopen_s(&stream, "..\\..\\input_array\\input_array_random_100.txt", "r");
	fscanf_s(stream, "%d", &arr_len);
	int *unsorted_array;
	unsorted_array = read_file(stream, arr_len);
	err = fclose(stream);
	char sortin_algo[ALGO_COUNT][100] = { "Bubble sort", "Modified bubble sort", "Selection sort",
	"Insertion sort", "Merge sort", "Quick sort"};
	clock_t start_time, end_time;
	double exec_time = 0;	
	double time_array[ALGO_COUNT][REPEAT] = {0};
	int repeat_idx;
	for (repeat_idx = 0; repeat_idx < REPEAT; repeat_idx++)
	{		
		// Bubble sort
		//printf("Bubble sort: ");
		int *unsorted_array_bubble_sort;
		unsorted_array_bubble_sort = (int *)malloc(arr_len * sizeof(int));
		memcpy(unsorted_array_bubble_sort, unsorted_array, sizeof(unsorted_array));
		start_time = clock();
		bubble_sort(unsorted_array_bubble_sort, arr_len);
		end_time = clock();
		exec_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
		//printf("%f\n", exec_time);
		time_array[0][repeat_idx] = exec_time;

		// Modified bubble sort
		//printf("modified bubble sort: ");
		int *unsorted_array_mod_bubble_sort;
		unsorted_array_mod_bubble_sort = (int *)malloc(arr_len * sizeof(int));
		memcpy(unsorted_array_mod_bubble_sort, unsorted_array, sizeof(unsorted_array));
		start_time = clock();
		modified_bubble_sort(unsorted_array_mod_bubble_sort, arr_len);
		end_time = clock();
		exec_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
		//printf("%f\n", exec_time);
		time_array[1][repeat_idx] = exec_time;


		// Selection sort
		//printf("selection sort: ");
		int *unsorted_array_selection_sort;
		unsorted_array_selection_sort = (int *)malloc(arr_len * sizeof(int));
		memcpy(unsorted_array_selection_sort, unsorted_array, sizeof(unsorted_array));
		start_time = clock();
		selection_sort(unsorted_array_selection_sort, arr_len);
		end_time = clock();
		exec_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
		//printf("%f\n", exec_time);
		time_array[2][repeat_idx] = exec_time;

		// Insertion sort
		//printf("Insertion sort: ");
		int *unsorted_array_insertion_sort;
		unsorted_array_insertion_sort = (int *)malloc(arr_len * sizeof(int));
		memcpy(unsorted_array_insertion_sort, unsorted_array, sizeof(unsorted_array));
		start_time = clock();
		insertion_sort(unsorted_array_insertion_sort, arr_len);
		end_time = clock();
		exec_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
		//printf("%f\n", exec_time);
		time_array[3][repeat_idx] = exec_time;

		// Merge sort
		//printf("Merge sort: ");
		int *temp_unsorted_array_merge_sort;
		temp_unsorted_array_merge_sort = (int *)malloc(arr_len * sizeof(int));
		int *unsorted_array_merge_sort;
		unsorted_array_merge_sort = (int *)malloc(arr_len * sizeof(int));
		memcpy(unsorted_array_merge_sort, unsorted_array, sizeof(unsorted_array));
		start_time = clock();
		merge_sort(unsorted_array_merge_sort, temp_unsorted_array_merge_sort, 0, arr_len - 1);
		end_time = clock();
		exec_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
		//printf("%f\n", exec_time);
		time_array[4][repeat_idx] = exec_time;


		// Quick sort
		//printf("Quick sort: ");
		int *unsorted_array_quick_sort;
		unsorted_array_quick_sort = (int *)malloc(arr_len * sizeof(int));
		memcpy(unsorted_array_quick_sort, unsorted_array, sizeof(unsorted_array));
		start_time = clock();
		quick_sort(unsorted_array_quick_sort, 0, arr_len - 1);
		end_time = clock();
		exec_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
		//printf("%f\n", exec_time);
		time_array[5][repeat_idx] = exec_time;
		
		free(unsorted_array_bubble_sort);
		free(unsorted_array_mod_bubble_sort);
		free(unsorted_array_selection_sort);
		free(unsorted_array_insertion_sort);
		free(unsorted_array_merge_sort);
		free(temp_unsorted_array_merge_sort);
		free(unsorted_array_quick_sort);		
	}
	free(unsorted_array);
	
	double mean_time;
	for (int i = 0; i < ALGO_COUNT; i++)
	{
		mean_time = 0;
		for (int j = 0; j < REPEAT; j++)
		{
			mean_time = mean_time + time_array[i][j];
		}
		printf("Execution time for %s is %f\n", sortin_algo[i], mean_time / REPEAT);
	}
	
	/*for (int i = 0; i < arr_len; i++)
	{
	printf("%d\t", unsorted_array[i]);
	}*/
	

	getchar();
	return 0;
}

