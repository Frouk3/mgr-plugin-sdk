#pragma once

#include <hkpCharacterProxyListener.h>
#include <hkReferencedObject.h>

class CharacterProxyListener : public hkReferencedObject, public hkpCharacterProxyListener
{
public:
    int field_10;
};