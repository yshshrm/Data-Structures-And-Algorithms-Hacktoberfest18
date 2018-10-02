void main() {

  List<int> list = [122,53,78,3,86,11,78,23,25];

  InsertionSort(list);

  print("sorted list is:");
  for (var i = 0; i < list.length; i++) {
    print(list[i]);
  }
}

void InsertionSort(List<int> list){
  int n = list.length;

  for (var i = 0; i < n; i++) {
    int key = list[i];
    int j = i-1;

    while(j >= 0 && list[j] > key){
      list[j+1] = list[j];
      j = j-1;
    }
    list[j+1] = key;
  }
}