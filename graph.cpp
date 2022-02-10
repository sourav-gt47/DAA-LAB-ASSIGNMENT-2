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

cout<<"\nGRAPH IN MATRIX FORMAT::\n"<<endl;
cout<<"   ";
for(int k=0;k<n;k++)
cout<<char(65 + k)<<"  ";
cout<<endl;
for(int i=0;i<n;i++){
cout<<char(65 + i)<<"  ";
for(int j=0;j<n;j++){

cout<<graph[i][j]<<"  ";

}

cout<<"\n";

}
//display adjacent of matrix graph[][]
cout<<endl;
for(int i=0;i<n;i++){
    cout<<"Adjacency of vertex "<<char(65 + i)<<"--> [";

for(int j=0;j<n;j++)
{    
     if(graph[i][j]==1) {
     cout<<char(65 + j)<<" ";

     }

}
cout<<"]"<<endl;

}

fin.close(); //to close the file

return 0;
}