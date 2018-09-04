/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-4
 *
 * @brief	��̬�ĸ�һ���������һЩ�����ְ��
 *  �����ӹ�����˵��Decoratorģʽ�����������������
**/


#include <memory>
#include <iostream>

// ����һ������Ľӿڣ����Ը���Щ����̬�����ְ��
class Component
{
public:
    virtual void Operation() = 0;
};

// ����һ�����󣬿��Ը�����������һЩְ��
class ConcreteComponent :
    public Component
{
public:
    virtual void Operation() override
    {
        std::cout << "ConcreteComponent::Operation." << std::endl;
    }
};

// ά��һ��ָ��Component�����ָ�룬������һ����Component�ӿ�һ�µĽӿ�
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

// ��������ְ��
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
    std::shared_ptr<Decorator> d1 = std::make_shared<ConcreteDecorator>(c), // ��һ��װ��
        d2 = std::make_shared<ConcreteDecorator>(d1);   // �ڶ���װ��

    d2->Operation();
    system("pause");
    return 0;
}