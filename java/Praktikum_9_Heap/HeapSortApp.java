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
public class HeapSortApp {

    public static void main(String[] args) throws IOException {
        int size, j;
        System.out.print("Masukkan jumlah item : ");
        size = getInt();
        Heap theHeap = new Heap(size);
        for (j = 0; j < size; j++) // fill array with
        { // random nodes
            int random = (int) (java.lang.Math.random() * 100);
            Node newNode = new Node(random);
            theHeap.insertAt(j, newNode);
            theHeap.incrementSize();
        }
        System.out.print("Random :");
        theHeap.displayArray();

        for (j = size / 2 - 1; j >= 0; j--) {
            theHeap.trickleDown(j);
        }
        System.out.print("Heap:  ");
        theHeap.displayArray();
        theHeap.displayHeap();
/*
        for (j = size - 1; j >= 0; j--) // remove from heap and
        { // store at array end
            Node biggestNode = theHeap.remove();
            theHeap.insertAt(j, biggestNode);
        }
*/
        theHeap.HeapSort();
        System.out.print("Sorted: ");
        theHeap.displayArray();
    }
//______________________________________________________________________________
//______________________________________________________________________________
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
