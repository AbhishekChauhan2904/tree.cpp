#include<bits/stdc++.h>
#include"treenode.h"
using namespace std;
treenode<int>* takeinputlevelwise(){
	int rootdata;
	cout<<"enter value of data"<<endl;
	cin>>rootdata;
	treenode<int>* root=new treenode<int>(rootdata);
	queue<treenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0){
		treenode<int>* front=pendingnodes.front();
		pendingnodes.pop();
		cout<<"enter number of children of "<<front->data<<endl;
		int numchild;
		cin>>numchild;
		for(int i=0;i<numchild;i++){
			int childdata;
			cout<<"enter "<< i <<"th child of "<<front->data<<endl;
			cin>>childdata;
			treenode<int> *child=new treenode<int>(childdata);
			front->children.push_back(child);
			pendingnodes.push(child);
		}
	}
	return root;
}
/*treenode<int> * takeinput(){
	int rootdata;
	cout<<"enter data"<<endl;
	cin>>rootdata;
	treenode<int>* root=new treenode<int>(rootdata);
	int n;
	cout<<"enter number of children"<<rootdata<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		treenode<int>* child=takeinput();
		root->children.push_back(child);
	}
	return root;
}*/
void printtree(treenode<int>*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++){
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++){
		printtree(root->children[i]);
	}
}
int main(){
	/*treenode<int>* root=new treenode<int>(20);
	treenode<int>* node1=new treenode<int>(30);
	treenode<int>* node2=new treenode<int>(40);
	root->children.push_back(node1);
	root->children.push_back(node2);*/
	treenode<int>* root=takeinputlevelwise();
	printtree(root);
	return 0;
}
