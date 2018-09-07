/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-7
 *
 * @brief	����һ�����������ڲ�״̬�ı�ʱ�ı�������Ϊ�����������ƺ��޸���������
**/

#include <iostream>
#include <memory>

// ����һ���ӿ��Է�װ��Context��һ���ض�״̬��ص���Ϊ
class State
{
public:
    virtual void Handle() = 0;
};

// ����ͻ�����Ȥ�Ľӿ�
// ά��һ��ConcreteState�����ʵ�������ʵ�����嵱ǰ״̬
class Context
{
public:
    void Request()
    {
        state_->Handle();           // ʵ��ʵ��������State�����ʵ��
    }
private:
    std::shared_ptr<State> state_;  // ͨ���ı�State���ı���Ϊ
};

// ÿһ������ʵ��һ��Context��һ��״̬��ص���Ϊ
class ConcreteStateA :
    public State
{
public:
    // ͨ�� State �̳�
    virtual void Handle() override
    {
        std::cout << "ConcreteStateA::Handle." << std::endl;
    }
};
// ÿһ������ʵ��һ��Context��һ��״̬��ص���Ϊ
class ConcreteStateB :
    public State
{
public:
    // ͨ�� State �̳�
    virtual void Handle() override
    {
        std::cout << "ConcreteStateB::Handle." << std::endl;
    }
};

int main(int argc, char *argv[])
{
	
}