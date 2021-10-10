#include <iostream>
#include <string>
using namespace std;
void get_next(string sp,int* next){
    int i=0;
    int j=-1;
    next[0]=-1;
    while(i<sp.length()){
        if(j==-1||sp[i]==sp[j]){
            i++;
            j++;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
}
void get_next_value(string sp,int* next){
    int i=0;
    int j=-1;
    next[0]=-1;
    while(i<sp.length()){
        if(j==-1||sp[i]==sp[j]){
            i++;
            j++;
            if(sp[i]!=sp[j]){
                next[i]=j;
            }
            else{
                next[i]=next[j];
            }
        }
        else{
            j=next[j];
        }
    }
}
int kmp_search(string s,string p,int* next){
    int i=0;
    int j=0;
    int slen=s.length();
    int plen=p.length();
    while(i<slen&&j<plen){
        if(j==-1||s[i]==p[j]){
            i++;
            j++;
        }
        else{
            j=next[j];
        }
    }
    if(j==plen){
        return i-j;
    }
    else{
        return -1;
    }
}
int main(){
    int groups;
    cin>>groups;
    while(groups--){
        string s;
        string p;
        cin>>s;
        cin>>p;
        int plen=p.length();
        int* next=new int[plen];
        get_next(p,next);
        int position=kmp_search(s,p,next);
        for(int i=0;i<plen;i++){
            cout<<next[i]<<' ';
        }
        cout<<endl<<position+1<<endl;
        delete[]next;
    }
}