/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-2
 *
 * @brief	抽象工厂：提供一个创建一系列相关或互相依赖对象的接口，而无需指定它们具体的类型
**/

#include <iostream>
#include <memory>


// 为一类产品对象声明一个接口（A产品）
class AbstractProductA
{
public:
    virtual void ShowProductA() = 0;
};
// 为一类产品对象声明一个接口（B产品）
class AbstractProductB
{
public:
    virtual void ShowProductB() = 0;
};

// 定义一个想被相应的具体工程创建的产品对象（A产品Ⅰ型）
class ConcreteProductA1 :
    public AbstractProductA
{
public:
    virtual void ShowProductA() override
    {
        std::cout << "Product A, by Factory Ⅰ." << std::endl;
    }
};
// 定义一个想被相应的具体工程创建的产品对象（A产品Ⅱ型）
class ConcreteProductA2 :
    public AbstractProductA
{
public:
    virtual void ShowProductA() override
    {
        std::cout << "Product A, by Factory Ⅱ." << std::endl;
    }
};
// 定义一个想被相应的具体工程创建的产品对象（B产品Ⅰ型）
class ConcreteProductB1 :
    public AbstractProductB
{
public:
    virtual void ShowProductB() override
    {
        std::cout << "Product B, by Factory Ⅰ." << std::endl;
    }
};
// 定义一个想被相应的具体工程创建的产品对象（B产品Ⅱ型）
class ConcreteProductB2 :
    public AbstractProductB
{
public:
    virtual void ShowProductB() override
    {
        std::cout << "Product B, by Factory Ⅱ." << std::endl;
    }
};


// 声明一个创建抽象产品对象的操作接口
class AbstractFactory
{
public:
    virtual std::shared_ptr<AbstractProductA> CreateProductA() = 0;
    virtual std::shared_ptr<AbstractProductB> CreateProductB() = 0;
};

// 实现创建具体产品对象的操作（Ⅰ型抽象工厂）
class ConcreteFactory1 :
    public AbstractFactory
{
public:
    virtual std::shared_ptr<AbstractProductA> CreateProductA() override
    {
        return std::make_shared<ConcreteProductA1>();
    }
    virtual std::shared_ptr<AbstractProductB> CreateProductB() override
    {
        return std::make_shared<ConcreteProductB1>();
    }
};

// 实现创建具体产品对象的操作（Ⅱ型抽象工厂）
class ConcreteFactory2 :
    public AbstractFactory
{
public:
    virtual std::shared_ptr<AbstractProductA> CreateProductA() override
    {
        return std::make_shared<ConcreteProductA2>();
    }
    virtual std::shared_ptr<AbstractProductB> CreateProductB() override
    {
        return std::make_shared<ConcreteProductB2>();
    }
};

// Client: 仅使用AbstractFactory和AbstractProduct类声明的接口
int main(int argc, char *argv[])
{
    std::shared_ptr<AbstractFactory> f1 = std::make_shared<ConcreteFactory1>(), // 工厂1
        f2 = std::make_shared<ConcreteFactory2>();  // 工厂2

    std::shared_ptr<AbstractProductA> p_a1 = f1->CreateProductA(),  // 工厂1出品的A产品
        p_a2 = f2->CreateProductA();    // 工厂2出品的A产品
    std::shared_ptr<AbstractProductB> p_b1 = f1->CreateProductB(),  // 工厂1出品的B产品
        p_b2 = f2->CreateProductB();    // 工厂2出品的B产品

    p_a1->ShowProductA();
    p_a2->ShowProductA();
    p_b1->ShowProductB();
    p_b2->ShowProductB();

    system("pause");
    return 0;
}