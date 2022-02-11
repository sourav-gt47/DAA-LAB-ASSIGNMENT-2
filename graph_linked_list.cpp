#include<bits/stdc++.h>
using namespace std;
//implementation of linked list
 class node{

 public:
 int data;
 node* next;
//constructor
   node(int n){
  data=n;
  next=NULL;
   }

 };

class linked_list{

public:
node* head;

linked_list()
{
    head=NULL;
}

void insert(int val){

if(head==NULL){

    head= new node(val);
    return;


}
else{

node* temp=head;

while(temp->next != NULL)
 temp=temp->next;

temp->next = new node(val);

}


}

void print(){

if(head==NULL)
{
    return;
}

node* temp=head;
while(temp!=NULL){

if(temp->next==NULL)
  cout<<char(temp->data + 65)<<"]";
else
cout<<char(temp->data + 65)<<"-->";
temp= temp->next;

}


}


};


int main(){

fstream fin;
fin.open("Ex.txt",ios::in); //read file mode

if(!fin){
    cout<<"error to open file!!"<<endl;
    exit(1);
}
int graph[10][10];
int n;
fin>>n; //vertices
for(int i=0;i<n;i++)
{
    for (int j = 0; j < n; j++)
    {
        fin>>graph[i][j]; //read values 
    }
    
}


linked_list adj[n]; //creating array of linked list type
int count=0;
for(int i=0;i<n;i++)
{
  for(int j=0;j<n;j++){
    
   if(graph[i][j] == 1)

   {   ++count;
       adj[i].insert(j);
   }

  }


}
cout<<"EDGES::"<<(count/2)<<endl;
cout<<"DEGREE:: "<<count<<endl;
int v;
cout<<"Enter the vertex no. you want to find the adjacency::";
cin>>v;
cout<<"vertex:: "<<char(64 + v)<<" [";
adj[v-1].print();
cout<<endl<<"\nGRAPH IN ADJACENT LIST FORMAT::\n";

for(int i=0;i<n;i++){
  cout<<"Adjacency of vertex::"<<char(i + 65)<<" [";
  adj[i].print();
  cout<<endl;

}

fin.close();
    return 0;
}