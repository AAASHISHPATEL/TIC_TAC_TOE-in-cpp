#include<iostream>
using namespace std;
string user1="";
    string user2="";
    char flag;
 char mat[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
 int row,col;
 char token;

void print(){ 
   cout<<endl;
   cout<< " "<<mat[0][0] <<" |"<<" "<<mat[0][1] <<"  |"<<" "<<mat[0][2]<<endl;
   cout<<"-------------"<<endl;
   cout<< " "<<mat[1][0] <<" |"<<" "<<mat[1][1] <<"  |"<<" "<<mat[1][2]<<endl; 
   cout<<"-------------"<<endl;
   cout<< " "<<mat[2][0] <<" |"<<" "<<mat[2][1] <<"  |"<<" "<<mat[2][2]<<endl;
  cout<<endl;
}

void move(){
   char dig;
   if(token=='X'){
      cout<<user1<<" enter position for X: ";
      cin>>dig;
   }
   else{
      cout<<user2<<" enter position for O: ";
      cin>>dig;
   }

   if(dig=='1'){
      row=0;
      col=0;
      
   }
   else if(dig=='2'){
      row=0;
      col=1;
   }
    else if(dig=='3'){
      row=0;
      col=2;
   }
    else if(dig=='4'){
      row=1;
      col=0;
   }
    else if(dig=='5'){
      row=1;
      col=1;
   }
    else if(dig=='6'){
      row=1;
      col=2;
   }
    else if(dig=='7'){
      row=2;
      col=0;
   }
    else if(dig=='8'){
      row=2;
      col=1;
   }
    else if(dig=='9'){
      row=2;
      col=2;
   }
   else{
      cout<<"!!!!!!!!!!Invalid position!!!!!!!!!!"<<endl;
      row=-1;
      col=-1;
   }

   if(row!=-1 && col!=-1){
      if(token =='X' && mat[row][col]!='X' && mat[row][col]!='O'){
        mat[row][col]='X';
        token ='O';
     }
   else if(token =='O' && mat[row][col]!='X' && mat[row][col]!='O'){
      mat[row][col]='O';
      token ='X';
   }
   else{
      cout<<"!!!!!!!!!!Invalid position!!!!!!!!!!"<<endl;
   }
   }
}

bool condition(){
   for(int i=0;i<3;i++){
      if(mat[i][0]=='X' && mat[i][1]=='X' && mat[i][2]=='X' || mat[0][i]=='X' && mat[1][i]=='X' && mat[2][i]=='X'){
   flag='X';
   return true;
  }
   }

   for(int i=0;i<3;i++){
      if(mat[i][0]=='O' && mat[i][1]=='O' && mat[i][2]=='O' || mat[0][i]=='O' && mat[1][i]=='O' && mat[2][i]=='O'){
   flag='O';
   return true;
  }
   }

   if(mat[0][0]=='X' && mat[1][1]=='X' && mat[2][2]=='X'){
      flag='X';
   return true;
   }

   if(mat[0][0]=='O' && mat[1][1]=='O' && mat[2][2]=='O'){
      flag='O';
   return true;
   }

   if(mat[0][2]=='X' && mat[1][1]=='X' && mat[2][0]=='X'){
      flag='O';
   return true;
   }

   if(mat[0][2]=='O' && mat[1][1]=='O' && mat[2][0]=='O'){
      flag='O';
   return true;
   }

   for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
         if(mat[i][j]!='X' && mat[i][j]!='O'){
            flag='d';
            return false;
         }
      }
   } 
  return true;
}

int main(){

   cout<<"Enter user1 name: ";
   cin>>user1;
   cout<<"Enter user2 name: ";
   cin>>user2;
   cout<<user1<<" your token is X::"<<endl;
   cout<<user2<<" your token is O::"<<endl;
   cout<<"What will be first move X or O: ";
   cin>>token;

   while(!condition()){
      print();
      move();
   }
   if(flag=='X'){
      print();
      cout<<user1<<"!!!you won!!!"<<endl;
   }
   else if(flag=='O'){
      print();
      cout<<user2<<"!!!you won!!!"<<endl;
   }
   else{
      print();
      cout<<"!!!!!!!Game Draw!!!!!!!!!"<<endl;
   }
   return 0;
}