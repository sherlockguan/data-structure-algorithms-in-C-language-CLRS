#include<stdio.h>
#include<stdlib.h>

//数据域+左右单指针,双指针没必要太复杂

typedef struct treeNode //节点
{
	char data;
	struct treeNode*LChild;
	struct treeNode*RChild;
	
}TREE,*LPTREE;

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
void midOrder(LPTREE root)
{//左根右
	if (root != NULL)
	{
		midOrder(root->LChild);
		printCurNode(root);
		midOrder(root->RChild);
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
int main()
{
	//创建节点

	LPTREE A = createNode('A');
	LPTREE B = createNode('B');
	LPTREE C = createNode('C');
	LPTREE D= createNode('D');
	LPTREE E = createNode('E');
	LPTREE F = createNode('F');
	LPTREE G = createNode('G');
	LPTREE H = createNode('H');
	//连接节点 根据我的图
	insertNode(A, B, C);
	insertNode(B, D, NULL);
	insertNode(D, NULL,F);
	insertNode(C, E, H);
	insertNode(E, NULL,G);

	printf("PREorder:");
	preOrder(A);
	printf("\n");

	printf("midorder：");
	midOrder(A);
	printf("\n");

	printf("lastorder：");
	lastOrder(A);
	printf("\n");

	system("pause");
	return 0;
}
