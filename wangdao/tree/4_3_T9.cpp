/*
算法要求：交换以可二叉树中的所有左右子树
算法思路：用后序遍历的思路，递归交换左右子树 

算法比较简单此处只给出算法实现的函数，不给出完整代码 
*/ 


void swap(BiTree bt)
{
	if(bt){
		swap(bt->lchild);
		swap(bt->rchild);
		BiTree temp=bt->lchild;
		bt->lchild=bt->rchild;
		bt->rchild=temp;
	}	
} 
