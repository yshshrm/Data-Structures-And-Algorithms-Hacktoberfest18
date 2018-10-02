public class PlacingParentheses{

     public static int countPossible = 0;
     public static Set<String> dpyes = new HashSet<>(); 
     public static Set<String> dpno = new HashSet<>(); 


     public static void numInterleaves(char[] s1, char[] s2, int size1, int size2){
         char[] result = new char[size1+size2];
         numInterleavesHelper(result,s1,s2,size1,size2,0,0,0);
     }


     public static void numInterleavesHelper(char[] res, char[] s1, char[] s2, int size1, int size2, int pos, int start1, int start2){
          if (pos == size1+size2){ 
               if (dpyes.contains(new String(res))){
                countPossible+=1;
               }
               else{
                    if(dpno.contains(new String(res))){
                         countPossible+=0;
                    }
                    else if (isValid(res)){
                         dpyes.add(new String(res));
                         countPossible+=1;
                    }
                    else{
                          dpno.add(new String(res));
                    }
               }
          }                       

          if (start1 < size1){
               res[pos] = s1[start1];
          numInterleavesHelper(res,s1,s2,size1,size2,pos+1,start1+1,start2);
          }
          if (start2 < size2){
               res[pos] = s2[start2];
          numInterleavesHelper(res,s1,s2,size1,size2,pos+1,start1,start2+1);
          }
     }         

     private static boolean isValid(char[] string){
         LinkedList<Character> myStack = new LinkedList<>();
         for (int i=0; i<string.length; i++){
              if (string[i] == "(".charAt(0)){
                   myStack.push(string[i]);
              }
              else{
                   if (myStack.isEmpty()){
                        return false;
                   }
                   if (string[i] == ")".charAt(0)){
                        myStack.pop();
                   }
              }       
         }
         return myStack.isEmpty();       
     } 
}   
