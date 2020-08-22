/*要求：由先序遍历序列和中序遍历序列建立二叉树 
所需数据结构：二叉树 
算法思想：
1.根据先序序列确定根节点，由此求出中序序列中左子树是哪一部分，右子树是哪一部分 
2.递归建立左子树，直到左子树为空 
3.递归建立右子树，直到右子树为空 
*/
#include<stdio.h>
#include<malloc.h>
using namespace std;

typedef int ElemType;

//二叉树的声明 
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//由先序和中序遍历序列，构建二叉树 
BiTree PreInCreate(ElemType A[],ElemType B[],int l1,int h1,int l2,int h2)
//A、B分别为先序和中序序列，l1和h1,l2和h2分别为先序序列和中序序列的第一个元素下标和最后一个元素的下标
//初始时l1=l2=1,h1=h2=n 
{
	int i;
	//新建一个节点
	BiTree root=(BiTNode*)malloc(sizeof(BiTNode)); 
	//确定根节点的值 
	root->data=A[l1];
	//确定根节点在中序序列中位置i
	for(i=l2;B[i]!=root->data;i++);
	//算出左右子树的结点个数
	int llen=i-l2;
	int rlen=h2-i;
	//左子树不为空时，递归建立左子树 
	if(llen)
		root->lchild=PreInCreate(A,B,l1+1,l1+llen,l2,l2+llen-1);
	else
		root->lchild=NULL;
	//右子树不为空时，递归建立右子树 
	if(rlen)
		root->rchild=PreInCreate(A,B,h1-rlen+1,h1,h2-llen+1,h2);
	else
		root->rchild=NULL;
	
	
	return root;
}

//由中序和后序序列，构建二叉树
BiTree PostInCreate(ElemType A[],ElemType B[],int l1,int h1,int l2,int h2)
//A、B分别为后序和中序序列，l1和h1,l2和h2分别为后序序列和中序序列的第一个元素下标和最后一个元素的下标
//初始时l1=l2=1,h1=h2=n 
{
	int i;
	BiTree root=(BiTNode*)malloc(sizeof(BiTNode));
	//确定根节点的值
	root->data=A[h1];
	//确定根节点在中序遍历中的位置
	for(i=l2;B[i]!=root->data;i++);
	int llen=i-l2;
	int rlen=h2-i;
	//左子树不为空时，递归建立左子树 
	if(llen)
		root->lchild=PostInCreate(A,B,l1,l1+llen-1,l2,l2+llen-1);
	else
		root->lchild=NULL;
	//右子树不为空时，递归建立右子树 
	if(rlen)
		root->rchild=PostInCreate(A,B,h1-rlen,h1-1,h2-rlen+1,h2);
	else
		root->rchild=NULL;
	
	return root;
	
}




//递归遍历算法：前序 
void PreOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		printf(" %d ",bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	} 
	
}

//递归遍历算法：中序
void InOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		InOrder(bt->lchild);
		printf(" %d ",bt->data);
		InOrder(bt->rchild);
	}	
}

//递归遍历算法：后序 
void PostOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		printf(" %d ",bt->data);
	}	
}

int main()
{
	int A[8]={0,1,2,4,5,3,6,7};//先序 
	int B[8]={0,4,2,5,1,6,3,7};//中序 
	int C[8]={0,4,5,2,6,7,3,1};//后序 
	BiTree root1,root2;
	root1=PreInCreate(A,B,1,7,1,7);
	root2=PostInCreate(C,B,1,7,1,7);
	printf("由先序和中序序列构建出来的树的后序序列：\n");
	PostOrder(root1);
	printf("\n由后序和中序序列构建出来的树的先序序列：\n");
	PreOrder(root2);
	return 0;
}
