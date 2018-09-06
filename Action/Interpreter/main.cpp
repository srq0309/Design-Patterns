/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-6
 *
 * @brief	解释权模式：给定一个语言，定义它的文法的一种表示，并定义一个解释器，
 *  这个解释器使用该表示来解释文法
**/


#include <iostream>
#include <memory>
#include <string>

// 声明一个抽象的解释操作，这个接口为抽象语法树中的所有节点所共享
class AbstractExpression
{
public:
    virtual void Interpret() = 0;
};

// 实现与文法中的终结符相关联的解释操作
// 一个句子中的每个终结符需要该类的一个实例
class TerminalExpression :
    public AbstractExpression
{
public:
    virtual void Interpret() override
    {
        throw std::logic_error("The method or operation is not implemented.");
    }
};

// 对文法的每一条规则都需要一个NonterminalExpression
// 文法的每个符号都维护一个AbstractExpression类型的实例变量
// 为文法的非终结符实现解释操作。解释一般需要递归地调用表示文法中那些对象的解释操作
class NonterminalExpression :
    public AbstractExpression
{
public:
    virtual void Interpret() override
    {
        throw std::logic_error("The method or operation is not implemented.");
    }
};

// 包含解释器之外的一些全局信息
class Context {};

int main(int argc, char *argv[])
{
    return 0;
}