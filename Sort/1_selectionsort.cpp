// sort.cpp : 定义控制台应用程序的入口点。
//排序算法都是升序 由小到大
//排序算法 从待排序列里面挑最小的放到第一个位置
#include "stdafx.h"
void print(int *a, int len, bool beforeSort= true);
void select_sort(int*a, int len);
int _tmain(int argc, _TCHAR* argv[])
{
	int array[10] = { 7, 44, 3, 5, 0, 99, 46, 12, 6, 1 };
	print(array, 10);
	printf("selection sort\n");
	select_sort(array, 10);//核心 把合适的数据挑选出来
	print(array, 10, false);
	while (1);
	return 0;
}

void print(int *a, int len, bool beforeSort)
{
	if (beforeSort)
		printf("before sorting: ");
	else
		printf("after sorting: ");
	for (int i = 0; i < len; i++)
		printf("%d\t", a[i]);
	printf("\n");
}
void select_sort(int*a, int len)
{
	int min_idx; 
	// i j 一个做遍历 一个做比较
	for (int i = 0; i < len - 1; i++)  //挑选次数 len-1,同时确定了待排数组的范围：从第i个到第len-1 看图带入
	{
		for (int j = i; j < len; j++)//找出范围内最小数据的下标
		{	//先假设第一个最小
			min_idx = i;
			 for (int j = i; j < len; j++)
			{
				 min_idx = (a[min_idx] < a[j]) ? min_idx : j;
			}
		}

			//和a[i]交换
		if (a[min_idx] < a[i])//不判断也行，理解了
		{
			int temp = a[min_idx];
			a[min_idx] = a[i];
			a[i] = temp;

		}
			
	}

}
