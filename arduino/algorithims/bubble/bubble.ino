//An int array name arr is sorted from lowest to highest and outputed.
void setup() {
  #define arraySize 5
  int arr[arraySize] = {8, 5, 1, 6, 9};
  for (int i = 0; i < arraySize - 1; i++) {
    for (int j = 0; j < arraySize - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp;
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  Serial.begin(9600);

  //OUTPUT
  for (int i = 0; i < arraySize; i++) {
    Serial.println(arr[i]);
  }
}

void loop() {
  
}

