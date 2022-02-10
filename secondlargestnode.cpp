#include<bits/stdc++.h>
using namespace std;
#include"treenode1.h"
treenode1<int>*takeinputlevelwise(){
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
void helper(treenode1<int>* root,treenode1<int>** first,treenode1<int>** second){
	if(root==NULL){
		return;
	}
	if((*first)==NULL){
		*first=root;
	}
	else if(root->data>(*first)->data){
		* second=*first;
		*first=root;
	}
	else if((*second)==NULL||root->data>(*second)->data){
		*second=root;
	}
	for(int i=0;i<root->children.size();i++){
		helper(root->children[i],first,second);
	}
}
treenode1<int>* secondlargestnode(treenode1<int>* root){
	treenode1<int>* first=NULL;
	treenode1<int>*second=NULL;
	helper(root,&first,&second);
	if(second==NULL){
		return NULL;
	}
	else if(second->data==first->data){
		return NULL;
	}
	return second;
}
int main(){
	treenode1<int>* root=takeinputlevelwise();
	treenode1<int>* ans=secondlargestnode(root);
	cout<<ans->data<<endl;
	return 0;
}