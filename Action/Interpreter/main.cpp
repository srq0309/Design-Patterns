/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-6
 *
 * @brief	����Ȩģʽ������һ�����ԣ����������ķ���һ�ֱ�ʾ��������һ����������
 *  ���������ʹ�øñ�ʾ�������ķ�
**/


#include <iostream>
#include <memory>
#include <string>

// ����һ������Ľ��Ͳ���������ӿ�Ϊ�����﷨���е����нڵ�������
class AbstractExpression
{
public:
    virtual void Interpret() = 0;
};

// ʵ�����ķ��е��ս��������Ľ��Ͳ���
// һ�������е�ÿ���ս����Ҫ�����һ��ʵ��
class TerminalExpression :
    public AbstractExpression
{
public:
    virtual void Interpret() override
    {
        throw std::logic_error("The method or operation is not implemented.");
    }
};

// ���ķ���ÿһ��������Ҫһ��NonterminalExpression
// �ķ���ÿ�����Ŷ�ά��һ��AbstractExpression���͵�ʵ������
// Ϊ�ķ��ķ��ս��ʵ�ֽ��Ͳ���������һ����Ҫ�ݹ�ص��ñ�ʾ�ķ�����Щ����Ľ��Ͳ���
class NonterminalExpression :
    public AbstractExpression
{
public:
    virtual void Interpret() override
    {
        throw std::logic_error("The method or operation is not implemented.");
    }
};

// ����������֮���һЩȫ����Ϣ
class Context {};

int main(int argc, char *argv[])
{
    return 0;
}