/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-4
 *
 * @brief	����ģʽ��Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ���
**/

/*!
 * �ж��ַ�ʽʵ�ִ�������ֱ���ö�̬���ƺ�c++���������ʵ��
 */

#include <memory>
#include <iostream>

 // ����RealSubject��Porxy�Ĺ����ӿڣ����������κ�ʱ��ʹ��RealSubject�ĵط�ʹ��Proxy
class Subject
{
public:
    virtual void Operation()
    {
        std::cout << "Subject::Operation." << std::endl;
    }
};

// ����Proxy�������ʵ��
class RealSubject :
    public Subject
{
public:
    virtual void Operation() override
    {
        std::cout << "RealSubject::Operation." << std::endl;
    }
};

// ����һ������ʹ�ô�����Է���ʬ��
// �ṩһ����Subject�Ľӿ���ͬ�Ľӿڣ��������������������ʵ��
// ���ƶ�ʵ��Ĵ�ȡ�������ܸ��𴴽���ɾ����
// �������������ڴ��������
class Proxy :
    public Subject
{
public:
    Proxy(std::shared_ptr<Subject> subject) :
        subject_(subject)
    {
    }
    virtual void Operation() override
    {
        subject_->Operation();
    }
private:
    std::shared_ptr<Subject> subject_;
};

// ���������*��->
class RealSubjectPtr
{
public:
    RealSubjectPtr(Subject *subject) :
        subject_(subject)
    {
    }
    Subject* operator->()
    {
        return subject_;
    }
    Subject& operator*()
    {
        return *subject_;
    }
private:
    Subject *subject_;
};

int main(int argc, char *argv[])
{
    auto realsubject = std::make_shared<RealSubject>();
    Proxy proxy(realsubject);

    RealSubjectPtr ps(realsubject.get());
    ps->Operation();

    proxy.Operation();

    system("pause");
    return 0;
}   