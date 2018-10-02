import 'dart:core';

void main(){
  List<int> list = [64, 34, 25, 12, 22, 11, 90];

 bubbleSort(list);

  print("Sorted list is:");
  for (var i = 0; i < list.length; i++) {
    print(list[i]);
  }
}

void bubbleSort(List<int> list){
  var n = list.length;
  print(n);
  for (var i = 0; i < n-1; i++) {
    for (var j = 0; j < n-i-1; j++) {
      if(list[j] > list[j+1]){
        var temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
      }
    }
  }
}