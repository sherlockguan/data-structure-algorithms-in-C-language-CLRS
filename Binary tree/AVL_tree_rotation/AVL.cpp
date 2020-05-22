#include<stdio.h>
#include"AVL.h"

int main()
{//调试-》窗口-》监视-》拖动手动
	AVLTree<int> tree;
	//私有函数安全不能给别人用
	tree.insert(10);
	tree.insert(88);
	tree.insert(4);
	tree.insert(33);
	tree.insert(666);

	while (1);
	return 0;
}
