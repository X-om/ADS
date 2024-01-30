#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
class poly{
    private:
        int coefficient;
        int exponent;
        poly *  next;
        friend class polynomial;
    public:
        poly();
        
};
poly :: poly(){
    coefficient = 0;
    exponent = 0;
    next = nullptr;
}
class polynomial{
    private:
        poly * head;
    public:
        polynomial(){ head = nullptr; }
        void create();
        void display();
        int length();
        void Add(polynomial p1 , polynomial p2);
        double evalueate();

};
void polynomial :: create(){
    char choice;
    while(true){
        poly * current = new poly;
        cout << "Enter the coefficient : ";
        cin >> current->coefficient;
        cout << "Enter the exponent : ";
        cin  >> current->exponent;
        if(head == nullptr){
            head = current;
            head->next = head;
        }
        else{
            poly * temp = head;
            while (temp->next != head)
                temp = temp->next;

            temp->next = current;
            current->next = head;
        }
        cout << "Press c to continue : ";
        cin >> choice;
        if(choice != 'c')
            break;
        
        cout << endl;
    }
}
void polynomial :: display(){
    poly * temp = head;
    do{
        if(temp->exponent == 1)
            cout << temp->coefficient << "X";
        else if(temp->exponent == 0)
            cout << temp->coefficient;
        else
            cout << temp->coefficient << "X^" << temp->exponent;

        if(temp->next != head)
            cout << " + ";

        temp = temp->next;
    }while (temp!=head);
}
int polynomial :: length(){
    int count = 0;
    if(head == nullptr)
        return count;
    
    poly * temp = head;
    do{
        count++;
        temp = temp->next;
    }while(temp!=head);
    return count;
}
void polynomial :: Add(polynomial p1 , polynomial p2){
        int i = 0;
        int j = 0;
        poly * temp1 = p1.head;
        poly * temp2 = p2.head;

        while(i < p1.length() && j < p2.length()){
            
            poly * current = new poly;

            if(temp1->exponent > temp2->exponent){
                current->coefficient = temp1->coefficient;
                current->exponent = temp1->exponent;
                temp1 = temp1->next;
                i++;
            }
            else if(temp1->exponent < temp2->exponent){    
                current->coefficient = temp2->coefficient;
                current->exponent = temp2->exponent;
                temp2 = temp2->next;
                j++;
            }
            else if(temp1->exponent == temp2->exponent){
                current->coefficient = temp1->coefficient + temp2->coefficient;
                current->exponent = temp1->exponent;
                temp1 = temp1->next;
                temp2 = temp2->next;
                i++;
                j++;
            }
            if(head == nullptr){
                head = current;
                current->next = head;
            }
            else{
                poly * temp = head;
                while(temp->next != head)
                    temp = temp->next;
                
                temp->next = current;
                current->next = head;
            }
        }

        for(; i < p1.length(); i++){
            poly * current = new poly;
            current->coefficient = temp1->coefficient;
            current->exponent = temp1->exponent;
            poly * temp = head;
            while (temp->next != head)
                temp = temp->next;
            
            temp->next = current;
            current->next = head;
        }
         for(; j < p2.length(); j++){
            poly * current = new poly;
            current->coefficient = temp2->coefficient;
            current->exponent = temp2->exponent;
            poly * temp = head;
            while (temp->next != head)
                temp = temp->next;
            
            temp->next = current;
            current->next = head;
        }
}
double polynomial :: evalueate(){
    if(head == nullptr){
        cout << "Enter the polynomial first" << endl << endl;
        return -1;
    }
    double x;
    cout << "Enter the value of X : ";
    cin >> x;
    poly * temp = head;
    double sum = 0;
    do{
        sum += temp->coefficient * pow(x,temp->exponent);
        temp = temp->next;
    
    }while (temp!=head);
    
    return sum;
    
}
int main(){
    system("clear");
    polynomial p1 , p2 , p3;
    p1.create();
    cout << endl;
    p1.display();
    cout << endl << endl;
    p2.create();
    cout << endl;
    p2.display();
    cout << endl;
    p3.Add(p1,p2);
    cout << endl << "Addition of p1 and p2 is : " << endl;
    p3.display();
    cout << endl << endl;
    cout << "Length of p1 is : " << p1.length() << endl << endl;
    cout << "Length of p2 is : " << p2.length() << endl << endl;
    cout << "Length of p3 is : " << p3.length() << endl << endl;
    setprecision(2);
    cout << "Evaluation of p3 with x = 2.5 is : " << endl << p3.evalueate() << endl;
    return 0;
}