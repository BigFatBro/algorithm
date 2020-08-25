/*
算法要求：计算给定的一棵二叉树当中所有双分支节点的个数
思路：设置一个静态变量count，遍历树的每一个节点，遇到双分支节点就count++

算法比较简单此处只给出算法实现的函数，不给出完整代码 
*/

//算法1 
int CountDCNode(BiTree root)
{
	static int count=0;
	if(root->lchild!=NULL&&root->rchild!=NULL)
		count++;
	if(root->lchild!=NULL)
		CountDCNode(root->lchild);
	if(root->rchild!=NULL)
		CountDCNode(root->rchild);
}

//算法2
int CountDCNode_2(BiTree root)
{
	if(root==NULL)
		return 0;
	if(root->lchild!=NULL&&root->rchild!=NULL)
		return CountDCNode_2(root->lchild)+CountDCNode_2(root->rchild)+1;
	else
		return CountDCNode_2(root->lchild)+CountDCNode_2(root->rchild);
}
