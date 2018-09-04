/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-4
 *
 * @brief	Ϊ��ϵͳ�е�һ��ӿ��ṩһ��һֱ�Ľ��棬Facadeģʽ������һ���߲�ӿڣ�
 *  ��һ�ӿ�ʹ��ϵͳ������ʹ��
**/

#include <iostream>
#include <memory>

// ʵ����ϵͳ�Ĺ���
// ������Facade����ָ�ɵ�����
// û��Facade���κ������Ϣ����������Facade���κ����û�ָ��
class SubSystem1
{
public:
    void OperationA()
    {
        std::cout << "SubSystem1::OperationA." << std::endl;
    }
    void OperationB()
    {
        std::cout << "SubSystem1::OperationB." << std::endl;
    }
};
class SubSystem2
{
public:
    void OperationA()
    {
        std::cout << "SubSystem2::OperationA." << std::endl;
    }
};

// ֪����Щ��ϵͳ�ฺ��������
// ���ͻ������������ʵ�����ϵͳ����
class Facade
{
public:
    Facade(std::shared_ptr<SubSystem1> sub1,
        std::shared_ptr<SubSystem2> sub2) :
        sub1_(sub1), sub2_(sub2)
    {
    }
    void Operation()
    {
        sub1_->OperationA();
        sub2_->OperationA();
        sub1_->OperationB();
    }
private:
    std::shared_ptr<SubSystem1> sub1_;
    std::shared_ptr<SubSystem2> sub2_;
};

int main(int argc, char *argv[])
{
    Facade facade(std::make_shared<SubSystem1>(), std::make_shared<SubSystem2>());
    facade.Operation();

    system("pause");
    return 0;
}