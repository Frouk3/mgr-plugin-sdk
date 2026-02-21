#pragma once
#include <SceneModelSystem.h>
#include <Hw.h>
#include <Animation.h>
#include <shared.h>
#include <eObjID.h>
#include <EntityHandle.h>
#include <HkDataManagerImplement.h>
#include <SceneBehaviorSystem.h>
#include <cSlowRateManager.h>

class cObj;
struct EntitySystem;
class Behavior;

class Entity
{
public:
	enum ALIVE_FLAG : unsigned int { ALIVE_RELEASE = 1, ALIVE_DELETE = 2 };

	cSlowRate m_SlowRate;
	char m_pName[32];
	eObjID m_ObjId;
	unsigned int m_AliveFlag;
	EntityHandle m_Handle;
	Hw::cFmerge m_EntityData;
	SceneModelSystem *m_pSceneManager;
	Behavior *m_pSceneModel;                 ///< There's no difference between m_pSceneModel and m_pBehavior
	Animation *m_pAnimation;
	BehaviorList *m_pBehaviorList;
	Behavior *m_pBehavior;
	BOOL m_bStartupImmediately; 
	BOOL m_bDebris;
	BOOL m_bDatsuEntity;
	int m_SetType;
	int field_5C; // used, but purpose - unknown

	struct ConstructInfo;

	Entity() { CallMethod<0x67CDE0, Entity *>(this); }
	~Entity() { CallMethod<0x681290, Entity *>(this); } // as it is called on operator delete, I suspect it to be the destructor 

	BOOL isAlive() { return ReturnCallMethod<BOOL, 0x67C7E0, Entity *>(this); }
	EntityHandle& getEntityHandle() { return ReturnCallMethod<EntityHandle&, 0x67C7F0, Entity *>(this); }
	Behavior *getSceneModel() { return ReturnCallMethod<Behavior*, 0x67C800, Entity *>(this); }
	BOOL createAnimation() { return ReturnCallMethod<BOOL, 0x67C810, Entity *>(this); }
	Animation* getAnimation() { return ReturnCallMethod<Animation*, 0x67C890, Entity *>(this); }
	Behavior *getBehavior() { return ReturnCallMethod<Behavior*, 0x67C8A0, Entity *>(this); }
	const Hw::cVec4& getTransPos() { return ReturnCallMethod<const Hw::cVec4&, 0x67C8B0, Entity *>(this); }
	const Hw::cVec4& getRot() { return ReturnCallMethod<const Hw::cVec4&, 0x67C8D0, Entity *>(this); }
	const Hw::cVec4& getScale() { return ReturnCallMethod<const Hw::cVec4&, 0x67C8F0, Entity *>(this); }
	cSlowRate *getSlowRate() { return ReturnCallMethod<cSlowRate*, 0x67C910, Entity *>(this); }
	void cleanupAnimation() { CallMethod<0x67CE60, Entity *>(this); }
	void setTransPos(const Hw::cVec4& pos) { CallMethod<0x67CE90, Entity *>(this, pos); }
	void addTransPos(const Hw::cVec4& pos) { CallMethod<0x67CEC0, Entity *>(this, pos); }
	void setRot(const Hw::cVec4& rot) { CallMethod<0x67CF00, Entity *>(this, rot); }
	void addRot(const Hw::cVec4& rot) { CallMethod<0x67CF40, Entity *>(this, rot); }
	void setScale(const Hw::cVec4& scale) { CallMethod<0x67CF90, Entity *>(this, scale); }
	void release() { CallMethod<0x6805F0, Entity *>(this); }
	BOOL startup(ConstructInfo& info) { return ReturnCallMethod<BOOL, 0x680E70, Entity *, ConstructInfo&>(this, info); }

	template <typename T = cObj>
	T* as() { return (T*)getBehavior(); }
};

VALIDATE_SIZE(Entity, 0x60);