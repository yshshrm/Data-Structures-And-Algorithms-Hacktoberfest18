bool isSorted(int a[], int n) 
{ 
    while ( --n > 1 ) 
        if (a[n] < a[n-1]) 
            return false; 
    return true; 
} 

void shuffle(int a[], int n) 
{ 
    for (int i=0; i < n; i++) 
        swap(a[i], a[rand()%n]); 
} 
 
void bogosort(int a[], int n) 
{ 
    while ( !isSorted(a, n) ) 
        shuffle(a, n); 
} 
