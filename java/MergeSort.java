class Merge{
	int [] a ={1, 5, 10, 8, 11, 12};
	
	public void mergeSort(int l, int r){
		int m= (l+r)/2;
		if(l>=r){
			return;
			}
		mergeSort(l,m);
		mergeSort(m+1,r);
		merge(l, m, r);
		}
		
		
	public void merge(int l, int m, int r){
		int n1= m-l+1;
		int n2= r-m;
		int n3 =n1+n2;
		int [] b = new int [n1];
		int[] c =new int [n2];
		for (int i=0; i<n1; ++i) 
            b[i] = a[l + i]; 
        for (int j=0; j<n2; ++j) 
            c[j] = a[m + 1+ j]; 
		int i=0, j=0;
		 int k = l; 
        while (i < n1 && j < n2) 
        { 
            if (b[i] < c[j]) 
            { 
                a[k] = b[i]; 
                i++; 
            } 
            else if (b[i]>c[j])
            { 
                a[k] = c[j]; 
                j++; 
            }
            else {
            	a[k]=c[j];
            	j++;
            	i++;
            	} 
            k++; 
        }
        while(i<n1){
        	a[k++]=b[i++];
        	}
        while(j<n2){
        	a[k++]=c[j++];
        	}
        	 
        	 }
        public void print(){
        	for(int i=0; i<6; i++){
        		System.out.print(a[i] +"\t");
        		}
        		}
       }
       
class CS10{
	public static void main(String [] args){
		Merge n= new Merge();
		n.mergeSort(0, 5);
		n.print();
		}
		}
		
		
	
	
	
