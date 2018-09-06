/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-6
 *
 * @brief	�ڲ��ƻ���װ��ǰ���£�����һ��������ڲ�״̬�����ڸö���֮�Ᵽ�����״̬��
 *  �����Ժ�Ϳ��Խ��ö���ָ�����ǰ��״̬��
**/

#include <iostream>
#include <string>
#include <memory>
#include <deque>

// ����¼�洢ԭ����������ڲ�״̬��ԭ����������Ҫ��������¼�洢ԭ��������Щ״̬
// ��ֹԭ��������Ķ�����ʱ���¼������״̬��ֻ�������ɱ���¼��ԭ����������ʱ�����¼���ڲ�״̬��
class Memento
{
public:
    std::string GetState()
    {
        return state_;
    }
    void SetState(std::string state)
    {
        state_ = state;
    }
private:
    std::string state_;
};

// ԭ��������һ������¼�����Լ�¼��ǰ��״̬
// ʹ�ñ���¼�ָ���ǰ�Ķ���
class Originator
{
public:
    void SetMemento(std::shared_ptr<Memento> memento)
    {
        state_ = memento->GetState();
    }
    std::shared_ptr<Memento> CreateMemento()
    {
        return std::make_shared<Memento>();
    }
private:
    std::string state_;
};

// ���𱣴�ñ���¼
// ���ܶԱ���¼�����ݽ��в�������
class Caretaker
{
public:
private:
    std::deque<std::shared_ptr<Memento>> mementos_;
};

int main(int argc, char *argv[])
{
	
}