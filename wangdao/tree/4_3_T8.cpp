/*
�㷨Ҫ�󣺼��������һ�ö�������������˫��֧�ڵ�ĸ���
˼·������һ����̬����count����������ÿһ���ڵ㣬����˫��֧�ڵ��count++

�㷨�Ƚϼ򵥴˴�ֻ�����㷨ʵ�ֵĺ������������������� 
*/

//�㷨1 
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

//�㷨2
int CountDCNode_2(BiTree root)
{
	if(root==NULL)
		return 0;
	if(root->lchild!=NULL&&root->rchild!=NULL)
		return CountDCNode_2(root->lchild)+CountDCNode_2(root->rchild)+1;
	else
		return CountDCNode_2(root->lchild)+CountDCNode_2(root->rchild);
}
