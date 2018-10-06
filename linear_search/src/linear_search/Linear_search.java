/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package linear_search;
import java.util.ArrayList;
/**
 *
 * @author Noelia
 */
public class Linear_search {

    public static int linearSearch (ArrayList<Integer> array, int value){
        boolean found = false;
        int position = 0;
                
        for (int i = 0; i < array.size() && !found; i++){
            if (array.get(i) == value){
                found = true;
                position = i;
            }
        }
        
        if (found)
            return position;
        else
            return -1;
    }
    
}
