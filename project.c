#include <stdio.h>
#include <stdlib.h>

// ballz

#define MAX 10
#define MAXLENGTH 100

void print_arr(int arr[]);
void quicksort(int a[], int lo, int hi);
void rsort(int a[], int n);

int main()
{
	int test1[] = {123, 5, 756, 43, 2, 432, 87, 97, 4314, 756756};
	int test2[] = {123, 5, 756, 43, 2, 432, 87, 97, 4314, 756756};
	int test3[] = {123, 5, 756, 43, 2, 432, 87, 97, 4314, 756756};
	print_arr(test1);
	quicksort(test1, 0, MAX - 1);
	print_arr(test1);

	print_arr(test2);
	rsort(test2, 10);
	print_arr(test2);

	print_arr(test3);
	merge_sort(test3, MAX);
	print_arr(test3);

	return 0;
}

void print_arr(int arr[])
{
	int i;
	printf("[");
	for (i = 0; i < MAX - 1; i++)
		printf("%d, ", arr[i]);
	printf("%d]\n", arr[MAX - 1]);
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
		/* compute the size of each bucket and
		   copy each record from array a to array temp */
		for(i = 0; i < 256; i++)
			bucket_size[i] = 0;
		for(j = 0; j < n; j++)
		{
			i = (a[j] >> shift) & 255;
			bucket_size[i]++;
			temp[j] = a[j];
		}

		/* mark off the beginning of each bucket */
		first_in_bucket[0] = 0;
		for(i = 1; i < 256; i++)
			first_in_bucket[i] = first_in_bucket[i - 1] + bucket_size[i - 1];

		/* copy each record from array temp to its bucket in array a */
		for(j = 0; j < n; j++)
		{
			i = (temp[j] >> shift) & 255;
			a[first_in_bucket[i]] = temp[j];
			first_in_bucket[i]++;
		}
	}
}
