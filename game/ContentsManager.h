#pragma once

#include <Entity.h>

// DO NOT OPERATE THIS STRUCTURE WITHOUT PROPER OVERLOADS
// Some virtuals are `pure` virtuals, and will guarantee a crash if not overloaded by other classes

class ContentsBase
{
public:
    Hw::cHeap *m_pHeap;
    int m_Id;
    int field_C;
    int field_10;

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1735D64);

    ContentsBase(Hw::cHeap &rHeap, int id) { CallMethod<0x4DC280, ContentsBase *, Hw::cHeap &, int>(this, rHeap, id); }

    virtual ContextInstance& getContext() { return *(ContextInstance*)(shared::base + 0x1735D64); }
    virtual ~ContentsBase() {}
    virtual void startup() {}
    virtual void update() {}
    virtual void cleanup() {}
};

class BrokenBridgeContents : public ContentsBase
{
public:
    int field_10;
    int field_14;
    EntityHandle field_18;
};

class ContentsManager
{
public:

    virtual ~ContentsManager() {}
    void update() { CallVMTFunc<1, ContentsManager *>(this); }
    void addContents(ContentsBase *pContent) { CallVMTFunc<2, ContentsManager *, ContentsBase *>(this, pContent); }
    void removeContentsId(int contentId) { CallVMTFunc<3, ContentsManager *, int>(this, contentId); }
    // returns current id for ContentsBase indexing
    int cycleId() { return ReturnCallVMTFunc<int, 4, ContentsManager *>(this); }
};