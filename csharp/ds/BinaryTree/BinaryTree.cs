namespace csharp.ds.BinaryTree
{
    public class BinaryTree
    {
        public int _value;
        public BinaryTree _leftNode;
        public BinaryTree _rightNode;

        public BinaryTree(int value) => _value = value;

        public BinaryTree(int value, BinaryTree leftNode, BinaryTree rightNode)
        {
            _value = value;
            _leftNode = leftNode;
            _rightNode = rightNode;
        }
    }
}
