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

#include "EosLog.h"
#include <time.h>

////////////////////////////////////////////////////////////////////////////////

void EosLog::Add(EnumLogMsgType type, const std::string &text)
{
	sLogMsg msg;
	msg.type = type;
	msg.timestamp = time(0);
	msg.text = text;
	m_Q.push_back(msg);

	//switch( type )
	//{
	//	case LOG_MSG_TYPE_WARNING:
	//	case LOG_MSG_TYPE_ERROR:
	//		printf("%s\n", text.c_str());	// convienient place to set a breakpoint
	//		break;
	//}
}

////////////////////////////////////////////////////////////////////////////////

void EosLog::Flush(LOG_Q &q)
{
	q.clear();
	m_Q.swap(q);
}

////////////////////////////////////////////////////////////////////////////////
