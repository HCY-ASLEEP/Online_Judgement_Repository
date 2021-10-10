#include <iostream>
using namespace std;
//Two test groups must both growing increasingly;
class node {
   public:
    int data;
    node* next;
    node() {
        next = NULL;
    }
};
class list {
   public:
    node* head;
    int len;
    list();
    ~list();
    void display();
};
list::list() {
    cin >> len;
    head = new node();
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
    delete head->next;
}
void list::display() {
    node* pointnow = head->next;
    while (pointnow) {
        cout << pointnow->data << ' ';
        pointnow = pointnow->next;
    }
    cout << endl;
}
void combine(list& list_1, list& list_2) {
    node* front_1 = list_1.head;
    node* pointnow_1 = list_1.head->next;
    node* front_2 = list_2.head;
    node* pointnow_2 = list_2.head->next;
    while (pointnow_1) {
        //First,find the place in group_2 to be inserted the number in group_1;
        //Attention, pointnow_2 can be NULL;
        //When pointnow_2 is NULL, pointnow_1 must be inserted the tail;
        //The place we looking for is between front_2 and pointnow_2;
        while (front_2) {
            if (pointnow_2 == NULL || pointnow_2->data > pointnow_1->data) {
                break;
                //Once found, break right now
            } 
            else {
                //There must be a "else"!
                front_2 = front_2->next;
                pointnow_2 = pointnow_2->next;
            }
        }
        node* temp = pointnow_1;
        front_1->next = front_1->next->next;
        pointnow_1 = pointnow_1->next;
        //Cut down the link of temp in group_1;
        temp->next = pointnow_2;
        front_2->next = temp;
        //Insert temp between front_2 and pointnow_2;
        front_2 = front_2->next;
        //Front_2 move to the place where temp should be;
    }
}
int main() {
    list list_1;
    list list_2;
    combine(list_1, list_2);
    list_2.display();
}