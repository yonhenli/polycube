/**
* ddosmitigator API
* ddosmitigator API generated from ddosmitigator.yang
*
* OpenAPI spec version: 1.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


// These methods have a default implementation. Your are free to keep it or add your own


#include "../Ddosmitigator.h"

std::shared_ptr<Stats> Ddosmitigator::getStats(){
  return Stats::getEntry(*this);
}

void Ddosmitigator::addStats(const StatsJsonObject &value){
  Stats::create(*this, value);
}

void Ddosmitigator::replaceStats(const StatsJsonObject &conf){
  Stats::removeEntry(*this);
  Stats::create(*this, conf);
}

void Ddosmitigator::delStats(){
  Stats::removeEntry(*this);
}


std::shared_ptr<BlacklistSrc> Ddosmitigator::getBlacklistSrc(const std::string &ip){
  return BlacklistSrc::getEntry(*this, ip);
}

std::vector<std::shared_ptr<BlacklistSrc>> Ddosmitigator::getBlacklistSrcList(){
  return BlacklistSrc::get(*this);
}

void Ddosmitigator::addBlacklistSrc(const std::string &ip, const BlacklistSrcJsonObject &conf){
  BlacklistSrc::create(*this, ip, conf);
}

void Ddosmitigator::addBlacklistSrcList(const std::vector<BlacklistSrcJsonObject> &conf){
  for(auto &i : conf){
    std::string ip_ = i.getIp();
    BlacklistSrc::create(*this, ip_,  i);
  }
}

void Ddosmitigator::replaceBlacklistSrc(const std::string &ip, const BlacklistSrcJsonObject &conf){
  BlacklistSrc::removeEntry(*this, ip);
  std::string ip_ = conf.getIp();
  BlacklistSrc::create(*this, ip_, conf);

}

void Ddosmitigator::delBlacklistSrc(const std::string &ip){
  BlacklistSrc::removeEntry(*this, ip);
}

void Ddosmitigator::delBlacklistSrcList(){
  BlacklistSrc::remove(*this);
}

std::shared_ptr<BlacklistDst> Ddosmitigator::getBlacklistDst(const std::string &ip){
  return BlacklistDst::getEntry(*this, ip);
}

std::vector<std::shared_ptr<BlacklistDst>> Ddosmitigator::getBlacklistDstList(){
  return BlacklistDst::get(*this);
}

void Ddosmitigator::addBlacklistDst(const std::string &ip, const BlacklistDstJsonObject &conf){
  BlacklistDst::create(*this, ip, conf);
}

void Ddosmitigator::addBlacklistDstList(const std::vector<BlacklistDstJsonObject> &conf){
  for(auto &i : conf){
    std::string ip_ = i.getIp();
    BlacklistDst::create(*this, ip_,  i);
  }
}

void Ddosmitigator::replaceBlacklistDst(const std::string &ip, const BlacklistDstJsonObject &conf){
  BlacklistDst::removeEntry(*this, ip);
  std::string ip_ = conf.getIp();
  BlacklistDst::create(*this, ip_, conf);

}

void Ddosmitigator::delBlacklistDst(const std::string &ip){
  BlacklistDst::removeEntry(*this, ip);
}

void Ddosmitigator::delBlacklistDstList(){
  BlacklistDst::remove(*this);
}



