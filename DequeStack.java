public class DequeStack implements Stack
{
   Deque D; // holds the elements of the stack
   public DequeStack()
   {
      D = new MyDeque();
   }
   @Override
   public int size()
   {
      return D.size();
   }
   @Override
   public boolean isEmpty()
   {
      return D.isEmpty();
   }
   @Override
   public void push(Object obj)
   {
      D.insertLast(obj);
   }
   @Override
   public Object top() throws StackEmptyException
   {
      try
      {
         return D.lastElement();
      }
      catch(DequeEmptyException err)
      {
         throw new StackEmptyException();
      }
   }
   @Override
   public Object pop() throws StackEmptyException
   {
      try
      {
         return D.removeLast();
      }
      catch(DequeEmptyException err)
      {
         throw new StackEmptyException();
      }
   }
}
