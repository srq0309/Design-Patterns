/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-4
 *
 * @brief	���ù��������Ч��֧�ִ���ϸ���ȵĶ���
**/

#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <cassert>

// ����һ���ӿڣ�ͨ������ӿ�flyweight���Խ��ܲ��������ⲿ״̬
class Flyweight
{
public:
    virtual void Operation() = 0;
};

// ʵ��flyweight�ӿڣ���Ϊ�ڲ�״̬���Ӵ洢�ռ䡣
// ConcreteFlyweight��������ǿɹ����
// �����洢��״̬�������ڲ��ģ����������������ConcreteFlyweight�ĳ���
class ConcreteFlyweight :
    public Flyweight
{
public:
    virtual void Operation() override
    {
        std::cout << "ConcreteFlyweight::Operation." << std::endl;
    }
};

// �������е�Flyweight���඼��Ҫ������Flyweight����ʹ�����Ϊ���ܣ�������ǿ�ƹ���
// ��Flyweight����ṹ��ĳЩ��Σ�UnsharedConcreteFlyweight����ͨ����ConcreteFlyweight������Ϊ�ӽڵ�
class UnsharedConcreteFlyweight:
    public Flyweight
{
public:
    virtual void Operation() override
    {
        std::cout << "UnsharedConcreteFlyweight::Operation." << std::endl;
    }
};

// ����������Flyweight����
// ȷ������Ĺ���flyweight�����û�����һ��flyweightʱ���ṩһ���Ѵ�����ʵ���򴴽�һ��
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


// ���㲢�洢һ������flyweight���ⲿ״̬
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