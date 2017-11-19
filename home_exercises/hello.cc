#include <iostream>
#include <string>

class HelloClass
{
  public:
    HelloClass()
    {
      name = "World";
    }
    void setHello(std::string x)
    {
      hello = x;
    }
    void setName(std::string x)
    {
      name = x;
    }
    std::string getHello()
    {
      return hello;
    }
    std::string getName()
    {
      return name;
    };
    std::string getMessage()
    {
      return hello + " " + name + "!";
    }
    void printMessage()
    {
      std::cout << getMessage() << std::endl;
    }
  private:
    std::string hello;
    std::string name;

};

int main()
{
  HelloClass hc;
  hc.setHello("Hello");
  std::cout << hc.getHello() + " " + hc.getName() + "!" << std::endl;
  std::cout << hc.getMessage() << std::endl;
  hc.setName("Javier");
  hc.printMessage();
  return 0;
}
