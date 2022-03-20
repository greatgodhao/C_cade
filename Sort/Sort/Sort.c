#include <stdio.h>

//插入排序
//时间复杂度O(N^2)
void InsertSort(int* a, int n) 
{
	//[0, end]有序  end + 1位置插入进去 [0, end + 1] 有序
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0) {
			if (a[end] > tmp) {
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}
	
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void TestInsertSort()
{
	int a[] = { 3, 4, 1, 5, 6, 1, 7, 9 };
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}


//直接插入排序的基础优化
//1.先进行预排序，让数组接近有序
//2.直接插入排序
void ShellSort(int* a, int n)
{
	int gap  = n;
	while (gap > 1) {
		gap = gap / 2;
		//gap > 1 时都是预排序
		for (int i = 0; i < n - gap; i++) {
			int end;
			int tmp = a[end + gap];
			while (end >= 0) {
				if (a[end] > tmp) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void TestShellSort()
{
	int a[] = { 3, 4, 1, 5, 6, 1, 7, 9 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

int main()
{
	TestShellSort();
	return 0;
}













