/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Solon
 */
 public class Search {
    
   static public Boolean LinearSearch(String[] table,String key)
    {
        for(int i=0;i<table.length;i++)
        {
            if(table[i].equals(key))
                return true;
        }
        return false;
    }
    
}
