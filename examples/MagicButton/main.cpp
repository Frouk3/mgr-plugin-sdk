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
					for (auto& entity : EntitySystem::Instance.m_EntityList)
					{
						if (!entity)
							continue;

						if (entity->m_nEntityFlags & 2 || entity->m_nEntityFlags & 1)
							continue;

						if ((entity->m_nEntityIndex & 0xF0000) != 0x20000) // NOT EM
							continue;

						auto enemy = entity->getEntityInstance<BehaviorEmBase>();

						if (enemy->GetContext()->hasInheritance(OBJ_CONTEXT(BehaviorEmBase)))
							enemy->m_vecTransPos.y = -1000.0f;
					}
				}
			};
	}
} __plugin;