/**
 *Big top heap
 **/
#include<stdio.h>

//标准c没有引用， 所以用指针
void swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void heap_adjust(int *a, int i, int size)
{
	int lchild = 2 * i;
	if (lchild > size){
		return;
	}

	int rchild = 2 * i + 1;
	int min = i;

	if(a[lchild] < a[min]){
		min = lchild;
	}
	if(rchild <= size && a[rchild] < a[min]){
		min = rchild;
	}

	if(min != i){
		swap(&a[i], &a[min]);
		heap_adjust(a, min, size);
	}
}

void heap_build(int *a, int size)
{
	for(int i = size / 2; i >= 1; i--){
		heap_adjust(a, i, size);
	}
}

void heap_sort(int *a, int size)
{
	heap_build(a, size);

	for(int i = size; i >= 1; i--){
		/*swap the top number with last number*/
		swap(&a[1], &a[i]);
		/*adjust heap*/
		heap_adjust(a, 1, i - 1);
	}
}

int main(int argc, char *args[])
{
	int a[] = {0, 16, 20, 3, 11, 17, 8};
	int size = 6;

	heap_sort(a, size);

	for(int i = 1; i <= size; i++){
		printf("%d", a[i]);
		printf(" ");
	}
	printf("\n");
/*
	int a[100];
	int size;

	while(scanf("%d", &size) == 1 && size > 0){
		for(int i = 1; i <= size; i++) {
			scanf("%d", &a[i]);
		}

		heap_sort(a, size);

		for(int i = 1; i <= size; i++){
			printf("%d", a[i]);
			printf(" ");
		}
	}
*/
	return 0;
}

