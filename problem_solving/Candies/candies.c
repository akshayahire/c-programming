// Complete the candies function below.
long candies(int n, int arr_count, int* arr) {
long old_value, new_value;
long candies_count = 1;
long max_candies = 1;

long *max_candies_arr = (long*) malloc(sizeof(long)*n);
max_candies_arr[0] = max_candies;
int loop_idx;
for (loop_idx = 1; loop_idx < n; loop_idx++)
{
    if(arr[loop_idx] > arr[loop_idx-1])
    {
        max_candies++;                               
    }
    else {
        max_candies = 1;                               
    }
    max_candies_arr[loop_idx] = max_candies;
    candies_count += max_candies;    
}

for (loop_idx = n-1; loop_idx > 0 ; loop_idx--)
{
    if((arr[loop_idx-1] > arr[loop_idx]) && 
    (max_candies_arr[loop_idx-1] <= max_candies_arr[loop_idx]))
    {
        old_value = max_candies_arr[loop_idx-1];
        new_value = max_candies_arr[loop_idx] + 1;
        max_candies_arr[loop_idx-1] = new_value;
        candies_count += new_value - old_value;
    }     
}
free(max_candies_arr);
return candies_count;
}
