#include <iostream>
using namespace std;
#define error -1
#define ok 0
//If it requires to find the node by using countings, it is a good way to write a function to find nodes by positions;
//In this case, we need to find six nodes in a linklist, front_1, target_1, back_1, front_2, target_2, and back_2;
//And we should also clearfy that the situation is different when target_1 is next to target_2 or not;
class node {
   public:
    int data;
    node* next;
    node() {
        next = NULL;
    }
};
class list {
    node* head;
    int len;
   public:
    list();
    ~list();
    node* get_target_node(int position);
    int swap(int position_1, int position_2);
    void display();
};
list::list() {
    head = new node();
    cin >> len;
    node* pointnow = head;
    for (int i = 0; i < len; i++) {
        node* openup = new node();
        cin >> openup->data;
        pointnow->next = openup;
        pointnow = pointnow->next;
    }
}
list::~list() {
    while (head->next) {
        node* temp = head->next;
        head->next = head->next->next;
        delete temp;
    }
    delete head;
}
node* list::get_target_node(int position) {
    if (position < 0 || position > len) {
        return NULL;
    }
    if (position == 0) {
        return head;
    }
    node* pointnow = head;
    for (int i = 0; i < position; i++) {
        pointnow = pointnow->next;
    }
    return pointnow;
}
int list::swap(int position_1, int position_2) {
    if(position_1<1||position_2>len){
        cout<<"error"<<endl;
        return error;
    }
    node* target_1_front = get_target_node(position_1-1);
    node* target_2_front = get_target_node(position_2-1);
    //When we find fronts of two targets,we can also find two targets, and also find two behinds of targets;
    node* target_1 = target_1_front->next;
    node* target_2 = target_2_front->next;
    if (target_1 && target_2) {
        node* target_1_back = target_1->next;
        node* target_2_back = target_2->next;
        if (target_1_back == target_2) {
            //If target_1 is next to target_2;
            target_1_front->next = target_2;
            target_2->next = target_1;
            target_1->next = target_2_back;
        } 
        else {
            target_1_front->next = target_2;
            target_2->next = target_1_back;
            target_2_front->next = target_1;
            target_1->next = target_2_back;
        }
        display();
        return ok;
    }
    else{
        cout<<"error"<<endl;
    }
    return error;
}
void list::display(){
    node* pointnow=head->next;
    while(pointnow){
        cout<<pointnow->data<<' ';
        pointnow=pointnow->next;
    }
    cout<<endl;
}
int main() {
    list example;
    example.display();
    int position_1;
    int position_2;
    int flag;

    cin>>position_1>>position_2;
    example.swap(position_1,position_2);
    
    cin>>position_1>>position_2;
    example.swap(position_1,position_2);
}