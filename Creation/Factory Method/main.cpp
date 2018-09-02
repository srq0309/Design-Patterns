/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-2
 *
 * @brief	工厂方法：定义一个用于创建对象的接口，让子类决定实例化哪一个类，
 *  使一个类的实例化延迟到其子类。
**/

#include <iostream>
#include <memory>

// 定义工厂方法所创建的对象的接口
class Product
{
public:
    virtual void Show()
    {
        std::cout << "Product Default." << std::endl;
    }
};

// 实现Product接口
class ConcreteProduct :
    public Product
{
public:
    virtual void Show() override
    {
        std::cout << "Product Concrete." << std::endl;
    }
};

// 声明工厂方法，该方法返回一个Product类型的对象
// 当然也可定义一个工厂方法的缺省实现，返回默认的对象
class Creator
{
public:
    virtual std::shared_ptr<Product> FactoryMethod()
    {
        return std::make_shared<Product>();
    }
};

// 重定义工厂方法以返回一个ConcreteProduct实例
class ConcreteCreator :
    public Creator
{
public:
    virtual std::shared_ptr<Product> FactoryMethod() override
    {
        return std::make_shared<ConcreteProduct>();
    }
};

int main(int argc, char *argv[])
{
    std::shared_ptr<Creator> c_dft = std::make_shared<Creator>(),   // 默认工厂
        c_a = std::make_shared<ConcreteCreator>();  // 工厂

    auto p_dft = c_dft->FactoryMethod();
    auto p_a = c_a->FactoryMethod();

    p_dft->Show();
    p_a->Show();

    system("pause");
    return 0;
}