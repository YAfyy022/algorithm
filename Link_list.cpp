#include <iostream>
#include <unordered_map> //hash表
struct  Node{
    Node():value(0),next(nullptr){}
    Node(int data):value(data),next(nullptr){}
    Node(int data,Node * next):value(data),next(next){}
    int value;
    Node *next;
};
Node* create_linklist(int len,int value){
    int size = (int)((len + 1));
    if(size == 0) return nullptr;
    size--;
    Node *head = new Node((int)(1));
    Node *pre = head;
    while(size != 0){
        Node *cur = new Node((int)(rand()*(value + 1)));
        pre->next = cur;
        pre = cur;
        size--;
    }
    return head;
}
Node* reverseLinkedList(Node* head){
    Node *pre = nullptr;
    Node *next = nullptr;
    while(head){
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;

}
void Bianli_list(Node * head){
    if(head == nullptr) return;
    Node *pre = head;
    while(pre){
        std::cout<< pre->value <<",";
        pre = pre->next;
    }
    std::cout<<"-\n";
}
//int main(void){
//    auto list_1 = create_linklist(10,4);
//    Bianli_list(list_1);
//    auto list_2 = reverseLinkedList(list_1);
//    Bianli_list(list_2);
//    return 0;
//}
