#include <shared.h>
#include <EntitySystem.h>
#include <Events.h>
#include <BehaviorEmBase.h>
#include <Hw.h> // for input

class Plugin
{
public:
	Plugin()
	{
		Events::OnTickEvent += []()
			{
				if (g_Keyboard.trig(Hw::KB_O))
				{
					for (Entity* entity : EntitySystem::ms_Instance.m_EntityList)
					{
						if (entity->m_AliveFlag & Entity::ALIVE_DELETE || entity->m_AliveFlag & Entity::ALIVE_RELEASE)
							continue;

						if ((entity->m_ObjId & 0xF0000) != 0x20000) // NOT EM
							continue;

						BehaviorEmBase* enemy = (BehaviorEmBase*)entity->getBehavior();

						if (enemy->getContext().hasInheritance(BehaviorEmBase::m_Context))
						{
							enemy->m_TransPos.y = -1000.0f;
							enemy->place(enemy->m_TransPos, enemy->m_Rot);
						}
					}
				}
			};
	}
} __plugin;