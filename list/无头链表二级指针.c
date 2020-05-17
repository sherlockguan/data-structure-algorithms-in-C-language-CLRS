#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node*next;
};
struct Node*createNode(int data)
{//无头链表
	struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//无头链表头插法插入新的节点会更新头节点的位置，也就改变了该一级指针的指向=》用二级指针的原因
void insertByHead(struct Node**headNode, int data)
{   //链表为空时 headnode 为头节点
	struct Node* newNode = createNode(data);//插入前先创建节点 不变
	//链表不为空时，新节点的下一个时原来头节点，头节点更新为新节点 
	newNode->next = *headNode;//等效于一级指针
	*headNode = newNode;

}
//指定位置插入
void insertBySpot(struct Node**headNode, int data, int posData)
{
	struct Node*posFrontNode = NULL;
	struct Node* posNode = *headNode;//从头开始找我们想插入的位置
	if (posNode != NULL)
	{
		if (posNode->data == posData)//第一个结点里面的数据是指定数据
		{
			insertByHead(headNode, data);
		}
		else
		{
			while (posNode != NULL && posNode->data != posData)
			{
				posFrontNode = posNode;
				posNode = posNode->next;
			}
			if (posNode == NULL)
			{
				return;
			}
			else //中间指定位置插入
			{
				struct Node* newNode = createNode(data);
				newNode->next = posNode; 
				posFrontNode->next = newNode;
			}
		}
	}
	else
	{
		return;
	}

}
void deleteByHead(struct Node**headNode)
{
	if (*headNode != NULL)//空没有下一个所以要判断一下
	{
		struct Node* headnext = (*headNode)->next;
		free(*headNode);
		*headNode = headnext;
	}
	else
		return;
}
void printList(struct Node*headNode)
{
	struct Node*pMove = headNode;
	while (pMove != NULL)
	{
		printf("%d\t", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}
void deleteBySpot(struct Node**headNode, int posData)
{//指定位置删除， 分类讨论， 可能会删除表头,无头链表，改变表头需要二级指针
	struct Node*posNode = *headNode; //从头开始找
	struct Node*posFrontNode = NULL;  //开始时 目标前一个为空
	
	while (posNode != NULL&&posNode->data != posData)
	{     
		//记录，往后依次找
		posFrontNode = posNode;
		posNode = posNode->next;
	}
	
	if (*headNode==NULL||posNode==NULL)//链表为空或者没找到删除目标
	{
		return;
	}
	else if (posFrontNode == NULL)//表头目标 删除
	{
		deleteByHead(headNode);
	}
	else//中间删除， 调节前后节点
	{
		posFrontNode->next = posNode->next;
		free(posNode);
		posNode = NULL;
	}
}
void deleteByTail(struct Node**headNode)//防止只有一个节点，此时需要调正表头置空
{
	if (*headNode != NULL)
	{
		struct Node*posFrontNode = NULL;//尾删除法，尾巴的前一个的默认初始化,删除尾巴后，置空原表尾的前一个表示尾巴
		struct Node* posNode = *headNode;
		while (posNode->next != NULL)
		{ //两个依次向后更新一步   //这里是单链表 没有办法从后往前走-》双链表
			posFrontNode = posNode;
			posNode = posNode->next;
		}
		if (posFrontNode == NULL)//仍然为默认初始化的值， 没有动=》表头
		{
			free(*headNode);
			*headNode = NULL;
		}
		else
		{
			free(posNode);//删除尾巴
			posFrontNode->next = NULL;
			posNode = NULL;
		}
	}
	else
		return;
	
	
}   
void insertByTail(struct Node**headNode,int data)//表头是空才改变表头
{
	struct Node*newNode = createNode(data);//首先创建插入节点
	if (*headNode == NULL)//空链表
	{
		*headNode = newNode;
	}
	else
	{
		//先找到表尾, 初始化表尾为表头的值，从前往后找，，顺着单指针
		struct Node*tailNode = *headNode;
		while (tailNode != NULL)
		{
			tailNode = tailNode->next;
		}
		tailNode->next = newNode;

	}

}
int main()
{
	struct Node*list = NULL;  //创建链表
	for (int i = 0; i < 8; i++)
	{
		insertByHead(&list, i);//取二级指针的地址

	}
	printList(list);
	deleteByHead(&list);
	printList(list);
	//指定位置插入
	insertBySpot(&list, 100, 3);//取二级指针地址， 3前插入100
	printList(list);
	

	//指定位置删除
	printf("delete by spot\n");
	deleteBySpot(&list, 100);
	deleteBySpot(&list, 4);
	printList(list);

	deleteByTail(&list);
	printList(list);

	printf("insert by tail\n");
	
	insertByTail(&list, 1200);
	printList(list);

	system("pause");
	return 0;

}

