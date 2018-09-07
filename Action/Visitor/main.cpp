/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-7
 *
 * @brief	表示一个作用与某对象结构中的各个元素的操作。
 *  它使得你可以在不改变各个元素的类的前提下定义作用与这些元素的新操作。
**/

#include <iostream>
#include <memory>

class ConcreteElementA;
class ConcreteElementB;

// 为对象结构中的ConcreteElement的每一个类生命一个Visit操作，该操作的名字和特征标识了发送Visit请求给该访问的那个类，
// 这使得访问者可以确定正被访问元素的具体的类，这样访问者就可以通过该元素的特定接口直接访问它
class Visitor
{
public:
    virtual void VisitConcreteElementA(std::shared_ptr<ConcreteElementA> element) = 0;
    virtual void VisitConcreteElementB(std::shared_ptr<ConcreteElementB> element) = 0;
};

// 定义一个Accept操作，它以一个访问者为参数
class Element
{
public:
    void virtual Accept(std::shared_ptr<Visitor> visitor) = 0;
};

// 实现Accept操作，该操作是以一个访问者为参数
class ConcreteElementA :
    public Element, public std::enable_shared_from_this<ConcreteElementA>
{
public:
    // 通过 Element 继承
    virtual void Accept(std::shared_ptr<Visitor> visitor) override
    {
        visitor->VisitConcreteElementA(shared_from_this());
    }
};

// 实现Accept操作，该操作是以一个访问者为参数
class ConcreteElementB :
    public Element, public std::enable_shared_from_this<ConcreteElementB>
{
public:
    // 通过 Element 继承
    virtual void Accept(std::shared_ptr<Visitor> visitor) override
    {
        visitor->VisitConcreteElementB(shared_from_this());
    }
};

// 实现每个Visit声明的操作，每个操作实现基本算法的一部分，该算法片段乃是对于与结构中对象的类，
// ConcreteVisiter为该算法提供了上下文并存储它的局部状态
// 这一状态常常在遍历该结构的过程中累计结果
class ConcreteVisitor :
    public Visitor
{
public:
    // 通过 Visitor 继承
    virtual void VisitConcreteElementA(std::shared_ptr<ConcreteElementA> element) override
    {   // 实际在这里访问元素
    }
    virtual void VisitConcreteElementB(std::shared_ptr<ConcreteElementB> element) override
    {
    }
};

int main(int argc, char *argv[])
{
}