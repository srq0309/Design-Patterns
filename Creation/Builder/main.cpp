/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-2
 *
 * @brief	生成器：将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示
**/

#include <iostream>
#include <string>
#include <memory>

// 表示被构造的复杂对象
// 包含定义组成部件的类，包括将这些部件装配成最终产品的接口
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

// 为创建一个Product对象的各个部件指定抽象接口
class Builder
{
    // 通常不将构建函数设置为纯虚函数，这样子类只构建它们各自关注的部分
public:
    virtual void BuildPart1() {}    // 构建第一部分
    virtual void BuildPart2() {}    // 构建第二部分

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

// 实现Builder接口以构造和装配产品的各个部分
// 定义并明确它所创建的表示
// 提供一个检索产品的接口
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

// 定义一个使用Builder接口的对象
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

// 客户创建DIrector对象，并用它所想要的Builder对象进行配置
// 生成器处理向导器的请求，并将部件添加到产品中
// 客户从生成器中检索产品
int main(int argc, char *argv[])
{
    std::shared_ptr<Builder> builderA = std::make_shared<ConcreteBuilderA>(),
        builderB = std::make_shared<ConcreteBuilderB>();
    Director director;

    // 产品1被构建器A创建
    director.Construct(builderA);
    auto p1 = builderA->GetResult();
    
    // 产品2被构建器B创建
    director.Construct(builderB);
    auto p2 = builderB->GetResult();

    p1->Show();
    p2->Show();

    system("pause");
    return 0;
}