#include<stdio.h>
void swap(int *a, int *b);
void swap2(int a, int b);

int main(void)
{
	int a, b;

	printf("Enter two integers:\n");
	scanf("%d %d", &a, &b);
	printf("Before:: a: %d, b: %d\n", a, b);
	swap2(a, b);
	printf("After:: a: %d, b: %d", a, b);

	return 0;
}



void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

	return;
}

void swap2(int a, int b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;

	return;
}

