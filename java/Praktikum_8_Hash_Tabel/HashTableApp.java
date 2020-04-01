/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Praktikum_8_Hash_Tabel;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author win 10
 */
public class HashTableApp {

    public static void main(String[] args) throws IOException {

        DataItem aDataItem;
        int aKey, size, n, keyPerCell;

        System.out.print("Enter size of hash table : ");
        size = getInt();
        System.out.print("Enter initial number of item :");
        n = getInt();

       //keyPerCell = 10;
        HashTable theHashTable = new HashTable(size);
        
       int[] data = {30, 15, 31, 24, 33, 33, 33, 33, 13, 56};
        for (int i = 0; i < n; i++) {
            //System.out.print("Masukkan angka ");
            //Key=getInt();
           aKey = data[i];
            aDataItem = new DataItem(aKey);
            theHashTable.insert(aDataItem);
        }

//                for (int j = 0; j < n; j++) {
//         aKey = (int) (Math.random() * keyPerCell * size);
//         aDataItem = new DataItem(aKey);
//         theHashTable.insert(aDataItem);
//
//         }
//         
        while (true) {

            System.out.print("Enter first letter of ");
            System.out.print("show, insert, delete, or, find : ");
            
            
            char choice = getChar();
            switch (choice) {
                case 's':
                    theHashTable.displayTable();
                    break;
                case 'i':
                    System.out.print("Enter key value to insert: ");
                    aKey = getInt();
                    aDataItem = new DataItem(aKey);
                    theHashTable.insert(aDataItem);
                    break;
                case 'd':
                    System.out.print("Enter key value to delete: ");
                    aKey = getInt();
                    theHashTable.delete(aKey);
                    break;
                case 'f':
                    System.out.print("Enter key value to find: ");
                    aKey = getInt();
                    aDataItem = theHashTable.find(aKey);
                    if (aDataItem != null) {
                        System.out.println("Found " + aKey);
                    } else {
                        System.out.println("Could not find " + aKey);
                    }
                    break;   
                default:
                    System.out.print("Invalid entry\n");       
            }
            
        }
    }

    private static int getInt() throws IOException {
        String s = getString();
        return Integer.parseInt(s);
    }

    private static char getChar() throws IOException {
        String s = getString();
        return s.charAt(0);
    }

    private static String getString() throws IOException {
        BufferedReader dataIn = new BufferedReader(new InputStreamReader(System.in));
        String s = dataIn.readLine();
        return s;
    }
}
