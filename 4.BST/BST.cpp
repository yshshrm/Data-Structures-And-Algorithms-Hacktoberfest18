#include<iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
	// Complete this class
    public:
    BinaryTreeNode<int> *root;
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }
    bool hasData(int x, BinaryTreeNode<int> *root){
         if(root == NULL)
            return false;
        else if(root->data == x)
            return true;
        else if(root->data < x)
            return hasData(x,root->right);
        else
            return hasData(x,root->left);
    }

    bool hasData(int x){
       return hasData(x,root);
    }

    BinaryTreeNode<int>* insert(int x , BinaryTreeNode<int> *root){
         BinaryTreeNode<int> *node = new BinaryTreeNode<int>(x);
        if(root == NULL){
            root = node;
           return root;
        }
        else if (root->data < node->data)
            root->right = insert(x, root->right);
        else
            root->left = insert(x, root->left);

        return root;
    }
    void insert(int x){
       root = insert(x,root);
    }
    // this function below is helper for "deleteData(int data, BinaryTreeNode<int>* root) "
     BinaryTreeNode<int>* minN(BinaryTreeNode<int>* root){

		if(root==NULL)
		return NULL;

		BinaryTreeNode<int>* ans=minN(root->left);

		if(ans==NULL)
		return root;

      return ans;
	}
    //lot of changes in the below fuction.. try to dry run the belpow function to get better understanding of the code
    BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* root){


		if(root==NULL)
		return NULL;

		if(data > root->data){
			BinaryTreeNode<int>*temp=deleteData(data,root->right);
			root->right=temp;
		}

		else if(data < root->data){
			BinaryTreeNode<int>*temp=deleteData(data,root->left);
			root->left=temp;
		}

		else if(root->data==data){

			if(root->left==NULL&&root->right==NULL)
			return NULL;

			else if(root->left!=NULL&&root->right==NULL){
				BinaryTreeNode<int>* temp=root->left;
				delete root;
				return temp;
			}

			else if(root->right!=NULL&&root->left==NULL){
				BinaryTreeNode<int>* temp=root->right;
				delete root;
				return temp;
			}
			else if(root->right!=NULL&&root->left!=NULL){

				BinaryTreeNode<int>* rightSmall=minN(root->right);

                int temp=root->data;
                //we also have to swap the datas of "rightSmall" and "root"
                // and then delete the temp data from the right sub-tree
				root->data=rightSmall->data;
                rightSmall->data=temp;
                root->right=deleteData(temp,root->right);

			}
		}
      return root;// return the root also after deleting
    }

    void deleteData(int x){
         root = deleteData(x, root);
    }

    void printTree(BinaryTreeNode<int> *root){
        if(root == NULL)
            return ;

        if(root->left==NULL && root->right==NULL)
        cout<<root->data<<":"<<endl;
        else
        cout<<root->data<<":";

        if(root->left != NULL)
        {   cout<<"L:"<<root->left->data<<",";
            if(root->right != NULL)
                cout<<"R:"<<root->right->data<<endl;
                else
                    cout<<endl;


    }
        else
        {
            if(root->right != NULL)
                cout<<"R:"<<root->right->data<<endl;
        }
        printTree(root->left);
        printTree(root->right);
    }

    void printTree(){
        printTree(root);
    }
};



int main(){
    BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->printTree();
                return 0;
                break;
        }
    }
}
