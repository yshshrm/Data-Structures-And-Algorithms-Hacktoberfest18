#include<stack>


int numNodes(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + numNodes(root->left) + numNodes(root->right);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {

    
    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *>s2;
    BinaryTreeNode<int> *temp1=root;
    while(temp1!=NULL)
    {
        s1.push(temp1);
        temp1=temp1->left;
    }
    
    BinaryTreeNode<int> *temp2=root;
    while(temp2!=NULL){
        s2.push(temp2);
        temp2=temp2->right;
    }
    int n=numNodes(root);
    int i=0;
    while(i<n-1)
    {
        if(s1.top()->data+s2.top()->data==s){
            BinaryTreeNode<int>* curr1 = s1.top();
            BinaryTreeNode<int>* curr2 = s2.top();
            cout<<s1.top()->data<<" "<<s2.top()->data<<endl;
            
            if (curr2->left == NULL) {
                s2.pop();
                i++;
            }
            else 
            {
                s2.pop();
                i++;
                curr2 = curr2 -> left;
                while(curr2 != NULL) {
                    s2.push(curr2);
                    curr2 = curr2 -> right;
                }
            }
            
            if (curr1->right == NULL) {
                s1.pop();
                i++;
            }    
            else {
                s1.pop();
                i++;
                curr1 = curr1 -> right;
                while (curr1 != NULL) {
                    s1.push(curr1);
                    curr1 = curr1 -> left;
                }
            }
       
            

            
        }
        
        else if(s1.top()->data+s2.top()->data>s){
            BinaryTreeNode<int>* curr = s2.top();
            if (curr->left == NULL) {
                s2.pop();
                i++;
            }
            else {
                s2.pop();
                i++;
                curr = curr -> left;
                while(curr != NULL) {
                    s2.push(curr);
                    curr = curr -> right;
                }
            }
        }
        
        else if(s1.top()->data+s2.top()->data < s){
            BinaryTreeNode<int>* curr = s1.top();
            if (curr->right == NULL) {
                s1.pop();
                i++;
            }    
            else {
                s1.pop();
                i++;
                curr = curr -> right;
                while (curr != NULL) {
                    s1.push(curr);
                    curr = curr -> left;
                }
            }
            
        }
        
        
        
    }
      
}