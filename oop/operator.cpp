#include <iostream>

using namespace std;

class student
{
public:
    student() : x(0) {}

    int x;

    student operator+(student s1);
    void printoj();
};

student student::operator+(student s1)
{
    x = x + s1.x;
    return *this ; 
}
void student::printoj()
{
    cout << "value  " << x << endl;
}

int main()
{

    student sabbir;
    sabbir.x = 87;

    student rt;
    rt = rt + sabbir;

    rt.printoj();

    return 0;
}