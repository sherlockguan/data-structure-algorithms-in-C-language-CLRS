 //每一个节点都有唯一关键字（pair）BST 不要求平衡，二叉搜索树的基本实现
//左孩子小于父节点，右节点大于父节点，任何一个子树仍是二叉搜索树,游戏中地图:场景树
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//数据pair C++
typedef struct dataPair
{
	int first;//关键字
	char second[20];//字符串为例
} DATA,*LPDATA;
//二叉树的结构体
typedef struct treeNode
{
	DATA data;
	struct treeNode*LChild;
	struct treeNode*RChild;
}NODE, *LPNODE;
//封装一个结构体描述二叉搜索树
typedef struct binarySearchTree
{
	LPNODE root;//根节点
	int treeSize; //万金油参数

}BST, *LPBST;

LPBST createBST()
{ //创建过程就是描述一种结构的最初状态
	LPBST tree = (LPBST)malloc(sizeof(BST));
	tree->root = NULL;
	tree->treeSize = 0;
	return tree;
}
//为插入做准备：创建节点
LPNODE createNode(DATA data)
{
	LPNODE newNode = (LPNODE)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->LChild = NULL;
	newNode->RChild = NULL;
	return newNode;
}
//万金油函数 求大小 判空
int size(LPBST tree)
{
	return tree->treeSize;
}
int empty(LPBST tree)
{
	return tree->treeSize == 0;
}
//遍历, BST 多用中序-》有序数列 小中大 左根右
void printNode(LPNODE curNode)
{
	printf("%d:%s\n", curNode->data.first, curNode->data.second);
}
void midOrder(LPNODE tree)
{
	if (tree != NULL)
	{
		midOrder(tree->LChild);
		printNode(tree);
		midOrder(tree->RChild);

	}
	

}


//插入节点
void insertNode(LPBST tree, DATA data)
{	//创建节点
	LPNODE newNode = createNode(data);
	//找到合适的位置->左根右 小中大
		//如果空的状态=》插入的节点直接成为根节点=====》下节课讲平衡方法 AVL 红黑树
	      
	//记录pmove和他父节点--》需要两个节点做插入
	LPNODE pMove = tree->root;
	LPNODE pMoveParent = NULL;
	//先做查找后做讨论分析
	while (pMove != NULL)
	{
		pMoveParent = pMove;
		if (data.first < pMove->data.first)
		{
			pMove = pMove->LChild;
		}
		else if (data.first>pMove->data.first)
		{
			pMove = pMove->RChild;
		}
		else//相等采用覆盖原来的数据，也可以
		{
			strcpy(pMove->data.second, data.second);
			return;
		}

	}
	//退出循环，分类讨论插入
	if (tree->root == NULL)
	{
		tree->root = newNode;
	}
	else//考虑在父节点的左边还是右边
	{
		if (pMoveParent->data.first > data.first)
		{
			pMoveParent->LChild = newNode;

		}
		else
		{
			pMoveParent->RChild = newNode;
		}

	}
	tree->treeSize++;


}
int main()
{
	LPBST tree = createBST();
	DATA array[8] = { 100, "boston", 500, "Chanel", 80, "erik", 40, "bob", 90, "lucky", 10, "good", 98, "ok", 102, "vampire" };
	for (int i = 0; i < 8; i++)
	{
		insertNode(tree, array[i]);
	}
	printf("mid order traversal:\n");
	midOrder(tree->root);
	system("pause");
	return 0;
}

