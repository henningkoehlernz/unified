#include "Tweaks/DisableMonkAbilitiesWhenPolymorphed.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNXLib::Hooking::FunctionHook* DisableMonkAbilitiesWhenPolymorphed::pGetUseMonkAbilities_hook;

DisableMonkAbilitiesWhenPolymorphed::DisableMonkAbilitiesWhenPolymorphed(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<Functions::CNWSCreature__GetUseMonkAbilities>(&CNWSCreature__GetUseMonkAbilities_hook);
    pGetUseMonkAbilities_hook = hooker->FindHookByAddress(Functions::CNWSCreature__GetUseMonkAbilities);
}

int32_t DisableMonkAbilitiesWhenPolymorphed::CNWSCreature__GetUseMonkAbilities_hook(CNWSCreature *pThis)
{
    if ( pThis->m_bIsPolymorphed )
        return false;
    return pGetUseMonkAbilities_hook->CallOriginal<int32_t>(pThis);
}

}
