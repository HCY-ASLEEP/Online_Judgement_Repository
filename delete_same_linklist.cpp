#include <iostream>
using namespace std;
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
    void remove_same();
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
    delete head;
}
void list::display() {
    node* pointnow = head->next;
    cout << len << ": ";
    while (pointnow) {
        cout << pointnow->data;
        if (pointnow->next) {
            cout << ' ';
        }
        pointnow = pointnow->next;
    }
}
void list::remove_same() {
    node* major = head->next;
    while (major) {
        node* front = major;
        node* pointnow = major->next;
        //"major" is the only one to save;
        //Pointnow is used to point the nums behind major;
        //When pointnow is NULL, it means that there is no nums behind major;
        while (pointnow) {
            if (pointnow->data == major->data) {
                front->next = front->next->next;
                node* temp = pointnow;
                pointnow = pointnow->next;
                len--;
                delete temp;
            } 
            else {
                //Attention, there must be a "else"!
                front = front->next;
                pointnow = pointnow->next;
            }
        }
        major = major->next;
    }
}
int main() {
    int times;
    cin >> times;
    while (times--) {
        list example;
        example.remove_same();
        example.display();
        if (times) {
            cout << endl;
        }
    }
}