#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;
 int akeyword(char strin[]){
 char keyword[15][10]={"int","float","string","if","else","case","long"};
 int i=0,flag=0;
 for (i=0;i<32;++i){
    if(strcmp(keyword[i],strin)==0){
        flag=1;
        break;
    }
 }
 return flag;
 }
int main()
{
 char ch ,strin[10] , operators[10] ="+-*/%^=";
 ifstream fin("salah.txt");
    int i,j=0;

    if(!fin.is_open()){
        cout<<"error while opening the file\n";
        exit(0);
      }
   while(!fin.eof()){
           ch = fin.get();
    for (i=0;i<6;i++){
        if (ch == operators[i])
            cout<<ch<<"  The word is Operator \n ";
    }
    if (isalnum(ch)){
        strin[j++]=ch;}

    else if ((ch == ' '|| ch == '\n') && (j != 0))
    {
         strin[j] = '\0';
                   j = 0;
        if (akeyword(strin)==1)
            cout<<strin<<" This is keyword  \n";
        else
            cout<<strin<<" This is indentifier  \n";
    }
  }
    fin.close();
    return 0;
}
