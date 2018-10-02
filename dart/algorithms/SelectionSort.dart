main(){

  List<int> list = [77,42,86,1,88,100,23,85];

  selectionSort(list);

  print("sorted array is:");
  for (var i = 0; i < list.length; i++) {
    print(list[i]);
  }

}

void selectionSort(List<int> list){
  var n = list.length;

  for(int i = 0; i < n-1; i++){
    var minIndex = i;
    for(int j = i+1; j < n; j++){
      if(list[j] < list[minIndex]){
        minIndex = j;
      }

      int temp = list[minIndex];
      list[minIndex] = list[i];
      list[i] = temp;
    }
  }
}