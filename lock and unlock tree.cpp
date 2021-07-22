/*
https://www.dailycodingproblem.com/blog/lockable-binary-trees/
https://www.geeksforgeeks.org/locking-and-unlocking-of-resources-in-the-form-of-n-ary-tree/

*/

#include<bits/stdc++.h>
using namespace std;
#define w(t) int t;cin>>t;while(t--)
#define pb   push_back
#define mk   make_pair
#define u_s  unordered_set
#define endl "\n"
#define prDouble(x) cout<<fixed<<setprecision(12)<<x
#define ll long long
#define ipair pair<int,int>
#define all(x) (x).begin(), (x).end()
const int32_t Mod=1e9+7;

const int mod=1e9+7;

/*
  ctrl+alt+p =preference 
  alt+shift to change laungauge
 */
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.first;
}

void open_file(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
}
void fast_io(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


class Node{
    
    public:
      bool isLock;
      int descendants_count;
      Node*parent;
      vector<Node*>	child;
      
	  Node(){
	     isLock=false;
	     descendants_count=0;
	     parent=NULL;
	  }
	  
	  Node(Node*parent){
		isLock=false;
	    descendants_count=0;
	    this->parent=parent;
	  }
};


bool isLock(Node*root){
     
     if( root==NULL )return false;
     
     return root->isLock;
}

void Lock(Node*root){
     
     if(root==NULL) return;
     if( root->descendants_count>0 or root->isLock==true)return;
     
     Node*cur=root;
     bool flag=false;
     
     while( cur!=NULL ){
	     
	     if( cur->isLock==true ){
			 flag=true;
			 break;
		 }
		 cur=cur->parent;
	 }
	 
	 if( flag )return;
	 
	 root->isLock=true;
	 root=root->parent;
	 
	 while( root!=NULL ){
	    root->descendants_count+=1;
	    root=root->parent;
	 }
          
}

void unLock(Node*root){
     
     if(root==NULL  or root->isLock==false)return;
     
     root->isLock=false;
     
     root=root->parent;
     
     while(root!=NULL){
		 root->descendants_count--;
		 root=root->parent;
	 }
}

void create(){
   
   //root
   Node* root= new Node();
   
   // child 
   Node* t1=new Node(root);
   Node* t2=new Node(root);
   Node* t3=new Node(root);
   
   root->child.push_back(t1);
   root->child.push_back(t2);
   root->child.push_back(t3);
   
   
   
   
   Node* t4=new Node(t1);
   Node* t5=new Node(t1);
   
   t1->child.push_back(t4);
   t1->child.push_back(t5);
   
   Node* t6=new Node(t4);
   Node* t7=new Node(t4);
   
   t4->child.push_back(t6);
   t4->child.push_back(t7);
   
   
   
   
   // Testing
   
   
   
   cout<<isLock(root)<<endl;
   //Lock(root);
   Lock(t7);
   Lock(t5);
   Lock(t1);
   unLock(t5);
   unLock(t7);
   Lock(t1);
   
   cout<<isLock(t1)<<endl;
   
   
   
}






int main(){ 

  open_file();
  fast_io();
  
 
  
  create();
  
  return 0;
}

 
