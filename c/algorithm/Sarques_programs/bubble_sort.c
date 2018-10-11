#include<stdio.h>
#include<stdlib.h>
/*void main(){
	int n,a[n],i,j,flag,b;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++){
		flag=0;
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				b=a[j];
				a[j]=a[j+1];
				a[j+1]=b;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}*/
/*int main(){
	int i,j,b,temp,n,a[n];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++){
		temp=i,b=a[i];
		for(j=i+1;j<n;j++){
			if(a[temp]>a[j]){
				temp=j;
				b=a[j];
			}                                                                                                                                          
		}
		a[temp]=a[i];
		a[i]=b;
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
} 
int main(){
	int i,b,n,a[n],k,c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		k=i,b=a[i];
		while((k>0)&&(a[k]<a[k-1])){
			c=a[k];
			a[k]=a[k-1];
			a[k-1]=c;
			k--;
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}  
void partition(int a[n],int m,int n){
	int pivot,j,low=0,up=n-1;
	if(n<2)
		return;
	pivot=a[rand()%n];
	while(low<up){
		while(a[low]<pivot)
			low++;
		while(a[up]>pivot)
			up--;
		j=a[up];
		a[up]=a[low];
		a[low]=j;
	}
	partition(a[low],low,up-1);
	partition(a[up],up-1,n);
}
int partition(int *a,int start,int end){
	int pivot=a[end],c,i;
	int pindex=start;
	for(i=0;i<end-1;i++){
		if(a[i]<=pivot){
			c=a[i];
			a[i]=a[pindex];
			a[pindex]=c;
			pindex++;
		}
	}
	c=a[pindex];
	a[pindex]=a[end];
	a[end]=c;
	return pindex;
}
int quicksort(int *a,int start,int end){
	if(start<end){
		int pindex=partition(a,start,end);
		quicksort(a,start,pindex-1);
		quicksort(a,pindex+1,end);
	}
}
int main(){
	int pivot,i,a[n];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
///////////////
typedef struct node{
	int data;
	struct node* lc;
	struct node* rc;
}node;
node* create_tree(){
	node* root,t1,t2,t3;
	int d;
	scanf("%d",&d);
	while(d!=-9999){
		t3=(node*)malloc(sizeof(node));
		t3->data=d;
		t3->lc=NULL;
		t3->rc=NULL;
		if(root==NULL){
			root=t3;
		}
		else{
			t2=NULL;
			t1=root;
			while(t1!=NULL){
				if(t1->data<=d){
					t2=t1;
					t1=t1->lc;
				}
				else{
					t2=t1;
					t1=t1->rc;
				}
			}
			if(t2->data<=d){
				t2->lc=t3;
			}
			else
				t2->rc=t3;
			scanf("%d",&d);
	}
}
void preorder(node *temp){
	if(temp!=NULL){
		printf("%d ",temp->data);
		preorder(temp->lc);
		preorder(temp->rc);
	}
}
void inorder(node *temp){
	if(temp!=NULL){
		inorder(temp->lc);
		printf("%d ",temp->data);
		inorder(temp->rc);
	}
}
void postorder(node *temp){
	if(temp!=NULL){
		postorder(temp->lc);
		postorder(temp->rc);
		printf("%d ",temp->data);
	}
}

int main(){
	node* r;
	r=create_tree();
	printf("\npreorder:");
	preorder(root);
	printf("\ninorder:");
	inorder(root);
	printf("\npostorder:");
	postorder(root);
	return 0;
}*/
void quicksort(int[],int,int);
int partition(int[],int,int);
int main(){
	int a[50],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
void quicksort(int a[],int l,int u){
	int j;
	if(l<u){
		j=partition(a,l,u);
		quicksort(a,l,j-1);
		quicksort(a,j+1,u);
	}
}
int partition(int a[],int l,int u){
	int v,i,j,temp;
	v=a[l];
	i=l;
	j=u+1;
	do{
		do
		i++;
		while(a[i]<v&&i<=u);
		do
		j--;
		while(v<a[j]);
		if(i<j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	while(i<j);
	a[l]=a[j];
	a[j]=v;
	return(j);
}