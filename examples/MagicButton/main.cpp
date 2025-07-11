#include <shared.h>
#include <EntitySystem.h>
#include <Events.h>
#include <BehaviorEmBase.h>

class Plugin
{
public:
	Plugin()
	{
		Events::OnTickEvent += []()
			{
				if (shared::IsKeyPressed('O', false))
				{
					for (auto& entity : EntitySystem::ms_Instance.m_EntityList)
					{
						if (!entity)
							continue;

						if (entity->m_EntityFlags & 2 || entity->m_EntityFlags & 1)
							continue;

						if ((entity->m_EntityIndex & 0xF0000) != 0x20000) // NOT EM
							continue;

						auto enemy = entity->getEntityInstance<BehaviorEmBase>();

						if (enemy->getContext().hasInheritance(BehaviorEmBase::ms_Context))
						{
							enemy->m_vecTransPos.y = -1000.0f;
							enemy->place(enemy->m_vecTransPos, enemy->m_vecRotation);
						}
					}
				}
			};
	}
} __plugin;