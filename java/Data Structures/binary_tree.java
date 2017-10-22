class Node {    

     Node left, right;
     int data;
 
     public Node() {
         left = null;
         right = null;
         data = 0;
     }

     public BTNode(int n) {
         left = null;
         right = null;
         data = n;
     }

     public void setLeft(Node n) {
         left = n;
     }

     public void setRight(Node n) {
         right = n;
     }

     public Node getLeft() {
         return left;
     }

     public Node getRight() {
         return right;
     }

     public void setData(int d) {
         data = d;
     }

     public int getData() {
         return data;
     }     
 }
 
 class BinaryTree {

     private Node root;
 
     public BinaryTree() {
         root = null;
     }

     public boolean isEmpty() {
         return root == null;
     }
    
     public void insert(int data) {
         root = insert(root, data);
     }
     
     private Node insert(Node node, int data)
     {
         if (node == null)
             node = new Node(data);
         else
         {
             if (node.getRight() == null)
                 node.right = insert(node.right, data);
             else
                 node.left = insert(node.left, data);             
         }
         return node;
     }     

     public int countNodes() {
         return countNodes(root);
     }
   
     private int countNodes(Node r) {
         if (r == null)
             return 0;
         else
         {
             int l = 1;
             l += countNodes(r.getLeft());
             l += countNodes(r.getRight());
             return l;
         }
     }     
 }