class TreeNode{
  dynamic left;
  dynamic right;
  int val;
  
  TreeNode(int x){
    this.val = x;
    this.left = null;
    this.right = null;
  }
}

class BinarySearchTree{
  TreeNode root;
  
  BinarySearchTree(TreeNode r){
    this.root = r;  
  }
  void insert(TreeNode node, TreeNode r){
    if (node.val > r.val){
      if (r.right == null){
        r.right = node;
      }
      else{
        insert(node, r.right); 
      }
    }
    else{
      if (r.left == null){
        r.left = node;    
      }
      else{
        insert(node, r.left);
      }
    }
  }
  
  void inorder_traversal(TreeNode r){
    if (r == null){
      return;
    }
    inorder_traversal(r.left);
    print(r.val);
    inorder_traversal(r.right);
  }
}

void main() {
  BinarySearchTree bst = BinarySearchTree(TreeNode(13));
  
  // Insert nodes into tree
  bst.insert(TreeNode(3), bst.root);
  bst.insert(TreeNode(5), bst.root);
  bst.insert(TreeNode(81), bst.root);
  bst.insert(TreeNode(32), bst.root);
  bst.insert(TreeNode(2), bst.root);
  
  // Traverse the tree inorder
  bst.inorder_traversal(bst.root);
}
// This code was contributed by Surya Kant Sahu (https://ojus1.github.io)