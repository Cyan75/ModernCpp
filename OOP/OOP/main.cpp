//
//  main.cpp
//  OOP
//
//  Created by Cyan on 2022/03/18.
//

#include <iostream>
#include "Savings.hpp"
#include "Checking.hpp"
#include "Transaction.hpp"
#include <typeinfo>

/*
class Animal{
public:
    void Eat(){
        std::cout<<" Animal eating "<<std::endl;
    }
    void Run(){
        std::cout<<" Animal running "<<std::endl;
    }
    void Speak(){
        std::cout<<" Animal speaking "<<std::endl;
    }
};
class Dog : public Animal{
public:
    void Eat(){
        std::cout<<" Dog eating meat "<<std::endl;
    }
    void Speak(){
        std::cout<<" Dog barking "<<std::endl;
    }
};
 */

/*
class Zip final {
public:
    Zip() {

    }
    void Compress(const std::string &filename) {

    }
    void Decompress(const std::string &filename) {

    }
    void PrintStatistics() {

    }
    
//    Destructor is not virtual, therefore it is risky to
//    inherit from this class.
//
//    Zip *p = new FastZip ;
//    delete p ;
//
//    This would call Zip destructor only. Therefore, the destructor
//    of FastZip will not execute & it will not be able to release
//    any resources
//
    ~Zip() {
        //release resources
    }
};

//class FastZip : public Zip { //Cannot inherit from a final class
//
//};

#pragma region Override
class Document {
public:
    virtual void Serialize(float version) = 0;
};
class Text : public Document {
public:
    void Serialize(float version)override final{
        std::cout << "Text::Serialize" << std::endl;
    }
};
class RichText : public Text {
public:
    //Cannot override because the function is final in base
//    void Serialize(float version)override {
//        std::cout << "RichText::Serialize" << std::endl;
//    }
};

class XML : public Document {
public:
    void Serialize(float version)override {
        std::cout << "XML::Serialize" << std::endl;
    }
};

void Write(Document *p) {
    p->Serialize(1.1f);
}
#pragma endregion
*/

/*
#pragma region Override
class Document{
public:
//    virtual void Serialize(float version){
//        std::cout << "Document::Serialize" << std::endl;
//    }
    
    //pure virtual
    virtual void Serialize(float version) = 0;
};
class Text : public Document{
public:
//    void Serialize(float version) override  final{
//        std::cout<<"Text::Serialize"<<std::endl;
//    }
};
class RichText : public Text{
public:
    //cannot override due to the final keyword in base
    void Serialize(float version) override{
        std::cout<<"RichText::Serialize"<<std::endl;
    }
};

class XML : public Document{
public:
    //not overriding Serialised : client doesn't know if XML is not getting serialised
    // the child class(XML) is not forced to override Serialize
    void Serialize(float version){
        std::cout<<"XML::Serialize"<<std::endl;
    }
};

void Write(Document *p){
    p->Serialize(1.1f);
}
*/

class Stream{
    std::string m_FileName;
public:
    Stream(const std::string & fileName){
        std::cout<<"Stream(const std::string & fileName)"<<std::endl;
    }
    const std::string & GetFileName() const{
        return m_FileName;
    }
    ~Stream(){
        std::cout<<"~Stream()"<<std::endl;
    }
};

class OutputStream : virtual public Stream{
    std::ostream &out;
    
    public :
    OutputStream(std::ostream &o, const std::string &fileName) : out(o), Stream(fileName){
        std::cout<<"OutputStream"<<std::endl;
    }
    std::ostream & operator << (const std::string &data){
        out<<data;
        return out;
    }
    ~OutputStream(){
        std::cout<<"~OutputStream()"<<std::endl;
    }
};

class InputStream : virtual public Stream{
    std::istream &in;
    
    public :
    InputStream(std::istream &i, const std::string &fileName) : in(i), Stream(fileName){
        std::cout<<"InputStream"<<std::endl;
    }
    std::istream & operator >> (std::string &data){
        in >> data;
        return in;
    }
    ~InputStream(){
        std::cout<<"~InputStream()"<<std::endl;
    }
};

class IOStream : public OutputStream, public InputStream{
public:
    IOStream(const std::string &fileName) : OutputStream(std::cout,fileName), InputStream(std::cin, fileName), Stream(fileName){
        std::cout<<"IOStream"<<std::endl;
    }
    ~IOStream(){
        std::cout<<"~IOStream()"<<std::endl;
    }
    
};
int main(int argc, const char * argv[]) {
//    Dog d;
//    d.Eat();
//    d.Run();
//    d.Speak();
    
//    Account acc("Cyan", 1000);
//    std::cout <<"initial balance : "<<acc.GetBalance() << std::endl;
//    acc.Deposit(200);
//    acc.Withdraw(380);
//    std::cout <<"Balance : "<<acc.GetBalance()<<std::endl;

//    Checking ch1("David", 200, 50);
//        Checking ch1("David", 200);
//    ch1.Withdraw(170);
//    std::cout <<"Balance : "<<ch1.GetBalance()<<std::endl;

    /*
    Checking ch("Bob", 700);
    Checking ch2("Cyan", 750);
    Transact(&ch);
    Transact(&ch2);
    Savings acc("David", 100, 0.05f);
    Transact(&acc);
     */
    /*
    Savings acc("Brad", 100, 0.05f);
    Transact(&acc);
    std::cout<<"size of Account : "<<sizeof(Account)<<std::endl;
     */
//    Account *acc = new Savings("Ashley", 300, 0.05f);
//    delete acc;
    
//    XML xml;
//    Write(&xml);
//    Checking ch("Lily", 100);
//    Account *pAccount = &ch;
//    Checking *pChecking = pAccount; //base pointer cannot contain a larger child
//    Checking *pChecking = static_cast<Checking*>(pAccount);
    /*
    Checking ch("Michael",200,50);
    Savings sv("Michael", 150, 0.05f);
    try {
        Transact(ch);
        Transact(sv);
    } catch (std::exception &ex) {
        std::cout<<"Exception : "<<ex.what()<<'\n';
    }
    Account* pAccount = & ch;
     */
//    std::cout<< ch.GetMinimumBalance()<<std::endl;
//    std::cout<< sv.GetInterestRate()<<std::endl;
    /*
    int i{};
    float f{};
    const std::type_info &ti1 = typeid(i);
    const std::type_info &ti2 = typeid(ch);
    const std::type_info &ti3 = typeid(sv);
    const std::type_info &ti4 = typeid(*pAccount);
    
    std:: cout << ti1.name() << std::endl;
    std:: cout << ti2.name() << std::endl;
    std:: cout << ti3.name() << std::endl;
    std:: cout << ti4.name() << std::endl;
    
    if(ti3 == typeid(Savings)){
        std::cout << "p points to saving object" << std::endl;
    }
    else{
        std::cout << "p does not points to saving object" << std::endl;
    }
    */
    
    /*
//    Text t;
//    Document &doc = t;
//    doc.Serialize(1.2f);
    XML xml;
    Write(&xml);
     */
    
    IOStream stream("doc.txt");
    std::string data;
    stream >> data;
    stream << data;
    std::cout << stream.GetFileName() << std::endl;
    return 0;
}
