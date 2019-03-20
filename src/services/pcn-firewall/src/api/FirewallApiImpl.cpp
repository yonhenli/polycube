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


#include "FirewallApiImpl.h"

namespace io {
namespace swagger {
namespace server {
namespace api {

using namespace io::swagger::server::model;

namespace FirewallApiImpl {
namespace {
std::unordered_map<std::string, std::shared_ptr<Firewall>> cubes;
std::mutex cubes_mutex;

std::shared_ptr<Firewall> get_cube(const std::string &name) {
  std::lock_guard<std::mutex> guard(cubes_mutex);
  auto iter = cubes.find(name);
  if (iter == cubes.end()) {
    throw std::runtime_error("Cube " + name + " does not exist");
  }

  return iter->second;
}

}

void create_firewall_by_id(const std::string &name, const FirewallJsonObject &jsonObject) {
  {
    // check if name is valid before creating it
    std::lock_guard<std::mutex> guard(cubes_mutex);
    if (cubes.count(name) != 0) {
      throw std::runtime_error("There is already a cube with name " + name);
    }
  }
  auto ptr = std::make_shared<Firewall>(name, jsonObject);
  std::unordered_map<std::string, std::shared_ptr<Firewall>>::iterator iter;
  bool inserted;

  std::lock_guard<std::mutex> guard(cubes_mutex);
  std::tie(iter, inserted) = cubes.emplace(name, std::move(ptr));

  if (!inserted) {
    throw std::runtime_error("There is already a cube with name " + name);
  }
}

void replace_firewall_by_id(const std::string &name, const FirewallJsonObject &bridge){
  throw std::runtime_error("Method not supported!");
}

void delete_firewall_by_id(const std::string &name) {
  std::lock_guard<std::mutex> guard(cubes_mutex);
  if (cubes.count(name) == 0) {
    throw std::runtime_error("Cube " + name + " does not exist");
  }
  cubes.erase(name);
}

std::vector<FirewallJsonObject> read_firewall_list_by_id() {
  std::vector<FirewallJsonObject> jsonObject_vect;
  for(auto &i : cubes) {
    auto m = get_cube(i.first);
    jsonObject_vect.push_back(m->toJsonObject());
  }
  return jsonObject_vect;
}

std::vector<nlohmann::fifo_map<std::string, std::string>> read_firewall_list_by_id_get_list() {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  for (auto &x : cubes) {
    nlohmann::fifo_map<std::string, std::string> m;
    m["name"] = x.first;
    r.push_back(std::move(m));
  }
  return r;
}

/**
* @brief   Create append by ID
*
* Create operation of resource: append*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] value appendbody object
*
* Responses:
* ChainAppendOutputJsonObject
*/
ChainAppendOutputJsonObject
create_firewall_chain_append_by_id(const std::string &name, const ChainNameEnum &chainName, const ChainAppendInputJsonObject &value) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
return chain->append(value);

}

/**
* @brief   Create apply-rules by ID
*
* Create operation of resource: apply-rules*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
*
* Responses:
* ChainApplyRulesOutputJsonObject
*/
ChainApplyRulesOutputJsonObject
create_firewall_chain_apply_rules_by_id(const std::string &name, const ChainNameEnum &chainName) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
return chain->applyRules();

}

/**
* @brief   Create chain by ID
*
* Create operation of resource: chain*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] value chainbody object
*
* Responses:
*
*/
void
create_firewall_chain_by_id(const std::string &name, const ChainNameEnum &chainName, const ChainJsonObject &value) {
  auto firewall = get_cube(name);

  firewall->addChain(chainName, value);
}

/**
* @brief   Create chain by ID
*
* Create operation of resource: chain*
*
* @param[in] name ID of name
* @param[in] value chainbody object
*
* Responses:
*
*/
void
create_firewall_chain_list_by_id(const std::string &name, const std::vector<ChainJsonObject> &value) {
  auto firewall = get_cube(name);
  firewall->addChainList(value);
}

/**
* @brief   Create reset-counters by ID
*
* Create operation of resource: reset-counters*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
*
* Responses:
* ChainResetCountersOutputJsonObject
*/
ChainResetCountersOutputJsonObject
create_firewall_chain_reset_counters_by_id(const std::string &name, const ChainNameEnum &chainName) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
return chain->resetCounters();

}

/**
* @brief   Create rule by ID
*
* Create operation of resource: rule*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
* @param[in] value rulebody object
*
* Responses:
*
*/
void
create_firewall_chain_rule_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id, const ChainRuleJsonObject &value) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);

  chain->addRule(id, value);
}

/**
* @brief   Create rule by ID
*
* Create operation of resource: rule*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] value rulebody object
*
* Responses:
*
*/
void
create_firewall_chain_rule_list_by_id(const std::string &name, const ChainNameEnum &chainName, const std::vector<ChainRuleJsonObject> &value) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  chain->addRuleList(value);
}

/**
* @brief   Create ports by ID
*
* Create operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
create_firewall_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value) {
  auto firewall = get_cube(name);

  firewall->addPorts(portsName, value);
}

/**
* @brief   Create ports by ID
*
* Create operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
create_firewall_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value) {
  auto firewall = get_cube(name);
  firewall->addPortsList(value);
}

/**
* @brief   Delete chain by ID
*
* Delete operation of resource: chain*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
*
* Responses:
*
*/
void
delete_firewall_chain_by_id(const std::string &name, const ChainNameEnum &chainName) {
  auto firewall = get_cube(name);

  firewall->delChain(chainName);
}

/**
* @brief   Delete chain by ID
*
* Delete operation of resource: chain*
*
* @param[in] name ID of name
*
* Responses:
*
*/
void
delete_firewall_chain_list_by_id(const std::string &name) {
  auto firewall = get_cube(name);
  firewall->delChainList();
}

/**
* @brief   Delete rule by ID
*
* Delete operation of resource: rule*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
*
*/
void
delete_firewall_chain_rule_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);

  chain->delRule(id);
}

/**
* @brief   Delete rule by ID
*
* Delete operation of resource: rule*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
*
* Responses:
*
*/
void
delete_firewall_chain_rule_list_by_id(const std::string &name, const ChainNameEnum &chainName) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  chain->delRuleList();
}

/**
* @brief   Delete ports by ID
*
* Delete operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
*
* Responses:
*
*/
void
delete_firewall_ports_by_id(const std::string &name, const std::string &portsName) {
  auto firewall = get_cube(name);

  firewall->delPorts(portsName);
}

/**
* @brief   Delete ports by ID
*
* Delete operation of resource: ports*
*
* @param[in] name ID of name
*
* Responses:
*
*/
void
delete_firewall_ports_list_by_id(const std::string &name) {
  auto firewall = get_cube(name);
  firewall->delPortsList();
}

/**
* @brief   Read accept-established by ID
*
* Read operation of resource: accept-established*
*
* @param[in] name ID of name
*
* Responses:
* FirewallAcceptEstablishedEnum
*/
FirewallAcceptEstablishedEnum
read_firewall_accept_established_by_id(const std::string &name) {
  auto firewall = get_cube(name);
  return firewall->getAcceptEstablished();

}

/**
* @brief   Read firewall by ID
*
* Read operation of resource: firewall*
*
* @param[in] name ID of name
*
* Responses:
* FirewallJsonObject
*/
FirewallJsonObject
read_firewall_by_id(const std::string &name) {
  return get_cube(name)->toJsonObject();

}

/**
* @brief   Read chain by ID
*
* Read operation of resource: chain*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
*
* Responses:
* ChainJsonObject
*/
ChainJsonObject
read_firewall_chain_by_id(const std::string &name, const ChainNameEnum &chainName) {
  auto firewall = get_cube(name);
  return firewall->getChain(chainName)->toJsonObject();

}

/**
* @brief   Read default by ID
*
* Read operation of resource: default*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
*
* Responses:
* ActionEnum
*/
ActionEnum
read_firewall_chain_default_by_id(const std::string &name, const ChainNameEnum &chainName) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  return chain->getDefault();

}

/**
* @brief   Read chain by ID
*
* Read operation of resource: chain*
*
* @param[in] name ID of name
*
* Responses:
* std::vector<ChainJsonObject>
*/
std::vector<ChainJsonObject>
read_firewall_chain_list_by_id(const std::string &name) {
  auto firewall = get_cube(name);
  auto &&chain = firewall->getChainList();
  std::vector<ChainJsonObject> m;
  for(auto &i : chain)
    m.push_back(i->toJsonObject());
  return m;
}

/**
* @brief   Read action by ID
*
* Read operation of resource: action*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* ActionEnum
*/
ActionEnum
read_firewall_chain_rule_action_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto rule = chain->getRule(id);
  return rule->getAction();

}

/**
* @brief   Read rule by ID
*
* Read operation of resource: rule*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* ChainRuleJsonObject
*/
ChainRuleJsonObject
read_firewall_chain_rule_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  return chain->getRule(id)->toJsonObject();

}

/**
* @brief   Read conntrack by ID
*
* Read operation of resource: conntrack*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* ConntrackstatusEnum
*/
ConntrackstatusEnum
read_firewall_chain_rule_conntrack_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto rule = chain->getRule(id);
  return rule->getConntrack();

}

/**
* @brief   Read description by ID
*
* Read operation of resource: description*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* std::string
*/
std::string
read_firewall_chain_rule_description_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto rule = chain->getRule(id);
  return rule->getDescription();

}

/**
* @brief   Read dport by ID
*
* Read operation of resource: dport*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* uint16_t
*/
uint16_t
read_firewall_chain_rule_dport_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto rule = chain->getRule(id);
  return rule->getDport();

}

/**
* @brief   Read dst by ID
*
* Read operation of resource: dst*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* std::string
*/
std::string
read_firewall_chain_rule_dst_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto rule = chain->getRule(id);
  return rule->getDst();

}

/**
* @brief   Read l4proto by ID
*
* Read operation of resource: l4proto*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* std::string
*/
std::string
read_firewall_chain_rule_l4proto_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto rule = chain->getRule(id);
  return rule->getL4proto();

}

/**
* @brief   Read rule by ID
*
* Read operation of resource: rule*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
*
* Responses:
* std::vector<ChainRuleJsonObject>
*/
std::vector<ChainRuleJsonObject>
read_firewall_chain_rule_list_by_id(const std::string &name, const ChainNameEnum &chainName) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto &&rule = chain->getRuleList();
  std::vector<ChainRuleJsonObject> m;
  for(auto &i : rule)
    m.push_back(i->toJsonObject());
  return m;
}

/**
* @brief   Read sport by ID
*
* Read operation of resource: sport*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* uint16_t
*/
uint16_t
read_firewall_chain_rule_sport_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto rule = chain->getRule(id);
  return rule->getSport();

}

/**
* @brief   Read src by ID
*
* Read operation of resource: src*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* std::string
*/
std::string
read_firewall_chain_rule_src_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto rule = chain->getRule(id);
  return rule->getSrc();

}

/**
* @brief   Read tcpflags by ID
*
* Read operation of resource: tcpflags*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* std::string
*/
std::string
read_firewall_chain_rule_tcpflags_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto rule = chain->getRule(id);
  return rule->getTcpflags();

}

/**
* @brief   Read action by ID
*
* Read operation of resource: action*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* ActionEnum
*/
ActionEnum
read_firewall_chain_stats_action_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto stats = chain->getStats(id);
  return stats->getAction();

}

/**
* @brief   Read stats by ID
*
* Read operation of resource: stats*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* ChainStatsJsonObject
*/
ChainStatsJsonObject
read_firewall_chain_stats_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  return chain->getStats(id)->toJsonObject();

}

/**
* @brief   Read bytes by ID
*
* Read operation of resource: bytes*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* uint64_t
*/
uint64_t
read_firewall_chain_stats_bytes_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto stats = chain->getStats(id);
  return stats->getBytes();

}

/**
* @brief   Read conntrack by ID
*
* Read operation of resource: conntrack*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* ConntrackstatusEnum
*/
ConntrackstatusEnum
read_firewall_chain_stats_conntrack_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto stats = chain->getStats(id);
  return stats->getConntrack();

}

/**
* @brief   Read description by ID
*
* Read operation of resource: description*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* std::string
*/
std::string
read_firewall_chain_stats_description_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto stats = chain->getStats(id);
  return stats->getDescription();

}

/**
* @brief   Read dport by ID
*
* Read operation of resource: dport*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* uint16_t
*/
uint16_t
read_firewall_chain_stats_dport_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto stats = chain->getStats(id);
  return stats->getDport();

}

/**
* @brief   Read dst by ID
*
* Read operation of resource: dst*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* std::string
*/
std::string
read_firewall_chain_stats_dst_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto stats = chain->getStats(id);
  return stats->getDst();

}

/**
* @brief   Read l4proto by ID
*
* Read operation of resource: l4proto*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* std::string
*/
std::string
read_firewall_chain_stats_l4proto_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto stats = chain->getStats(id);
  return stats->getL4proto();

}

/**
* @brief   Read stats by ID
*
* Read operation of resource: stats*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
*
* Responses:
* std::vector<ChainStatsJsonObject>
*/
std::vector<ChainStatsJsonObject>
read_firewall_chain_stats_list_by_id(const std::string &name, const ChainNameEnum &chainName) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto &&stats = chain->getStatsList();
  std::vector<ChainStatsJsonObject> m;
  for(auto &i : stats)
    m.push_back(i->toJsonObject());
  return m;
}

/**
* @brief   Read pkts by ID
*
* Read operation of resource: pkts*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* uint64_t
*/
uint64_t
read_firewall_chain_stats_pkts_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto stats = chain->getStats(id);
  return stats->getPkts();

}

/**
* @brief   Read sport by ID
*
* Read operation of resource: sport*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* uint16_t
*/
uint16_t
read_firewall_chain_stats_sport_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto stats = chain->getStats(id);
  return stats->getSport();

}

/**
* @brief   Read src by ID
*
* Read operation of resource: src*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* std::string
*/
std::string
read_firewall_chain_stats_src_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto stats = chain->getStats(id);
  return stats->getSrc();

}

/**
* @brief   Read tcpflags by ID
*
* Read operation of resource: tcpflags*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
*
* Responses:
* std::string
*/
std::string
read_firewall_chain_stats_tcpflags_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto stats = chain->getStats(id);
  return stats->getTcpflags();

}

/**
* @brief   Read conntrack by ID
*
* Read operation of resource: conntrack*
*
* @param[in] name ID of name
*
* Responses:
* FirewallConntrackEnum
*/
FirewallConntrackEnum
read_firewall_conntrack_by_id(const std::string &name) {
  auto firewall = get_cube(name);
  return firewall->getConntrack();

}

/**
* @brief   Read egress-port by ID
*
* Read operation of resource: egress-port*
*
* @param[in] name ID of name
*
* Responses:
* std::string
*/
std::string
read_firewall_egress_port_by_id(const std::string &name) {
  auto firewall = get_cube(name);
  return firewall->getEgressPort();

}

/**
* @brief   Read ingress-port by ID
*
* Read operation of resource: ingress-port*
*
* @param[in] name ID of name
*
* Responses:
* std::string
*/
std::string
read_firewall_ingress_port_by_id(const std::string &name) {
  auto firewall = get_cube(name);
  return firewall->getIngressPort();

}

/**
* @brief   Read interactive by ID
*
* Read operation of resource: interactive*
*
* @param[in] name ID of name
*
* Responses:
* bool
*/
bool
read_firewall_interactive_by_id(const std::string &name) {
  auto firewall = get_cube(name);
  return firewall->getInteractive();

}

/**
* @brief   Read ports by ID
*
* Read operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
*
* Responses:
* PortsJsonObject
*/
PortsJsonObject
read_firewall_ports_by_id(const std::string &name, const std::string &portsName) {
  auto firewall = get_cube(name);
  return firewall->getPorts(portsName)->toJsonObject();

}

/**
* @brief   Read ports by ID
*
* Read operation of resource: ports*
*
* @param[in] name ID of name
*
* Responses:
* std::vector<PortsJsonObject>
*/
std::vector<PortsJsonObject>
read_firewall_ports_list_by_id(const std::string &name) {
  auto firewall = get_cube(name);
  auto &&ports = firewall->getPortsList();
  std::vector<PortsJsonObject> m;
  for(auto &i : ports)
    m.push_back(i->toJsonObject());
  return m;
}

/**
* @brief   Read session-table by ID
*
* Read operation of resource: session-table*
*
* @param[in] name ID of name
* @param[in] src ID of src
* @param[in] dst ID of dst
* @param[in] l4proto ID of l4proto
* @param[in] sport ID of sport
* @param[in] dport ID of dport
*
* Responses:
* SessionTableJsonObject
*/
SessionTableJsonObject
read_firewall_session_table_by_id(const std::string &name, const std::string &src, const std::string &dst, const std::string &l4proto, const uint16_t &sport, const uint16_t &dport) {
  auto firewall = get_cube(name);
  return firewall->getSessionTable(src, dst, l4proto, sport, dport)->toJsonObject();

}

/**
* @brief   Read eta by ID
*
* Read operation of resource: eta*
*
* @param[in] name ID of name
* @param[in] src ID of src
* @param[in] dst ID of dst
* @param[in] l4proto ID of l4proto
* @param[in] sport ID of sport
* @param[in] dport ID of dport
*
* Responses:
* uint32_t
*/
uint32_t
read_firewall_session_table_eta_by_id(const std::string &name, const std::string &src, const std::string &dst, const std::string &l4proto, const uint16_t &sport, const uint16_t &dport) {
  auto firewall = get_cube(name);
  auto sessionTable = firewall->getSessionTable(src, dst, l4proto, sport, dport);
  return sessionTable->getEta();

}

/**
* @brief   Read session-table by ID
*
* Read operation of resource: session-table*
*
* @param[in] name ID of name
*
* Responses:
* std::vector<SessionTableJsonObject>
*/
std::vector<SessionTableJsonObject>
read_firewall_session_table_list_by_id(const std::string &name) {
  auto firewall = get_cube(name);
  auto &&sessionTable = firewall->getSessionTableList();
  std::vector<SessionTableJsonObject> m;
  for(auto &i : sessionTable)
    m.push_back(i->toJsonObject());
  return m;
}

/**
* @brief   Read state by ID
*
* Read operation of resource: state*
*
* @param[in] name ID of name
* @param[in] src ID of src
* @param[in] dst ID of dst
* @param[in] l4proto ID of l4proto
* @param[in] sport ID of sport
* @param[in] dport ID of dport
*
* Responses:
* std::string
*/
std::string
read_firewall_session_table_state_by_id(const std::string &name, const std::string &src, const std::string &dst, const std::string &l4proto, const uint16_t &sport, const uint16_t &dport) {
  auto firewall = get_cube(name);
  auto sessionTable = firewall->getSessionTable(src, dst, l4proto, sport, dport);
  return sessionTable->getState();

}

/**
* @brief   Replace chain by ID
*
* Replace operation of resource: chain*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] value chainbody object
*
* Responses:
*
*/
void
replace_firewall_chain_by_id(const std::string &name, const ChainNameEnum &chainName, const ChainJsonObject &value) {
  auto firewall = get_cube(name);

  firewall->replaceChain(chainName, value);
}

/**
* @brief   Replace chain by ID
*
* Replace operation of resource: chain*
*
* @param[in] name ID of name
* @param[in] value chainbody object
*
* Responses:
*
*/
void
replace_firewall_chain_list_by_id(const std::string &name, const std::vector<ChainJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Replace rule by ID
*
* Replace operation of resource: rule*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
* @param[in] value rulebody object
*
* Responses:
*
*/
void
replace_firewall_chain_rule_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id, const ChainRuleJsonObject &value) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);

  chain->replaceRule(id, value);
}

/**
* @brief   Replace rule by ID
*
* Replace operation of resource: rule*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] value rulebody object
*
* Responses:
*
*/
void
replace_firewall_chain_rule_list_by_id(const std::string &name, const ChainNameEnum &chainName, const std::vector<ChainRuleJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Replace ports by ID
*
* Replace operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
replace_firewall_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value) {
  auto firewall = get_cube(name);

  firewall->replacePorts(portsName, value);
}

/**
* @brief   Replace ports by ID
*
* Replace operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
replace_firewall_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Update accept-established by ID
*
* Update operation of resource: accept-established*
*
* @param[in] name ID of name
* @param[in] value If Connection Tracking is enabled, all packets belonging to ESTABLISHED connections will be forwarded automatically. Default is ON.
*
* Responses:
*
*/
void
update_firewall_accept_established_by_id(const std::string &name, const FirewallAcceptEstablishedEnum &value) {
  auto firewall = get_cube(name);

  firewall->setAcceptEstablished(value);
}

/**
* @brief   Update firewall by ID
*
* Update operation of resource: firewall*
*
* @param[in] name ID of name
* @param[in] value firewallbody object
*
* Responses:
*
*/
void
update_firewall_by_id(const std::string &name, const FirewallJsonObject &value) {
  auto firewall = get_cube(name);

  firewall->update(value);
}

/**
* @brief   Update chain by ID
*
* Update operation of resource: chain*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] value chainbody object
*
* Responses:
*
*/
void
update_firewall_chain_by_id(const std::string &name, const ChainNameEnum &chainName, const ChainJsonObject &value) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);

  chain->update(value);
}

/**
* @brief   Update default by ID
*
* Update operation of resource: default*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] value Default action if no rule matches in the ingress chain. Default is DROP.
*
* Responses:
*
*/
void
update_firewall_chain_default_by_id(const std::string &name, const ChainNameEnum &chainName, const ActionEnum &value) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);

  chain->setDefault(value);
}

/**
* @brief   Update chain by ID
*
* Update operation of resource: chain*
*
* @param[in] name ID of name
* @param[in] value chainbody object
*
* Responses:
*
*/
void
update_firewall_chain_list_by_id(const std::string &name, const std::vector<ChainJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Update rule by ID
*
* Update operation of resource: rule*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] id ID of id
* @param[in] value rulebody object
*
* Responses:
*
*/
void
update_firewall_chain_rule_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id, const ChainRuleJsonObject &value) {
  auto firewall = get_cube(name);
  auto chain = firewall->getChain(chainName);
  auto rule = chain->getRule(id);

  rule->update(value);
}

/**
* @brief   Update rule by ID
*
* Update operation of resource: rule*
*
* @param[in] name ID of name
* @param[in] chainName ID of chain_name
* @param[in] value rulebody object
*
* Responses:
*
*/
void
update_firewall_chain_rule_list_by_id(const std::string &name, const ChainNameEnum &chainName, const std::vector<ChainRuleJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Update conntrack by ID
*
* Update operation of resource: conntrack*
*
* @param[in] name ID of name
* @param[in] value Enables the Connection Tracking module. Mandatory if connection tracking rules are needed. Default is ON.
*
* Responses:
*
*/
void
update_firewall_conntrack_by_id(const std::string &name, const FirewallConntrackEnum &value) {
  auto firewall = get_cube(name);

  firewall->setConntrack(value);
}

/**
* @brief   Update egress-port by ID
*
* Update operation of resource: egress-port*
*
* @param[in] name ID of name
* @param[in] value Name for the egress port, from which arrives traffic processed by EGRESS chain (by default it&#39;s the second port of the cube)
*
* Responses:
*
*/
void
update_firewall_egress_port_by_id(const std::string &name, const std::string &value) {
  auto firewall = get_cube(name);

  firewall->setEgressPort(value);
}

/**
* @brief   Update ingress-port by ID
*
* Update operation of resource: ingress-port*
*
* @param[in] name ID of name
* @param[in] value Name for the ingress port, from which arrives traffic processed by INGRESS chain (by default it&#39;s the first port of the cube)
*
* Responses:
*
*/
void
update_firewall_ingress_port_by_id(const std::string &name, const std::string &value) {
  auto firewall = get_cube(name);

  firewall->setIngressPort(value);
}

/**
* @brief   Update interactive by ID
*
* Update operation of resource: interactive*
*
* @param[in] name ID of name
* @param[in] value Interactive mode applies new rules immediately; if &#39;false&#39;, the command &#39;apply-rules&#39; has to be used to apply all the rules at once. Default is TRUE.
*
* Responses:
*
*/
void
update_firewall_interactive_by_id(const std::string &name, const bool &value) {
  auto firewall = get_cube(name);

  firewall->setInteractive(value);
}

/**
* @brief   Update firewall by ID
*
* Update operation of resource: firewall*
*
* @param[in] value firewallbody object
*
* Responses:
*
*/
void
update_firewall_list_by_id(const std::vector<FirewallJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Update ports by ID
*
* Update operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
update_firewall_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value) {
  auto firewall = get_cube(name);
  auto ports = firewall->getPorts(portsName);

  ports->update(value);
}

/**
* @brief   Update ports by ID
*
* Update operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
update_firewall_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}



/*
 * help related
 */

std::vector<nlohmann::fifo_map<std::string, std::string>> read_firewall_chain_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&firewall = get_cube(name);

  auto &&chain = firewall->getChainList();
  for(auto &i : chain) {
    nlohmann::fifo_map<std::string, std::string> keys;

    keys["name"] = ChainJsonObject::ChainNameEnum_to_string(i->getName());

    r.push_back(keys);
  }
  return r;
}

std::vector<nlohmann::fifo_map<std::string, std::string>> read_firewall_chain_rule_list_by_id_get_list(const std::string &name, const ChainNameEnum &chainName) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&firewall = get_cube(name);
  auto &&chain = firewall->getChain(chainName);

  auto &&rule = chain->getRuleList();
  for(auto &i : rule) {
    nlohmann::fifo_map<std::string, std::string> keys;

    keys["id"] = std::to_string(i->getId());

    r.push_back(keys);
  }
  return r;
}

std::vector<nlohmann::fifo_map<std::string, std::string>> read_firewall_chain_stats_list_by_id_get_list(const std::string &name, const ChainNameEnum &chainName) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&firewall = get_cube(name);
  auto &&chain = firewall->getChain(chainName);

  auto &&stats = chain->getStatsList();
  for(auto &i : stats) {
    nlohmann::fifo_map<std::string, std::string> keys;

    keys["id"] = std::to_string(i->getId());

    r.push_back(keys);
  }
  return r;
}

std::vector<nlohmann::fifo_map<std::string, std::string>> read_firewall_ports_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&firewall = get_cube(name);

  auto &&ports = firewall->getPortsList();
  for(auto &i : ports) {
    nlohmann::fifo_map<std::string, std::string> keys;

    keys["name"] = i->getName();

    r.push_back(keys);
  }
  return r;
}

std::vector<nlohmann::fifo_map<std::string, std::string>> read_firewall_session_table_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&firewall = get_cube(name);

  auto &&sessionTable = firewall->getSessionTableList();
  for(auto &i : sessionTable) {
    nlohmann::fifo_map<std::string, std::string> keys;

    keys["src"] = i->getSrc();
    keys["dst"] = i->getDst();
    keys["l4proto"] = i->getL4proto();
    keys["sport"] = std::to_string(i->getSport());
    keys["dport"] = std::to_string(i->getDport());

    r.push_back(keys);
  }
  return r;
}


}

}
}
}
}

