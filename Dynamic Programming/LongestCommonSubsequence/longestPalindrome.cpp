#include<iostream>
using namespace std;

string reversedString(string s1){
    string s2="";
    for(int i=s1.length()-1;i>=0;i--){
        s2+=s1[i];
    }
    return s2;
}

string getLCSstring(string s1,string s2){
    int n=s1.length();
    string t[n+1][n+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            //if(i==0 || j==0){
                t[i][j]="";
                break;
            //}
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // if(i==0 || j==0){
            //     t[i][j]="";
            //     break;
            // }
            if(s1[i-1]==s2[j-1]){
                t[i][j]=t[i-1][j-1]+s1[i-1];
            }
            else{
                if(t[i][j-1].length()>t[i-1][j].length()){
                    t[i][j]=t[i][j-1];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
    } 
    return t[n][n];
}

int main(){
    string s1;
    cin>>s1;
    cout<<s1<<" "<<reversedString(s1);
    cout<<endl;
    cout<<getLCSstring(s1,reversedString(s1));

}