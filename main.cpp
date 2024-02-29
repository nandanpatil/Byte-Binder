#include <bits/stdc++.h>
using namespace std;

class Node{
    char val;
    unsigned long long int freq;
    Node *left;
    Node *right;
    
    Node(){
        val='-';
        freq=-1;
        left=NULL;
        right=NULL;
    }

    Node(char c,unsigned long long int f){
        val=c;
        freq=f;
        left=NULL;
        right=NULL;
    }

    Node(unsigned long long int f){
        val='-';
        freq=f;
        left=NULL;
        right=NULL;
    }

    friend class Huffman;
    friend class pqComp;
};

class pqComp{
    public:
    bool operator()(Node const *a,Node const *b){
        return a->freq > b->freq;
    }
};



class Huffman{
    string fileName;
    unordered_map<char,unsigned long long int>frequency;
    Node *tree;
    public:
    Huffman(string name){
        fileName=name;
        tree=NULL;
    }

    void countFrequency(){
        fstream file;
        file.open(fileName,ios::in);
        if(!file.is_open()){
            cerr<<"Error opening file \n";
            return;
        }
        string line;
        while(getline(file,line)){
            for(unsigned long long int i=0;i<line.length();i++){
                frequency[line[i]]++;
            }
        }
    }

    void createHuffmanTree(){
        priority_queue<Node*,vector<Node*>,pqComp>pq;
        for(auto it:frequency){
            Node *node = new Node(it.first,it.second);
            pq.push(node);
        }

        while(pq.size()>=2){
            Node *node1 = pq.top();
            pq.pop();
            Node *node2 =pq.top();
            pq.pop();

            unsigned long long int newTotalFreq = node1->freq+node2->freq;
            Node *parentNode = new Node(newTotalFreq);
            parentNode->left = node1;
            parentNode->right = node2;
            pq.push(parentNode);
        }

        tree  = pq.top();
        levelOrder(tree);        
    }

    void levelOrder(Node *root){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            unsigned long long int size = q.size();
            for(unsigned long long int i=0;i<size;i++){
                Node *src = q.front();
                q.pop();
                cout<<"["<<src->val<<","<<src->freq<<"]"<<" ";
                if(src->left)q.push(src->left);
                if(src->right)q.push(src->right);
            }
             cout<<endl;
        }
       
    }

};


int main()
{
    Huffman h("test.txt");
    h.countFrequency();
    h.createHuffmanTree();

}