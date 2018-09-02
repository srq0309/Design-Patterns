/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-2
 *
 * @brief	����������һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ
**/

#include <iostream>
#include <string>
#include <memory>

// ��ʾ������ĸ��Ӷ���
// ����������ɲ������࣬��������Щ����װ������ղ�Ʒ�Ľӿ�
class Product
{
public:
    std::string part1;
    std::string part2;

    void Show()
    {
        std::cout << "part1: " << part1 << ", part2: " << part2 << std::endl;
    }
};

// Ϊ����һ��Product����ĸ�������ָ������ӿ�
class Builder
{
    // ͨ������������������Ϊ���麯������������ֻ�������Ǹ��Թ�ע�Ĳ���
public:
    virtual void BuildPart1() {}    // ������һ����
    virtual void BuildPart2() {}    // �����ڶ�����

    virtual void InitBuilder()
    {
        product_ = std::make_shared<Product>();
    }
    virtual std::shared_ptr<Product> GetResult()
    {
        return product_;
    }
protected:
    std::shared_ptr<Product> product_;
};

// ʵ��Builder�ӿ��Թ����װ���Ʒ�ĸ�������
// ���岢��ȷ���������ı�ʾ
// �ṩһ��������Ʒ�Ľӿ�
class ConcreteBuilderA :
    public Builder
{
public:
    virtual void BuildPart1() override
    {
        product_->part1 = "Part 1, by ConcreteBuilder A";
    }

    virtual void BuildPart2() override
    {
        product_->part2 = "Part 2, by ConcreteBuilder A";
    }
};

// Builder B
class ConcreteBuilderB :
    public Builder
{
public:
    virtual void BuildPart1() override
    {
        product_->part1 = "Part 1, by ConcreteBuilder B";
    }

    virtual void BuildPart2() override
    {
        product_->part2 = "Part 2, by ConcreteBuilder B";
    }
};

// ����һ��ʹ��Builder�ӿڵĶ���
class Director
{
public:
    void Construct(std::shared_ptr<Builder> builder)
    {
        builder->InitBuilder();
        builder->BuildPart1();
        builder->BuildPart2();
    }
};

// �ͻ�����DIrector���󣬲���������Ҫ��Builder�����������
// �������������������󣬲���������ӵ���Ʒ��
// �ͻ����������м�����Ʒ
int main(int argc, char *argv[])
{
    std::shared_ptr<Builder> builderA = std::make_shared<ConcreteBuilderA>(),
        builderB = std::make_shared<ConcreteBuilderB>();
    Director director;

    // ��Ʒ1��������A����
    director.Construct(builderA);
    auto p1 = builderA->GetResult();
    
    // ��Ʒ2��������B����
    director.Construct(builderB);
    auto p2 = builderB->GetResult();

    p1->Show();
    p2->Show();

    system("pause");
    return 0;
}