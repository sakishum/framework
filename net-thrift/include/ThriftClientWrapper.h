/* Copyright(C)
* For free
* All right reserved
* 
*/
/**
* @file ThriftClientWrapper.h
* @brief thrift客户端通信包装
* @author highway-9, 787280310@qq.com
* @version 1.1.0
* @date 2015-11-25
*/

#ifndef _THRIFTCLIENTWRAPPER_H
#define _THRIFTCLIENTWRAPPER_H

#include <string>

class Message;
class ThriftClientImpl;

/**
* @brief thrift客户端通信包装类
*/
class ThriftClientWrapper
{
  public:
    /**
    * @brief ThriftClientWrapper 构造函数
    */
    ThriftClientWrapper();

    /**
    * @brief ~ThriftClientWrapper 析构函数
    */
    ~ThriftClientWrapper();

    /**
    * @brief init 初始化thrift客户端
    *
    * @param ip 服务器ip地址
    * @param port 服务器端口号，默认为9090
    */
    void init(const std::string& ip, const unsigned int& port = 9090);

    /**
    * @brief sendMessage 发送消息到服务器端
    *
    * @param message 发送的消息
    * @param retMessage 接收的消息
    *
    * @return 成功返回true，否则返回false
    */
    bool sendMessage(Message* message, Message* retMessage);

    /**
    * @brief deinit 反初始化，释放一些资源
    */
    void deinit();

    /**
    * @brief setConnectMsecTimeoutOnce 设置单次连接超时
    *
    * @param connectMsecTimeout 超时时间，单位：毫秒
    */
    void setConnectMsecTimeoutOnce(const unsigned int& connectMsecTimeout);

    /**
    * @brief setSendMsecTimeoutOnce 设置单次发送超时
    *
    * @param sendMsecTimeout 超时时间，单位：毫秒
    */
    void setSendMsecTimeoutOnce(const unsigned int& sendMsecTimeout);

    /**
    * @brief setRecivedMsecTimeoutOnce 设置单次接收超时
    *
    * @param recivedMsecTimeout 超时时间，单位：毫秒
    */
    void setRecivedMsecTimeoutOnce(const unsigned int& recivedMsecTimeout);

  private:
    ThriftClientImpl*       m_impl;     ///< thrift客户端实现类指针
};

#endif
