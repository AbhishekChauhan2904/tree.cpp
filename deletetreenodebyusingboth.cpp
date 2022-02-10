#include<bits/stdc++.h>
using namespace std;
#include"treenode.h"
treenode<int>* takeinputlevelwise(){
	int rootdata;
	cout<<"enter data of root"<<endl;
	cin>>rootdata;
	treenode<int>* root=new treenode<int>(rootdata);
	queue<treenode<int>*> pendingnode;
	pendingnode.push(root);
	while(pendingnode.size()!=0){
		treenode<int>* front=pendingnode.front();
		pendingnode.pop();
		cout<<"enter value of children "<<front->data<<endl;
		int numchild;
		cin>>numchild;
		for(int i=0;i<numchild;i++){
			cout<<"enter "<<i<<"th value of child of "<<front->data<<endl;
			int childdata;
			cin>>childdata;
			treenode<int>* child=new treenode<int>(childdata);
			front->children.push_back(child);
			pendingnode.push(child);
		}
	}
	return root;
}
void printtree(treenode<int>* root){
	if(root==NULL){
		return ;
	}
	queue<treenode<int>*> pendingnode;
	pendingnode.push(root);
	while(pendingnode.size()!=0){
		treenode<int>* front=pendingnode.front();
		pendingnode.pop();
		cout<<front->data<<":";
		for(int i=0;i<front->children.size();i++){
			pendingnode.push(front->children[i]);
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
/*void deletetree(treenode<int>*root){
	for(int i=0;i<root->children.size();i++){
		deletetree(root->children[i]);
	}
	delete root;
}*/
int main(){
	treenode<int>* root=takeinputlevelwise();
	printtree(root);
	//deletetree(root);
	delete root;
	return 0;
}