/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-7
 *
 * @brief	�۲���ģʽ�����������һ��һ�Զ�Ĺ�ϵ����һ�������״̬�����仯ʱ���������������Ķ��󶼵õ�֪ͨ�������仯
**/

#include <iostream>
#include <memory>
#include <string>
#include <set>

// Ϊ��Щ��Ŀ�귢���ı�ʱ���ȡ֪ͨ�Ķ�����һ�����½ӿ�
class Observer
{
public:
    virtual void Update() = 0;
};

// Ŀ��֪�����Ĺ۲��ߣ��������������۲��߹۲�ͬһĿ��
// �ṩע���ɾ���۲��߶���Ľӿ�
class Subject
{
public:
    virtual void Attach(std::shared_ptr<Observer> observer)
    {
        observers_.insert(observer);
    }
    virtual void Dettach(std::shared_ptr<Observer> observer)
    {
        observers_.erase(observer);
    }
    virtual void Notify()
    {
        for (auto iter = observers_.begin(); iter != observers_.end(); ++iter) {
            (*iter)->Update();
        }
    }
private:
    std::set<std::shared_ptr<Observer>> observers_;
};

// ���й�״̬�����ConcreteObserver����
// ������״̬�����ı�ʱ�������ĸ����۲��߷���֪ͨ
class ConcreteSubject :
    public Subject
{
public:
    std::string GetState() { return state_; }
    void SetState(std::string state)
    {
        state_ = state;
        Notify();   // ֪ͨ�۲��߸ı�״̬
    }
private:
    std::string state_;
};

// ά��һ��ָ��ConcreteSubject���������
// �洢�й�״̬����Щ״̬Ӧ��Ŀ��״̬����һ��

class ConcreteObserver :
    public Observer
{
public:
    ConcreteObserver(std::shared_ptr<ConcreteSubject> subject) :
        subject_(subject)
    {
    }
    // ͨ�� Observer �̳�
    virtual void Update() override
    {
        data_ = subject_->GetState();
    }
private:
    std::shared_ptr<ConcreteSubject> subject_;
    std::string data_;
};

int main(int argc, char *argv[])
{
    
}