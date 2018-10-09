package adt.avltree;

import adt.bst.BSTNode;

public class AVLCountAndFillImpl<T extends Comparable<T>> extends AVLTreeImpl<T> implements AVLCountAndFill<T> {

   private int LLcounter;
   private int LRcounter;
   private int RRcounter;
   private int RLcounter;

   public AVLCountAndFillImpl() {

   }

   @Override
   protected void rebalance(BSTNode<T> node) {
      int balance = calculateBalance(node);
      if (balance > 1) {
         if (calculateBalance((BSTNode<T>) node.getLeft()) < 0) {
            adt.bt.Util.leftRotation((BSTNode<T>) node.getLeft());
            LRcounter++;
         } else {
            LLcounter++;
         }
         if (node == getRoot()) {
            setRoot((BSTNode<T>) node.getLeft());
         }
         adt.bt.Util.rightRotation(node);
      } else if (balance < -1) {
         if (calculateBalance((BSTNode<T>) node.getRight()) > 0) {
            adt.bt.Util.rightRotation((BSTNode<T>) node.getRight());
            RLcounter++;
         } else {
            RRcounter++;
         }
         if (node == getRoot()) {
            setRoot((BSTNode<T>) node.getRight());
         }
         adt.bt.Util.leftRotation(node);
      }
   }

   @Override
   public int LLcount() {
      return LLcounter;
   }

   @Override
   public int LRcount() {
      return LRcounter;
   }

   @Override
   public int RRcount() {
      return RRcounter;
   }

   @Override
   public int RLcount() {
      return RLcounter;
   }

   @Override
   public void fillWithoutRebalance(T[] array) {
	  quickInsert(array, 0, array.length - 1);
   }

   private void quickInsert(T[] array, int leftIndex, int rightIndex) {
      if (leftIndex < rightIndex) {
         int pivot = partition(array, leftIndex, rightIndex);
         insertWithoutRebalance(array[pivot]);
         quickInsert(array, leftIndex, pivot - 1);
         quickInsert(array, pivot + 1, rightIndex);
      }
   }

   private int partition(T[] array, int leftIndex, int rightIndex) {
      int i = leftIndex + 1;
      int f = rightIndex;
      while (i <= f) {
         if (array[i].compareTo(array[leftIndex]) <= 0) {
            i++;
         } else if (array[f].compareTo(array[leftIndex]) > 0) {
            f--;
         } else {
            swap(array, i, f);
            i++;
            f--;
         }
      }
      swap(array, leftIndex, f);
      return f;
   }

   private void insertWithoutRebalance(T element) {
      insertWithNodeWithoutRebalance(getRoot(), element);
   }

   @SuppressWarnings("unchecked")
   private void insertWithNodeWithoutRebalance(BSTNode<T> node, T element) {
      if (node.isEmpty()) {
         node.setData(element);
         node.setLeft(new BSTNode.Builder<T>().data(null).parent(node).build());
         node.setRight(new BSTNode.Builder<T>().data(null).parent(node).build());
      } else {
         if ((element.compareTo(node.getData()) < 0)) {
            insertWithNodeWithoutRebalance((BSTNode<T>) node.getLeft(), element);
         } else if ((element.compareTo(node.getData()) > 0)) {
            insertWithNodeWithoutRebalance((BSTNode<T>) node.getRight(), element);
         }

      }

   }

   private void swap(T[] array, int i, int j) {
      if (array == null)
         throw new IllegalArgumentException();

      T temp = array[i];
      array[i] = array[j];
      array[j] = temp;
   }

}
