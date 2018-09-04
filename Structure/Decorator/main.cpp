/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-4
 *
 * @brief	动态的给一个对象添加一些额外的职责。
 *  就增加功能来说，Decorator模式相比生成子类更加灵活
**/


#include <memory>
#include <iostream>

// 定义一个对象的接口，可以给这些对象动态地添加职责
class Component
{
public:
    virtual void Operation() = 0;
};

// 定义一个对象，可以给这个对象添加一些职责
class ConcreteComponent :
    public Component
{
public:
    virtual void Operation() override
    {
        std::cout << "ConcreteComponent::Operation." << std::endl;
    }
};

// 维护一个指向Component对象的指针，并定义一个与Component接口一致的接口
class Decorator :
    public Component
{
public:
    Decorator(std::shared_ptr<Component> component) :
        component_(component)
    {
    }
    virtual void Operation() override
    {
        component_->Operation();
    }
private:
    std::shared_ptr<Component> component_;
};

// 向组件添加职责
class ConcreteDecorator :
    public Decorator
{
public:
    ConcreteDecorator(std::shared_ptr<Component> component) :
        Decorator(component)
    {
    }
    virtual void Operation() override
    {
        Decorator::Operation();
        AddedBehavior();
    }
    void AddedBehavior()
    {
        std::cout << "ConcreteDecorator::AddedBehavior." << std::endl;
    }
};

int main(int argc, char *argv[])
{
    std::shared_ptr<Component> c = std::make_shared<ConcreteComponent>();
    std::shared_ptr<Decorator> d1 = std::make_shared<ConcreteDecorator>(c), // 第一层装饰
        d2 = std::make_shared<ConcreteDecorator>(d1);   // 第二层装饰

    d2->Operation();
    system("pause");
    return 0;
}