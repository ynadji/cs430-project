#include <stdio.h>
#include <stdlib.h>
#include "project.h"
#include <sys/time.h>
#include <string.h>

// ballz

#define MAX 10
#define MAXLENGTH 5000
#define MAX_ITER 3
#define NUM_TESTS 5

void print_arr(int arr[], int len, char *arr_name);
int int_cmp(const void *a, const void *b);
void quicksort(int a[], int lo, int hi);
double get_runtime(struct timeval *start, struct timeval *end);
void print_results(double *quick, double *merge, double *radix, char *listname);
void rsort(int a[], int n);
void mergesort_array(int a[], int size, int temp[]);

int main()
{
	int i;

	struct timeval start;
	struct timeval end;

	double qsort_time[NUM_TESTS];
	double merge_time[NUM_TESTS];
	double radix_time[NUM_TESTS];

	for (i = 0; i < NUM_TESTS; i++)
	{
		qsort_time[i] = 0;
		merge_time[i] = 0;
		radix_time[i] = 0;
	}

	// list of 10
	for (i = 0; i < MAX_ITER; i++)
	{
		int *tmparr = (int *) malloc(sizeof list10_1);

		// test #1

		memcpy(tmparr, list10_1, sizeof(list10_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 10);
		gettimeofday(&end, NULL);

		qsort_time[0] += get_runtime(&start, &end);
		
		memcpy(tmparr, list10_1, sizeof(list10_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 10, NULL);
		gettimeofday(&end, NULL);

		merge_time[0] += get_runtime(&start, &end);
		
		memcpy(tmparr, list10_1, sizeof(list10_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 10);
		gettimeofday(&end, NULL);

		radix_time[0] += get_runtime(&start, &end);

		// test #2
		
		memcpy(tmparr, list10_2, sizeof(list10_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 10);
		gettimeofday(&end, NULL);

		qsort_time[1] += get_runtime(&start, &end);

		memcpy(tmparr, list10_2, sizeof(list10_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 10, NULL);
		gettimeofday(&end, NULL);

		merge_time[1] += get_runtime(&start, &end);
		
		memcpy(tmparr, list10_2, sizeof(list10_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 10);
		gettimeofday(&end, NULL);

		radix_time[1] += get_runtime(&start, &end);

		// test #3
		
		memcpy(tmparr, list10_3, sizeof(list10_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 10);
		gettimeofday(&end, NULL);

		qsort_time[2] += get_runtime(&start, &end);

		memcpy(tmparr, list10_3, sizeof(list10_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 10, NULL);
		gettimeofday(&end, NULL);

		merge_time[2] += get_runtime(&start, &end);
		
		memcpy(tmparr, list10_3, sizeof(list10_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 10);
		gettimeofday(&end, NULL);

		radix_time[2] += get_runtime(&start, &end);

		// test #4
		
		memcpy(tmparr, list10_4, sizeof(list10_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 10);
		gettimeofday(&end, NULL);

		qsort_time[3] += get_runtime(&start, &end);

		memcpy(tmparr, list10_4, sizeof(list10_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 10, NULL);
		gettimeofday(&end, NULL);

		merge_time[3] += get_runtime(&start, &end);
		
		memcpy(tmparr, list10_4, sizeof(list10_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 10);
		gettimeofday(&end, NULL);

		radix_time[3] += get_runtime(&start, &end);

		// test #5
		
		memcpy(tmparr, list10_5, sizeof(list10_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 10);
		gettimeofday(&end, NULL);

		qsort_time[4] += get_runtime(&start, &end);
		
		memcpy(tmparr, list10_5, sizeof(list10_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 10, NULL);
		gettimeofday(&end, NULL);

		merge_time[4] += get_runtime(&start, &end);
		
		memcpy(tmparr, list10_5, sizeof(list10_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 10);
		gettimeofday(&end, NULL);

		radix_time[4] += get_runtime(&start, &end);

		free(tmparr);
	}
	print_results(qsort_time, merge_time, radix_time, "10");

	// list of 100
	for (i = 0; i < MAX_ITER; i++)
	{
		int *tmparr = (int *) malloc(sizeof list100_1);

		// test #1

		memcpy(tmparr, list100_1, sizeof(list100_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 100);
		gettimeofday(&end, NULL);

		qsort_time[0] += get_runtime(&start, &end);
		
		memcpy(tmparr, list100_1, sizeof(list100_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 100, NULL);
		gettimeofday(&end, NULL);

		merge_time[0] += get_runtime(&start, &end);
		
		memcpy(tmparr, list100_1, sizeof(list100_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 100);
		gettimeofday(&end, NULL);

		radix_time[0] += get_runtime(&start, &end);

		// test #2
		
		memcpy(tmparr, list100_2, sizeof(list100_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 100);
		gettimeofday(&end, NULL);

		qsort_time[1] += get_runtime(&start, &end);

		memcpy(tmparr, list100_2, sizeof(list100_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 100, NULL);
		gettimeofday(&end, NULL);

		merge_time[1] += get_runtime(&start, &end);
		
		memcpy(tmparr, list100_2, sizeof(list100_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 100);
		gettimeofday(&end, NULL);

		radix_time[1] += get_runtime(&start, &end);

		// test #3
		
		memcpy(tmparr, list100_3, sizeof(list100_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 100);
		gettimeofday(&end, NULL);

		qsort_time[2] += get_runtime(&start, &end);

		memcpy(tmparr, list100_3, sizeof(list100_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 100, NULL);
		gettimeofday(&end, NULL);

		merge_time[2] += get_runtime(&start, &end);
		
		memcpy(tmparr, list100_3, sizeof(list100_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 100);
		gettimeofday(&end, NULL);

		radix_time[2] += get_runtime(&start, &end);

		// test #4
		
		memcpy(tmparr, list100_4, sizeof(list100_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 100);
		gettimeofday(&end, NULL);

		qsort_time[3] += get_runtime(&start, &end);

		memcpy(tmparr, list100_4, sizeof(list100_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 100, NULL);
		gettimeofday(&end, NULL);

		merge_time[3] += get_runtime(&start, &end);
		
		memcpy(tmparr, list100_4, sizeof(list100_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 100);
		gettimeofday(&end, NULL);

		radix_time[3] += get_runtime(&start, &end);

		// test #5
		
		memcpy(tmparr, list100_5, sizeof(list100_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 100);
		gettimeofday(&end, NULL);

		qsort_time[4] += get_runtime(&start, &end);
		
		memcpy(tmparr, list100_5, sizeof(list100_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 100, NULL);
		gettimeofday(&end, NULL);

		merge_time[4] += get_runtime(&start, &end);
		
		memcpy(tmparr, list100_5, sizeof(list100_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 100);
		gettimeofday(&end, NULL);

		radix_time[4] += get_runtime(&start, &end);

		free(tmparr);
	}
	print_results(qsort_time, merge_time, radix_time, "100");

	// list of 1000
	for (i = 0; i < MAX_ITER; i++)
	{
		int *tmparr = (int *) malloc(sizeof list1000_1);

		// test #1

		memcpy(tmparr, list1000_1, sizeof(list1000_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 1000);
		gettimeofday(&end, NULL);

		qsort_time[0] += get_runtime(&start, &end);
		
		memcpy(tmparr, list1000_1, sizeof(list1000_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 1000, NULL);
		gettimeofday(&end, NULL);

		merge_time[0] += get_runtime(&start, &end);
		
		memcpy(tmparr, list1000_1, sizeof(list1000_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 1000);
		gettimeofday(&end, NULL);

		radix_time[0] += get_runtime(&start, &end);

		// test #2
		
		memcpy(tmparr, list1000_2, sizeof(list1000_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 1000);
		gettimeofday(&end, NULL);

		qsort_time[1] += get_runtime(&start, &end);

		memcpy(tmparr, list1000_2, sizeof(list1000_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 1000, NULL);
		gettimeofday(&end, NULL);

		merge_time[1] += get_runtime(&start, &end);
		
		memcpy(tmparr, list1000_2, sizeof(list1000_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 1000);
		gettimeofday(&end, NULL);

		radix_time[1] += get_runtime(&start, &end);

		// test #3
		
		memcpy(tmparr, list1000_3, sizeof(list1000_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 1000);
		gettimeofday(&end, NULL);

		qsort_time[2] += get_runtime(&start, &end);

		memcpy(tmparr, list1000_3, sizeof(list1000_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 1000, NULL);
		gettimeofday(&end, NULL);

		merge_time[2] += get_runtime(&start, &end);
		
		memcpy(tmparr, list1000_3, sizeof(list1000_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 1000);
		gettimeofday(&end, NULL);

		radix_time[2] += get_runtime(&start, &end);

		// test #4
		
		memcpy(tmparr, list1000_4, sizeof(list1000_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 1000);
		gettimeofday(&end, NULL);

		qsort_time[3] += get_runtime(&start, &end);

		memcpy(tmparr, list1000_4, sizeof(list1000_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 1000, NULL);
		gettimeofday(&end, NULL);

		merge_time[3] += get_runtime(&start, &end);
		
		memcpy(tmparr, list1000_4, sizeof(list1000_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 1000);
		gettimeofday(&end, NULL);

		radix_time[3] += get_runtime(&start, &end);

		// test #5
		
		memcpy(tmparr, list1000_5, sizeof(list1000_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 1000);
		gettimeofday(&end, NULL);

		qsort_time[4] += get_runtime(&start, &end);
		
		memcpy(tmparr, list1000_5, sizeof(list1000_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 1000, NULL);
		gettimeofday(&end, NULL);

		merge_time[4] += get_runtime(&start, &end);
		
		memcpy(tmparr, list1000_5, sizeof(list1000_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 1000);
		gettimeofday(&end, NULL);

		radix_time[4] += get_runtime(&start, &end);

		free(tmparr);
	}
	print_results(qsort_time, merge_time, radix_time, "1000");

	// list of 5000
	for (i = 0; i < MAX_ITER; i++)
	{
		int *tmparr = (int *) malloc(sizeof list5000_1);

		// test #1

		memcpy(tmparr, list5000_1, sizeof(list5000_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 5000);
		gettimeofday(&end, NULL);

		qsort_time[0] += get_runtime(&start, &end);
		
		memcpy(tmparr, list5000_1, sizeof(list5000_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 5000, NULL);
		gettimeofday(&end, NULL);

		merge_time[0] += get_runtime(&start, &end);
		
		memcpy(tmparr, list5000_1, sizeof(list5000_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 5000);
		gettimeofday(&end, NULL);

		radix_time[0] += get_runtime(&start, &end);

		// test #2
		
		memcpy(tmparr, list5000_2, sizeof(list5000_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 5000);
		gettimeofday(&end, NULL);

		qsort_time[1] += get_runtime(&start, &end);

		memcpy(tmparr, list5000_2, sizeof(list5000_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 5000, NULL);
		gettimeofday(&end, NULL);

		merge_time[1] += get_runtime(&start, &end);
		
		memcpy(tmparr, list5000_2, sizeof(list5000_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 5000);
		gettimeofday(&end, NULL);

		radix_time[1] += get_runtime(&start, &end);

		// test #3
		
		memcpy(tmparr, list5000_3, sizeof(list5000_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 5000);
		gettimeofday(&end, NULL);

		qsort_time[2] += get_runtime(&start, &end);

		memcpy(tmparr, list5000_3, sizeof(list5000_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 5000, NULL);
		gettimeofday(&end, NULL);

		merge_time[2] += get_runtime(&start, &end);
		
		memcpy(tmparr, list5000_3, sizeof(list5000_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 5000);
		gettimeofday(&end, NULL);

		radix_time[2] += get_runtime(&start, &end);

		// test #4
		
		memcpy(tmparr, list5000_4, sizeof(list5000_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 5000);
		gettimeofday(&end, NULL);

		qsort_time[3] += get_runtime(&start, &end);

		memcpy(tmparr, list5000_4, sizeof(list5000_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 5000, NULL);
		gettimeofday(&end, NULL);

		merge_time[3] += get_runtime(&start, &end);
		
		memcpy(tmparr, list5000_4, sizeof(list5000_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 5000);
		gettimeofday(&end, NULL);

		radix_time[3] += get_runtime(&start, &end);

		// test #5
		
		memcpy(tmparr, list5000_5, sizeof(list5000_1));
		gettimeofday(&start, NULL);
		quicksort(tmparr, 0, 5000);
		gettimeofday(&end, NULL);

		qsort_time[4] += get_runtime(&start, &end);
		
		memcpy(tmparr, list5000_5, sizeof(list5000_1));
		gettimeofday(&start, NULL);
		mergesort_array(tmparr, 5000, NULL);
		gettimeofday(&end, NULL);

		merge_time[4] += get_runtime(&start, &end);
		
		memcpy(tmparr, list5000_5, sizeof(list5000_1));
		gettimeofday(&start, NULL);
		rsort(tmparr, 5000);
		gettimeofday(&end, NULL);

		radix_time[4] += get_runtime(&start, &end);

		free(tmparr);
	}

	print_results(qsort_time, merge_time, radix_time, "5000");

	return 0;
}

double get_runtime(struct timeval *start, struct timeval *end)
{
	double total = 0;
	total = (end->tv_usec - start->tv_usec) / (double) 1000;
	if (end->tv_sec - start->tv_sec != 0)
		total += (end->tv_sec - start->tv_sec) * 1000;

	return total;
}

void print_results(double *quick, double *merge, double *radix, char *listname)
{
	int i;
	printf("List: %s\n", listname);
	for (i = 0; i < NUM_TESTS; i++)
	{
		printf("\nTest #%d:\n", i+1);
		printf("Quicksort: %f\n", quick[i] / MAX_ITER);
		printf("Mergesort: %f\n", merge[i] / MAX_ITER);
		printf("Radixsort: %f\n", radix[i] / MAX_ITER);
	}
}

void print_arr(int arr[], int len, char *arr_name)
{
	int i;
	printf("%s: ", arr_name);
	printf("[");
	for (i = 0; i < len - 1; i++)
		printf("%d, ", arr[i]);

	printf("%d]\n", arr[len - 1]);
}

void quicksort(int a[], int lo, int hi) {
	int h, l, p, t;

	if (lo < hi) {
		l = lo;
		h = hi;
		p = a[hi];

		do {
			while ((l < h) && (a[l] <= p)) 
				l = l+1;
			while ((h > l) && (a[h] >= p))
				h = h-1;
			if (l < h) {
				t = a[l];
				a[l] = a[h];
				a[h] = t;
			}
		} while (l < h);

		t = a[l];
		a[l] = a[hi];
		a[hi] = t;

		quicksort(a, lo, l-1);
		quicksort(a, l+1, hi);
	}
}

void rsort(int a[], int n)
{
	int i,j;
	int shift;
	int temp[MAXLENGTH];
	int bucket_size[256], first_in_bucket[256];

	for(shift = 0; shift < 32; shift += 8)
	{
		for(i = 0; i < 256; i++)
			bucket_size[i] = 0;
		for(j = 0; j < n; j++)
		{
			i = (a[j] >> shift) & 255;
			bucket_size[i]++;
			temp[j] = a[j];
		}

		first_in_bucket[0] = 0;
		for(i = 1; i < 256; i++)
			first_in_bucket[i] = first_in_bucket[i - 1] + bucket_size[i - 1];

		for(j = 0; j < n; j++)
		{
			i = (temp[j] >> shift) & 255;
			a[first_in_bucket[i]] = temp[j];
			first_in_bucket[i]++;
		}
	}
}

void mergesort_array(int a[], int size, int temp[]) {
	int i1, i2, tempi;

	if (size <= 1) {
		return;
	}

	if (temp == NULL) {
		temp = malloc(sizeof(int)*size);
		mergesort_array(a, size, temp);
	}

	mergesort_array(a, size/2, temp);
	mergesort_array(a + size/2, size - size/2, temp);
	i1 = 0;
	i2 = size/2;
	tempi = 0;
	while (i1 < size/2 && i2 < size) {
		if (a[i1] < a[i2]) {
			temp[tempi] = a[i1];
			i1++;
		} else {
			temp[tempi] = a[i2];
			i2++;
		}
		tempi++;
	}

	while (i1 < size/2) {
		temp[tempi] = a[i1];
		i1++;
		tempi++;
	}
	while (i2 < size) {
		temp[tempi] = a[i2];
		i2++;
		tempi++;
	}

	memcpy(a, temp, size*sizeof(int));
}
