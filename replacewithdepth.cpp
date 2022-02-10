#include<bits/stdc++.h>
using namespace std;
#include"treenode1.h"
treenode1<int>* takeinputlevelwise(){
	int rootdata;
	cin>>rootdata;
	treenode1<int>*root=new treenode1<int>(rootdata);
	queue<treenode1<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0){
		treenode1<int>*front=pendingnodes.front();
		pendingnodes.pop();
		int numchild;
		cin>>numchild;
		for(int i=0;i<numchild;i++){
			int childdata;
			cin>>childdata;
			treenode1<int>*child=new treenode1<int>(childdata);
			front->children.push_back(child);
			pendingnodes.push(child);
		}
	}
	return root;
}
void help(treenode1<int>* root,int depth){
	root->data=depth;
	for(int i=0;i<root->children.size();i++){
		help(root->children[i],depth+1);
	}
}
void depthreplace(treenode1<int>*root){
	if(root==NULL){
		return;
	}
	int depth=0;
	help(root,depth);
}
void printtree(treenode1<int>*root){
	cout<<root->data<<endl;
	for(int i=0;i<root->children.size();i++){
		cout<<root->children[i]->data<<" ";
	}
	
	for(int i=0;i<root->children.size();i++){
		printtree(root->children[i]);
	}
	cout<<endl;
}
int main(){
     treenode1<int>*root=takeinputlevelwise();
     depthreplace(root);
     printtree(root);
	return 0;
}