function sumTwoLowest(...args){
    const arry = Array.from(args[0]).sort((a,b) => a - b);
    const test = arry.every((val) => Number.isInteger(val));
      if(!test){
        return "only intergers are accepted"
      }else{
        return arry[0] + arry[1];
      }   
  }

const a =sumTwoLowest([19, 5, 42, 4]);
console.log(a);