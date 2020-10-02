package dataStructures;

/**ChainNode class creates a node with data and link elment in a node */
class ChainNode
{
    // data members will be visible to all the classes within the package
    Object element; // data element
    ChainNode next; // link element

    // package visible constructors
    ChainNode()
    {
        // default values of element and next will be set to null
    }

    ChainNode(Object element)
    {
        this.element = element; //default value of next will be set to null
    }

    ChainNode(Object element,ChainNode next)
    {
        this.element = element;
        this.next = next;
    }

}

public class Chain implements LinearList
{
    protected ChainNode firstNode; // to keep track of first node
    protected int size; // to determine size of the linked list

    /** creates a list that is empty */
    public Chain(int initialCapacity) // this constructor is in accordance with constructor of Array implementation of LinearList, initialCapacity is useless
    {
        // default value of firstNode will be set to null and of size will be set to zero
    }

    public Chain()
    {
        this(0);
    }

    /** checks if there's an element in the list */
    public boolean isEmpty()
    {
        return size == 0;
    }

    /** returns the number of elements in the list */
    public int size()
    {
        return size;
    }

    /** checks if the index is within the range otherwise throws IndexOutOfBound exception */
    public void checkIndex(int index)
    {
        if(index<0 || index>=size)
            throw new IndexOutOfBoundsException
                ("Index= " +index+ " Size= "+size);
    }

    /** returns the object at the specified index */
    public Object get(int index)
    {
        checkIndex(index);

        ChainNode currentNode = firstNode;
            for(int i=0;i<index;i++) // moves upto the desired node
                currentNode = currentNode.next;

        return currentNode.element;
    }

    /** returns the index of the specified element */
    public int indexOf(Object theElement)
    {
        ChainNode currentNode = firstNode;
        int index = 0; // index of currentNode
        while(currentNode != null && !currentNode.element.equals(theElement)) // loop ends if the element is found or the list has been traversed and element is not found
        {
            currentNode = currentNode.next; // moves to the next node
            index++;
        }

        if(currentNode == null)
            return -1; // if element is not found
        else
            return index;
    }

    /** removes and return the node at the spicified index */
    public Object remove(int index)
    {
        checkIndex(index);

        Object removedElement;
        
            if(index == 0) // to remove the front node or node at the index zero
            {
                removedElement = firstNode.element; // to initialize the removed element with the element of the node to be removed
                firstNode = firstNode.next; // removes the node
            }
            else // to remove the node at the index other than the front node or at the index zero
            {
            ChainNode p = firstNode;
                // to reach at the predecessor or index-1 node of the node to be removed.
                for(int i=0;i<index-1;i++)
                    p = p.next;

            removedElement = p.next.element; // to initialize the removedElement with the element of the node to be removed
            p.next = p.next.next; //removes the node
        }
        size--;

        return removedElement;

    }

    /** insert a node at the given index with the element */
    public void add(int index, Object theElement)
    {
        // to check the index
        if(index<0 || index>size)
            throw new IndexOutOfBoundsException
                ("Index= " +index+ " Size= " +size);

        if(index == 0) // to insert the node at the index 0
            firstNode = new ChainNode(theElement, firstNode); // inserts the node
        else // to insert the node at the index other than zero
        {
        ChainNode q = firstNode;
            // to reach at the prdecessor or index-1 node to be inserted
            for(int i=0;i<index-1;i++)
                q = q.next; 

        q.next = new ChainNode(theElement, q.next); // inserts the node after p or at the given index with the element
        }
        size++;
    }

    /** converts elements of the list into a string */
    public String toString()
    {
        StringBuffer s = new StringBuffer("[");
        ChainNode currentNode = firstNode;
        // puts elements of the list into the buffer
        while(currentNode != null)
        {
            if(currentNode.element == null)
                s.append("null, ");
            else
                s.append(currentNode.element.toString() +", ");
            
        currentNode = currentNode.next;
        }

        if(size>0)
            s.delete(s.length()-2,s.length()); // removes last ", "
        s.append("]");

        // creates and return an equivalent string
        return new String(s);
    }

    public static void main(String[] args)
    {
        LinearList x = new Chain(4);

        // checks add method
        x.add(0, new Integer(4));
        x.add(0, new Integer(3));
        x.add(0, new Integer(2));
        x.add(0, new Integer(1));

        // checks isEmpty method
        if(x.isEmpty())
            System.out.println("List is empty");
        else
            System.out.println("List is not empty");

        // checks size method
            System.out.println("Number of element in the list are: " +x.size());

        // checks get method
        System.out.println("Element at the index 2 is: " +x.get(2));

        //checks indexOf method
        if(x.indexOf(4)>0)
            System.out.println("Index of the element is: " +x.indexOf(4));
        else
            System.out.println("No such element exists in the list");
        
        // checks remove method
        System.out.println("Element removed from the list is: " +x.remove(2));
    
        // toString method
        System.out.print("Elements in the lists are: " +x);

    }
}
