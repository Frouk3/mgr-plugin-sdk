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
						if (!entity)
							continue;

						if (entity->m_EntityFlags & 2 || entity->m_EntityFlags & 1)
							continue;

						if ((entity->m_EntityIndex & 0xF0000) != 0x20000) // NOT EM
							continue;

						BehaviorEmBase* enemy = entity->getEntityInstance<BehaviorEmBase>();

						if (enemy->getContext().hasInheritance(BehaviorEmBase::ms_Context))
						{
							enemy->m_TransPos.y = -1000.0f;
							enemy->place(enemy->m_TransPos, enemy->m_Rot);
						}
					}
				}
			};
	}
} __plugin;