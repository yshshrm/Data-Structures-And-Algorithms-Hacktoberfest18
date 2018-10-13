void pigeonholeSort(int arr[], int n) 
{ 
    // Find minimum and maximum values in arr[] 
    int min = arr[0], max = arr[0]; 
    for (int i = 1; i < n; i++) 
    { 
        if (arr[i] < min) 
            min = arr[i]; 
        if (arr[i] > max) 
            max = arr[i]; 
    } 
    int range = max - min + 1; // Find range 
    vector<int> holes[range]; 
    
    for (int i = 0; i < n; i++) 
        holes[arr[i]-min].push_back(arr[i]); 
  
    int index = 0;  // index in sorted array 
 
    for (int i = 0; i < range; i++) 
    { 
       vector<int>::iterator it; 
       for (it = holes[i].begin(); it != holes[i].end(); ++it) 
            arr[index++]  = *it; 
    } 
} 
