// Copyright (c) 2015 Electronic Theatre Controls, Inc., http://www.etcconnect.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#pragma once
#ifndef EOS_UDP_WIN_H
#define EOS_UDP_WIN_H

#ifndef EOS_UDP_H
#include "EosUdp.h"
#endif

#include <WinSock2.h>
#include <Windows.h>

////////////////////////////////////////////////////////////////////////////////

class EosUdpIn_Win
	: public EosUdpIn
{
public:
	EosUdpIn_Win();
	virtual ~EosUdpIn_Win();

	virtual bool Initialize(EosLog &log, const char *ip, unsigned short port);
	virtual bool IsInitialized() const {return (m_Socket!=-1);}
	virtual void Shutdown();
	virtual const char* RecvPacket(EosLog &log, unsigned int timeoutMS, unsigned int retryCount, int &len, void *addr, int *addrSize);

private:
	SOCKET	m_Socket;
};

////////////////////////////////////////////////////////////////////////////////

class EosUdpOut_Win
	: public EosUdpOut
{
public:
	EosUdpOut_Win();
	virtual ~EosUdpOut_Win();

	virtual bool Initialize(EosLog &log, const char *ip, unsigned short port);
	virtual bool IsInitialized() const {return (m_Socket!=-1);}
	virtual void Shutdown();
	virtual bool SendPacket(EosLog &log, const char *buf, int len);

private:
	SOCKET		m_Socket;
	sockaddr_in	m_Addr;
};

////////////////////////////////////////////////////////////////////////////////

#endif
