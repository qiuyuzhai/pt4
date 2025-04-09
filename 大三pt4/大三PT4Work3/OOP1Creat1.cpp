#include <vector>
#include <memory>
#include "pt4.h"
using namespace std;

class Product
{
public:
    virtual string GetInfo() = 0;
    virtual void Transform() = 0;
    virtual ~Product()
    {
        Show("Product");
    }
};

// Implement the ConcreteProduct1
//   and ConcreteProduct2 descendant classes

class Creator
{
protected:
    virtual shared_ptr<Product> FactoryMethod(string info) = 0;
public:
    string AnOperation(string info);
    virtual ~Creator()
    {
        Show("Creator");
    }
};

string Creator::AnOperation(string info)
{
    auto p = FactoryMethod(info);
    p->Transform();
    p->Transform();
    return p->GetInfo();
}

// Implement the ConcreteCreator1
//   and ConcreteCreator2 descendant classes;
//   the AnOperation method should not be
//   overridden in these classes

void Solve()
{
    Task("OOP1Creat1");

}
