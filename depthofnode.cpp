#include<bits/stdc++.h>
using namespace std;
#include"treenode.h"
treenode<int>* takeinputlevelwise(){
	int rootdata;
	cout<<"enter the value of root"<<endl;
	cin>>rootdata;
	treenode<int>*root=new treenode<int>(rootdata);
	queue<treenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0){
		treenode<int>* front=pendingnodes.front();
		pendingnodes.pop();
		cout<<"enter value of children "<<front->data<<endl;
		int numchild;
		cin>>numchild;
		for(int i=0;i<numchild;i++){
			int childdata;
			cout<<"enter "<<i<< " th value of child of "<< front->data<<endl;
             cin>>childdata;
             treenode<int>* child=new treenode<int>(childdata);
             front->children.push_back(child);
             pendingnodes.push(child);
		}

	}
	return root;
}
void printnode(treenode<int>* root){
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
void printlevel(treenode<int>*root,int k){
	if(root==NULL){
		return;
	}
   if(k==0){
   	cout<<root->data<<endl;
   	return;
 }
for(int i=0;i<root->children.size();i++){
	printlevel(root->children[i],k-1);
}
}
int numnodes(treenode<int>*root){
	if(root==NULL){
		return 0;
	}
	int ans=1;
	for(int i=0;i<root->children.size();i++){
		ans+=numnodes(root->children[i]);
	}
	return ans;
}
int main(){
	treenode<int>* root=takeinputlevelwise();
	printnode(root);
	int k;
	cin>>k;
	cout<<"num:"<<numnodes(root)<<endl;
	cout<<"level:"<<endl;
	printlevel(root,2);
return 0;
}