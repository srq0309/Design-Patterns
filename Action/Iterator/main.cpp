/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-6
 *
 * @brief	迭代器模式：提供一种方法顺序访问一个集合对象中的各个元素，而又不暴露该对象的内部表示
**/

#include <iostream>
#include <memory>

// 迭代器定义访问和遍历元素的接口
template<typename _Ty>
class Iterator
{
public:
    virtual std::shared_ptr<Iterator> First() = 0;
    virtual std::shared_ptr<Iterator> Next() = 0;
    virtual bool IsDone() = 0;
    virtual _Ty CurrentItem() = 0;
};

// 聚合定义创建相应迭代器的接口
template<typename _Ty>
class Aggregate
{
public:
    virtual std::shared_ptr<Iterator<_Ty>> CreateIterator() = 0;
};

// 具体聚合实现创建相应迭代器的接口，该操作返回ConcreteIterator的一个适当的实例
template<typename _Ty>
class ConcreteAggregate:
    public Aggregate<_Ty>
{
};

// 具体迭代器实现迭代器接口
// 对该聚合遍历时时跟踪当前位置
template<typename _Ty>
class ConcreteIterator :
    public Iterator<_Ty>
{
};

int main(int argc, char *argv[])
{
	
}