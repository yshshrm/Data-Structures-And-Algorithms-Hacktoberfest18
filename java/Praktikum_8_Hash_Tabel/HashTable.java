/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Praktikum_8_Hash_Tabel;

/**
 *
 * @author win 10
 */
public class HashTable {

    private DataItem[] hashArray;
    private int arraySize;
    private int nElemen;
    private DataItem nonItem;

    public HashTable(int size) {
        arraySize = size;
        hashArray = new DataItem[size];
        nonItem = new DataItem(-1);
        nElemen=0;
    }

    public void displayTable() {
         System.out.println("Table: ");
        for (int j = 0; j < arraySize; j++) {
            if (hashArray[j] != null) {
                System.out.println(" | " + j + "\t | "
                        + hashArray[j].getKey() + " |");
            } else {
                System.out.println(" | " + j + "\t | -- |");
            }
        }
        System.out.println("");
    }

    public int hashFunc(int key) {
        return key % arraySize;
    }
    public int hashFunc2(int key){
        return  5 - key % 5;
    }

    public void insert(DataItem item) {
        if(isFull()){
            System.out.println("Udah Penuh");
        }else{
        int key = item.getKey();
        int hashVal = hashFunc(key);
        int stepSize = hashFunc2(key);
        
        while (hashArray[hashVal] != null && hashArray[hashVal].getKey() != -1) {
            hashVal += stepSize;
            hashVal %= arraySize;
        }
                
        hashArray[hashVal] = item;
        nElemen++;
        }
    }
    public boolean isFull(){
        return (nElemen==arraySize);
    }

    public DataItem delete(int key) {
        int hashVal = hashFunc(key);
        int stepSize=hashFunc2(key);
        
        while (hashArray[hashVal] != null) {
            if (hashArray[hashVal].getKey() == key) {
                DataItem temp = hashArray[hashVal]; // save item
                hashArray[hashVal] = null; // delete item
                return temp;
            }
            hashVal += stepSize; // go to next cell
            hashVal %= arraySize;
        }
        return null;
    }
    
    public DataItem find(int key){
        int hashVal = hashFunc(key);
        int stepSize=hashFunc2(key);
        
        while(hashArray[hashVal] != null){
            if(hashArray[hashVal].getKey()==key){
                return hashArray[hashVal];
            }

            hashVal += stepSize;
            hashVal %= arraySize;
        }
        return null;
    }
    
}
