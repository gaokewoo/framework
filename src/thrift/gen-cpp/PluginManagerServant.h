/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef PluginManagerServant_H
#define PluginManagerServant_H

#include <thrift/TDispatchProcessor.h>
#include "PluginManagerServant_types.h"



class PluginManagerServantIf {
 public:
  virtual ~PluginManagerServantIf() {}
  virtual void load(std::string& _return, const std::string& pluginInfo) = 0;
  virtual void unload(const std::string& pluginInfo) = 0;
  virtual void killContainer(const std::string& containerName) = 0;
  virtual void updateHostList(const std::string& newHostList) = 0;
};

class PluginManagerServantIfFactory {
 public:
  typedef PluginManagerServantIf Handler;

  virtual ~PluginManagerServantIfFactory() {}

  virtual PluginManagerServantIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(PluginManagerServantIf* /* handler */) = 0;
};

class PluginManagerServantIfSingletonFactory : virtual public PluginManagerServantIfFactory {
 public:
  PluginManagerServantIfSingletonFactory(const boost::shared_ptr<PluginManagerServantIf>& iface) : iface_(iface) {}
  virtual ~PluginManagerServantIfSingletonFactory() {}

  virtual PluginManagerServantIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(PluginManagerServantIf* /* handler */) {}

 protected:
  boost::shared_ptr<PluginManagerServantIf> iface_;
};

class PluginManagerServantNull : virtual public PluginManagerServantIf {
 public:
  virtual ~PluginManagerServantNull() {}
  void load(std::string& /* _return */, const std::string& /* pluginInfo */) {
    return;
  }
  void unload(const std::string& /* pluginInfo */) {
    return;
  }
  void killContainer(const std::string& /* containerName */) {
    return;
  }
  void updateHostList(const std::string& /* newHostList */) {
    return;
  }
};

typedef struct _PluginManagerServant_load_args__isset {
  _PluginManagerServant_load_args__isset() : pluginInfo(false) {}
  bool pluginInfo;
} _PluginManagerServant_load_args__isset;

class PluginManagerServant_load_args {
 public:

  PluginManagerServant_load_args() : pluginInfo() {
  }

  virtual ~PluginManagerServant_load_args() throw() {}

  std::string pluginInfo;

  _PluginManagerServant_load_args__isset __isset;

  void __set_pluginInfo(const std::string& val) {
    pluginInfo = val;
  }

  bool operator == (const PluginManagerServant_load_args & rhs) const
  {
    if (!(pluginInfo == rhs.pluginInfo))
      return false;
    return true;
  }
  bool operator != (const PluginManagerServant_load_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PluginManagerServant_load_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PluginManagerServant_load_pargs {
 public:


  virtual ~PluginManagerServant_load_pargs() throw() {}

  const std::string* pluginInfo;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PluginManagerServant_load_result__isset {
  _PluginManagerServant_load_result__isset() : success(false) {}
  bool success;
} _PluginManagerServant_load_result__isset;

class PluginManagerServant_load_result {
 public:

  PluginManagerServant_load_result() : success() {
  }

  virtual ~PluginManagerServant_load_result() throw() {}

  std::string success;

  _PluginManagerServant_load_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const PluginManagerServant_load_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const PluginManagerServant_load_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PluginManagerServant_load_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PluginManagerServant_load_presult__isset {
  _PluginManagerServant_load_presult__isset() : success(false) {}
  bool success;
} _PluginManagerServant_load_presult__isset;

class PluginManagerServant_load_presult {
 public:


  virtual ~PluginManagerServant_load_presult() throw() {}

  std::string* success;

  _PluginManagerServant_load_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _PluginManagerServant_unload_args__isset {
  _PluginManagerServant_unload_args__isset() : pluginInfo(false) {}
  bool pluginInfo;
} _PluginManagerServant_unload_args__isset;

class PluginManagerServant_unload_args {
 public:

  PluginManagerServant_unload_args() : pluginInfo() {
  }

  virtual ~PluginManagerServant_unload_args() throw() {}

  std::string pluginInfo;

  _PluginManagerServant_unload_args__isset __isset;

  void __set_pluginInfo(const std::string& val) {
    pluginInfo = val;
  }

  bool operator == (const PluginManagerServant_unload_args & rhs) const
  {
    if (!(pluginInfo == rhs.pluginInfo))
      return false;
    return true;
  }
  bool operator != (const PluginManagerServant_unload_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PluginManagerServant_unload_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PluginManagerServant_unload_pargs {
 public:


  virtual ~PluginManagerServant_unload_pargs() throw() {}

  const std::string* pluginInfo;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PluginManagerServant_unload_result {
 public:

  PluginManagerServant_unload_result() {
  }

  virtual ~PluginManagerServant_unload_result() throw() {}


  bool operator == (const PluginManagerServant_unload_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const PluginManagerServant_unload_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PluginManagerServant_unload_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PluginManagerServant_unload_presult {
 public:


  virtual ~PluginManagerServant_unload_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _PluginManagerServant_killContainer_args__isset {
  _PluginManagerServant_killContainer_args__isset() : containerName(false) {}
  bool containerName;
} _PluginManagerServant_killContainer_args__isset;

class PluginManagerServant_killContainer_args {
 public:

  PluginManagerServant_killContainer_args() : containerName() {
  }

  virtual ~PluginManagerServant_killContainer_args() throw() {}

  std::string containerName;

  _PluginManagerServant_killContainer_args__isset __isset;

  void __set_containerName(const std::string& val) {
    containerName = val;
  }

  bool operator == (const PluginManagerServant_killContainer_args & rhs) const
  {
    if (!(containerName == rhs.containerName))
      return false;
    return true;
  }
  bool operator != (const PluginManagerServant_killContainer_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PluginManagerServant_killContainer_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PluginManagerServant_killContainer_pargs {
 public:


  virtual ~PluginManagerServant_killContainer_pargs() throw() {}

  const std::string* containerName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PluginManagerServant_killContainer_result {
 public:

  PluginManagerServant_killContainer_result() {
  }

  virtual ~PluginManagerServant_killContainer_result() throw() {}


  bool operator == (const PluginManagerServant_killContainer_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const PluginManagerServant_killContainer_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PluginManagerServant_killContainer_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PluginManagerServant_killContainer_presult {
 public:


  virtual ~PluginManagerServant_killContainer_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _PluginManagerServant_updateHostList_args__isset {
  _PluginManagerServant_updateHostList_args__isset() : newHostList(false) {}
  bool newHostList;
} _PluginManagerServant_updateHostList_args__isset;

class PluginManagerServant_updateHostList_args {
 public:

  PluginManagerServant_updateHostList_args() : newHostList() {
  }

  virtual ~PluginManagerServant_updateHostList_args() throw() {}

  std::string newHostList;

  _PluginManagerServant_updateHostList_args__isset __isset;

  void __set_newHostList(const std::string& val) {
    newHostList = val;
  }

  bool operator == (const PluginManagerServant_updateHostList_args & rhs) const
  {
    if (!(newHostList == rhs.newHostList))
      return false;
    return true;
  }
  bool operator != (const PluginManagerServant_updateHostList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PluginManagerServant_updateHostList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PluginManagerServant_updateHostList_pargs {
 public:


  virtual ~PluginManagerServant_updateHostList_pargs() throw() {}

  const std::string* newHostList;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PluginManagerServant_updateHostList_result {
 public:

  PluginManagerServant_updateHostList_result() {
  }

  virtual ~PluginManagerServant_updateHostList_result() throw() {}


  bool operator == (const PluginManagerServant_updateHostList_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const PluginManagerServant_updateHostList_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PluginManagerServant_updateHostList_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PluginManagerServant_updateHostList_presult {
 public:


  virtual ~PluginManagerServant_updateHostList_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class PluginManagerServantClient : virtual public PluginManagerServantIf {
 public:
  PluginManagerServantClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  PluginManagerServantClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void load(std::string& _return, const std::string& pluginInfo);
  void send_load(const std::string& pluginInfo);
  void recv_load(std::string& _return);
  void unload(const std::string& pluginInfo);
  void send_unload(const std::string& pluginInfo);
  void recv_unload();
  void killContainer(const std::string& containerName);
  void send_killContainer(const std::string& containerName);
  void recv_killContainer();
  void updateHostList(const std::string& newHostList);
  void send_updateHostList(const std::string& newHostList);
  void recv_updateHostList();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class PluginManagerServantProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<PluginManagerServantIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (PluginManagerServantProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_load(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_unload(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_killContainer(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_updateHostList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  PluginManagerServantProcessor(boost::shared_ptr<PluginManagerServantIf> iface) :
    iface_(iface) {
    processMap_["load"] = &PluginManagerServantProcessor::process_load;
    processMap_["unload"] = &PluginManagerServantProcessor::process_unload;
    processMap_["killContainer"] = &PluginManagerServantProcessor::process_killContainer;
    processMap_["updateHostList"] = &PluginManagerServantProcessor::process_updateHostList;
  }

  virtual ~PluginManagerServantProcessor() {}
};

class PluginManagerServantProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  PluginManagerServantProcessorFactory(const ::boost::shared_ptr< PluginManagerServantIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< PluginManagerServantIfFactory > handlerFactory_;
};

class PluginManagerServantMultiface : virtual public PluginManagerServantIf {
 public:
  PluginManagerServantMultiface(std::vector<boost::shared_ptr<PluginManagerServantIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~PluginManagerServantMultiface() {}
 protected:
  std::vector<boost::shared_ptr<PluginManagerServantIf> > ifaces_;
  PluginManagerServantMultiface() {}
  void add(boost::shared_ptr<PluginManagerServantIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void load(std::string& _return, const std::string& pluginInfo) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->load(_return, pluginInfo);
    }
    ifaces_[i]->load(_return, pluginInfo);
    return;
  }

  void unload(const std::string& pluginInfo) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->unload(pluginInfo);
    }
    ifaces_[i]->unload(pluginInfo);
  }

  void killContainer(const std::string& containerName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->killContainer(containerName);
    }
    ifaces_[i]->killContainer(containerName);
  }

  void updateHostList(const std::string& newHostList) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->updateHostList(newHostList);
    }
    ifaces_[i]->updateHostList(newHostList);
  }

};



#endif
