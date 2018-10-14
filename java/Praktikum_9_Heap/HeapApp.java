/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Praktikum_9_Heap;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author win 10
 */
public class HeapApp {

    public static void main(String[] args) throws IOException {
        int value, value2;
        Heap theHeap = new Heap(35); // make a Heap; max size 31
        boolean success;
        theHeap.insert(70); // insert 10 items
        theHeap.insert(40);
        theHeap.insert(50);
        theHeap.insert(20);
        theHeap.insert(60);
        theHeap.insert(100);
        theHeap.insert(80);
        theHeap.insert(30);
        theHeap.insert(10);
        theHeap.insert(90);
        theHeap.insert(12);
        theHeap.insert(35);

        while (true) // until [Ctrl]-[C]
        {
            System.out.print("Enter first letter of ");
            System.out.print("show, insert, remove, change: ");
            int choice = getChar();
            switch (choice) {
                case 's': // show
                    theHeap.displayHeap();
                    break;
                case 'i': // insert
                    System.out.print("Enter value to insert: ");
                    value = getInt();
                    success = theHeap.insert(value);
                    if (!success) {
                        System.out.println("Can’t insert; heap full");
                    }
                    break;
                case 'r': // remove
                    if (!theHeap.isEmpty()) {
                        theHeap.remove();
                    } else {
                        System.out.println("Can’t remove; heap empty");
                    }
                    break;
                case 'c': // change
                    System.out.print("Enter current index of item: ");
                    value = getInt();
                    System.out.print("Enter new key: ");
                    value2 = getInt();
                    success = theHeap.change(value, value2);
                    if (!success) {
                        System.out.println("Invalid index");
                    }
                    break;
                default:
                    System.out.println("Invalid entry\n");
            } // end switch
        } // end while
    }

    private static int getChar() throws IOException {
        String s = getString();
        return s.charAt(0);
    }

    private static int getInt() throws IOException {
        String s = getString();
        return Integer.parseInt(s);
    }

    private static String getString() throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String s = br.readLine();
        return s;
    }
}
