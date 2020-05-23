#pragma once //防止头文件重复引入
//写代码顺序不同于编译顺序
//所有容器都是一个模板类,模板：把类型当作一个未知量，实现声明一个文件 不能多文件
//模板注意运算符重载问题，自定义类型   eg:out输出时ostream& operator<<(ostream& out,Info data)
//bool operator>(infor data1, infor data2){return data1.name>data2.name}比较类大小 重载比较 >
//结构体默认共有  类默认私有
template <class T>
struct TreeNode
{
	T data;
	TreeNode* pLeft;  
	TreeNode* pRight;
	int height;
	TreeNode(const T& data)
	{
		this->data = data;
		pLeft = NULL;
		pRight = NULL;
		height = 0;
	}
};

template<class T>
class AVLTree
{

	TreeNode<T>* pRoot;
public:
	AVLTree(){ pRoot = NULL;}
	~AVLTree(){}

	void insert(const T& data);//引用：安全 防止临时副本产生浪费
private:
	void _insertNodeToTree(TreeNode<T>*& root, const T& data);//为了方便，私有类型，cpp中用不了 插入完毕后还要做旋转 所以要找到对应的子树 用**同*&
	int _getHeight(TreeNode<T>*pRoot);//获取树的高度
	//右旋 对应图1
	TreeNode<T>*RR(TreeNode<T>*pRoot);
	//左旋对应 图2
	TreeNode<T>*LL(TreeNode<T>*pRoot);
	//右左旋转 对应 图4
	TreeNode<T>*RL(TreeNode<T>*pRoot);
	//图三
	TreeNode<T>*LR(TreeNode<T>*pRoot);
};


template<class T>
//右旋 对应图1 和左旋 对称 左变右 右变左
TreeNode<T>* AVLTree<T>::RR(TreeNode<T>* root)
{
	//1.记录root的左孩子
	TreeNode<T>*pTemp = root->pLeft;
	//2.pTemp的右孩子成为root的左孩子
	root->pLeft = pTemp->pRight;
	//3.
	pTemp->pRight= root;
	//4.
	root->height = 1 + ((_getHeight(root->pLeft) > _getHeight(root->pRight)) ? _getHeight(root->pLeft) : _getHeight(root->pRight));
	//5.
	return pTemp;
	
}

template<class T>
//左旋对应 图2

TreeNode<T>*AVLTree<T>::LL(TreeNode<T>*root)
{
//1.记录root的右孩子
	TreeNode<T>*pTemp = root->pRight;
//2.pTemp的左孩子成为root的右孩子
	root->pRight = pTemp->pLeft;
//3.
	pTemp->pLeft = root;
//4.
	root->height = 1 + ((_getHeight(root->pLeft) > _getHeight(root->pRight)) ? _getHeight(root->pLeft) : _getHeight(root->pRight));
//5.
	return pTemp;

}

template<class T>
//右左旋转 对应 图4

TreeNode<T>*AVLTree<T>::RL(TreeNode<T>*root)
{
	root->pRight = RR(root->pRight);//先以root的右孩子为轴右旋转
	return LL(root);//以根为轴左旋
}


template<class T>
//图三
TreeNode<T>*AVLTree<T>::LR(TreeNode<T>*root)
{
	root->pLeft = LL(root->pLeft);//先以root的左孩子为轴
	return RR(root);//以根为轴右旋
}

template<class T>
void AVLTree<T>::insert(const T&data)
{
	_insertNodeToTree(pRoot, data);
	
}
template<class T>
int AVLTree<T>::_getHeight(TreeNode<T>*pRoot)
{
	if (pRoot)
		return pRoot->height;
	else return 0;
}
template<class T>
void AVLTree<T>::_insertNodeToTree(TreeNode<T>*& root, const T& data)
{//作为一个平衡二叉树，首先是一个有序二叉树
	//1.以有序二叉树的方式插入
	if (NULL == root)
	{
		root = new TreeNode<T>(data);//如果没有构造函数 下面还要给成员变量都要初始化
		
	}
	else if (data>root->data)
	{
		_insertNodeToTree(root->pRight,data);//大的值放根右边
		//检查是否需要旋转	//获取左右子树的高度比较高度差
		if (_getHeight(root->pRight) - _getHeight(root->pLeft)>1)
		{
			//判断是哪种不平衡导致的 图2或4
			if (data > root->pRight->data)//图二
			{
				printf("left rotation");
				root = LL(root);
			}
			else//图四
			{
				printf("右左旋转");
				root = RL(root);
			}
		}
		
	}
	else
	{
		_insertNodeToTree(root->pLeft,data);//检查是否需要旋转 图1或图3
		if ((_getHeight(root->pLeft) - _getHeight(root->pRight) < 1))//右边高
		{
			//判断是哪种不平衡导致的 图1或3
			if (data < root->pRight->data)//图1
			{
				printf("right rotation");
				root = RR(root);//以root为轴右旋 然后赋值给root 修改根节点
			}
			else//图3
			{
				printf("left right rotation");
				root = LR(root);
			}
		}
	}

	//3.设置高度
	int lh = _getHeight(root->pLeft); //左边高度
	int rh = _getHeight(root->pRight);//右边高度
	root->height = 1 + ((lh > rh) ? lh : rh);//高度大的那边加1
	printf("根节点的数据%d和高度%d", root->data, root->height);
}
