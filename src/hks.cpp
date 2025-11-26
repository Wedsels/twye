#include "common.hpp"

#include <filesystem>

void carefully( ::std::string original, ::std::string replace, ::std::vector< ::std::pair< ::std::string, ::std::string > >& target, ::std::set< ::std::string >& careful ) {
    target.push_back( { "= " + original, "= " + replace } );
    target.push_back( { original + " ==", replace + " ==" } );
    target.push_back( { "( " + original + " )", "( " + replace + " )" } );
    target.push_back( { "[ " + original + " ]", "[ " + replace + " ]" } );
    target.push_back( { "( " + original + ",", "( " + replace + "," } );
    target.push_back( { " " + original + " )", " " + replace + " )" } );

    careful.emplace( "= " + original );
    careful.emplace( original + " ==" );
    careful.emplace( "( " + original + " )" );
    careful.emplace( "[ " + original + " ]" );
    careful.emplace( "( " + original + "," );
    careful.emplace( " " + original + " )" );
}

::size_t c9997( ::std::wstring path ) {
    ::std::vector< ::std::pair< ::std::string, ::std::string > > pattern =
    {
        { "env(GetDamageLevel)", "TakeABreath()" },
        {
            "function Update()",
            "function TakeABreath()\n"
            "    local level = env(GetDamageLevel)\n"
            "    breath = os.clock()\n"
            "    damagelevelers[level] = damagelevelers[level] or 0\n"
            "    if breath - damagelevelers[level] > 1 then\n"
            "        damagelevelers[level] = breath\n"
            "    else\n"
            "        level = 0\n"
            "    end\n"
            "    return level\n"
            "end\n"
            "\n"
            "function Update()\n"
        },
        {
            "global = {}",
            "breath = os.clock()\n"
            "damagelevelers = {}\n"
            "global = {}"
        },
    };

    return ::common::replace( ::common::fromw( path ), pattern , true, {} ).second;
}

::size_t c0000( ::std::wstring path ) {
    ::std::set< ::std::string > careful;
    ::std::vector< ::std::pair< ::std::string, ::std::string > > pattern;
    ::carefully( "Unknown163", "SetCanChangeEquipmentOff", pattern, careful );
    ::carefully( "SetIsEquipmentMenuAccessOff", "SetCanChangeEquipmentOff", pattern, careful );

    pattern.append_range(
        ::std::vector< ::std::pair< ::std::string, ::std::string > > {
    // powerstance
            { "env(ActionRequest, ACTION_ARM_R1)", "checkR1()" },
            { "env(ActionRequest, ACTION_ARM_L1)", "checkL1()" },
            { "env(ActionRequest, ACTION_ARM_L2)", "checkL2()" },
            {
                "function IsWeaponCanGuard()",
                "function IsWeaponCanGuard()\n"
                "	if IsEnableDualWielding() ~= -1 and CanDualParry() == nil then\n"
                "		return TRUE\n"
                "	end\n"
            },
            {
                "    if IsEnableDualWielding() ~= -1 then\n"
                "        return FALSE\n"
                "    end\n",
                "    if CanDualParry() ~= nil or env(ActionRequest, ACTION_ARM_R1) == TRUE then\n"
                "        return FALSE\n"
                "    end\n"
            },
            { "is_spear == TRUE or is_rapier == TRUE or is_large_spear == TRUE or is_large_rapier == TRUE", "pokers[env(GetEquipWeaponCategory, HAND_RIGHT)] == TRUE" },
            // { "arts_cat ==", "checkSAI() ~= 92 and arts_cat ==" },
            { "arts_cat == WEAPON_CATEGORY_SHORT_SWORD", "arts_cat == dagger or checkSAI() == 92 and parriers[wep_cat] == dagger" },
            { "arts_cat == WEAPON_CATEGORY_CURVEDSWORD", "arts_cat == curved or checkSAI() == 92 and parriers[wep_cat] == curved" },
            {
                "IsShieldArts(weaponswordartid) == FALSE and IsArrowStanceArts(weaponswordartid) == FALSE",
                "IsShieldArts(weaponswordartid) == FALSE and IsArrowStanceArts(weaponswordartid) == FALSE and (CanDualParry() == nil or env(ActionDuration, ACTION_ARM_L2) > 0)"
            },
            {
                "function GetHandChangeType(hand)",
                "function GetHandChangeType(hand)\n"
                "    if CanDualParry() == hand then\n"
                "        return WEAPON_CHANGE_REQUEST_INVALID\n"
                "    end\n"
            },
            {
                "function Update()",
                "function checkENSAI()\n"
                "    if CanDualParry() ~= nil and (env(ActionRequest, ACTION_ARM_L1) == TRUE or Cancel(ACTION_ARM_L1)) then\n"
                "        return TRUE\n"
                "    end\n"
                "    return c_IsEnableSwordArts\n"
                "end\n"
                "\n"
                "function checkSAI()\n"
                "    if CanDualParry() ~= nil and (env(ActionRequest, ACTION_ARM_L1) == TRUE or Cancel(ACTION_ARM_L1)) then\n"
                "        SetVariable(\"IsEnoughArtPointsL2\", 0)\n"
                "        return 92\n"
                "    end\n"
                "    return c_SwordArtsID\n"
                "end\n"
                "\n"
                "function checkSAH()\n"
                "    local parry = CanDualParry()\n"
                "    if parry ~= nil and (env(ActionRequest, ACTION_ARM_L1) == TRUE or Cancel(ACTION_ARM_L1)) then\n"
                "        act(SetWeaponCancelType, env(GetWeaponCancelType, parry))\n"
                "        return parry\n"
                "    end\n"
                "    return c_SwordArtsHand\n"
                "end\n"
                "\n"
                "function CanDualParry()\n"
                "    if env(IsCOMPlayer) == TRUE then return nil end\n"
                "    local lh = env(GetEquipWeaponCategory, HAND_LEFT)\n"
                "    local ls = powerstances[lh]\n"
                "    if parriers[env(GetEquipWeaponCategory, HAND_RIGHT)] ~= nil and c_Style == HAND_RIGHT_BOTH then\n"
                "        return HAND_RIGHT\n"
                "    end\n"
                "    if c_Style ~= HAND_RIGHT_BOTH and parriers[env(GetEquipWeaponCategory, HAND_LEFT)] ~= nil and (IsEnableDualWielding() ~= -1 or c_Style == HAND_LEFT_BOTH or ls ~= nil and lh ~= throw and ls[3] == 0) then\n"
                "        return HAND_LEFT\n"
                "    end\n"
                "    return nil\n"
                "end\n"
                "\n"
                "function CanPoke()\n"
                "    if pokers[env(GetEquipWeaponCategory, HAND_RIGHT)] == TRUE and CanDualParry() == nil and env(ActionDuration, ACTION_ARM_L1) > 0 then\n"
                "        return TRUE\n"
                "    end\n"
                "    return FALSE\n"
                "end\n"
                "\n"
                "function checkR1()\n"
                "    local request = env(ActionRequest, ACTION_ARM_R1)\n"
                "    if IsEnableDualWielding() ~= -1 and CanPoke() ~= TRUE and env(IsCOMPlayer) == FALSE then\n"
                "        return FALSE\n"
                "    end\n"
                "    return request\n"
                "end\n"
                "\n"
                "function checkL1()\n"
                "    local request = env(ActionRequest, ACTION_ARM_L1)\n"
                "    if env(ActionRequest, ACTION_ARM_R1) == TRUE and checkR1() == FALSE then\n"
                "        return TRUE\n"
                "    elseif (request == TRUE or Cancel(ACTION_ARM_L1)) and CanDualParry() ~= nil then\n"
                "        return FALSE\n"
                "    elseif request == TRUE and IsEnableDualWielding() ~= -1 and env(IsCOMPlayer) == FALSE then\n"
                "        return FALSE\n"
                "    elseif Cancel(ACTION_ARM_L1) and IsWeaponCanGuard() == TRUE then\n"
                "        return TRUE\n"
                "    elseif IsEnableDualWielding() ~= -1 then\n"
                "        return FALSE\n"
                "    end\n"
                "    return request\n"
                "end\n"
                "\n"
                "function checkL2()\n"
                "    local request = env(ActionRequest, ACTION_ARM_L2)\n"
                "    if CanDualParry() ~= nil and (env(ActionRequest, ACTION_ARM_L1) == TRUE or Cancel(ACTION_ARM_L1)) then\n"
                "        return TRUE\n"
                "    elseif Cancel(ACTION_ARM_L2) and (c_SwordArtsID == 92 or c_SwordArtsID == 93 or c_SwordArtsID == 97) then\n"
                "        return TRUE\n"
                "    end\n"
                "    return request\n"
                "end\n"
                "\n"
                "function Update()"
            },
            {
                "    local rightSpecialKind = env(GetEquipWeaponSpecialCategoryNumber, HAND_RIGHT)\n"
                "    local leftSpecialKind = env(GetEquipWeaponSpecialCategoryNumber, HAND_LEFT)",
                "    local rightSpecialKind = env(GetEquipWeaponSpecialCategoryNumber, HAND_RIGHT)\n"
                "    local leftSpecialKind = env(GetEquipWeaponSpecialCategoryNumber, HAND_LEFT)\n\n"
                "    local ls = powerstances[leftKind]\n"
                "    local rs = powerstances[rightKind]\n"
                "    if ls ~= nil and rs ~= nil and env(IsCOMPlayer) == FALSE\n"
                "    and ( ( rs[1] ~= 0 and ls[1] ~= 0 and ( ls[2] == 1 or rs[2] ~= 1 ) )\n"
                "    or ( rs[2] ~= 0 and ls[2] ~= 0 and ( ls[1] == 1 or rs[1] ~= 1 ) ) )\n"
                "    then\n"
                "        if ls[3] == rs[3]\n"
                "        or ls[3] < rs[3] and ( ls[3] + ls[4] ) >= ( rs[3] - rs[5] )\n"
                "        or ls[3] > rs[3] and ( ls[3] - ls[5] ) <= ( rs[3] + rs[4] )\n"
                "        or rs[3] < ls[3] and ( rs[3] + rs[4] ) >= ( ls[3] - ls[5] )\n"
                "        or rs[3] > ls[3] and ( rs[3] - rs[5] ) <= ( ls[3] + ls[4] )\n"
                "        then\n"
                "            return HAND_RIGHT\n"
                "        end\n"
                "    end\n\n"
            },
    // movement
            {
                "env(ActionRequest, ACTION_ARM_L3) == TRUE and c_IsStealth == FALSE",
                "env(ActionRequest, ACTION_ARM_L3) == TRUE and c_IsStealth == FALSE and not b_[\"sprint\"]"
            },
            {
                "    elseif env(GetSpEffectID, 100220) == TRUE then",
                "    elseif b_[\"sprint\"] and GetVariable(\"MoveSpeedLevel\") > 0 or env(IsCOMPlayer) == TRUE and env(GetSpEffectID, 100220) == TRUE then\n        act(LockonFixedAngleCancel)"
            },
            {
                "function ExecEvasion(backstep_limit, estep, is_usechainrecover)\n    if ",
                "function ExecEvasion(backstep_limit, estep, is_usechainrecover)\n    if env(ActionCancelRequest, ACTION_ARM_L3) == FALSE and "
            },
            {
                "function ExecEvent(state)",
                "function ExecEvent(state)\n"
                "    if (string.find(state, \"Attack\") or string.find(state, \"SwordArts\") or string.find(state, \"Magic\"))\n"
                "    and not (string.find(state, \"Step\") or state == \"W_Rolling\" or string.find(state, \"Shield\")) then\n"
                "        b_[\"cancelrate\"] = os.clock()\n"
                "    else\n"
                "        b_[\"cancelrate\"] = 0\n"
                "    end\n\n"
                "    b_[\"last\"] = state\n\n"
            },
            { "env(ActionRequest, ACTION_ARM_CHANGE_STYLE) == FALSE", "env(ActionRequest, ACTION_ARM_CHANGE_STYLE) == FALSE and not Cancel(ACTION_ARM_CHANGE_STYLE)" },
            { "env(IsGuardFromAtkCancel) == FALSE", "env(IsGuardFromAtkCancel) == FALSE and not Cancel(ACTION_ARM_L1)" },
            { "    act(SetCanChangeEquipmentOff)\n    act(DisallowAdditiveTurning, TRUE)", "    act(SetCanChangeEquipmentOff)" },
            { " or env(MovementRequestDuration) <= 0", "" },
            // { "env(ActionRequest, ACTION_ARM_SP_MOVE)", "env(ActionRequest, ACTION_ARM_L3) == TRUE" },
            { "env(ActionRequest, ACTION_ARM_SP_MOVE)", "env(ActionRequest, ACTION_ARM_L3)" },
            { "evasionRequest == TRUE", "evasionRequest == TRUE" },
            { "env(ActionRequest, ACTION_ARM_L3) == FALSE", "env(ActionRequest, ACTION_ARM_SP_MOVE) == FALSE" },
            { "if env(ActionDuration, ACTION_ARM_SP_MOVE) > 0 then", "if env(ActionDuration, ACTION_ARM_L3) > 0 then" },
            { "env(ActionDuration, ACTION_ARM_SP_MOVE) <= 0", "env(ActionDuration, ACTION_ARM_L3) <= 0" },
            {
                "    local sp_action = env(ActionDuration, ACTION_ARM_SP_MOVE)",
                "    local sp_action = env(ActionDuration, ACTION_ARM_SP_MOVE)\n"
                "        if sp_action > 0 then\n"
                "            LadderSendCommand(LADDER_EVENT_COMMAND_EXIT)\n"
                "            LadderSetActionState(LADDER_ACTION_INVALID)\n"
                "            ExecEvent(\"W_LadderDrop\")\n"
                "            return TRUE\n"
                "        end\n"
            },
            // { "    c_RollingAngle = env(GetRollAngle) * 0.009999999776482582\n    c_ArtsRollingAngle = env(GetSwordArtsRollAngle) * 0.009999999776482582", "    c_RollingAngle = GetVariable(\"MoveAngle\")\n    c_ArtsRollingAngle = GetVariable(\"MoveAngle\")" },
            {
                "    if env(ActionRequest, ACTION_ARM_ROLLING) == TRUE then",
                "\n"
                "    if env(IsCOMPlayer) == FALSE then\n"
                "        if env(ActionRequest, ACTION_ARM_EMERGENCYSTEP) == TRUE and (env(IsEmergencyEvasionPossible, 0) == TRUE or env(IsEmergencyEvasionPossible, 1) == TRUE) then\n"
                "            return ATTACK_REQUEST_EMERGENCYSTEP\n"
                "        end\n"
                "        if env(ActionRequest, ACTION_ARM_SP_MOVE) == TRUE or (string.find(b_[\"last\"], \"W_Land\") or Cancel(ACTION_ARM_SP_MOVE) or b_[\"draw\"]) and env(ActionDuration, ACTION_ARM_SP_MOVE) > 0 and env(IsLanding) == TRUE then\n"
                "            if b_[\"last\"] ~= \"W_Rolling\" and GetVariable(\"MoveAngle\") > 140 or GetVariable(\"MoveAngle\") < -140 or GetVariable(\"MoveSpeedLevel\") <= 0 then\n"
                "                return ATTACK_REQUEST_BACKSTEP\n"
                "            end\n"
                "            return ATTACK_REQUEST_ROLLING\n"
                "        end\n"
                "        return ATTACK_REQUEST_INVALID\n"
                "    end\n"
                "\n"
                "    if env(ActionRequest, ACTION_ARM_ROLLING) == TRUE then"
            },
            {
                "        local turn_angle_real = 200\n"
                "\n"

                "        if GetVariable(\"IsLockon\") == false and env(IsPrecisionShoot) == FALSE and env(IsCOMPlayer) == FALSE",
                "        local turn_angle_real = 200\n"
                "\n"

                "        if env(IsPrecisionShoot) == FALSE and env(IsCOMPlayer) == FALSE"
            },
            { "function DefaultBackStep_onActivate()", "function DefaultBackStep_onActivate()\n     act(TurnToLockonTargetImmediately)" },
            { "function DefaultBackStep_onUpdate()", "function DefaultBackStep_onUpdate()\n     act(TurnToLockonTargetImmediately)" },
            { "function Rolling_onUpdate()", "function Rolling_onUpdate()\n     act(LockonFixedAngleCancel)" },
            { "function Rolling_Selftrans_onUpdate()", "function Rolling_Selftrans_onUpdate()\n     act(LockonFixedAngleCancel)" },
            {
                "\"W_AttackRightBackstep\", \"W_AttackRightHeavy1Start\",\n"
                "        \"W_AttackLeftLight1\", \"W_AttackLeftHeavy1\", \"W_AttackBothBackstep\", \"W_AttackBothHeavy1Start\",",
                "\"W_AttackRightBackstep\", \"W_AttackRightHeavyDash\",\n"
                "        \"W_AttackLeftLight1\", \"W_AttackLeftHeavy1\", \"W_AttackBothBackstep\", \"W_AttackBothHeavyDash\","
            },
            {
                "            if env(GetSpEffectID, 100020) == TRUE then",
                "            if env(GetSpEffectID, 100020) == TRUE and env(IsOnMount) == TRUE then"
            },
            {
                "                SetVariable(\"ToggleDash\", 0)\n            else",
                "                SetVariable(\"ToggleDash\", 0)\n            elseif env(IsOnMount) == TRUE then"
            },
            {
                "function Update()",
                "function Cancel(actype)\n"
                "    local dur = env(ActionDuration, actype)\n"
                "    return dur > 0 and dur <= 60 and os.clock() - b_[\"cancelrate\"] < 1\n"
                "end\n"
                "\n"
                "fponce = true\n"
                "\n"
                "function Update()\n"
                "    act(AddSpEffect, 20380100)\n"
                "    act(AddSpEffect, 102000)\n"
                "    act(AddSpEffect, 3450)\n"
                "\n"
                "    if env(GetSpEffectID, 350401) == TRUE then\n"
                "        if fponce then\n"
                "            act(AddSpEffect, 5031601)\n"
                "            act(AddSpEffect, 5031601)\n"
                "            fponce = false\n"
                "        end\n"
                "    else\n"
                "        fponce = true\n"
                "    end\n"
                "\n"
                "    if (env(ActionDuration, ACTION_ARM_L3) >= 240\n"
                "        or env(ActionDuration, ACTION_ARM_L3) > 0 and GetVariable(\"MoveSpeedLevel\") > 0 and c_IsStealth == FALSE\n"
                "        or c_IsStealth == TRUE)\n"
                "    and env(GetStamina) > 0 then\n"
                "        b_[\"sprint\"] = true\n"
                "    elseif env(ActionCancelRequest, ACTION_ARM_L3) == FALSE then\n"
                "        b_[\"sprint\"] = false\n"
                "    end\n"
                "    if string.find(b_[\"last\"], \"Start\") then\n"
                "        if string.find(b_[\"last\"], \"Heavy\") or string.find(b_[\"last\"], \"Ride\") and string.find(b_[\"last\"], \"Hard\") then\n"
                "            if env(ActionDuration, ACTION_ARM_R2) > 240 or env(ActionDuration, ACTION_ARM_L2) > 240 then\n"
                "                b_[\"last\"] = \"\"\n"
                "            elseif env(ActionDuration, ACTION_ARM_R2) <= 0 and env(ActionDuration, ACTION_ARM_L2) <= 0 then\n"
                "                ExecEventAllBody(b_[\"last\"]:gsub(\"Start\", \"End\"))\n\n"
                "            end\n"
                "        elseif string.find(b_[\"last\"], \"Arts\") or string.find(b_[\"last\"], \"Attack\") then\n"
                "            ExecEventAllBody(b_[\"last\"]:gsub(\"Start\", \"End\"))\n"
                "        end\n"
                "    end\n"
                // "    if IsEnableDualWielding() == -1 then\n"
                // "        act(AddSpEffect, 7210)\n"
                // "        act(AddSpEffect, 7220)\n"
                // "    end\n"
                // "    if c_Style == HAND_RIGHT_BOTH or c_Style == HAND_LEFT_BOTH then\n"
                // "        act(AddSpEffect, 7230)\n"
                // "        act(AddSpEffect, 7240)\n"
                // "    end\n"
            },
            {
                "global = {}",
                "b_ = {}\n"
                "\n"
                "l1scale = 0.965\n"
                "l1rest = {}\n"
                "l1clock = {}\n"
                "l1time = g_FrameCount\n"
                "cancelwait = 0\n"
                "\n"
                "breath = os.clock()\n"
                "damagelevelers = {}\n"
                "global = {}"
            },
            { "env(GetDamageLevel)", "TakeABreath()" },
            {
                "function Update()",
                "function TakeABreath()\n"
                "    local level = env(GetDamageLevel)\n"
                "    breath = os.clock()\n"
                "    damagelevelers[level] = damagelevelers[level] or 0\n"
                "    if breath - damagelevelers[level] > 1 then\n"
                "        damagelevelers[level] = breath\n"
                "    else\n"
                "        level = 0\n"
                "    end\n"
                "    return level\n"
                "end\n"
                "\n"
                "function Update()\n"
            },
    // attack speed
            {
                "function Update()",
                "function atkhand()\n"
                "    if c_Style == HAND_LEFT_BOTH then\n"
                "        return HAND_LEFT\n"
                "    end\n"
                "    return HAND_RIGHT\n"
                "end\n"
                "\n"
                "function dualtime(move)\n"
                "    local key = env(GetEquipWeaponCategory, HAND_RIGHT) .. move\n"
                "    if l1clock[key] == nil then\n"
                "        local redrawl1 = false\n"
                "\n"
                "        for k,_ in pairs(l1clock) do\n"
                "            if l1rest[k] == nil or l1rest[k] > (0.8 + g_FrameCount - l1clock[k]) ^ (1.0 / l1scale) then\n"
                "                l1rest[k] = g_FrameCount - l1clock[k]\n"
                "                redrawl1 = true\n"
                "            end\n"
                "            l1clock[k] = nil\n"
                "        end\n"
                "\n"
                "        if redrawl1 then\n"
                "            local file = io.open(\"speedstorage.txt\", \"w\")\n"
                "            for k,v in pairs(l1rest) do\n"
                "                file:write(k .. \"\\n\")\n"
                "                file:write(v .. \"\\n\")\n"
                "            end\n"
                "            io.close(file)\n"
                "        end\n"
                "\n"
                "        l1clock[key] = g_FrameCount\n"
                "    end\n"
                "end\n"
                "\n"
                "function Update()\n"
                "    if not b_[\"l1pass\"] then\n"
                "        b_[\"l1pass\"] = true\n"
                "\n"
                "        local readfile = io.open(\"speedstorage.txt\", \"r\")\n"
                "        while true do\n"
                "            if readfile == nil then\n"
                "                break\n"
                "            end\n"
                "\n"
                "            local speedkey = readfile:read()\n"
                "            if speedkey == nil then\n"
                "                break\n"
                "            end\n"
                "\n"
                "            local speedval = readfile:read()\n"
                "            if speedval == nil then\n"
                "                break\n"
                "            end\n"
                "\n"
                "            l1rest[speedkey] = tonumber(speedval)\n"
                "        end\n"
                "        io.close(readfile)\n"
                "    end\n"
            },
            {
                "    local request = GetAttackRequest(is_guard)\n\n    if request == ATTACK_REQUEST_INVALID then\n        return FALSE",
                "    local request = GetAttackRequest(is_guard)\n\n    if request == ATTACK_REQUEST_INVALID then\n"
                "        if b_[\"last\"] ~= nil and cancelwait > 0 and string.find(b_[\"last\"], \"DualLight\") and IsEnableDualWielding() ~= -1 and env(ActionDuration, ACTION_ARM_R1) > 0 and env(ActionDuration, ACTION_ARM_R1) < 240 and g_FrameCount - l1time > cancelwait then\n"
                "            request = ATTACK_REQUEST_DUAL_RIGHT\n"
                "            cancelwait = 0\n"
                "        else\n"
                "            return FALSE\n"
                "        end\n"
            },
            {
                "        is_Dual = TRUE\n        ExecEventAllBody(l1)",
                "        dualtime(l1)\n"
                "        l1time = g_FrameCount\n"
                "        if l1rest[env(GetEquipWeaponCategory, HAND_RIGHT) .. l1] ~= nil then\n"
                "            cancelwait = l1rest[env(GetEquipWeaponCategory, HAND_RIGHT) .. l1] ^ l1scale\n"
                "        else\n"
                "            cancelwait = 0\n"
                "        end\n"
                "        is_Dual = TRUE\n        ExecEventAllBody(l1)"
            },
    // bow
            {
                "function Update()",
                "function bowcool()\n"
                "    local time = 90\n"
                "    if env(GetEquipWeaponCategory, atkhand()) ~= WEAPON_CATEGORY_LARGE_ARROW then\n"
                "        time = 30\n"
                "    end\n"
                "    return time\n"
                "end\n"
                "\n"
                "function Update()"
            },
            {
                "    g_FrameCount = g_FrameCount + 1",
                "    g_FrameCount = g_FrameCount + 1\n"
                "    if b_[\"draw\"] then\n"
                "        if b_[\"fulldraw\"] then\n"
                "            b_[\"drawcool\"] = g_FrameCount\n"
                "            if c_Style == HAND_LEFT_BOTH then\n"
                "                act(AddSpEffect, 1703)\n"
                "            else\n"
                "                act(AddSpEffect, 1701)\n"
                "            end\n"
                "        end\n"
                "    end\n"
                "    if (b_[\"draw\"] and not b_[\"fulldraw\"] or not b_[\"draw\"]) and g_FrameCount - b_[\"drawcool\"] > bowcool() * 1.75 then\n"
                "        if c_Style == HAND_LEFT_BOTH then\n"
                "            if env(GetSpEffectID, 1703) == TRUE then\n"
                "                act(AddSpEffect, 1666)\n"
                "            end\n"
                "        else\n"
                "            if env(GetSpEffectID, 1701) == TRUE then\n"
                "                act(AddSpEffect, 1661)\n"
                "            end\n"
                "        end\n"
                "        if env(GetEquipWeaponCategory, atkhand()) ~= WEAPON_CATEGORY_LARGE_ARROW then\n"
                "            act(AddSpEffect, 6903)\n"
                "        else\n"
                "            act(AddSpEffect, 6909)\n"
                "        end\n"
                "    end\n"
                "    b_[\"fulldraw\"] = false\n"
                "    b_[\"draw\"] = false\n"
            },
            {
                "function MoveStart(blend_type, event, gen_hand)",
                "function MoveStart(blend_type, event, gen_hand)\n"
                "    if b_[\"fulldraw\"] and env(GetEquipWeaponCategory, atkhand()) == WEAPON_CATEGORY_LARGE_ARROW then\n"
                "        return\n"
                "    end\n"
            },
            {
                "    if env(IsAnimEnd, 1) == TRUE then\n"
                "        if g_ArrowSlot == 0 then",
                "    if env(IsAnimEnd, 1) == TRUE or g_FrameCount - b_[\"startdraw\"] > bowcool() and env(ActionDuration, ACTION_ARM_R1) <= 0 and env(ActionDuration, ACTION_ARM_R2) <= 0 then\n"
                "        if g_ArrowSlot == 0 then"
            },
            {
                "function ArrowLowerCommonFunction(event, lower_state, to_idle_on_cancel)",
                "function ArrowLowerCommonFunction(event, lower_state, to_idle_on_cancel)\n"
                "    if event ~= Event_AttackArrowRightFireMove and event ~= Event_AttackArrowLeftFireMove then\n"
                "        b_[\"draw\"] = true\n"
                "        act(TurnToLockonTargetImmediately)\n"
                "    end"
            },
            { "\n    if g_ArrowSlot == 0 then", "\n    b_[\"fulldraw\"] = true\n    if g_ArrowSlot == 0 then" },
            { "function AttackArrowRight_Activate()", "function AttackArrowRight_Activate()\n    b_[\"startdraw\"] = g_FrameCount" },
            { "function AttackArrowLeft_Activate()", "function AttackArrowLeft_Activate()\n    b_[\"startdraw\"] = g_FrameCount" },
            { "function SwordArtsLeft_Activate()", "function SwordArtsLeft_Activate()\n    b_[\"startdraw\"] = g_FrameCount" },
            { "function SwordArts_Activate()", "function SwordArts_Activate()\n    b_[\"startdraw\"] = g_FrameCount" },
            { "Fire_Upper_onUpdate()", "Fire_Upper_onUpdate()\n    b_[\"startdraw\"] = g_FrameCount\n    b_[\"draw\"] = false" },
            { "FireMove_Upper_onUpdate()", "FireMove_Upper_onUpdate()\n    b_[\"startdraw\"] = g_FrameCount\n    b_[\"draw\"] = false" },
            { "FireDash_onUpdate()", "FireDash_onUpdate()\n    b_[\"startdraw\"] = g_FrameCount\n    b_[\"draw\"] = false" },
            { "FireStep_onUpdate()", "FireStep_onUpdate()\n    b_[\"startdraw\"] = g_FrameCount\n    b_[\"draw\"] = false" },
        }
    );

    ::std::ifstream t( ::common::homedir + L"twye_options.txt" );
    ::std::stringstream buffer;
    buffer << t.rdbuf();
    pattern.push_back( {
        "global = {}",
        buffer.str() + "\n"
        "attackrequests = {\n"
        "    [ ACTION_ARM_R1 ] = FALSE,\n"
        "    [ ACTION_ARM_R2 ] = FALSE,\n"
        "    [ ACTION_ARM_L1 ] = FALSE,\n"
        "    [ ACTION_ARM_L2 ] = FALSE,\n"
        "}\n"
        "\n"
        "global = {}"
    } );

    ::carefully( "c_SwordArtsID", "checkSAI()", pattern, careful );
    ::carefully( "c_SwordArtsHand", "checkSAH()", pattern, careful );
    ::carefully( "c_IsEnableSwordArts", "checkENSAI()", pattern, careful );

    return ::common::replace( ::common::fromw( path ), pattern, true, careful ).second;
}

void ::common::hks::hksmain() {
    for ( ::std::wstring i : { L"c0000.hks", L"c9997.hks" } ) {
        ::common::time();

        ::std::wstring path = ::common::moddir + L"action\\script\\" + i;

        if ( !::std::filesystem::exists( path ) ) {
            ::common::write( L"found missing files, acquiring " + i );

            ::std::filesystem::create_directories( ::common::moddir + L"action\\script\\" );

            if ( !::system( ::common::fromw( L"curl -o \"" + path + L"\" \"https://raw.githubusercontent.com/ividyon/EldenRingHKS/main/" + i + L"\"" ).c_str() ) )
                ::common::write( L"succesfully acquired " + i );
            else {
                ::common::write( L"failed to acquire " + i );
                continue;
            }
        }

        DWORD attributes = ::GetFileAttributesW( path.c_str() );
        bool read = attributes & FILE_ATTRIBUTE_READONLY;

        if ( read ) attributes &= ~FILE_ATTRIBUTE_READONLY;
        ::SetFileAttributesW( path.c_str(), attributes );

        if ( read && ::std::filesystem::exists( path + L".bak" ) )
            ::std::filesystem::copy_file( path + L".bak", path, ::std::filesystem::copy_options::overwrite_existing );
        else
            ::std::filesystem::copy_file( path, path + L".bak", ::std::filesystem::copy_options::overwrite_existing );

        if ( i == L"c0000.hks" ) ::common::write( L"modified and verified ", ::c0000( path ), L" characters for the c0000.hks in ", ::common::time() , L" microseconds" );
        if ( i == L"c9997.hks" ) ::common::write( L"modified and verified ", ::c9997( path ), L" characters for the c9997.hks in ", ::common::time() , L" microseconds" );

        ::SetFileAttributesW( path.c_str(), FILE_ATTRIBUTE_READONLY );
    }
}