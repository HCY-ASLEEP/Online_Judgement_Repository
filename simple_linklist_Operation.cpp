#include <iostream>
using namespace std;
#define error -1
#define ok 0
class node{
    public:
        int data;
        node* next;
        node(){
            next=NULL;
        }
};
class list{
    public:
        node* head;
        int len;
        list();
        ~list();
        node* get_target_node(int position);
        int get_target_data(int position);
        int insert(int position,int candidate_data);
        int del_target(int position);
        void display();
};
list::list(){
    head=new node();
    cin>>len;
    node* pointnow=head;
    for(int i=0;i<len;i++){
        node* openup=new node();
        cin>>openup->data;
        pointnow->next=openup;
        pointnow=pointnow->next;
    }
}
list::~list(){
    node* pointnow;
    while(true){
        node* temp=head->next;
        head->next=head->next->next;
        pointnow=head->next;
        delete temp;
        if(!pointnow){
            break;
        }
    }
    delete head;
}
node* list::get_target_node(int position){
    if(position<0||position>len){
        return NULL;
    }
    if(position==0){
        return head;
    }
    int count=0;
    node* pointnow=head;
    while(true){
        pointnow=pointnow->next;
        ++count;
        if(count==position){
            break;
        }
    }
    return pointnow;
}
int list::get_target_data(int position){
    if(position<1){
        cout<<"error"<<endl;
        return error;
    }
    node* temp=get_target_node(position);
    if(temp){
        return temp->data;
    }
    else{
        cout<<"error"<<endl;
    }
    return error;
}
int list::insert(int position,int candidate_data){
    if(position<1||position>len+1){
        cout<<"error"<<endl;
        return error;
    }
    node* front=get_target_node(position-1);
    node* openup=new node();
    openup->data=candidate_data;
    openup->next=front->next;
    front->next=openup;
    len++;
    return ok;
}
int list::del_target(int position){
    if(position<1||position>len){
        cout<<"error"<<endl;
        return error;
    }
    node* front=get_target_node(position-1);
    node* temp=front->next;
    front->next=front->next->next;
    len--;
    delete temp;
    return ok;
}
void list::display(){
    node* pointnow=head->next;
    while(pointnow){
        cout<<pointnow->data<<' ';
        pointnow=pointnow->next;
    }
    cout<<endl;
}
int main(){
    list example;
    example.display();
    int position;
    int data;
    int flag;
    
    cin>>position>>data;
    flag=example.insert(position,data);
    if(flag==ok){
        example.display();
    }

    cin>>position>>data;
    flag=example.insert(position,data);
    if(flag==ok){
        example.display();
    }

    cin>>position;
    flag=example.del_target(position);
    if(flag==ok){
        example.display();
    }

    cin>>position;
    flag=example.del_target(position);
    if(flag==ok){
        example.display();
    }

    cin>>position;
    flag=example.get_target_data(position);
    if(flag!=error){
        cout<<flag<<endl;
    }

    cin>>position;
    flag=example.get_target_data(position);
    if(flag!=error){
        cout<<flag<<endl;
    }
}