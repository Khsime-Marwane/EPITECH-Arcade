#include "Component.hh"
#include "IGUI.hh"

namespace arcade
{
  class GUI : public IGUI
  {
    std::vector<std::unique_ptr<Component>>  _components;

  public:
    GUI();
    virtual ~GUI();

    virtual std::size_t size() const;
    virtual IComponent &at(std::size_t n);

    void  addComponent(std::unique_ptr<Component>);
    Component &getComponent(std::size_t n);
  };
}
