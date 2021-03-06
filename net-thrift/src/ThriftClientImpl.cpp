/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
 /* Copyright(C)
 * For free
 * All right reserved
 * 
 */
 /**
 * @file ThriftClientImpl.cpp
 * @brief thrift客户端实现文件
 * @author highway-9, 787280310@qq.com
 * @version 1.1.0
 * @date 2015-11-25
 */

#include "ThriftClientImpl.h"
#include "Message.h"
#include <mutex>

#define CONNECT_MSEC_TIMEOUT        3000            // 默认连接超时时间，单位：毫秒
#define SEND_MSEC_TIMEOUT           10000           // 默认发送超时时间，单位：毫秒
#define RECIVED_MSEC_TIMEOUT        10000           // 默认接收超时时间，单位：毫秒

ThriftClientImpl::ThriftClientImpl()
    : m_ip("127.0.0.1"),
    m_port(9090),
    m_connectMsecTimeout(CONNECT_MSEC_TIMEOUT),
    m_sendMsecTimeout(SEND_MSEC_TIMEOUT),
    m_recivedMsecTimeout(RECIVED_MSEC_TIMEOUT)
{
    // Do nothing.
}

ThriftClientImpl::~ThriftClientImpl()
{
    deinit();
}

void ThriftClientImpl::init(const std::string& ip, const unsigned int& port)
{
    m_ip = ip;
    m_port = port;
}

void ThriftClientImpl::deinit()
{
    // Do nothing.
}

bool ThriftClientImpl::sendMessage(Message* message, Message* retMessage)
{
    static std::mutex mt;
    std::lock_guard<std::mutex> locker(mt);

    if (message == NULL || retMessage == NULL)
    {
        std::cout << "message or retMessage is NULL" << std::endl;
        return false;
    }

    std::string content = message->serializeSelf();
    delete message;
    message = NULL;

    try 
    {
        boost::shared_ptr<TTransport> socket(new TSocket(m_ip.c_str(), m_port));
        boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
        boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
        RPCMessageServiceClient client(protocol);

        transport->open();

        std::string retContent;
        client.sendMessage(retContent, content);
        if (retContent.empty())
        {
            std::cout << "Recived content is empty" << std::endl;
            return false;
        }
        retMessage->deserializeSelf(retContent);

        transport->close();
    } catch (TException& e)
    {
        std::cout << "ERROR: " << e.what() << std::endl;
        return false;
    }

    return true;
}

void ThriftClientImpl::setConnectMsecTimeoutOnce(const unsigned int& connectMsecTimeout)
{
    m_connectMsecTimeout = connectMsecTimeout;
}

void ThriftClientImpl::setSendMsecTimeoutOnce(const unsigned int& sendMsecTimeout)
{
    m_sendMsecTimeout = sendMsecTimeout;
}

void ThriftClientImpl::setRecivedMsecTimeoutOnce(const unsigned int& recivedMsecTimeout)
{
    m_recivedMsecTimeout = recivedMsecTimeout;
}
