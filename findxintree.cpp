#include<bits/stdc++.h>
using namespace std;
#include"treenode1.h"
treenode1<int>* takeinputlevelwise(){
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
bool findingxinttree(treenode1<int>* root,int x){
if(root->data==x){
	return true;
}	
bool ans=false;
for(int i=0;i<root->children.size();i++){
	bool smallans=findingxinttree(root->children[i],x);
	if(smallans!=ans&&smallans==true){
		ans=smallans;
	}
}
return ans;
}
int main(){
		int x;
	cin>>x;
	treenode1<int>*root=takeinputlevelwise();

 bool x1=findingxinttree(root,x);
 if(x1==0){
 	cout<<"false"<<endl;
}
else{
	cout<<"true"<<endl;
}
 	return 0;
}