// stack for Tree
#include<iostream>
using namespace std;
const int MAX = 30;
class treeNode{
    private:
        char data;
        treeNode * left;
        treeNode * right;

    public:
        treeNode() : left(nullptr) , right(nullptr){ }
        friend class tree;
};
class stack{
    private:
        int top;
        treeNode * data[MAX];
        
    public:
        stack(){
            top = -1;
        }
        //friend class declaration
        friend class tree;

        void push(treeNode * temp){
            if(isFull()){
                cout << "stack is full" << endl;
                return;
            }
            top++;
            data[top] = temp;
        }
        treeNode * pop(){
            if(isEmpty()){
                cout << "stack is empty" << endl << endl;
                return nullptr;
            }
            treeNode * temp = data[top];
            data[top] = nullptr;
            top--;
            return temp; 
        }
        bool isFull(){
            if(top == MAX - 1)
                return true;
            
            return false;
        }
        bool isEmpty(){
            if(top == -1)
                return true;
            
            return false;
        }
};
class tree{
    private:
        treeNode * root;
    public:
        tree(){
            root = nullptr;
         }
        void create_nr();
        void inOrder();
        void preOrder();
        void postOrder();
};
void tree :: create_nr(){
    if(root == nullptr){
        root = new treeNode;
        cout << "Enter The Data Of Root Node : ";
        cin >> root->data;
    }
    treeNode * temp;
    bool flag = true;
    char choice;
    do
    {
        temp = root;
        flag = true;
        treeNode * current = new treeNode;
        cout << "Enter the Data : ";
        cin >> current->data;
        while (flag){
            cout << "Add Node To Left or Right Of " << temp->data << " (l/r) : ";
            cin >> choice;
            if(choice == 'l'){
                if(temp->left == nullptr){
                    temp->left = current;
                    flag = false;
                }
                temp = temp->left;
            }
            else{
                if(choice == 'r'){
                    if(temp->right == nullptr){
                        temp->right = current;
                        flag = false;
                    }
                    temp = temp->right;
                }
            }
        }
        cout << "Press c to continue : ";
        cin >> choice;
        cout << endl;
        if(choice != 'c')
            break;
    } while (true);
    
}
void tree :: inOrder(){
    if(root == nullptr)
        return;
    
    treeNode * temp = root;
    stack * st = new stack;
    while(true){
        while(temp!=nullptr){
            st->push(temp);
            temp = temp->left;
        }
        if(st->isEmpty())
            break;
        
        temp = st->pop();
        cout << temp->data << " -> ";
        temp = temp->right;
    }
    delete st;
    delete temp;
}
void tree :: preOrder(){
    if(root == nullptr)
        return;
    treeNode * temp = root;
    stack * st = new stack;
    while (true)
    {
        while (temp!=nullptr)
        {
            cout << temp->data << " -> ";
            st->push(temp);
            temp = temp->left;
        }
        if(st->isEmpty())
            break;
        
        temp = st->pop();
        temp = temp->right;
    }

    delete st;
    delete temp;
    
}
void tree :: postOrder(){
    if(root == nullptr)
        return;
    
    treeNode * temp = root;
    stack * st = new stack;
    while(true){
        while(temp!=nullptr){
            st->push(temp);
            temp = temp->left;
        }
        if(st->data[st->top] == nullptr){
            temp = st->pop();
            cout << temp->data << " -> ";
        }
        while(st->isEmpty() != true && st->data[st->top]->right == temp){
                temp = st->pop();
                cout << temp->data << " -> ";
        }
        if(st->isEmpty())
            break; 
        
        temp = st->data[st->top]->right;
    }

    delete temp;
    delete st;
}

int main(){
    tree mytree;
    mytree.create_nr();
    cout << "In_order : ";
    mytree.inOrder();
    cout << endl;
    cout << "PreOrder : ";
    mytree.preOrder();    
    cout << endl;
    cout << "postOrder : ";
    mytree.postOrder();

}