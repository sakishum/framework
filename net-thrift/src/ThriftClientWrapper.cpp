/* Copyright(C)
* For free
* All right reserved
* 
*/
/**
* @file ThriftClientWrapper.cpp
* @brief thrift客户端通信包装实现文件
* @author highway-9, 787280310@qq.com
* @version 1.1.0
* @date 2015-11-25
*/

#include "ThriftClientWrapper.h"
#include "ThriftClientImpl.h"
#include "Message.h"

ThriftClientWrapper::ThriftClientWrapper()
    : m_impl(NULL)
{
    if (m_impl == NULL)
    {
        m_impl = new ThriftClientImpl;
    }
}

ThriftClientWrapper::~ThriftClientWrapper()
{
    if (m_impl != NULL)
    {
        delete m_impl;
        m_impl = NULL;
    }
}

void ThriftClientWrapper::init(const std::string& ip, const unsigned int& port)
{
    if (m_impl != NULL)
    {
        m_impl->init(ip, port);
    }
}

bool ThriftClientWrapper::sendMessage(Message* message, Message* retMessage)
{
    if (m_impl != NULL)
    {
        return m_impl->sendMessage(message, retMessage);
    }

    return false;
}

void ThriftClientWrapper::deinit()
{
    if (m_impl != NULL)
    {
        m_impl->deinit();
    }
}

void ThriftClientWrapper::setConnectMsecTimeoutOnce(const unsigned int& connectMsecTimeout)
{
    if (m_impl != NULL)
    {
        m_impl->setConnectMsecTimeoutOnce(connectMsecTimeout);
    }
}

void ThriftClientWrapper::setSendMsecTimeoutOnce(const unsigned int& sendMsecTimeout)
{
    if (m_impl != NULL)
    {
        m_impl->setSendMsecTimeoutOnce(sendMsecTimeout);
    }
}

void ThriftClientWrapper::setRecivedMsecTimeoutOnce(const unsigned int& recivedMsecTimeout)
{
    if (m_impl != NULL)
    {
        m_impl->setRecivedMsecTimeoutOnce(recivedMsecTimeout);
    }
}
