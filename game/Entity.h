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

	Entity() { MAKE_CALL(shared::base + 0x67CDE0, void(__thiscall *)(Entity*), this); }
	~Entity() { MAKE_CALL(shared::base + 0x681290, void(__thiscall *)(Entity*), this); } // as it is called on operator delete, I suspect it to be the destructor 

	BOOL isAlive() { return MAKE_CALL(shared::base + 0x67C7E0, BOOL(__thiscall *)(Entity*), this); }
	EntityHandle& getEntityHandle() { return MAKE_CALL(shared::base + 0x67C7F0, EntityHandle&(__thiscall *)(Entity*), this); }
	Behavior *getSceneModel() { return MAKE_CALL(shared::base + 0x67C800, Behavior*(__thiscall *)(Entity*), this); }
	BOOL createAnimation() { return MAKE_CALL(shared::base + 0x67C810, BOOL(__thiscall *)(Entity*), this); }
	Animation* getAnimation() { return MAKE_CALL(shared::base + 0x67C890, Animation*(__thiscall *)(Entity*), this); }
	Behavior *getBehavior() { return MAKE_CALL(shared::base + 0x67C8A0, Behavior*(__thiscall *)(Entity*), this); }
	const Hw::cVec4& getTransPos() { return MAKE_CALL(shared::base + 0x67C8B0, const Hw::cVec4&(__thiscall *)(Entity*), this); }
	const Hw::cVec4& getRot() { return MAKE_CALL(shared::base + 0x67C8D0, const Hw::cVec4&(__thiscall *)(Entity*), this); }
	const Hw::cVec4& getScale() { return MAKE_CALL(shared::base + 0x67C8F0, const Hw::cVec4&(__thiscall *)(Entity*), this); }
	cSlowRate *getSlowRate() { return MAKE_CALL(shared::base + 0x67C910, cSlowRate*(__thiscall *)(Entity*), this); }
	void cleanupAnimation() { MAKE_CALL(shared::base + 0x67CE60, void(__thiscall *)(Entity*), this); }
	void setTransPos(const Hw::cVec4& pos) { MAKE_CALL(shared::base + 0x67CE90, void(__thiscall *)(Entity*, const Hw::cVec4&), this, pos); }
	void addTransPos(const Hw::cVec4& pos) { MAKE_CALL(shared::base + 0x67CEC0, void(__thiscall *)(Entity*, const Hw::cVec4&), this, pos); }
	void setRot(const Hw::cVec4& rot) { MAKE_CALL(shared::base + 0x67CF00, void(__thiscall *)(Entity*, const Hw::cVec4&), this, rot); }
	void addRot(const Hw::cVec4& rot) { MAKE_CALL(shared::base + 0x67CF40, void(__thiscall *)(Entity*, const Hw::cVec4&), this, rot); }
	void setScale(const Hw::cVec4& scale) { MAKE_CALL(shared::base + 0x67CF90, void(__thiscall *)(Entity*, const Hw::cVec4&), this, scale); }
	void release() { MAKE_CALL(shared::base + 0x6805F0, void(__thiscall *)(Entity*), this); }
	BOOL startup(ConstructInfo& info) { return MAKE_CALL(shared::base + 0x680E70, BOOL(__thiscall *)(Entity*, ConstructInfo&), this, info); }

	template <typename T = cObj>
	T* as() { return (T*)getBehavior(); }
};

VALIDATE_SIZE(Entity, 0x60);