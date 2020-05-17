//栈的方式实现先序遍历，非递归， 栈：STACK LIFO 回退思想，撞了南墙再回头
//先序：根左右，定义一个指针指向根节点打印当前数据，
    // 遍历走一个节点打印一个节点,把当前节点位置入栈 pmove,当PMOVE为空出栈，找出栈节点的右面

#include<stdio.h>
#include<stdlib.h>

//数据域+左右单指针,双指针没必要太复杂

typedef struct treeNode //节点
{
	char data;
	struct treeNode*LChild;
	struct treeNode*RChild;

}TREE, *LPTREE;

//创建节点
LPTREE createNode(char data)
{
	LPTREE newNode = (LPTREE)malloc(sizeof(TREE));
	newNode->data = data;
	newNode->LChild = NULL;
	newNode->RChild = NULL;
	return newNode;
}
//没有任何限制的树,没啥应用价值，单纯用来研究遍历
void insertNode(LPTREE parentNode, LPTREE LChild, LPTREE RChild)
{
	parentNode->LChild = LChild;
	parentNode->RChild = RChild;
}
//打印当前节点
void printCurNode(LPTREE curpMove)
{
	printf("%c\t", curpMove->data);
}
//递归先序遍历:退出性条件，
void preOrder(LPTREE root)
{
	if (root != NULL)
	{
		//根左右
		printCurNode(root);
		preOrder(root->LChild);//root->LChild, root->LChild->LChild
		preOrder(root->RChild);
	}
}
void preOrderByStack(LPTREE root)
{
	if (root == NULL)
	{
		return;
	}
	//准备一个栈
	LPTREE stack[10];//数组栈容量
	int stackTop = -1;
	//移动的指针
	LPTREE pMove = root;
	while (stackTop != -1||pMove)
	{
		//边走边打印,走的是左边，走一个入一个
		while (pMove)//非空
		{
			printf("%c\t", pMove->data);//%s:string %c character
			stack[++stackTop] = pMove;
			pMove = pMove->LChild;
		}
		if (stackTop != -1) //出栈
		{
			pMove = stack[stackTop];
			//找右边
			stackTop--;
			pMove = pMove->RChild;

		}
	}

}
void midOrder(LPTREE root)
{//左根右
	if (root != NULL)
	{
		midOrder(root->LChild);
		printCurNode(root);
		midOrder(root->RChild);
	}
}
//中序非递归遍历 边走边入栈 走到最左边(空） 只在出栈过程打印
void midOrderByStack(LPTREE root)
{
	if (root == NULL)
		return;
	struct treeNode*stack[10];
	int stackTop = -1;
	LPTREE pMove = root;
	while (stackTop != -1 || pMove)//pMOVE!=NULL
	{
		while (pMove)
		{
			stack[++stackTop] = pMove;
			pMove = pMove->LChild;
		}
		if (stackTop != -1)
		{
			pMove = stack[stackTop--];
			printf("%c",pMove->data);
			pMove = pMove->RChild;
		}
	}
}
void lastOrder(LPTREE root)
{
	if (root != NULL)
	{
		lastOrder(root->LChild);
		lastOrder(root->RChild);
		printCurNode(root);
	}
}
void lastOrderByStack(LPTREE root)//左右根 ，看图理解，回退的节点存在右节点时先打印其右节点，所以要有访问标记
{
	if (root == NULL)
		return;
	struct treeNode*stack[10];
	int stackTop = -1;
	LPTREE pMove = root;
	LPTREE pLastVisted = NULL;
	while (pMove)
	{
		stack[++stackTop] = pMove;
		pMove = pMove->LChild;

	}
	while (stackTop != -1)
	{
		pMove = stack[stackTop--];
		if (pMove->RChild==NULL || pMove->RChild == pLastVisted)
		{
			printf("%c", pMove->data);
			pLastVisted = pMove;
		}
		else
		{
			stack[++stackTop] = pMove;
			pMove = pMove->RChild;
			while (pMove)//找当前节点右子树的最左边
			{
				stack[++stackTop] = pMove;
				pMove = pMove->LChild;
			}
		}
	}
}
int main()
{
	//创建节点

	LPTREE A = createNode('A');
	LPTREE B = createNode('B');
	LPTREE C = createNode('C');
	LPTREE D = createNode('D');
	LPTREE E = createNode('E');
	LPTREE F = createNode('F');
	LPTREE G = createNode('G');
	LPTREE H = createNode('H');
	//连接节点 根据我的图
	insertNode(A, B, C);
	insertNode(B, D, NULL);
	insertNode(D, NULL, F);
	insertNode(C, E, H);
	insertNode(E, NULL, G);

	printf("PREorder:");
	preOrder(A);
	printf("\n");
	printf("PREorder:");
	preOrderByStack(A);
	printf("\n");

	printf("midorder：");
	midOrder(A);
	printf("\n");
	printf("midorder：");
	midOrderByStack(A);
	printf("\n");

	printf("lastorder：");
	lastOrder(A);
	printf("\n");
	printf("lastorder：");
	lastOrderByStack(A);
	printf("\n");
	system("pause");
	return 0;
}
