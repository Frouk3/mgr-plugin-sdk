#pragma once

#include <hkReferencedObject.h>

#define HK_WARN(id, a)
#define HK_WARN_ONCE(id, a)			
#define HK_ASSERT(id, a)				
#define HK_ASSERT2(id, a, TEXT)		
#define HK_ASSERT3(id, a, TEXT)	

class hkError : public hkReferencedObject
{
public:
    enum Message
    {
        MESSAGE_REPORT = 0x0,
        MESSAGE_WARNING = 0x1,
        MESSAGE_ASSERT = 0x2,
        MESSAGE_ERROR = 0x3
    };
};

class hkDefaultError : public hkError
{
public:
    int m_disabledAssertIds;
    int m_sectionIds[3];
    int m_errorFunction;
    void *m_errorObject;
};