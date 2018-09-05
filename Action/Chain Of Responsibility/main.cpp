/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-5
 *
 * @brief	ʹ��������л��ᴦ�����󣬴Ӷ���������ķ����ߺͽ�����֮�����Ϲ�ϵ��
 *  ����Щ��������һ���������������������ݸ�����ֱ����һ����������Ϊֹ
**/

#include <iostream>
#include <memory>
#include <string>

// ����һ����������Ľӿ�
// ����ѡ��ʵ�ֺ����
class Handler
{
public:
    virtual void HandleRequest(const std::string& key) = 0;
    void SetSuccessor(std::shared_ptr<Handler> successor)
    {
        successor_ = successor;
    }
protected:
    std::shared_ptr<Handler> successor_;
};

// �����������������
// �ɷ������ĺ����
// ������Դ������������֮�����򽫸�����ת�������ĺ����
class ConcreteHandlerA :
    public Handler
{
public:
    virtual void HandleRequest(const std::string& key) override
    {
        if (key == "A") {
            std::cout << "ConcreteHandlerA::HandleRequest." << std::endl;
        } else if (successor_) {
            successor_->HandleRequest(key);
        }
    }
};
class ConcreteHandlerB :
    public Handler
{
public:
    virtual void HandleRequest(const std::string& key) override
    {
        if (key == "B") {
            std::cout << "ConcreteHandlerB::HandleRequest." << std::endl;
        } else if (successor_) {
            successor_->HandleRequest(key);
        }
    }
};

int main(int argc, char *argv[])
{
    std::shared_ptr<Handler> h1 = std::make_shared<ConcreteHandlerA>(),
        h2 = std::make_shared<ConcreteHandlerB>();
    h1->SetSuccessor(h2);

    h1->HandleRequest("A");
    h1->HandleRequest("B");
    h1->HandleRequest("C");

    system("pause");
    return 0;
}