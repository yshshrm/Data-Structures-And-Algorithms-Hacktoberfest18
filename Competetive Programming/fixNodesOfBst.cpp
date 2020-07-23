void inOrder(struct Node *root, vector<pair<int, node*>> &v)
{
	if(!root)
		return;
	inOrder(root -> left, v);
	v.push_back(make_pair(root ->data, root));
	inOrder(root -> right, v);
}

struct Node *correctBST( struct Node* root )
{
	vector<pair<int, node*>> v;
	inOrder(root, v);
	pair<int, node*> p1, p2;
	p1 = v[0];
	p2 = v[1];
	Node *t = p1.second;
	Node *t1 = p2.second;
	t -> data = p2.first;
	t1 -> data = p1.first;
	return root;
}