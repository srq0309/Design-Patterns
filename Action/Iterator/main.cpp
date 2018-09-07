/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-6
 *
 * @brief	������ģʽ���ṩһ�ַ���˳�����һ�����϶����еĸ���Ԫ�أ����ֲ���¶�ö�����ڲ���ʾ
**/

#include <iostream>
#include <memory>

// ������������ʺͱ���Ԫ�صĽӿ�
template<typename _Ty>
class Iterator
{
public:
    virtual std::shared_ptr<Iterator> First() = 0;
    virtual std::shared_ptr<Iterator> Next() = 0;
    virtual bool IsDone() = 0;
    virtual _Ty CurrentItem() = 0;
};

// �ۺ϶��崴����Ӧ�������Ľӿ�
template<typename _Ty>
class Aggregate
{
public:
    virtual std::shared_ptr<Iterator<_Ty>> CreateIterator() = 0;
};

// ����ۺ�ʵ�ִ�����Ӧ�������Ľӿڣ��ò�������ConcreteIterator��һ���ʵ���ʵ��
template<typename _Ty>
class ConcreteAggregate:
    public Aggregate<_Ty>
{
};

// ���������ʵ�ֵ������ӿ�
// �Ըþۺϱ���ʱʱ���ٵ�ǰλ��
template<typename _Ty>
class ConcreteIterator :
    public Iterator<_Ty>
{
};

int main(int argc, char *argv[])
{
	
}