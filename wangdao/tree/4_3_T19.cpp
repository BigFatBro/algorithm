/*
�㷨Ҫ�󣺼���������Ĵ�Ȩ·�����ȣ�WPL,��������������Ҷ�ڵ�Ĵ�Ȩ·������֮��)���ڵ�ṹΪleftָ�룬Ȩֵweight��rightָ��
�㷨˼�룺����һ����̬����wpl�� �ݹ�����Ȩ·�����ȣ�����Ҷ�ڵ�ʱ���Ҷ�ڵ�Ĵ�Ȩ·�����ȣ���depth��Ҷ�ڵ�weight, �ۼ�����Ҷ�ڵ�Ĵ�Ȩ·�����ȣ���Ϊ���Ĵ�Ȩ·������ 
 
�㷨�Ƚϼ򵥴˴�ֻ�����㷨ʵ�ֵĺ������������������� 
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
