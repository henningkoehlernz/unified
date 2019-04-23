#pragma once

#include "API/Types.hpp"
#include "API/Vector.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class AllowPolymorphedCast
{
public:
    AllowPolymorphedCast(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t AddCastSpellActions_hook(NWNXLib::API::CNWSCreature *pThis, uint32_t nSpellId, int32_t nMultiClass, int32_t nDomainLevel,
        int32_t nMetaType, int32_t bSpontaneousCast, NWNXLib::API::Vector vTargetLocation, uint32_t oidTarget, int32_t bAreaTarget, int32_t bAddToFront,
        int32_t bFake, unsigned char nProjectilePathType, int32_t bInstant, int32_t bAllowPolymorphedCast, int32_t nFeat, unsigned char nCasterLevel);
    static NWNXLib::Hooking::FunctionHook* pAddCastSpellActions_hook;
};

}
