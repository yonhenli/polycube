/**
* firewall API
* firewall API generated from firewall.yang
*
* OpenAPI spec version: 1.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */



#include "PortsJsonObject.h"
#include <regex>

namespace io {
namespace swagger {
namespace server {
namespace model {

PortsJsonObject::PortsJsonObject() {
  m_nameIsSet = false;
}

PortsJsonObject::PortsJsonObject(const nlohmann::json &val) :
  JsonObjectBase(val) {
  m_nameIsSet = false;


  if (val.count("name")) {
    setName(val.at("name").get<std::string>());
  }
}

nlohmann::json PortsJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();
  if (!getBase().is_null()) {
    val.update(getBase());
  }

  if (m_nameIsSet) {
    val["name"] = m_name;
  }

  return val;
}

std::string PortsJsonObject::getName() const {
  return m_name;
}

void PortsJsonObject::setName(std::string value) {
  m_name = value;
  m_nameIsSet = true;
}

bool PortsJsonObject::nameIsSet() const {
  return m_nameIsSet;
}




}
}
}
}

