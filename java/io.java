
import java.io.*;    
class CountTest   
{
         public static void main(String args[])
         {
             try
             {
             FileInputStream fin=new FileInputStream("fineNames.txt");
             int charc,num,word,line,i;
             charc=num=0;
             word=1;
             line=1;
             i=fin.read();
             while(i!=-1)
             {
                 char c=(char)i;
                 if(Character.isLetter(i))
                 charc++;
                 else if(Character.isDigit(i))
                 num++;
                 else if(i=='.' || i==' '||i=='\n')
                 word++;
                 if(i=='\r'||i=='\n')
                 line++;
                 i=fin.read();
             }
             System.out.println("Characters="+charc+"\nNumbers="+num+"\nWords="+word+"\nLines="+line);
             fin.close();
         }
         catch(FileNotFoundException e)
         {
             e.printStackTrace();
         }
         catch(IOException e)
         {
             e.printStackTrace();
         }
     }
}
