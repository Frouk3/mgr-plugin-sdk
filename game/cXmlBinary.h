#pragma once

#include "cXml.h"
#include "Hw.h"

class cXmlBinary : public cXml
{
public:
    Hw::cHeapVariable *m_pAllocator;
    int *m_pNodes;
    void *m_pBxm;
    cXml::Node *m_pNodesInfo;
    cXml::Data *m_pData;
    char *m_pStrings;
    int m_nFileFlags;

    cXmlBinary()
    {
        MAKE_CALL(shared::base + 0xA05360, void(__thiscall *)(cXmlBinary*), this);
    }

    BOOL open(void *bxm, Hw::cHeapVariable *allocator)
    {
        return MAKE_CALL(shared::base + 0xA062B0, BOOL(__thiscall *)(cXmlBinary*, void*, Hw::cHeapVariable*), this, bxm, allocator);
    }

    // vft start
    
    int getFirstChild()
    {
        return MAKE_VCALL(1, int(__thiscall *)(cXmlBinary*), this);
    }

    BOOL isOpened()
    {
        return MAKE_VCALL(2, BOOL(__thiscall *)(cXmlBinary*), this);
    }

    int getChildNumber(unsigned int node)
    {
        return MAKE_VCALL(4, int(__thiscall *)(cXmlBinary*, unsigned int), this, node);
    }

    int getFirstChildIndex(unsigned int node, unsigned int num)
    {
        return MAKE_VCALL(5, int(__thiscall *)(cXmlBinary*, unsigned int, unsigned int), this, node, num);
    }

    int getSection(unsigned int node, const char *section)
    {
        return MAKE_VCALL(6, int(__thiscall *)(cXmlBinary*, unsigned int, const char*), this, node, section);
    }

    size_t getDataString(unsigned int data, char *buffer, size_t size)
    {
        return MAKE_VCALL(8, size_t(__thiscall *)(cXmlBinary*, unsigned int, char*, size_t), this, data, buffer, size);
    }

    size_t getNodeDataString(unsigned int data)
    {
        return MAKE_VCALL(9, size_t(__thiscall *)(cXmlBinary*, unsigned int), this, data);
    }

    BOOL compareDataString(unsigned int data, const char *str1)
    {
        return MAKE_VCALL(10, BOOL(__thiscall *)(cXmlBinary*, unsigned int, const char *), this, data, str1);
    }

    BOOL compareNodeString(unsigned int node, const char *str1)
    {
        return MAKE_VCALL(11, BOOL(__thiscall *)(cXmlBinary*, unsigned int, const char*), this, node, str1);
    }

    float* getNodeFloat(unsigned int node, float *value)
    {
        return MAKE_VCALL(12, float *(__thiscall *)(cXmlBinary*, unsigned int, float*), this, node, value);
    }

    float *getNodeFloat16(unsigned int node, float *value)
    {
        return MAKE_VCALL(13, float *(__thiscall *)(cXmlBinary*, unsigned int, float*), this, node, value);
    }

    int getNodeByte(unsigned int node, unsigned char *value)
    {
        return MAKE_VCALL(14, int(__thiscall *)(cXmlBinary*, unsigned int, unsigned char*), this, node, value);
    }

    float* getNodeFloat4(unsigned int node, float *value)
    {
        return MAKE_VCALL(15, float *(__thiscall *)(cXmlBinary*, unsigned int, float*), this, node, value);
    }

    // vft end


};