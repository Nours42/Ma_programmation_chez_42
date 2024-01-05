#include "Warlock.hpp"

int main()
{
Warlock const richard("Richard", "Mistress of Magma");
Warlock* jack = new Warlock("Jack", "the Long");

richard.introduce();
std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

jack->introduce();
std::cout << jack->getName() << " - " << jack->getTitle() << std::endl;
jack->setTitle("the Mighty");

jack->introduce();

richard.introduce();

delete jack;

return (0);
}