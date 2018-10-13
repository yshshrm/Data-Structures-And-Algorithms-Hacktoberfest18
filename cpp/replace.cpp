void replaceCharacter(char input[], char c1, char c2) {
   if(input[0]=='\0')
     return;
  
  replaceCharacter(input+1,c1,c2);
  for(int i=0;input[i]!='\0';i++)
  if(input[i]==c1)
    input[i]=c2;
}
