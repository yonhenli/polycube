/**
* iptables API
* iptables API generated from iptables.yang
*
* OpenAPI spec version: 1.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */

/*
* ChainRuleJsonObject.h
*
*
*/

#pragma once


#include "JsonObjectBase.h"


namespace io {
namespace swagger {
namespace server {
namespace model {

#ifndef CONNTRACKSTATUSENUM
#define CONNTRACKSTATUSENUM
enum class ConntrackstatusEnum {
  NEW, ESTABLISHED, RELATED, INVALID
};
#endif
#ifndef ACTIONENUM
#define ACTIONENUM
enum class ActionEnum {
  DROP, LOG, ACCEPT
};
#endif

/// <summary>
///
/// </summary>
class  ChainRuleJsonObject : public JsonObjectBase {
public:
  ChainRuleJsonObject();
  ChainRuleJsonObject(const nlohmann::json &json);
  ~ChainRuleJsonObject() final = default;
  nlohmann::json toJson() const final;


  /// <summary>
  /// Rule Identifier
  /// </summary>
  uint32_t getId() const;
  void setId(uint32_t value);
  bool idIsSet() const;

  /// <summary>
  /// Name of the interface via which the packet is received
  /// </summary>
  std::string getInIface() const;
  void setInIface(std::string value);
  bool inIfaceIsSet() const;
  void unsetInIface();

  /// <summary>
  /// Name of the interface via which the packet is going to be sent
  /// </summary>
  std::string getOutIface() const;
  void setOutIface(std::string value);
  bool outIfaceIsSet() const;
  void unsetOutIface();

  /// <summary>
  /// Source IP Address.
  /// </summary>
  std::string getSrc() const;
  void setSrc(std::string value);
  bool srcIsSet() const;
  void unsetSrc();

  /// <summary>
  /// Destination IP Address.
  /// </summary>
  std::string getDst() const;
  void setDst(std::string value);
  bool dstIsSet() const;
  void unsetDst();

  /// <summary>
  /// Level 4 Protocol.
  /// </summary>
  std::string getL4proto() const;
  void setL4proto(std::string value);
  bool l4protoIsSet() const;
  void unsetL4proto();

  /// <summary>
  /// Source L4 Port
  /// </summary>
  uint16_t getSport() const;
  void setSport(uint16_t value);
  bool sportIsSet() const;
  void unsetSport();

  /// <summary>
  /// Destination L4 Port
  /// </summary>
  uint16_t getDport() const;
  void setDport(uint16_t value);
  bool dportIsSet() const;
  void unsetDport();

  /// <summary>
  /// TCP flags. Allowed values: SYN, FIN, ACK, RST, PSH, URG, CWR, ECE. ! means set to 0.
  /// </summary>
  std::string getTcpflags() const;
  void setTcpflags(std::string value);
  bool tcpflagsIsSet() const;
  void unsetTcpflags();

  /// <summary>
  /// Connection status (NEW, ESTABLISHED, RELATED, INVALID)
  /// </summary>
  ConntrackstatusEnum getConntrack() const;
  void setConntrack(ConntrackstatusEnum value);
  bool conntrackIsSet() const;
  void unsetConntrack();
  static std::string ConntrackstatusEnum_to_string(const ConntrackstatusEnum &value);
  static ConntrackstatusEnum string_to_ConntrackstatusEnum(const std::string &str);

  /// <summary>
  /// Action if the rule matches. Default is DROP.
  /// </summary>
  ActionEnum getAction() const;
  void setAction(ActionEnum value);
  bool actionIsSet() const;
  void unsetAction();
  static std::string ActionEnum_to_string(const ActionEnum &value);
  static ActionEnum string_to_ActionEnum(const std::string &str);

private:
  uint32_t m_id;
  bool m_idIsSet;
  std::string m_inIface;
  bool m_inIfaceIsSet;
  std::string m_outIface;
  bool m_outIfaceIsSet;
  std::string m_src;
  bool m_srcIsSet;
  std::string m_dst;
  bool m_dstIsSet;
  std::string m_l4proto;
  bool m_l4protoIsSet;
  uint16_t m_sport;
  bool m_sportIsSet;
  uint16_t m_dport;
  bool m_dportIsSet;
  std::string m_tcpflags;
  bool m_tcpflagsIsSet;
  ConntrackstatusEnum m_conntrack;
  bool m_conntrackIsSet;
  ActionEnum m_action;
  bool m_actionIsSet;
};

}
}
}
}

