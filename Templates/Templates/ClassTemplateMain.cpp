//
//  ClassTemplateMain.cpp
//  Templates
//
//  Created by Cyan on 2022/04/15.
//

#include <iostream>

template<typename T, int size>
class Stack{
//    int m_Buffer[512];
    T m_Buffer[size];
    int m_Top{-1};
public:
    Stack() = default;
    Stack(const Stack &obj){
        m_Top = obj.m_Top;
        for (int i = 0; i <= m_Top; ++i) {
            m_Buffer[i] = obj.m_Buffer[i];
        }
        m_Top = obj.m_Top;
    }
    
//    void Push(int elem){
    void Push(const T &elem){
        m_Buffer[++m_Top] = elem;
    }
    void Pop();
//    int Top() const {
    const T& Top() const {
        return m_Buffer[m_Top];
    }
    bool IsEmpty() {
        return m_Top == -1;
    }
    //factory method : creating the instance of the class
    //shorthand expression available
    static Stack Create();
};

//when the definition of a member function is given outside the class,
// there should be given the syntax of the templates
template<typename T, int size>
void Stack<T, size>::Pop(){
    --m_Top;
}


// the compiler does not know what Stack type is
template<typename T, int size>
 Stack<T, size> Stack<T,size>::Create(){
    return Stack<T, size>();
}
/*
int main(){
//    Stack s;
//    Stack<int> s;
    Stack<float, 10> s = Stack<float, 10>::Create();
    s.Push(3);
    s.Push(1);
    s.Push(6);
    s.Push(9);
    auto s2(s);
    
    while(!s2.IsEmpty()){
        std::cout<< s2.Top() << " ";
        s2.Pop();
    }
    return 0;
}
*/
