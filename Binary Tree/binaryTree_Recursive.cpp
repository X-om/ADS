// Recursive 
#include<iostream>
using namespace std;

class treeNode{
    private:
        char data;
        treeNode * Left;
        treeNode * Right;

        // friend class
        friend class tree;

    public:
        treeNode() : Left(nullptr) , Right(nullptr) { }
};

class tree{
    private:
    
        treeNode * root;

    public:
        tree() : root(nullptr) { }

        void create_r(){
            int value;
            root = new treeNode;
            cout << "Enter The Root Node value : ";
            cin >> root->data;
            cout << endl;
            create_r(root);
        }

        void create_r(treeNode * temp){
            char ch;
            cout << "Add Node To Left Of " << temp->data << " (y/n) : ";
            cin >> ch;
            if(ch == 'y'){
                treeNode * current = new treeNode;
                cout << "Enter The Data : ";
                cin >> current->data;
                cout << endl;
                temp->Left = current;
                create_r(current);
            }
            cout << "Add Node To Right Of " << temp->data << " (y/n) : ";
            cin >> ch;
            if(ch == 'y'){
                treeNode * current = new treeNode;
                cout << "Enter The Data : ";
                cin >> current->data;
                cout << endl;
                temp->Right = current;
                create_r(current);
            }
        }
        void Inorder(){
            cout << endl << endl;
            Inorder(root);
        }
        void Inorder(treeNode * temp){
            if(temp != nullptr){
                Inorder(temp->Left);
                cout << " -> " << temp->data;
                Inorder(temp->Right);
            }
        }
        void pre_order(){
            cout << endl << endl;
            pre_order(root);
        }
        void pre_order(treeNode * temp){
            if(temp != nullptr){
                cout << " -> " << temp->data;
                pre_order(temp->Left);
                pre_order(temp->Right);
            }
        }
        void post_order(){
            cout << endl << endl;
            post_order(root);
        }
        void post_order(treeNode * temp){
            if(temp != nullptr){
                post_order(temp->Left);
                post_order(temp->Right);
                cout << " -> " << temp->data;
            }
        }

};

int main(){
    system("clear");
    tree Mytree;
    Mytree.create_r();

    cout << "InOrder : ";
    Mytree.Inorder();

    cout << endl << endl;
    
    cout << "Pre_Order : ";
    Mytree.pre_order();

    cout << endl << endl;

    cout << "Post_Order : ";
    Mytree.post_order();

    cout << endl << endl;
}