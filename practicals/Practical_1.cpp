#include<iostream>
using namespace std;
#define MAX 20
class treeNode{
    private:
        char data;
        treeNode * left;
        treeNode * right;
    public:
        friend class tree;
};
class stack{
    private:
        int top;
        treeNode * data[MAX];
    public:
        friend class tree;
        stack(){
            top = -1;
        }
        void push(treeNode * temp){
            if(isFull())
                return;
            
            top++;
            data[top] = temp;
        }
        treeNode * pop(){
            if(isEmpty())
                return nullptr;
            
            treeNode * res = data[top];
            data[top] = nullptr;
            top--;
            return res;
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
        tree();
        void create_r();
        void create_r(treeNode * temp);
        void inorder_r();
        void inorder_r(treeNode * temp);
        void preorder_r();
        void preorder_r(treeNode * temp);
        void postorder_r();
        void postorder_r(treeNode * temp);
        void create_nr();
        void inorder_nr();
        void preorder_nr();
        void postorder_nr();
};
tree::tree(){
    root = nullptr;
}

void tree :: create_r(){
        root = new treeNode;
        cout << "Enter the data for root node : ";
        cin >> root->data;
        create_r(root);
}
void tree :: create_r(treeNode * temp){
    char choice;
    cout << "Allocate node to left of " << temp->data << " (y/n) : ";
    cin >> choice;
    if(choice == 'y'){
        treeNode * current = new treeNode;
        cout << endl << "Enter the data for current node : ";
        cin >> current->data;
        cout << endl;
        temp->left = current;
        create_r(current);
    }
    cout << "Allocate node to right of " << temp->data << " (y/n) : ";
    cin >> choice;
    if(choice == 'y'){
        treeNode * current =  new treeNode;
        cout << endl << "Enter the data for current node : ";
        cin >> current->data;
        cout << endl;
        temp->right = current;
        create_r(current);
    }
}
void tree :: inorder_r(){
    if(root == nullptr){
        cout << "No recursive tree exist !" << endl << endl;
        return;
    }
    inorder_r(root);
}
void tree :: inorder_r(treeNode * temp){
    if(temp!=nullptr){
        inorder_r(temp->left);
        cout << " -> " << temp->data;
        inorder_r(temp->right);
    }
}
void tree :: preorder_r(){
    if(root == nullptr){
        cout << "No recursive tree exist !" << endl << endl;
        return;
    }
    preorder_r(root);
}
void tree :: preorder_r(treeNode * temp){
    if(temp!=nullptr){
        cout << " -> " << temp->data;
        preorder_r(temp->left);
        preorder_r(temp->right);
    }
}
void tree :: postorder_r(){
    if(root == nullptr){
        cout << "No recursive tree exist !" << endl << endl;
        return;
    }
    postorder_r(root);
}
void tree :: postorder_r(treeNode * temp){
    if(temp!=nullptr){
        postorder_r(temp->left);
        postorder_r(temp->right);
        cout << " -> " << temp->data;
    }
}

void tree :: create_nr(){
    if(root == nullptr){
        root = new treeNode;
        cout << "Enter the data for root node : ";
        cin >> root->data;
    }
    treeNode * temp;
    int flag;
    char choice;
    do{
        temp = root;
        flag = 0;
        treeNode * current = new treeNode;
        cout << "Enter the data : ";
        cin >> current->data;
        while(flag == 0){   
            cout << "Add To Left or right of " << temp->data << " (l/r) : ";
            cin >> choice;
            if(choice == 'l'){
                if(temp->left == nullptr){
                    temp->left = current;
                    flag = 1;
                }
                temp = temp->left;
            }
            else{
                if(choice == 'r'){
                    if(temp->right == nullptr){
                        temp->right = current;
                        flag = 1;
                    }
                    temp = temp->right;
                }
            }       
        }
        cout << "Press c to continue : ";
        cin >> choice;
        if(choice != 'c')
            break;

        cout << endl;
    }while(true);
}
void tree :: inorder_nr(){
    if(root == nullptr)
        return;
    treeNode * temp = root;
    stack * st = new stack;
    while(true){
        
        while(temp != nullptr){
            st->push(temp);
            temp = temp->left;
        }
        if(st->isEmpty())
            break;
        
        temp = st->pop();
        cout << " -> " << temp->data;
        temp = temp->right;
    }
    delete st;
    delete temp;
    cout << endl;
}
void tree :: preorder_nr(){
    if(root == nullptr)
        return;
    treeNode * temp = root;
    stack * st = new stack;
    while(true){
        while(temp!=nullptr){
            cout << " -> " << temp->data;
            st->push(temp);
            temp = temp->left;
        }
        if(st->isEmpty())
            break;
        
        temp = st->pop();
        temp = temp->right;
    }
    delete temp;
    delete st;
    cout << endl;
}
void tree :: postorder_nr(){
    if(root == nullptr)
        return;
    treeNode * temp = root;
    stack * st = new stack;
    while(true){
        while(temp!=nullptr){
            st->push(temp);
            temp = temp->left;
        }
        if(st->data[st->top]->right == nullptr){
            temp = st->pop();
            cout << " -> " << temp->data;
        }
        while(st->isEmpty() != true && st->data[st->top]->right == temp){
            temp = st->pop();
            cout << " -> " << temp->data;
        }
        if(st->isEmpty())
            break;
        
        temp = st->data[st->top]->right;
    }
    delete st;
    delete temp;
    cout << endl;
}



int main(){
    system("clear"); 
    bool flag = true;
    int choice;
    do{
        tree * bt = new tree;
        cout << "1. create recursive binary tree" << endl << "2. create non recursive binary tree" 
        << endl << "3.Exit" << endl;
        cout << endl << "Enter your choice : ";
        cin >> choice;
        switch(choice){
            case 1:{
                system("clear");
                cout << "\t\t\t**** Recursive Tree *****" << endl << endl;
                int ch;
                bool recursive_flag = true;
                do{
                    cout << "1.Create" << endl << "2.Inorder" << endl 
                    << "3.Preorder" << endl << "4.Postorder" << endl 
                    << "5.Exit" << endl;
                    cout << endl << "Enter your choice : ";
                    cin >> ch;
                    switch (ch)
                    {
                    case 1:
                        bt->create_r();
                        cout << endl;
                        break;
                    case 2: 
                        cout << "Inorder : ";
                        bt->inorder_r();
                        cout << endl << endl;
                        break;
                    case 3:
                        cout << "Preorder : ";
                        bt->preorder_r();
                        cout << endl << endl;
                        break;
                    case 4:
                        cout << "Postorder : ";
                        bt->postorder_r();
                        cout << endl << endl;
                        break;
                    case 5:
                            delete bt;
                            recursive_flag = false;
                        break;
                    default:
                        cout << "Enter valid choice !" << endl << endl; 
                        break;
                    }
                }while(recursive_flag);
                break;
            }
            case 2:{
                system("clear");
                cout << "\t\t\t**** NON Recursive Tree *****" << endl << endl;
                int ch;
                bool non_recursive_flag = true;
                do{
                    cout << "1.Create" << endl << "2.Inorder" << endl 
                    << "3.Preorder" << endl << "4.Postorder" << endl 
                    << "5.Exit" << endl;
                    cout << endl << "Enter your choice : ";
                    cin >> ch;
                    switch (ch)
                    {
                    case 1:
                        bt->create_nr();
                        cout << endl;
                        break;
                    case 2: 
                        cout << "Inorder : ";
                        bt->inorder_nr();
                        cout << endl << endl;
                        break;
                    case 3:
                        cout << "Preorder : ";
                        bt->preorder_nr();
                        cout << endl << endl;
                        break;
                    case 4:
                        cout << "Postorder : ";
                        bt->postorder_nr();
                        cout << endl << endl;
                        break;
                    case 5:
                            non_recursive_flag = false;
                        break;
                    default:
                        cout << "Enter valid choice !" << endl << endl; 
                        break;
                    }
                }while(non_recursive_flag);
                break;
            }
            case 3:
                delete bt;
                flag = false;
                break;
            default:
                cout << "Enter the valid choice !" << endl;
                break;
        }
    }while(flag);


}