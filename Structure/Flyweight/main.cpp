/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-4
 *
 * @brief	运用共享对象有效的支持大量细粒度的对象
**/

#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <cassert>

// 描述一个接口，通过这个接口flyweight可以接受并作用于外部状态
class Flyweight
{
public:
    virtual void Operation() = 0;
};

// 实现flyweight接口，并为内部状态增加存储空间。
// ConcreteFlyweight对象必须是可共享的
// 它所存储的状态必须是内部的；即，它必须独立于ConcreteFlyweight的场景
class ConcreteFlyweight :
    public Flyweight
{
public:
    virtual void Operation() override
    {
        std::cout << "ConcreteFlyweight::Operation." << std::endl;
    }
};

// 并非所有的Flyweight子类都需要被共享，Flyweight对象使共享成为可能，但并不强制共享
// 在Flyweight对象结构的某些层次，UnsharedConcreteFlyweight对象通常将ConcreteFlyweight对象作为子节点
class UnsharedConcreteFlyweight:
    public Flyweight
{
public:
    virtual void Operation() override
    {
        std::cout << "UnsharedConcreteFlyweight::Operation." << std::endl;
    }
};

// 创建并管理Flyweight对象
// 确保合理的共享flyweight，当用户请求一个flyweight时，提供一个已创建的实例或创建一个
class FlyweightFactory
{
public:
    std::shared_ptr<Flyweight> GetFlyweight(std::string key)
    {
        if (flyweights_[key] == nullptr) {
            flyweights_[key] = std::make_shared<ConcreteFlyweight>();
        }
        return flyweights_[key];
    }
private:
    std::map<std::string, std::shared_ptr<Flyweight>> flyweights_;
};


// 计算并存储一个或多个flyweight的外部状态
int main(int argc, char *argv[])
{
    std::shared_ptr<Flyweight> unshared_flyweight = std::make_shared<UnsharedConcreteFlyweight>();
    FlyweightFactory factory;
    auto f1 = factory.GetFlyweight("f1");
    auto f2 = factory.GetFlyweight("f2");
    auto f3 = factory.GetFlyweight("f1");
    assert(f1 == f3);

    f1->Operation();
    f2->Operation();
    unshared_flyweight->Operation();

    system("pause");
    return 0;
}