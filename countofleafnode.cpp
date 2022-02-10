#include<bits/stdc++.h>
using namespace std;
#include"treenode.h"
treenode<int>* takeinputlevelwise(){
	int rootdata;
	cout<<"enter value of root"<<endl;
	cin>>rootdata;
	treenode<int>*root=new treenode<int>(rootdata);
	queue<treenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0){
		treenode<int>*front=pendingnodes.front();
		pendingnodes.pop();
		cout<<"enter value of children "<<front->data<<endl;
		int numchild;
		cin>>numchild;
		for(int i=0;i<numchild;i++){
			int childddata;
			cout<<"enter "<< i <<" th value of child of "<< front->data<<endl;
			cin>>childddata;
			treenode<int>*child=new treenode<int>(childddata);
			front->children.push_back(child);
			pendingnodes.push(child);
		}
	}
	return root;
}
void printtree(treenode<int>*root){
	if(root==NULL){
		return;
	}
	queue<treenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0){
		treenode<int>*front=pendingnodes.front();
		pendingnodes.pop();
		cout<<front->data<<":";
		for(int i=0;i<front->children.size();i++){
			pendingnodes.push(front->children[i]);
			if(i==front->children.size()-1){
				cout<<front->children[i]->data;
			}
			else{
				cout<<front->children[i]->data<<",";
			}
		}
		cout<<endl;
	}
}
int countnumberofleaf(treenode<int>*root){
	if(root==NULL){
		return 0;
	}
	if(root->children.size()==0){
		return 1;
	}
	int sum=0;
	for(int i=0;i<root->children.size();i++){
		sum+=countnumberofleaf(root->children[i]);
	} 
	return sum;
}
int main(){
	treenode<int>*root=takeinputlevelwise();
	printtree(root);
	int k=countnumberofleaf(root);
	cout<<k<<endl;
	return 0;
}