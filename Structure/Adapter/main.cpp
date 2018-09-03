/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-3
 *
 * @brief	将一个类的接口转换成客户希望的另外一个接口，
 *  Adapter模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。
**/

#include <iostream>

// 定义Client使用的与特定领域相关的接口
class Target
{
public:
    virtual void Request()
    {
        std::cout << "Target::Request." << std::endl;
    }
};

// 与符合Target接口的对象协同
class Client
{
public:
    void Work(std::shared_ptr<Target> target)
    {
        target->Request();
    }
};

// 定义一个已经存在的接口，这个接口需要适配
class Adaptee
{
public:
    void SpecificRequest()
    {
        std::cout << "Adaptee::SpecificRequest" << std::endl;
    }
};

// 对Adapee的接口与Target的接口进行适配
class Adapter :
    public Target, private Adaptee
{
public:
    virtual void Request() override
    {
        Adaptee::SpecificRequest();
    }
};

int main(int argc, char *argv[])
{
    Client().Work(std::make_shared<Adapter>());
    system("pause");
}
