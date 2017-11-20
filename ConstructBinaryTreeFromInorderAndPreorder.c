/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * typedef struct TreeNode treenode;
 * 
 * treenode* treenode_new(int val) {
 *     treenode* node = (treenode *) malloc(sizeof(treenode));
 *     node->val = val;
 *     node->left = NULL;
 *     node->right = NULL;
 *     return node;
 * }
 */
/**
 * @input preorder : Integer array
 * @input n1 : Integer array's ( preorder ) length
 * @input inorder : Integer array
 * @input n2 : Integer array's ( inorder ) length
 * 
 * @Output root pointer of tree.
 */
int pre=0;
 treenode* create(int num)
{
	treenode* newnode=(treenode*)malloc(sizeof(treenode));
	newnode->val=num;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

int search(int *inorder,int start,int end,int num)
{
	int i;
	for(i=start;i<=end;i++)
	{
		if(inorder[i]==num)
		return i;
	}
}

treenode* tree(int* preorder,int* inorder,int start,int end)
{
	if(start>end)
		return NULL;
	treenode* root=create(preorder[pre++]);
	if(start==end)
		return root;
	int index=search(inorder,start,end,root->val);
	root->left=tree(preorder,inorder,start,index-1);
	root->right=tree(preorder,inorder,index+1,end);
	return root;
}

treenode* buildTree(int* preorder, int n1, int* inorder, int n2) {
	pre=0;
	treenode* root=tree(preorder,inorder,0,n1-1);
	return root;
}
