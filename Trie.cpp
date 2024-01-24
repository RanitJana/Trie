#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    int startWith, endWith;

    bool isCharPresent(char ch)
    {
        return links[ch - 'a'];
    }

    Node *createNode()
    {
        return new Node();
    }

    Node *getNext(char ch)
    {
        return links[ch - 'a'];
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->isCharPresent(word[i]))
            {
                temp->links[word[i] - 'a'] = temp->createNode();
            }
            temp = temp->getNext(word[i]);
            temp->startWith++;
        }
        temp->endWith++;
    }

    int isWordPresent(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->isCharPresent(word[i]))
                return 0;
            temp = temp->getNext(word[i]);
        }
        return temp->endWith;
    }

    int prefixCount(string prefix)
    {
        Node *temp = root;
        for (int i = 0; i < prefix.size(); ++i)
        {
            if (!temp->isCharPresent(prefix[i]))
                return 0;
            temp = temp->getNext(prefix[i]);
        }
        return temp->startWith;
    }

    bool erase(string word)
    {
        if (!isWordPresent(word))
        {
            cout << "The is no matching word present.\n";
            return false;
        }
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            temp = temp->getNext(word[i]);
            temp->startWith--;
        }
        temp->endWith--;
        return true;
    }
};

int main()
{
    Trie t;
    t.insert("ranit");
    t.insert("neha");
    t.insert("raj");
    t.erase("ranit");
    cout << t.prefixCount("n") << endl;
    return 0;
}