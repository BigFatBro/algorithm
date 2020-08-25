/*
算法要求：计算二叉树的带权路径长度（WPL,即二叉树中所有叶节点的带权路径长度之和)，节点结构为left指针，权值weight，right指针
算法思想：设置一个静态变量wpl， 递归计算带权路径长度，到达叶节点时算出叶节点的带权路径长度：用depth乘叶节点weight, 累加所有叶节点的带权路径长度，即为树的带权路径长度 
 
算法比较简单此处只给出算法实现的函数，不给出完整代码 
*/ 
int WPL(BiTree root)
{
	return wpl_preOrder(root,0);
}

int wpl_preOrder(BiTree root,int depth)
{
	static int wpl=0;
	if(root->lchild==NULL&&root->rchild==NULL)
		wpl+=deep*root->weight;
	if(root->lchild!=NULL)
		wpl_preOrder(root->lchild,depth+1);
	if(root->rchild!=NULL)
		wpl_preOrder(root->rchild,depth+1); 
	return wpl;
}
