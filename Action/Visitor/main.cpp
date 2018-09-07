/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-7
 *
 * @brief	��ʾһ��������ĳ����ṹ�еĸ���Ԫ�صĲ�����
 *  ��ʹ��������ڲ��ı����Ԫ�ص����ǰ���¶�����������ЩԪ�ص��²�����
**/

#include <iostream>
#include <memory>

class ConcreteElementA;
class ConcreteElementB;

// Ϊ����ṹ�е�ConcreteElement��ÿһ��������һ��Visit�������ò��������ֺ�������ʶ�˷���Visit������÷��ʵ��Ǹ��࣬
// ��ʹ�÷����߿���ȷ����������Ԫ�صľ�����࣬���������߾Ϳ���ͨ����Ԫ�ص��ض��ӿ�ֱ�ӷ�����
class Visitor
{
public:
    virtual void VisitConcreteElementA(std::shared_ptr<ConcreteElementA> element) = 0;
    virtual void VisitConcreteElementB(std::shared_ptr<ConcreteElementB> element) = 0;
};

// ����һ��Accept����������һ��������Ϊ����
class Element
{
public:
    void virtual Accept(std::shared_ptr<Visitor> visitor) = 0;
};

// ʵ��Accept�������ò�������һ��������Ϊ����
class ConcreteElementA :
    public Element, public std::enable_shared_from_this<ConcreteElementA>
{
public:
    // ͨ�� Element �̳�
    virtual void Accept(std::shared_ptr<Visitor> visitor) override
    {
        visitor->VisitConcreteElementA(shared_from_this());
    }
};

// ʵ��Accept�������ò�������һ��������Ϊ����
class ConcreteElementB :
    public Element, public std::enable_shared_from_this<ConcreteElementB>
{
public:
    // ͨ�� Element �̳�
    virtual void Accept(std::shared_ptr<Visitor> visitor) override
    {
        visitor->VisitConcreteElementB(shared_from_this());
    }
};

// ʵ��ÿ��Visit�����Ĳ�����ÿ������ʵ�ֻ����㷨��һ���֣����㷨Ƭ�����Ƕ�����ṹ�ж�����࣬
// ConcreteVisiterΪ���㷨�ṩ�������Ĳ��洢���ľֲ�״̬
// ��һ״̬�����ڱ����ýṹ�Ĺ������ۼƽ��
class ConcreteVisitor :
    public Visitor
{
public:
    // ͨ�� Visitor �̳�
    virtual void VisitConcreteElementA(std::shared_ptr<ConcreteElementA> element) override
    {   // ʵ�����������Ԫ��
    }
    virtual void VisitConcreteElementB(std::shared_ptr<ConcreteElementB> element) override
    {
    }
};

int main(int argc, char *argv[])
{
}