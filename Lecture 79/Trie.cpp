#include<iostream>
using namespace std;


class TrieNode{
    public:
         char data;
         TrieNode * children[26];
         bool isTerminal;

        TrieNode(char ch){
            data=ch;

            for(int i=0;i< 26;i++){
                children[i]=NULL;
            }

            isTerminal=false;
        }

};

class Trie{
    public:
        TrieNode * root;

        Trie(){
            root=new TrieNode('\0'); // Root node is a dummy node, it does not hold any character so bascically it is a null character
        }

        void insertUtil(TrieNode * root,string word){
            if(word.length()==0){
                root->isTerminal=true;
                return;
            }

            // Find the index of the character to check in the children array , we start from the root node and then move down

            // Assuming all characters are lowercase English letters
            int index=word[0]-'a';
            TrieNode * child; // We need the child for the further recursive calls

            // First check if the current Node has that child already 
            if(root->children[index] != NULL){
                child=root->children[index];
            }
            // That child does not exist create that child 
            else{
                child = new TrieNode(word[0]);
                root->children[index]=child;
            }

            // At root we check the first character of the word, now we need to check the rest of the word by going to its child

            // Recursion
            // We pass the child and the rest of the word (word.substr(1) removes the first character from the word)
            insertUtil(child,word.substr(1)); //substr(start_pos) or substr(start_pos, length) returns that specific substring  of the string

        }
            
        void insertWord(string word){
            insertUtil(root,word);
        }

        bool searchUtil(TrieNode * root,string word){
            if(word.length()==0){
                return root->isTerminal;
            }

            int index = word[0]-'a';
            TrieNode * child ;

            if(root->children[index]!=NULL){
                child=root->children[index];
            }else{
                return false;
            }

            return searchUtil(child,word.substr(1));
        }

        bool search(string word){
            return searchUtil(root,word);
        }

        void removeUtil(TrieNode * root,string word){
            if(word.length()==0){
                root->isTerminal=false; // We just need to mark the end of the word as false
                return;
            }

            int index=word[0]-'a';
            TrieNode * child;

            if(root->children[index]!=NULL){
                child=root->children[index];
            }else{
                return; // Word does not exist, so we do not need to do anything
            }

            removeUtil(child,word.substr(1));

            // After removing the word, we need to check if the child has any other children or not
            // If it does not have any children, we can delete that child node

            // If the child is not terminal and has no children, we can delete it
            if(!child->isTerminal){
                bool hasChildren=false;
                for(int i=0;i<26;i++){
                    if(child->children[i]!=NULL){
                        hasChildren=true;
                        break;
                    }
                }
                if(!hasChildren){ // If it does not have any children
                    delete child; // Delete the child node
                    root->children[index]=NULL; // Set the pointer to NULL
                }
            }
        }
            
};


int main(){
    
    Trie t;
    t.insertWord("hello");
    t.insertWord("hell");
    t.insertWord("heaven");
    t.insertWord("heavenly");
    cout << t.search("hello") << endl;      // 1
    cout << t.search("hell") << endl;       // 1
    cout << t.search("heaven") << endl;    // 1
    cout << t.search("heavenly") << endl;  // 1
    cout << t.search("heavens") << endl;   // 0

    // IN TRIE TC of insert, search and remove is O(length of the word) because we are traversing the length of the word
    // So if the word is of length m, then the time complexity is O(m)

    // And space complexity is O(m*n) where n is the number of words in the trie and m is the length of the longest word or average length of the all the words in the trie

    return 0;
}