/*
�㷨Ҫ�󣺽����Կɶ������е�������������
�㷨˼·���ú��������˼·���ݹ齻���������� 

�㷨�Ƚϼ򵥴˴�ֻ�����㷨ʵ�ֵĺ������������������� 
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
