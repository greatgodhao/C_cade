#include <stdio.h>

//��������
//ʱ�临�Ӷ�O(N^2)
void InsertSort(int* a, int n) 
{
	//[0, end]����  end + 1λ�ò����ȥ [0, end + 1] ����
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


//ֱ�Ӳ�������Ļ����Ż�
//1.�Ƚ���Ԥ����������ӽ�����
//2.ֱ�Ӳ�������
void ShellSort(int* a, int n)
{
	int gap  = n;
	while (gap > 1) {
		gap = gap / 2;
		//gap > 1 ʱ����Ԥ����
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













