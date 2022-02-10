#include <bits/stdc++.h>
using namespace std;
#include "treenode.h"
treenode<int>* takeinputlevelwise(){
	int rootdata;
	cout<<"enter value of root"<<endl;
	cin>>rootdata;
	treenode<int>* root= new treenode<int>(rootdata);
	queue<treenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0){
		treenode<int>* front=pendingnodes.front();
		pendingnodes.pop();
		cout<<"enter value of children of "<<front->data<<endl;
           int numchild;
           cin>>numchild;
           for(int i=0;i<numchild;i++){
           	int childdata;
           	cout<<"enter "<<i<<"th value of child of "<<front->data<<endl;
           	cin>>childdata;
           	treenode<int>* child=new treenode<int>(childdata);
           	front->children.push_back(child);
           	pendingnodes.push(child);
           }
	}
	return root;
}
void printinput(treenode<int>* root){
	if(root==NULL){
		return;
	}
	for(int i=0;i<root->children.size();i++){
		printinput(root->children[i]);
	}
	cout<<root->data<<" ";
}
int main(){
	treenode<int>* root=takeinputlevelwise();
	printinput(root);
	return 0;
}