#include <iostream>
#include <stack>  // Include the stack header

int main() {
    std::stack<int> st;  // Create a stack of integers

    // Push elements onto the stack
    st.push(67);
    st.push(7);
    st.push(44);

    // Access the top element
    std::cout << "Top element: " << st.top() << std::endl;  // Outputs 44

    // Pop elements from the stack
    std::cout << "Popped element: " << st.top() << std::endl;
    st.pop();  // Removes 44

    std::cout << "Popped element: " << st.top() << std::endl;
    st.pop();  // Removes 7

    std::cout << "Popped element: " << st.top() << std::endl;
    st.pop();  // Removes 67

    // Check if the stack is empty
    if (st.empty()) {
        std::cout << "Stack is empty" << std::endl;
    }

    return 0;
}
