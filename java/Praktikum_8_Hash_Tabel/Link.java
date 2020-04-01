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
public class Link {

    private int iData; // data item
    public Link next; // next link in list
// -------------------------------------------------------------

    public Link(int it) // constructor
    {
        iData = it;
    }
// -------------------------------------------------------------

    public int getKey() {
        return iData;
    }
// -------------------------------------------------------------

    public void displayLink() // display this link
    {
        System.out.print(iData + " ");
    }
}
