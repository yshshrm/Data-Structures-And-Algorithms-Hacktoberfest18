import java.util.*;

public class morris {
    static Node root;
    public static class Node {
        int data;
        Node left;
        Node right;
    }

    static Node fun(Node node){
        Node lkarm = node.left;

        while(lkarm.right != null && lkarm.right != node){
            lkarm = lkarm.right;
        }

        return lkarm;
    }

    public static void main(String[] args){
        Node node = root;
        while(node != null){
            if(node.left == null){
                System.out.println(node.data);
                node = node.right;
            } else {
                Node lkarm = fun(node);

                if(lkarm.right == null){
                    System.out.println(node.data);
                    lkarm.right = node;
                    node = node.left;
                }
                else if(lkarm.right == node){
                    lkarm.right = null;
                    node = node.right;
                }
            }
        }
    }
}






