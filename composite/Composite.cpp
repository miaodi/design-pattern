#include <iostream>
#include <string>
#include <vector>
#include <array>

class Component
{
  public:
    virtual void traverse() = 0;
};

class Leaf : public Component
{
  public:
    Leaf(const std::string &val) : mVal{val} {}
    void SetVal(const std::string &val)
    {
        mVal = val;
    }

    void traverse() override
    {
        std::cout << mVal << std::endl;
    }

  private:
    std::string mVal;
};

class Composite : public Component
{
  public:
    void Add(std::unique_ptr<Component> &&x)
    {
        mContent.push_back(std::move(x));
    }
    void traverse() override
    {
        for (const auto &i : mContent)
        {
            i->traverse();
        }
    }

  private:
    std::vector<std::unique_ptr<Component>> mContent;
};
int main()
{
    std::array<std::unique_ptr<Composite>, 4> containers;
    for (int i = 0; i < 4; i++)
    {
        containers[i] = std::make_unique<Composite>();
        for (int j = 0; j < 3; j++)
        {
            containers[i]->Add(std::make_unique<Leaf>(std::to_string(i * 3 + j)));
        }
    }


    for (int i = 1; i < 4; i++)
        containers[0]->Add(std::move(containers[i]));
    containers[0]->traverse();
    return 0;
}
