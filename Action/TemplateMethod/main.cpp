/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-7
 *
 * @brief	模板方法：定义一个操作中的算法的骨架，而将一些步骤延迟到子类中。
 *  TemplateMethod使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤
**/

#include <iostream>
#include <memory>

// 定义抽象的原语操作，具体的子类将重定义它们以实现一个算法的各个步骤
class AbstractClass
{
public:
    void TemplateMethod()
    {   // 执行预定的操作步骤，每个步骤的由子类具体实现
        PrimitiveOperation1();
        PrimitiveOperation2();
    }
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;
};

class ConcreteClass :
    public AbstractClass
{
public:
    // 通过 AbstractClass 继承
    virtual void PrimitiveOperation1() override
    {
        std::cout << "Operation 1." << std::endl;
    }
    virtual void PrimitiveOperation2() override
    {
        std::cout << "Operation 2." << std::endl;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}