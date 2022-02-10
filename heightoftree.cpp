#include<bits/stdc++.h>
using namespace std;
#include"treenode.h"
treenode<int>* takinginputlevelwise(){
	int rootdata;
	cout<<"enter value of root"<<endl;
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
			cout<<"enter "<< i <<" th value of child of "<<front->data<<endl;
			cin>>childdata;
			treenode<int>* child=new treenode<int>(childdata);
			front->children.push_back(child);
			pendingnodes.push(child);
		}
	}
	return root;
}
int height(treenode<int>* root) {
	if(root==NULL){
		return 0;
	}
	int maxHeight = 0;
		for(int i=0;i<root->children.size();i++) {
			int max = height(root->children[i]);
			if(maxHeight< max ) {
				maxHeight = max;
			}
		}
		return maxHeight + 1;
/*
   
    int h =1;
    
    if(root->children.size()==0)
        return h;	
    
   int arr[root->children.size()];
    for(int i=0;i<root->children.size();i++)
    {
        arr[i]=height(root->children[i]);
        
    }
    sort(arr,arr+root->children.size(),greater<int>());
    h+=arr[0];
   
    return h;*/ 
}
void printtree(treenode<int>* root){
	if(root==NULL){
		return ;
	}
	queue<treenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0){
		treenode<int>* front=pendingnodes.front();
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
int main(){
	treenode<int>*root=takinginputlevelwise();
	printtree(root);
	int heightoftree=height(root);
	cout<<heightoftree<<endl;
	return 0;
}