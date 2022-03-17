//
//  main.cpp
//  C++Goodies
//
//  Created by Cyan on 2022/02/07.
//

#include <iostream>
//#include <initializer_list>
//#include <cassert>
#include <vector>
/*
enum class Colour{RED, GREEN, BLUE};//global scope

void FillColour(Colour colour){
    // fill the background
    if (colour == Colour::RED) {
        // paint with red
        std::cout<< " RED " << std::endl;
    }
    else if (colour == Colour::GREEN){
        // paint with green
        std::cout<< " GREEN " << std::endl;
    }
    else if (colour == Colour::BLUE){
        // paint with blue
        std::cout<< " BLUE " << std::endl;
    }
}
*/
/*
void UsingStdString(){
    //String
    //Initialisation and assign
    std::string s = "Hello";
    
    //Access
    s[0] = 'W';
    char ch = s[1];
    std::cout<<s<<std::endl;
//    std::cin>s;
    std::getline(std::cin, s);
    
    //Size
    s.length();
    
    //Insert & concatenate
    std::string s1{"hello"}, s2{"world"};
    s = s1 + s1;
    s+=s1;
    s.insert(6,"world");
    
    //Comparison
    if (s1 != s2){
        
    }
    //Removal
    s.erase();
    s.erase(0,5);
    s.clear();
    
    //Search
    auto pos = s.find("world", 0);  //substring
    if (pos != std::string::npos){
        //found
    }
}

enum class TrafficLight : char{RED, GREEN, YELLOW};
*/
/*
class Distance{
    long double m_Kilometres;
public:
    Distance(long double km) : m_Kilometres{km}{
        
    }
    long double GetKm() const{
        return m_Kilometres;
    }
    void SetKm(long double val){
        m_Kilometres = val;
    }
};
//the literal operator function
Distance operator"" _mi(long double val){
    return Distance{ val * 1.6};
}
Distance operator""_metres(long double val){
    return Distance{val / 1000};
}
 */
/*
constexpr int GetNum(){
    return 43;
}

constexpr int Add( int x, int y){
    return x+y;
}

constexpr int Max(int x, int y){
    //multiple return statement is not allowed
//    if (x>y)
//        return x;
//    else
//        return y;
    //C++14 allows this
    return (x>y)? x : y;
}
*/
/*
class Bag {
    int arr[10];
    int m_Size{};
public:
    //Provides uniform initialization support for braced list of elements as arguments
    Bag(std::initializer_list<int> values) {
        assert(values.size() < 10);
        auto it = values.begin();
        while (it != values.end()) {
            Add(*it);
            ++it;
        }
    }
    void Add(int value) {
        assert(m_Size < 10);
        arr[m_Size++] = value;
    }
    void Remove() {
        --m_Size;
    }
    int operator [](int index) {
        return arr[index];
    }
    int GetSize()const {
        return m_Size;
    }
};
void Print(std::initializer_list<int> values) {
    //auto it = values.begin();
    //while (it != values.end()) {
    //    std::cout << *it++ << " ";
    //}
    for (auto x : values) {
        std::cout << x << " ";
    }
}
*/
union Test{
    int x;
    char ch;
    //CTOR can initialise only one member
    Test() : x{100}{
        std::cout<< "__FUNCSIG__" <<std::endl;
    }
    ~Test(){
        std::cout << "__FUNCSIG__" << std::endl;
    }
};

struct A {
    A() {
        std::cout << "__FUNCSIG__" << std::endl;
    }
    ~A() {
        std::cout << "__FUNCSIG__" << std::endl;
    }

    A(const A& other) {
        std::cout << "__FUNCSIG__" << std::endl;
    }

    A(A&& other) noexcept{
        std::cout << "__FUNCSIG__" << std::endl;
    }

    A& operator=(const A& other) {
        std::cout << "__FUNCSIG__" << std::endl;
        if (this == &other)
            return *this;
        return *this;
    }

    A& operator=(A&& other) noexcept {
        std::cout << "__FUNCSIG__" << std::endl;
        if (this == &other)
            return *this;
        return *this;
    }
};
struct B {

    B() {
        std::cout << "__FUNCSIG__" << std::endl;

    }
    ~B() {
        std::cout << "__FUNCSIG__" << std::endl;

    }

    B(const B& other) {
        std::cout << "__FUNCSIG__" << std::endl ;
    }

    B(B&& other) noexcept {
        std::cout << "__FUNCSIG__" << std::endl ;
    }

    B& operator=(const B& other) {
        std::cout << "__FUNCSIG__" << std::endl ;
        if (this == &other)
            return *this;
        return *this;
    }

    B& operator=(B&& other) noexcept {
        std::cout << "__FUNCSIG__" << std::endl ;
        if (this == &other)
            return *this;
        return *this;
    }
    virtual void Foo(){}
    
};

//user-defined data type in union
union UDT{
    A a ;
    B b ;
    std::string s ;
    UDT() {
        
    }
    ~UDT() {
        
    }
};

int main(int argc, const char * argv[]) {
    /*
    std::cout << "Hello, World!\n";
    Colour c = Colour::RED;
    FillColour(c);
    FillColour(Colour::GREEN);
    FillColour(static_cast<Colour>(2));
    */
    //TODO lower to upper upper to lower translation using ToUpper and ToLower
    /*
    Distance dist{32.0_mi};
    Distance d2 {7123.0_metres};
    std::cout<< d2.GetKm()<<std::endl;
    */
    /*
    //behaves as a constexpr function : evaluated at compile time
    constexpr int i = 10;
    const int k = 20;
    int arr[i];
    int arr3 [k];
    //behaves as a constexpr function : evaluated at compile time
    const int j = GetNum();
    int arr2[j];
    
    //behaves as a normal function : evaluated at runtime
    int x = GetNum();
    
    // the value is calculated duting compile time : faster than invoking Add
    constexpr int sum = Add(3,5);
    int sum2 = Add(3,5);
     */
    
    /*
    int x{ 0 };
    float y{ 3.1f };
    int arr[5]{ 3,1,3,8,2 };
    std::string s{ "Hello C++" };
    std::initializer_list<int> data = { 1,2,3,4 };
    //Braced list of elements automatically creates an initializer_list object
    auto values = { 1,2,3,4 };

    //Bag b{ 3,1,8 };
    ////b.Add(3);
    ////b.Add(1);
    ////b.Add(8);
    //for (int i = 0; i < b.GetSize(); ++i) {
    //    std::cout << b[i] << " ";
    //}

    //Print({ 8,2,6,7 });
    for (auto x : { 8,2,6,7 }) {
        std::cout << x << " ";
    }
    */
    /*
    std::vector<int> data{1,2,3};
    for (int i=0; i<5; ++i) {
        data.push_back(i*10);
    }
    //access
    data[0] = 100;
//    for (int i=0; i<data.size(); i++) {
//        std::cout<< data[i] << " ";
//    }
    for (auto x : data) {
        std::cout<< x << " ";
    }
    auto it = data.begin();
    std::cout << *it;
    ++it;
    --it;
    it = it+5;
    //delete
    data.erase(it);
    std::cout<<std::endl;
    for (auto x : data) {
        std::cout<< x << " ";
    }
    //insert
    it = data.begin()+5;
    std::cout<<std::endl;
    data.insert(it,500);
    for (auto x : data) {
        std::cout<< x << " ";
    }*/
    
//    std::cout << sizeof(Test) << std::endl;
    Test t ;
//    std::cout << t.ch << std::endl;

    t.x = 1000 ;

//    std::cout << t.ch << std::endl;
    
    using namespace std::string_literals ;
    UDT udt ;
    //new(&udt.s) std::string{"Hello world"} ;

    new (&udt.a) A{} ;
    udt.a.~A() ;
    return 0;
}
