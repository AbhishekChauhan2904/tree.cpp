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
treenode1<int>* nextlarger(treenode1<int>* root,int x){
	if(root==NULL){
		return NULL;
	}
treenode1<int>* ans=NULL;
	if(root->data>x){
		ans=root;
	}
	for(int i=0;i<root->children.size();i++){
		treenode1<int>* temp=nextlarger(root->children[i],x);
		if(temp==NULL){
			continue;
		}
		else{
           if(ans==NULL){
            ans=temp;
           }
           else if(temp->data>x&&temp->data<ans->data){
          ans=temp;
           }
		}
	}
	return ans;
}
int main(){
	int x;
	cin>>x;
	treenode1<int>* root=takeinputlevelwise();
     treenode1<int>* ans=nextlarger(root,x);
     cout<<ans->data<<endl;
	return 0;
}