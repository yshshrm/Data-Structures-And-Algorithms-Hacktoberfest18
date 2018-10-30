function validPhoneNumber(phoneNumber){
  var counter= [0,0,0,0];
  for(var i=0; i<phoneNumber.length ; i++){
    if(phoneNumber[i]=='('){
      counter[0]=counter[0]+1;
    }else if( phoneNumber[i]==')'){
      counter[1]=counter[1]+1;
    
    }else if( phoneNumber[i]==' '){
      counter[2]=counter[2]+1;
    
    }else if( phoneNumber[i]=='-'){
      counter[3]=counter[3]+1;
    
    }
    
  }
  if (counter[0] == 1 && counter[1] == 1 && counter[2] == 1 && counter[3] == 1){
    return true;
  }
  else
    return false;
}
