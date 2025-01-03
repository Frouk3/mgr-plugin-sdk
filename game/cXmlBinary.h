#pragma once

#include "cXml.h"
#include "Hw.h"

class cXmlBinary : public cXml
{
public:
    Hw::cHeapVariable *m_pAllocator;
    int *m_pNodes;
    void *m_Bxm;
    cXml::Node *m_pNodesInfo;
    cXml::Data *m_pData;
    char *m_pStrings;
    int m_nFileFlags;

    virtual ~cXmlBinary() override {};
    
    int getFirstChild()
    {
        return ReturnCallVMTFunc<int, 1, cXmlBinary*>(this);
    }

    BOOL isOpened()
    {
        return ReturnCallVMTFunc<BOOL, 2, cXmlBinary*>(this);
    }

    int getChildNumber(unsigned int node)
    {
        return ReturnCallVMTFunc<int, 4, cXmlBinary*, unsigned int>(this, node);
    }

    int getFirstChildIndex(unsigned int node, unsigned int num)
    {
        return ReturnCallVMTFunc<int, 5, cXmlBinary*, unsigned int, unsigned int>(this, node, num);
    }

    int getSection(unsigned int node, const char *section)
    {
        return ReturnCallVMTFunc<int, 6, cXmlBinary*, unsigned int, const char*>(this, node, section);
    }

    size_t getDataString(unsigned int data, char *buffer, size_t size)
    {
        return ReturnCallVMTFunc<size_t, 8, cXmlBinary*, unsigned int, char*, size_t>(this, data, buffer, size);
    }

    size_t getNodeDataString(unsigned int data)
    {
        return ReturnCallVMTFunc<size_t, 9, cXmlBinary*, unsigned int>(this, data);
    }

    BOOL compareDataString(unsigned int data, const char *str1)
    {
        return ReturnCallVMTFunc<BOOL, 10, cXmlBinary*, unsigned int, const char *>(this, data, str1);
    }

    BOOL compareNodeString(unsigned int node, const char *str1)
    {
        return ReturnCallVMTFunc<BOOL, 11, cXmlBinary*, unsigned int, const char*>(this, node, str1);
    }

    float* getNodeFloat(unsigned int node, float *value)
    {
        return ReturnCallVMTFunc<float *, 12, cXmlBinary*, unsigned int, float*>(this, node, value);
    }

    float *getNodeFloat16(unsigned int node, float *value)
    {
        return ReturnCallVMTFunc<float*, 13, cXmlBinary*, unsigned int, float*>(this, node, value);
    }

    int getNodeByte(unsigned int node, unsigned char *value)
    {
        return ReturnCallVMTFunc<int, 14, cXmlBinary*, unsigned int, unsigned char*>(this, node, value);
    }

    float* getNodeFloat4(unsigned int node, float *value)
    {
        return ReturnCallVMTFunc<float*, 15, cXmlBinary*, unsigned int, float*>(this, node, value);
    }
};