#pragma once
template<class T>
struct TreeNode
{
        data;
        TreeNode* pLeft;
        TreeNode* pRight;
        int height;
}

template<class T>
class AVLTree
{
        TreeNode<T> *pRoot;
 public:
        AVLTree(){pRoot =NULL;}
        ~AVLTree(){};
        void insert(const T&data);//引用防止临时对象的产生
 private:
 //插入完毕后还要做旋转 所以要找到对应的子树
        void _insertNodeToTree(TreeNode<T>*&root, const T&data);
        
}

template<class T>
void AVLTree<T>::insert(const T&data)
{
        insertNodeToTree(pRoot,data);
}
template<class T>
void AVLTree<T>::_insertNodeToTree(TreeNode<T>*&root, const T&data)
