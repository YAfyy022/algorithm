//
// Created by GuoylyL on 2022/9/24.
//
//二叉树
//先序 先头节点，再左子树，然后右子树
//中序 先左子树，再头节点，然后右子树
//后序 先左子树，再右子树，然后头节点
//


/*
void f(Node head){
    if(head == nullptr) return;                      1
                                                    /  \
    //1  打印放在这里是先序                           2    3
    f(head.left);                                 / \  / \
    //2 中序                                     4   5 6   7
    f(head.right)
    //3 后序列
}
 递归
 三次返回 每个节点都会到达三次
 1,2,4,4,4,2,5,5,5,2,1,3,6,6,6,3,7,7,7,3,1
任何递归函数都可以改为非递归函数
自己设计压栈来实现
    stack [                     ,1] cout 1
    0，先压入头节点
    1.弹出就打印
    2.如果有右孩子先压右孩子，再压左孩子
    stack [                    2,3] cout 2
    stack [                  4,5,3]
    coding:
    stack 先放入头
    栈不为空就弹出一个节点，打印，再压右，再左；

    整棵树是可以被左边界完全分解掉的

*/
#include <iostream>
#include <stack>
struct Node{
    int val;
    Node *right;
    Node *left;
    Node(int x):val(x){}
};
void view_pre(Node *head){
    if (head == nullptr) return;
    std::cout << head->val << " ";
    view_pre(head->left);
    view_pre(head->right);
}
//void pre(Node *head) {
//    if (head != nullptr) {
//        std::stack<Node*> stack;
//        stack.push(head);
//        while (!stack.empty()) {
//            head = stack.top();
//            std::cout<<head->val<< " ";
//            if (head->right != nullptr) {
//                stack.push(head->right);
//            }
//            if (head->left != nullptr) {
//                stack.push(head->left);
//            }
//        }
//    }
//
//}
//设置一个tag 发现一个层开始或结束 来层序遍历  TreeMAXWidth
//使用map容器
//
//不使用map
//


//序列化和反序列化

//1.可以使用先序或者中序或者后序或者按层遍历，来实现二叉树的序列化 同样去做反序列化
//[1,1,null,1,null,null,null] 才能遍历出相同数字的不同结构的各种顺序遍历

int main(){
    Node *head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);

    return 0;
}

