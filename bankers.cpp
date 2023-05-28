#include<bits/stdc++.h>
#include<iostream>

using namespace std;
/**
 * 
 * 
 * We have allocation and need and available 
 *
 * GOAL0 - iterate and determine whether safe sequence or not. 
 * 
 * GOAL1 - Include additional requests.
 * 
 * 
 */
int seq[100];
bool isSafe(int n,int m,vector<vector<int>> allocation, vector<vector<int>> need, vector<vector<int>> max_alloc, vector<int> avail)
{
vector<bool> isFinished (n,false);
int flag=0,i=0;

while(i<n){
    int c=0;
   // cout<<isFinished[i]<<endl;
if(isFinished[i]==false)
 {
    for (int  j = 0; j< m; j++)
 {
    if( need[i][j]<=avail[j]){
        c++;
    }
 }
 if(c==m){
    //release allocated resources and isFinished[i]=True;
   
   c=0;
 
     for (int  j = 0; j< m; j++)
 {
    avail[j]+= allocation[i][j];
 }
    isFinished[i]=true;
    seq[flag++]=i;
      i=0;
 }
 else{
    i++;
}
}else{
    i++;
}
//cout<< "here \n";
}
if(flag!=n){
   
    std::cout<< "\n++++++++  Deadlock occurred|Unsafe State  ++++++++\n";
return false;
}else{
   std:: cout <<"\nNo Deadlock\nSafe Sequence  : ";
    for (int i = 0; i < n; i++)
    {
       cout << seq[i]<<" ";

    }cout <<endl;
    
}
return true;

}

void display(int n,int m,vector<vector<int>> allocation, vector<vector<int>> need, vector<vector<int>> max_alloc, vector<int> avail){
    cout << "Available resources : ";
    for(int i=0;i<m;i++){
        cout<< avail[i] <<" ";
    }
    cout<<endl;

    cout<< " maximum allocation : \n";
for(int i=0;i<n;i++){
    for (int j = 0; j < m; j++)
    {
        cout<<max_alloc[i][j]<<" ";

    }cout<<endl;
}cout<<endl;

cout<< "Allocation : \n";
for(int i=0;i<n;i++){
    for (int j = 0; j < m; j++)
    {
       cout<<allocation[i][j]<<" ";

    }cout<<endl;
}
cout<<endl;
cout<< "Need : \n";
for(int i=0;i<n;i++){
    for (int j = 0; j < m; j++)
    {
       cout<<need[i][j]<<" ";

    }cout<<endl;
}
cout<<endl;

}

    void calc_need(int n,int m ,vector<vector<int>> allocation,vector<vector<int>>& need,vector<vector<int>> max_alloc )
{
    for(int i=0;i<n;i++)
    {
    
        for (int j = 0; j < m; j++)
        {
       
             need[i][j] = max_alloc[i][j]-allocation[i][j];

        }
    }
}

int main(){
int n , m ;
cout<<"Enter no. of users and no. of resources \n";
cin>> n>>m;
vector<vector<int>> allocation (n,vector<int> (m,0));
vector<vector<int>> need (n,vector<int> (m,0));
vector<vector<int>> max_alloc (n,vector<int> (m,0));
vector<int>avail(m,0);
//input resources available
cout<< "Enter available no. instances of every resource ";
for(int i=0;i<m;i++){
 cin>> avail[i];
}
cout <<endl;
// input allocation 
cout<< "Enter resource allocation\n";
for(int i=0;i<n;i++){
    for (int j = 0; j < m; j++)
    {
        cin>>allocation[i][j];

    }
}

// input max
cout<< "Enter maximum allocation\n";
for(int i=0;i<n;i++){
    for (int j = 0; j < m; j++)
    {
        cin>>max_alloc[i][j];

    }
}
//calculate need 
calc_need(n,m,allocation,need,max_alloc);
bool res = isSafe(n, m, allocation,  need,  max_alloc,  avail);
 cout<<endl;

while(true){
     cout <<"\nDisplay all matrices ? (Y/N)" <<endl;  
 char opt;
 cin>>opt;
 if(opt=='Y')display( n, m, allocation,  need,  max_alloc, avail);
cout <<"\nMake additional request? (Y/N)" <<endl;  
 char opt1;
 cin>>opt1;
 if(opt1=='Y')
 {


cout<< "Enter the request \n";
int req[m];
cout << "\nuser: ";
int user, lock=0;
cin>>user;
cout <<"Enter req : ";
for(int k =0 ; k<m ; k++){
    cin>> req[k];

}
cout <<endl;

for(int k =0 ; k<m ; k++ ){
   if( allocation[user][k]+req[k]>max_alloc[user][k] || avail[k]-req[k]<0){
    lock=1;
    break;
   }


}
if(!lock){
    for(int k =0 ; k<m ; k++ ){
    allocation[user][k]+=req[k];
    avail[k]-=req[k];
}
    calc_need(n,m,allocation,need,max_alloc);
    cout << "Request Accepted! |/. |/.  Checking for deadlock...\n";
if(!isSafe(n, m, allocation,  need,  max_alloc,  avail)){
break;
}

 }else {
 cout << "\n  ##Request Rejected\n";

 }
 
 }
 else{
    break;
 }
}
    return 0;
}