//
//  main.cpp
//  Lambda
//
//  Created by Cyan on 2022/04/27.
//

#include <iostream>

/*
//using Comparator = bool(*)(int, int);
template<typename T, int size, typename Comparator>
void Sort(T(&arr)[size], Comparator comp){
    for (int i = 0; i< size - 1 ; ++i) {
        for (int j = 0; j < size-1 ; ++j) {
            if (comp(arr[j] , arr[j+1])) {   //pointer to a function : cannot be in-lined
                T temp = std::move(arr[j]);
                arr[j] = std::move(arr[j+1]);
                arr[j+1] = std::move(temp);
            }
        }
    }
}
bool Comp1(int x, int y){
    return x>y;
}
bool Comp2(int x, int y){
    return x<y;
}
struct Comp3 {
    bool operator() (int x, int y){
        return x>y;
    }
};
*/

//Possible implementation of a lambda expression as a function object
template<typename T>
struct Unnamed {
    T operator()(T x, T y)const {
        return x + y;
    }
};
int main(int argc, const char * argv[]) {
   
//    //Compiler automatically creates a function object
//    auto fn = []() {
//        std::cout << "Welcome to Lambda expressions" << std::endl ;
//    };
//    fn();
//    std::cout << typeid(fn).name() << std::endl;
//    //Generic/polymorphic lambda
//    //                              <optional specifiers>
//    auto sum = [](auto x, auto y)/*mutable*/ /*noexcept*/(false){
//        return x + y;            //    ^^^^        ^^^^
//    };
//    Unnamed<int> n;
//    std::cout << "Sum is:" << sum(5.5f, 2.2f) << std::endl;
    
    /*
    Comp1(3,5);
    Comp3 comp3;
    comp3(3,5);//comp3.operator()
    int arr[]{1,6,8,4,0};
    for (auto x : arr) {
        std::cout << x <<" ";
    }
    std::cout<<std::endl;
    Sort(arr, Comp2);
    for (auto x : arr) {
        std::cout << x << " ";
    }
     */
    
    auto fn = []()<void>{
        std::cout<< " welcome to Lambda expressions";
    }();
    fn();
    std::cout << typeid(fn).name << std::endl;
    return 0;
    
}
