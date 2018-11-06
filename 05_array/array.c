#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Array
{
	int size;
	int used;
	int *arr;
} Array;

void dump(Array *array)
{
	for (int i = 0; i < array->used; ++i)
		printf("[%02d]:%08d\n", i, array->arr[i]);
}

void alloc(Array *array)
{
	array->arr = (int *)malloc(sizeof(int) * array->size);
}

int insert(Array *array, int elem)
{
	int idx;
	if (array->used >= array->size)
		return -1;
	for (idx = 0; idx < array->used; ++idx)
	{
		if (array->arr[idx] > elem)
			break;
	}
	if (idx < array->used)
		memmove(&array->arr[idx+1], &array->arr[idx],
				(array->used - idx) * sizeof(int));
	array->arr[idx] = elem;
	array->used++;
	return idx;
}

int search(Array *array, int elem)
{
	int idx;
	for (idx = 0; idx < array->used; ++idx)
	{
		if (array->arr[idx] == elem)
			return idx;
		if (array->arr[idx] > elem)
			return -1;
	}
	return -1;
}

int delete(Array *array, int elem)
{
    int idx;
	if (!array || !array->arr)
		return -1;
    idx = search(array, elem);
    if (-1 == idx)
        return 0;
	if (idx < 0 || idx > array->used)
		return -1;
	memmove(&array->arr[idx], &array->arr[idx + 1],
			(array->used - idx) * sizeof(int));
	array->used--;
	return 0;
}

int main(int argc, char *argv[])
{
	int idx;
	Array ten_int = {10, 0, NULL};

	alloc(&ten_int);
	if (!ten_int.arr)
		return -1;
	insert(&ten_int, 4);
	insert(&ten_int, 3);
	insert(&ten_int, 2);
	insert(&ten_int, 1);
	dump(&ten_int);

	idx = search(&ten_int, 2);
	printf("2 is at position %2d\n", idx);
	idx = search(&ten_int, 9);
	printf("9 is at position %2d\n", idx);

    printf("delete 6\n");
	delete (&ten_int, 6);
	dump(&ten_int);

    printf("delete 3\n");
	delete (&ten_int, 3);
	dump(&ten_int);

	return 0;
}
