const RankingAscending = arr => {
  for(let i =0;i<arr.length;i++){
    for(let j =0;i<arr.length;j++){
      if(arr[i]>arr[j]){
        let tem = arr[i];
        arr[i]=arr[j];
        arr[j]=tem;
      }
    }
  }
}
