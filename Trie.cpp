//
// Created by GuoylyL on 2022/9/19 with Trie.
//
#include <iostream>
#include <vector>
#include <string>

struct Node{
    Node():pass(0),end(0){
        for(int i = 0; i < 26; i++){
            nexts[i] = nullptr;
        }
    } //26 字母
    ~Node()
    {
        for(int i = 0; i < 26; i++)
            delete nexts[i];
    }
    // nexts[0] -> nullptr
    // 0  --  a
    // 1  --  b
    // ........
    // 25 --  z
    //nexts[i] == nullptr i方向上的路不存在
    //nexts[i] ！= nullptr i方向上的路存在
    int pass;
    int end;
    Node *nexts[26];
};
class Trie{

public:
    Trie(){
        node_root = new Node();
    }
    void insert(std::string &word){
        Node *node = node_root;
        node->pass++;
        for(int i = 0;i<word.size();i++){
            int id = word[i] -'a';
            if(node->nexts[id] == nullptr)
                node->nexts[id] = new Node();
            node = node->nexts[id];
            node->pass++;
        }
        node->end++;
    }
    int search(std::string &word){
        Node *node = node_root;
        for(int i=0;i<word.size();i++){
            int idex = word[i] - 'a';
            if(node->nexts[idex] == nullptr) return 0;
            node = node->nexts[idex];
        }
        return node->end;
    }
    int prefixNumber(std::string &word){
        Node *node = node_root;
        for(int i=0;i<word.size();i++){
            int idex = word[i] - 'a';
            if(node->nexts[idex] == nullptr) return 0;
            node = node->nexts[idex];
        }
        return node->pass;
    }
    void delete_once(std::string &word){

    }
private:
    Node *node_root;
};

int main(void){
    Trie tr;
    std::string a = "abc";
    std::string b = "abc";
    std::string c = "abc";
    tr.insert(a);
    tr.insert(b);
    tr.insert(c);

    int w = 0;
    w = tr.search(a);
    std::cout << w<<std::endl;
    return 0;
}