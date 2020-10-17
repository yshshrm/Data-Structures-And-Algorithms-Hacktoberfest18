package adt.heap;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import adt.stack.StackHeapImpl;
import adt.stack.StackOverflowException;
import adt.stack.StackUnderflowException;

public class StackHeapImplTest {
	public StackHeapImpl<String> stack;

	@Before
	public void setUp() throws Exception {
		stack = new StackHeapImpl<String>(6);
	}


	@Test
	public void testPush() throws StackOverflowException, StackUnderflowException {
		stack.push("Juan");
		assertFalse(stack.isEmpty());
		
		stack.push("Amintas");
		
		assertEquals("Amintas", stack.pop());
		
		assertEquals("Juan", stack.pop());
		assertTrue(stack.isEmpty());
		
		stack.push("Juan1");
		stack.push("Juan2");
		stack.push("Juan3");
		stack.push("Juan4");
		stack.push("Juan5");
		stack.push("Juan6");
		assertTrue(stack.isFull());
		
		assertEquals("Juan6", stack.pop());
		assertEquals("Juan5", stack.pop());
		assertEquals("Juan4", stack.pop());
		assertEquals("Juan3", stack.pop());
		assertEquals("Juan2", stack.pop());
		assertEquals("Juan1", stack.pop());
		
	}
	
}
