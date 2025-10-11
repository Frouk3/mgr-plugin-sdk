#define SHARED_USE_EX_FUNCS

#include <Events.h>
#include <cGameUIManager.h>
#include <EntitySystem.h>
#include <shared.h>
#include <cObjReadManager.h>
#include <Hw.h> // for cInput

bool isObjExists(eObjID objId)
{
	char buffer[128];

	char* folder = nullptr;

	for (int i = 0; i < 12; i++)
	{
		std::pair<int, char*>* pFolderNames = (std::pair<int, char*>*)(shared::base + 0x1490198);

		if (pFolderNames[i].first == (objId & 0xF0000))
		{
			folder = pFolderNames[i].second;
			break;
		}
	}

	sprintf(buffer, "%s\\%s%04x.dat", folder, folder, objId & 0x0000FFFF);

	return ((BOOL(__cdecl*)(const char*))(shared::base + 0x9EC390))(buffer) == TRUE;
}

struct EntSpawn
{
	bool bDone = false;
	eObjID mObjId = eObjID(0);
	int iSetType = 0;
	bool bWorkFail = false;

	Entity* m_Entity = nullptr;
};

class EntSpawnQueue : public lib::StaticArray<EntSpawn, 16>
{
public:

	Entity* getLastEntity();
};

EntSpawnQueue m_EntQueue;

Entity* EntSpawnQueue::getLastEntity()
{
	EntSpawn* queue = nullptr;

	for (EntSpawn& str : *this)
	{
		if (str.bDone && !str.bWorkFail && str.m_Entity)
			queue = &str;
	}

	Entity* resultEntity = nullptr;

	if (queue)
		resultEntity = queue->m_Entity;

	if (queue)
		remove(*queue);

	return resultEntity;
}

class Spawner
{
public:

	Spawner()
	{
		Events::OnUpdateEvent.after += []()
			{
				if (m_EntQueue.m_size)
				{
					for (EntSpawn& str : m_EntQueue)
					{
						if (!str.bDone)
						{
							if (!str.bWorkFail)
								str.bWorkFail = g_ObjReadManager.requestObject(str.mObjId, str.iSetType) == 0;

							str.bDone = g_ObjReadManager.isObjectLoaded(str.mObjId, str.iSetType);
						}
					}

					for (int i = 0; i < m_EntQueue.m_size; i++)
					{
						EntSpawn& elem = m_EntQueue[i];

						if (elem.bWorkFail)
							m_EntQueue.remove(elem);

						if (!elem.bWorkFail && elem.bDone && !elem.m_Entity)
							elem.m_Entity = EntitySystem::ms_Instance.createEntity("SpawnedObject", elem.mObjId, nullptr);
					}
				}

				if (Entity* entity = m_EntQueue.getLastEntity(); entity)
				{
					Behavior* instance = entity->getEntityInstance<Behavior>();

					cVec4 pos = cGameUIManager::ms_Instance.m_pPlayer ? cGameUIManager::ms_Instance.m_pPlayer->m_vecTransPos : cVec4();
					cVec4 rot = cGameUIManager::ms_Instance.m_pPlayer ? cGameUIManager::ms_Instance.m_pPlayer->m_vecRotation : cVec4();

					instance->place(pos, rot);

					g_ObjReadManager.endWork(instance->m_ObjId, instance->m_nSetType); // Removes reference
				}

				shared::ExPressKeyUpdate();
			};

		Events::OnTickEvent += []()
			{
				if (cInput::ms_KeyInput.isKeyPressed('H')) // spawn boss Sam for example
				{
					eObjID objectId = eObjID(0x20020); 
					m_EntQueue.push_back({ .mObjId = objectId, .iSetType = 0, .bWorkFail = !isObjExists(objectId) });
				}
			};
	}
} __spawner;