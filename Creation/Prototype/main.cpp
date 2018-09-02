/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-2
 *
 * @brief	用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象
**/


#include <iostream>
#include <memory>

// 原型，必须提供一个克隆自身的接口
class Prototype
{
public:
    virtual std::shared_ptr<Prototype> Clone() = 0;
    virtual void Show() = 0;
};

// 实现一个原型A
class ConcretePrototypeA :
    public Prototype
{
public:
    virtual std::shared_ptr<Prototype> Clone() override
    {
        return std::make_shared<ConcretePrototypeA>(*this);
    }

    virtual void Show() override
    {
        std::cout << "ConcretePrototype A." << std::endl;
    }

};
// 实现一个原型B
class ConcretePrototypeB :
    public Prototype
{
public:
    virtual std::shared_ptr<Prototype> Clone() override
    {
        return std::make_shared<ConcretePrototypeB>(*this);
    }

    virtual void Show() override
    {
        std::cout << "ConcretePrototype B." << std::endl;
    }

};

int main(int argc, char *argv[])
{
    std::shared_ptr<Prototype> p_a1 = std::make_shared<ConcretePrototypeA>(),
        p_b1 = std::make_shared<ConcretePrototypeB>();

    auto p_a2 = p_a1->Clone();
    auto p_b2 = p_b1->Clone();

    p_a1->Show();
    p_a2->Show();

    p_b1->Show();
    p_b2->Show();

    system("pause");
    return 0;
}