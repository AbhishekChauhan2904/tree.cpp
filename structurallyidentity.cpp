#include<bits/stdc++.h>
using namespace std;
#include"treenode1.h"
treenode1<int>* takeinputlevelwise1(){
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
bool sametreeornot(treenode1<int>* root1,treenode1<int>* root2){
	if(root1->data!=root2->data){
		return false;
	}
	if(root1->children.size()!=root2->children.size()){
		return false;
	}
bool ans=true;
for(int i=0;i<root1->children.size();i++){
	bool smallans=sametreeornot(root1->children[i],root2->children[i]);
	if(smallans==false){
		ans=smallans;
	}
}
return ans;
}
int main(){
treenode1<int>* root1=takeinputlevelwise1();
treenode1<int>* root2=takeinputlevelwise1();
	bool x1=sametreeornot(root1,root2);
 if(x1==0){
 	cout<<"false"<<endl;
}
else{
	cout<<"true"<<endl;
}
	return 0;
}