#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <Stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

class Stack
{
    int *arr;
    int cap;
    int size;

public:
    Stack()
    {
        arr = new int[1];
        cap = 1;
        size = 0;
    }

    void resize( int ncap)
    {
        int *nr = new int[ncap];
        for (int i = 0; i < size; i++)
        {
            nr[i] = arr[i];
        }
        delete[] arr;
        arr = nr;
        cap = ncap;
    }

    void add(int n)
    {
        if (size == cap)
        {
            resize(cap*2);
            cout<< "upppsized " << endl; 

        }

        arr[size++] = n;
    }
    void print(){
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i] <<" " ;     /* code */
        }
        cout<<endl;
        
    }

    int stackpop(){
        int t = arr[size-1] ; 
        size-- ; 
        if(size < cap/4){
            resize(cap/2) ; 
            cout<< "downsized " << endl; 
        } ; 
        return t ;
    }

    int peek(){
        return arr[size-1] ;
    }
    int numofelements(){
        return size ; 
    }

};

int main()
{

   Stack box ; 
   box.add(98) ; 
   box.add(28) ; 
   box.add(8) ; 
   box.add(118) ; 
   box.add(118) ; 
   box.add(118) ; 
   box.add(118) ; 
   box.add(118) ; 
   box.add(118) ; 
   box.add(118) ; 
   box.add(118) ; 
   box.add(118) ; 
   box.add(118) ; 
   box.add(118) ; 

  

  // box.stackpop() ; 
  // box.stackpop() ; 



box.print() ;
    

    return 0;
}