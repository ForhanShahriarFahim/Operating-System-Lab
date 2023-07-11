#include<bits/stdc++.h>
using namespace std;
int i,j,fault=0;
void enhanced(vector<int>&pages,int frame,vector<int>&referenc)
{
    map<int,string>mp;
    map<int,int>pos;
    set<int>tmp;
    for(i=0;i<pages.size();i++){
        int val= pages[i];
        pos[val]=i;
        if(tmp.size()<frame){
            if(tmp.find(val)==tmp.end()){
                fault++;
                tmp.insert(val);
                bool flag=0;
                for(auto x:referenc){
                    if(x==i){
                        falg=1;
                        mp[val]="11";
                        break;
                    }
                }
                if(!flag){
                    mp[val]="10";
                }
            }
            else{
                bool flag=0;
                for(auto x:referenc){
                    if(x==i){
                        flag=1;
                        mp[val]="11";
                        break;
                    }
                }
                if(!flag){
                    mp[val]="10";
                }
            }
        }else{
            if(tmp.find(val)==tmp.end()){
                fault++;
                int cnt=0;
                for(auto str:mp){
                    string s=str.second;
                    if(s[0]=='0') {

                    }
                }




                bool flag=0;
                for(auto x:referenc){
                    if(x==i){
                        flag=1;
                        mp[val]="11";
                        break;
                    }
                }
                if(!flag){
                    mp[val]="10";
                }
            }
            else{
                bool flag=0;
                for(auto x:referenc){
                    if(x==i){
                        flag=1;
                        mp[val]="11";
                        break;
                    }
                }
                if(!flag){
                    mp[val]="10";
                }
            }
        }
    }
}
int main()
{
   int n;
   freopen("enhance.txt","r",stdin);
   cin>>n>>m;
   vector<int>pages(n),referenc(m);
   for(i=0;i<n;i++)
        cin>>pages[i];
   for(i=0;i<n;i++)
        cin>>referenc[i];
   int frame;
   cin>>frame;
   enhanced(pages,frame,referenc);
}
