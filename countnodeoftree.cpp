#include<bits/stdc++.h>
using namespace std;
#include"treenode.h"
treenode<int>* takeinputlevelwise(){
	int rootdata;
	cout<<"enter value of root data"<<endl;
	cin>>rootdata;
	treenode<int>* root=new treenode<int>(rootdata);
	queue<treenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0){
		treenode<int>* front=pendingnodes.front();
		pendingnodes.pop();
		cout<<"enter number of children "<<front->data<<endl;
		int numchild;
		cin>>numchild;
		for(int i=0;i<numchild;i++){
			int childdata;
			cout<<"enter "<< i <<" th child of "<<front->data<<endl;
			cin>>childdata;
			treenode<int>*child=new treenode<int>(childdata);
			front->children.push_back(child);
			pendingnodes.push(child);
		}
	}
	return root;
}
void printtree(treenode<int>* root){
	if(root==NULL){
		return ;
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
int numnodes(treenode<int>*root){
	int ans=1;
	for(int i=0;i<root->children.size();i++){
		ans+=numnodes(root->children[i]);
	}
	return ans;
}
int main(){
	treenode<int>* root=takeinputlevelwise();
	printtree(root);
	int numberofnode=numnodes(root);
	cout<<numberofnode<<endl;
	
	return 0;
}