/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-4
 *
 * @brief	代理模式：为其他对象提供一种代理以控制对这个对象的访问
**/

/*!
 * 有多种方式实现代理，下面分别采用多态机制和c++运算符重载实现
 */

#include <memory>
#include <iostream>

 // 定义RealSubject和Porxy的公共接口，这样就在任何时候使用RealSubject的地方使用Proxy
class Subject
{
public:
    virtual void Operation()
    {
        std::cout << "Subject::Operation." << std::endl;
    }
};

// 定义Proxy所代表的实体
class RealSubject :
    public Subject
{
public:
    virtual void Operation() override
    {
        std::cout << "RealSubject::Operation." << std::endl;
    }
};

// 保存一个引用使得代理可以访问尸体
// 提供一个与Subject的接口相同的接口，这样代理可以用来代替实体
// 控制对实体的存取，并可能负责创建和删除它
// 其他功能以来于代理的类型
class Proxy :
    public Subject
{
public:
    Proxy(std::shared_ptr<Subject> subject) :
        subject_(subject)
    {
    }
    virtual void Operation() override
    {
        subject_->Operation();
    }
private:
    std::shared_ptr<Subject> subject_;
};

// 重载运算符*和->
class RealSubjectPtr
{
public:
    RealSubjectPtr(Subject *subject) :
        subject_(subject)
    {
    }
    Subject* operator->()
    {
        return subject_;
    }
    Subject& operator*()
    {
        return *subject_;
    }
private:
    Subject *subject_;
};

int main(int argc, char *argv[])
{
    auto realsubject = std::make_shared<RealSubject>();
    Proxy proxy(realsubject);

    RealSubjectPtr ps(realsubject.get());
    ps->Operation();

    proxy.Operation();

    system("pause");
    return 0;
}   