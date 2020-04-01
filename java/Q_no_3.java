package arraysandstrings;
public class Q_no_3 {
    // firstly use trim function
    static String paragraph = "twinkle twinkle little star how are wonder what you are";
     // then use toCharArray
    //static StringBuffer str2;
    static String str;
    static StringBuffer stbuf;
    static char ch[] = paragraph.toCharArray();
    static char temp[] = new char[ch.length];
    static char copyArray[] = new char[ch.length];
    
    public static void main(String[] args) {
        //remove spaces
        removeSpaces();
        BubblesortCharArray();
    }
    
    static void removeSpaces(){
        for(int i = 0; i<ch.length; i++) {
        //    System.out.println("character: " + ch[i]);
            if(ch[i] != ' ') {
                copyArray[i] = ch[i];
            }
        }
    }
    
    static void BubblesortCharArray() {
        for(int i = 0; i < ch.length; i++) {
            for(int j = 1; j < ch.length; j++) {
                if(copyArray[i] > copyArray[j]) {
                    temp[i] = copyArray[i];
                    copyArray[i] = copyArray[j];
                    copyArray[j] = temp[i];
                }
            }
        }
        str = String.valueOf(copyArray);
        stbuf = new StringBuffer(str);
        System.out.print(stbuf.reverse());
    }
}

