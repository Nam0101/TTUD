#include <bits/stdc++.h>
using namespace std;

char* buffer(int n,int n2,char* strNum){
    char* str=new char[30];
    for(int i=0;i<(n-n2);i++){
        str[i]='0';
    }
    strcat(str,strNum);
    return str;
}
char* addTwoInt(int length,char* str1,char* str2){
    char* strResult=new char[length+1];
    cout<<length<<" "<<str1<<" "<<str2<<endl;
    strResult[0]='0';
    for(int i=length;i>=0;i--){
        int num1=str1[i]-48;
        int num2=str2[i]-48;
        char result=num1+num2;
        cout<<"sss: "<<result<<endl;
        if(result>=10){
            result=result-10;
            str2[i-1]+=1;
        }
        strResult[i]=result+'0';
    }
    return strResult;
}

int main(){
    char *strNum1=new char[30];
    char *strNum2=new char[30];
    cin >> strNum1 >> strNum2;
    int length1=strlen(strNum1);
    int length2=strlen(strNum2);
    if(length1>length2){
        strNum2=buffer(length1,length2,strNum2);
        length2=length1;
    }
    else{
        strNum1=buffer(length2,length1,strNum1);
        length1=length2;
    }
    char *result=addTwoInt(length1,strNum1,strNum2);
    cout<<result<<endl;
    
   
}