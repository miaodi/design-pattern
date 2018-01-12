#include <iostream>
#include <string>

class AbstractWheel
{
  public:
    AbstractWheel() = default;
    int get() const;
    void set(int);
    virtual ~AbstractWheel() = 0;

  private:
    int _size;
};

// Pure virtual destructor are legal in standard C++ and one of the most
// important thing is that if class contains pure virtual destructor it is must
// to provide a function body for the pure virtual destructor.
AbstractWheel::~AbstractWheel() {}

int AbstractWheel::get() const { return _size; }

void AbstractWheel::set(int i) { _size = i; }

class JeepWheel : public AbstractWheel
{
  public:
    JeepWheel() { AbstractWheel::set(5); }
};

class MiniWheel : public AbstractWheel
{
  public:
    MiniWheel() { AbstractWheel::set(3); }
};

class AbstractBody
{
  public:
    std::string get() const;
    void set(std::string);
    virtual ~AbstractBody() = 0;

  private:
    std::string _color;
};

AbstractBody::~AbstractBody() {}

std::string AbstractBody::get() const { return _color; }

void AbstractBody::set(std::string color) { _color = color; }

class JeepBody : public AbstractBody
{
  public:
    JeepBody() { AbstractBody::set("Blue"); }
};

class MiniBody : public AbstractBody
{
  public:
    MiniBody() { AbstractBody::set("Yellow"); }
};

class AbstractFactory
{
  public:
    virtual AbstractWheel *MakeWheel() = 0;
    virtual AbstractBody *MakeBody() = 0;
};

class MiniFactory : public AbstractFactory
{
  public:
    AbstractWheel *MakeWheel();
    AbstractBody *MakeBody();
};

AbstractWheel *MiniFactory::MakeWheel() { return new MiniWheel(); }

AbstractBody *MiniFactory::MakeBody() { return new MiniBody(); }

class JeepFactory : public AbstractFactory
{
  public:
    AbstractWheel *MakeWheel();
    AbstractBody *MakeBody();
};

AbstractWheel *JeepFactory::MakeWheel() { return new JeepWheel(); }

AbstractBody *JeepFactory::MakeBody() { return new JeepBody(); }

// Final product
class Car
{
  public:
    AbstractBody *_body;
    AbstractWheel *_wheels[4];
    void GetInfo() const;
};

void Car::GetInfo() const
{
    for (int i = 0; i < 4; i++)
    {
        std::cout << i + 1 << ": " << _wheels[i]->get() << std::endl;
    }
    std::cout << _body->get() << std::endl;
}

class Director
{
  public:
    Director() = delete;
    Director(AbstractFactory *builder);
    Car *CreateCar();

  private:
    AbstractFactory *_builder;
};

Director::Director(AbstractFactory *builder) : _builder(builder) {}

Car *Director::CreateCar()
{
    auto car = new Car();
    car->_body = _builder->MakeBody();
    car->_wheels[0] = _builder->MakeWheel();
    car->_wheels[1] = _builder->MakeWheel();
    car->_wheels[2] = _builder->MakeWheel();
    car->_wheels[3] = _builder->MakeWheel();
    return car;
}

int main()
{
    Car *car1, *car2;
    car1 = Director(new MiniFactory()).CreateCar();
    car1->GetInfo();
    car2 = Director(new JeepFactory()).CreateCar();
    car2->GetInfo();
    return 0;
}
