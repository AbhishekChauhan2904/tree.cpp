#include<bits/stdc++.h>
using namespace std;
#include"treenode1.h"
treenode1<int>* takeinputlevelwise(){
	int rootdata;
	cin>>rootdata;
	treenode1<int>* root=new treenode1<int>(rootdata);
	queue<treenode1<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0){
		treenode1<int>* front=pendingnodes.front();
		pendingnodes.pop();
		int numchild;
		cin>>numchild;
		for(int i=0;i<numchild;i++){
			int childdata;
			cin>>childdata;
			treenode1<int>* child=new treenode1<int>(childdata);
			front->children.push_back(child);
			pendingnodes.push(child);
		}
	}
	return root;
}
treenode1<int>* maxSumNode(treenode1<int>* root){
     treenode1<int>*ans=root;
	int sum=root->data;
	for(int i=0;i<root->children.size();i++){
		sum+=root->children[i]->data;
		
	}
		
	for(int i=0;i<root->children.size();i++){
		treenode1<int>*childmax=maxSumNode(root->children[i]);
		int smallsumofchild=childmax->data;
		for(int i=0;i<childmax->children.size();i++){
			smallsumofchild+=childmax->children[i]->data;
		}
		if(sum<=smallsumofchild){
			ans=childmax;
			sum=smallsumofchild;
		}
	}
return ans;
}

int main(){
	treenode1<int>*root=takeinputlevelwise();
	treenode1<int>*ans=maxSumNode(root);
	cout<<ans->data<<endl;
 	return 0;
}
