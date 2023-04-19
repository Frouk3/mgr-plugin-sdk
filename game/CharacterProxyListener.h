#pragma once

#include "hkpCharacterProxyListener.h"
#include "hkReferencedObject.h"

class CharacterProxyListener : public hkReferencedObject, hkpCharacterProxyListener
{
public:

    virtual ~CharacterProxyListener() override {};
};