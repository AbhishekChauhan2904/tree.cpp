#include<bits/stdc++.h>
using namespace std;
template<typename T>
class treenode1
{
public:
	T data;
	vector<treenode1<T>*> children;

	treenode1(T data){
      this->data=data;
	}
	~treenode1(){
		for(int i=0;i<children.size();i++){
			delete children[i];
		}
	}
	
};