/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* root)
{
	if (root == NULL)
		return;

	/* recur on left sutree */
	printInorder(root->left);

	/* now print data of node */
	cout << root->data << " ";

	/* then recur on right subtree */
	printInorder(root->right);
}
