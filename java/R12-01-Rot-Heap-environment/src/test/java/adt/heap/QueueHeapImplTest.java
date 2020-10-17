package adt.heap;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import adt.queue.QueueHeapImpl;
import adt.queue.QueueOverflowException;
import adt.queue.QueueUnderflowException;
import adt.stack.StackHeapImpl;
import adt.stack.StackOverflowException;
import adt.stack.StackUnderflowException;

public class QueueHeapImplTest {
	public QueueHeapImpl<String> queue;

	@Before
	public void setUp() throws Exception {
		queue = new QueueHeapImpl<String>(6);
	}


	@Test
	public void testPush() throws QueueOverflowException, QueueUnderflowException {
		queue.enqueue("Juan");
		assertFalse(queue.isEmpty());
		
		queue.enqueue("Amintas");
		
		assertEquals("Juan", queue.dequeue());
		
		assertEquals("Amintas", queue.dequeue());
		assertTrue(queue.isEmpty());
		
		queue.enqueue("Juan1");
		queue.enqueue("Juan2");
		queue.enqueue("Juan3");
		queue.enqueue("Juan4");
		queue.enqueue("Juan5");
		queue.enqueue("Juan6");
		assertTrue(queue.isFull());
		
		assertEquals("Juan1", queue.dequeue());
		assertEquals("Juan2", queue.dequeue());
		assertEquals("Juan3", queue.dequeue());
		assertEquals("Juan4", queue.dequeue());
		assertEquals("Juan5", queue.dequeue());
		assertEquals("Juan6", queue.dequeue());
		
	}
	
}
