#include<bits/stdc++.h>
using namespace std;

int main()
{
  fstream fin; //create an object f of a class fstream 
  fin.open("Ex.txt", ios::in); //read mode
  
    if(!fin){

     cout<<"Error to open the file!!"<<endl;
     exit(1);
 }

int n;
fin>>n;//to read no. of vertices of file
int graph[10][10];
for(int i=0; i<n; i++ ){

    for(int j=0 ;j<n; j++){
    fin>>graph[i][j]; //to read a graph from file

    }
}

for(int i=0; i<n; i++ ){

    for(int j=0 ;j<n; j++){
    cout<<graph[i][j]<<" "; //to print a graph from file

    }
    cout<<endl;
}


vector<vector<int> >adj(n);

for(int i=0;i<n;i++){
 for(int j=0;j<n;j++){
  if(graph[i][j] == 1)
    adj[i].push_back(j);

}

}
int count=0;
//to calculate no. of edges
for(int i=0 ;i<n;i++)
{
  for(int j=0;j<n;j++)
{
   if(graph[i][j] == 1)
 
     ++count;
 
}


}

cout<<"\nNo. of edges::"<<(count/2)<<endl;
cout<<"Total degree of graph::"<<count<<endl; //sum(deg)= 2*(edges)

int v;
cout<<"Enter the vertex no. you want to display adjacency::";
cin>>v;
cout<<"vertex::"<<char(v + 64)<<" ";

for(int i=0;i<n;i++){

if(graph[v-1][i]==1)
cout<<"-->"<<char(i + 65);

}


//display graph
cout<<"\n\nGRAPH IN ADJACENT LIST FORMAT"<<endl;

for(int i=0;i<adj.size();i++){

cout<<char(i + 65)<<" ";
for(int j=0;j<adj[i].size();j++){
if(j==adj.size()-1){
cout<<"-->"<<char(adj[i][j] + 65)<<endl;
break;}
else
cout<<"-->"<<char(adj[i][j] + 65);

}

cout<<endl;

}



fin.close(); //to close the file

return 0;
}