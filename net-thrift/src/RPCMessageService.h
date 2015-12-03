/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef RPCMessageService_H
#define RPCMessageService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "RPCMessage_types.h"



#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class RPCMessageServiceIf {
 public:
  virtual ~RPCMessageServiceIf() {}
  virtual void sendMessage(std::string& _return, const std::string& message) = 0;
};

class RPCMessageServiceIfFactory {
 public:
  typedef RPCMessageServiceIf Handler;

  virtual ~RPCMessageServiceIfFactory() {}

  virtual RPCMessageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(RPCMessageServiceIf* /* handler */) = 0;
};

class RPCMessageServiceIfSingletonFactory : virtual public RPCMessageServiceIfFactory {
 public:
  RPCMessageServiceIfSingletonFactory(const boost::shared_ptr<RPCMessageServiceIf>& iface) : iface_(iface) {}
  virtual ~RPCMessageServiceIfSingletonFactory() {}

  virtual RPCMessageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(RPCMessageServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<RPCMessageServiceIf> iface_;
};

class RPCMessageServiceNull : virtual public RPCMessageServiceIf {
 public:
  virtual ~RPCMessageServiceNull() {}
  void sendMessage(std::string& /* _return */, const std::string& /* message */) {
    return;
  }
};

typedef struct _RPCMessageService_sendMessage_args__isset {
  _RPCMessageService_sendMessage_args__isset() : message(false) {}
  bool message :1;
} _RPCMessageService_sendMessage_args__isset;

class RPCMessageService_sendMessage_args {
 public:

  RPCMessageService_sendMessage_args(const RPCMessageService_sendMessage_args&);
  RPCMessageService_sendMessage_args& operator=(const RPCMessageService_sendMessage_args&);
  RPCMessageService_sendMessage_args() : message() {
  }

  virtual ~RPCMessageService_sendMessage_args() throw();
  std::string message;

  _RPCMessageService_sendMessage_args__isset __isset;

  void __set_message(const std::string& val);

  bool operator == (const RPCMessageService_sendMessage_args & rhs) const
  {
    if (!(message == rhs.message))
      return false;
    return true;
  }
  bool operator != (const RPCMessageService_sendMessage_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RPCMessageService_sendMessage_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RPCMessageService_sendMessage_pargs {
 public:


  virtual ~RPCMessageService_sendMessage_pargs() throw();
  const std::string* message;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RPCMessageService_sendMessage_result__isset {
  _RPCMessageService_sendMessage_result__isset() : success(false) {}
  bool success :1;
} _RPCMessageService_sendMessage_result__isset;

class RPCMessageService_sendMessage_result {
 public:

  RPCMessageService_sendMessage_result(const RPCMessageService_sendMessage_result&);
  RPCMessageService_sendMessage_result& operator=(const RPCMessageService_sendMessage_result&);
  RPCMessageService_sendMessage_result() : success() {
  }

  virtual ~RPCMessageService_sendMessage_result() throw();
  std::string success;

  _RPCMessageService_sendMessage_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const RPCMessageService_sendMessage_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const RPCMessageService_sendMessage_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RPCMessageService_sendMessage_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RPCMessageService_sendMessage_presult__isset {
  _RPCMessageService_sendMessage_presult__isset() : success(false) {}
  bool success :1;
} _RPCMessageService_sendMessage_presult__isset;

class RPCMessageService_sendMessage_presult {
 public:


  virtual ~RPCMessageService_sendMessage_presult() throw();
  std::string* success;

  _RPCMessageService_sendMessage_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class RPCMessageServiceClient : virtual public RPCMessageServiceIf {
 public:
  RPCMessageServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  RPCMessageServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void sendMessage(std::string& _return, const std::string& message);
  void send_sendMessage(const std::string& message);
  void recv_sendMessage(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class RPCMessageServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<RPCMessageServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (RPCMessageServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_sendMessage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  RPCMessageServiceProcessor(boost::shared_ptr<RPCMessageServiceIf> iface) :
    iface_(iface) {
    processMap_["sendMessage"] = &RPCMessageServiceProcessor::process_sendMessage;
  }

  virtual ~RPCMessageServiceProcessor() {}
};

class RPCMessageServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  RPCMessageServiceProcessorFactory(const ::boost::shared_ptr< RPCMessageServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< RPCMessageServiceIfFactory > handlerFactory_;
};

class RPCMessageServiceMultiface : virtual public RPCMessageServiceIf {
 public:
  RPCMessageServiceMultiface(std::vector<boost::shared_ptr<RPCMessageServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~RPCMessageServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<RPCMessageServiceIf> > ifaces_;
  RPCMessageServiceMultiface() {}
  void add(boost::shared_ptr<RPCMessageServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void sendMessage(std::string& _return, const std::string& message) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->sendMessage(_return, message);
    }
    ifaces_[i]->sendMessage(_return, message);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class RPCMessageServiceConcurrentClient : virtual public RPCMessageServiceIf {
 public:
  RPCMessageServiceConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  RPCMessageServiceConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void sendMessage(std::string& _return, const std::string& message);
  int32_t send_sendMessage(const std::string& message);
  void recv_sendMessage(std::string& _return, const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif



#endif