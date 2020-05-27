// sort.cpp : 定义控制台应用程序的入口点。
//排序算法都是升序 由小到大
//选择排序算法 从待排序列里面挑最小的放到第一个位置
#include "stdafx.h"
//2.插入排序 一个遍历指针的数据每次临时存储 比较 比他小的数据右移 找到合适位置插入
void insert_sort(int *a, int len);
void print(int *a, int len, bool beforeSort= true);
void select_sort(int*a, int len);
int _tmain(int argc, _TCHAR* argv[])
{
	int array[10] = { 7, 44, 3, 5, 0, 99, 46, 12, 6, 1 };
	print(array, 10);
	//printf("selection sort\n");
	printf("insertion sort\n");
	//select_sort(array, 10);//核心 把合适的数据挑选出来
	insert_sort(array, 10);
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



void insert_sort(int *a, int len)   //优化selectionsort 不稳定 根据数据情况
{ //想思路的时候去发散 想出来后严格执行
	//外层循环 1-》len-1 范围   把第i的数据插入到len-1截至
	for (int i = 1; i < len; i++)
	{//1.临时存储当前数据
		int tmp = a[i];
	//2.定位插入点 插入点之后的元素往后挪 from i-1 to 0 比tmp 大 就覆盖 小则结束
		//不知循环次数用while
		int j = i - 1;
		while (j >= 0 && a[j]>tmp)//左边大于右边 挪
		{
			a[j + 1] = a[j];
			j--;
		}
	//3.插入
		a[j + 1] = tmp;
		//print(a, 10);
	}
	

}
