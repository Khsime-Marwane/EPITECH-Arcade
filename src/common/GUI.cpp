#include "GUI.hh"

arcade::GUI::GUI() : _components()
{
}

arcade::GUI::~GUI()
{
}

std::size_t arcade::GUI::size() const
{
  return (this->_components.size());
}

arcade::IComponent  &arcade::GUI::at(std::size_t n)
{
  return (*this->_components[n]);
}

void  arcade::GUI::addComponent(std::unique_ptr<Component> component)
{
  this->_components.push_back(std::move(component));
}

arcade::Component  &arcade::GUI::getComponent(std::size_t n)
{
  return (*this->_components[n]);
}
