#include<iostream>
#include<vector>
using namespace std;

class minheap{
	vector<int>v;

	void heapify(int index){
		int min_index=index;

        int left=2*index;
		int right=left+1;

		if(left<v.size() && v[min_index]>v[left]){
			min_index=left;
		}
		if(right<v.size() && v[min_index]>v[right]){
			min_index=right;
		}
		if(min_index!=index){
			swap(v[min_index],v[index]);
			heapify(min_index);
		}
	}
public:
	minheap(){
		v.push_back(-1);       //as we don't use the zeroth index
	}

	void push(int data){
		v.push_back(data);

		int index=v.size()-1;
		int parent=index/2;
		while(index>1 && v[parent]>v[index]){
			swap(v[parent],v[index]);
			index=parent;
			parent=parent/2;
		}
	}

	void pop(){
		int last=v.size()-1;
		swap(v[1],v[last]);
		v.pop_back();

		heapify(1);
	}

	int top(){
		return v[1];
	}

	bool empty(){
		return v.size()==1;     //as one element always exists at zeroth index
	}
};

int main(){
    minheap h;
    h.push(4);
    h.push(14);
    h.push(40);
    h.push(24);
    h.push(2);
    h.push(1);
    while(!h.empty()){
        cout<<h.top()<<endl;
        h.pop();
    }
	return 0;
}
