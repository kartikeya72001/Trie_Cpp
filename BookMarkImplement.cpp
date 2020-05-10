#include <iostream>
#include <unordered_map>
using namespace std;

class node{
public:
    char data;
    bool terminal;
    unordered_map<char,node*> child;

     node(char data)
     {
         this->data = data;
         this->terminal = false;
     }
};

class Trie{
public:
    node* root;
    int count;

    Trie()
    {
        this->root = new node('\0');
        this->count = 0;
    }

    void add(string str)
    {
        node* temp = root;
        for(int i=0;i<str.length();i++)
        {
            char ch = str[i];
            if(temp->child.count(ch))
            {
                temp = temp->child[ch];
            }
            else{
                node *n = new node(ch);
                temp->child[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }
    bool search(string str)
    {
        node* temp = root;
        for(int i=0;i<str.length();i++)
        {
            char ch = str[i];
            if(temp->child.count(ch))
            {
                temp = temp->child[ch];
            }
            else{
                return false;
            }
        }
        return temp->terminal;
    }
};

int main(int argc, char const *argv[]) {
    Trie t;
    int n;
    cin>>n;
    while(n--)
    {
        string str;
        cin>>str;
        t.add(str);
    }
    int q;
    cin>>q;
    while(q--)
    {
        string str;
        cin>>str;
        cout<<t.search(str)<<endl;
    }
    return 0;
}
