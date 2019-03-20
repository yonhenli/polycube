/**
* simplebridge API
* simplebridge API generated from simplebridge.yang
*
* OpenAPI spec version: 1.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


// These methods have a default implementation. Your are free to keep it or add your own


#include "../Simplebridge.h"

std::shared_ptr<Ports> Simplebridge::getPorts(const std::string &name){
  return Ports::getEntry(*this, name);
}

std::vector<std::shared_ptr<Ports>> Simplebridge::getPortsList(){
  return Ports::get(*this);
}

void Simplebridge::addPorts(const std::string &name, const PortsJsonObject &conf){
  Ports::create(*this, name, conf);
}

void Simplebridge::addPortsList(const std::vector<PortsJsonObject> &conf){
  for(auto &i : conf){
    std::string name_ = i.getName();
    Ports::create(*this, name_,  i);
  }
}

void Simplebridge::replacePorts(const std::string &name, const PortsJsonObject &conf){
  Ports::removeEntry(*this, name);
  std::string name_ = conf.getName();
  Ports::create(*this, name_, conf);

}

void Simplebridge::delPorts(const std::string &name){
  Ports::removeEntry(*this, name);
}

void Simplebridge::delPortsList(){
  Ports::remove(*this);
}

std::shared_ptr<Fdb> Simplebridge::getFdb(){
  return Fdb::getEntry(*this);
}

void Simplebridge::addFdb(const FdbJsonObject &value){
  Fdb::create(*this, value);
}

void Simplebridge::replaceFdb(const FdbJsonObject &conf){
  Fdb::removeEntry(*this);
  Fdb::create(*this, conf);
}

void Simplebridge::delFdb(){
  Fdb::removeEntry(*this);
}




