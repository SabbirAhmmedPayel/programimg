#include <iostream>
#include <vector>  

using namespace std;


class node{
    int data ; 
    node* next;

    public:

    node(int x ){
        data = x ; 
        next = nullptr ; 

    }
} ; 

class linkedlist{
    node *head;

    public : 
    linkedlist(){
        head = nullptr ; 
    }

} ; 


int main() {
 
 linkedlist list1 ; 


return 0 ; 
 }