#include "common.hpp"

#include <filesystem>

void careful( std::string original, std::string replace, std::vector<std::pair<std::string, std::string>>& target ) {
    target.push_back( { "= " + original, "= " + replace } );
    target.push_back( { original + " ==", replace + " ==" } );
    target.push_back( { "(" + original + ")", "(" + replace + ")" } );
    target.push_back( { "[" + original + "]", "[" + replace + "]" } );
    target.push_back( { "(" + original + ",", "(" + replace + "," } );
    target.push_back( { " " + original + ")", " " + replace + ")" } );
}

size_t c9997( std::wstring path ) {
    std::vector<std::pair<std::string, std::string>> pattern =
    {
        {
            "env(GetDamageLevel)",
            "TakeABreath()"
        },
        {
            "function Update()",
            "function TakeABreath()\n"
            "    local level = env(GetDamageLevel)\n"
            "    local offset = 0.450 + (level / 100 + 0.20) * 5\n"
            "    if time - damagelevelers[level] > offset then\n"
            "        time = os.clock()\n"
            "        damagelevelers[level] = time\n"
            "        return level\n"
            "    end\n"
            "    damagelevelers[level] = time\n"
            "    return DAMAGE_LEVEL_NONE\n"
            "end\n"
            "\n"
            "function Update()\n"
        },
        {
            "global = {}",
            "time = os.clock()\n"
            "damagelevelers = {\n"
            "    [DAMAGE_LEVEL_NONE] = 0,\n"
            "    [DAMAGE_LEVEL_SMALL] = 0,\n"
            "    [DAMAGE_LEVEL_MIDDLE] = 0,\n"
            "    [DAMAGE_LEVEL_LARGE] = 0,\n"
            "    [DAMAGE_LEVEL_LARGE_BLOW] = 0,\n"
            "    [DAMAGE_LEVEL_PUSH] = 0,\n"
            "    [DAMAGE_LEVEL_FLING] = 0,\n"
            "    [DAMAGE_LEVEL_SMALL_BLOW] = 0,\n"
            "    [DAMAGE_LEVEL_MINIMUM] = 0,\n"
            "    [DAMAGE_LEVEL_UPPER] = 0,\n"
            "    [DAMAGE_LEVEL_EX_BLAST] = 0,\n"
            "    [DAMAGE_LEVEL_BREATH] = 0,\n"
            "}\n"
            "\n"
            "global = {}"
        },
    };

    return common::replace( common::fromw( path ), pattern , true ).second;
}

size_t c0000( std::wstring path ) {
    std::vector<std::pair<std::string, std::string>> pattern =
    {
// powerstance
        {
            "env(ActionRequest, ACTION_ARM_R1)",
            "checkR1()"
        },
        {
            "env(ActionRequest, ACTION_ARM_L1)",
            "checkL1()"
        },
        {
            "env(ActionRequest, ACTION_ARM_L2)",
            "checkL2()"
        },
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
        {
            "is_spear == TRUE or is_rapier == TRUE or is_large_spear == TRUE or is_large_rapier == TRUE",
            "pokers[env(GetEquipWeaponCategory, HAND_RIGHT)] == TRUE"
        },
        {
            "arts_cat == WEAPON_CATEGORY_SHORT_SWORD",
            "arts_cat == dagger or checkSAI() == 92 and CanDualParry() ~= nil and env(ActionRequest, ACTION_ARM_L1) == TRUE and parriers[wep_cat] == dagger"
        },
        {
            "arts_cat == WEAPON_CATEGORY_CURVEDSWORD",
            "arts_cat == curved or checkSAI() == 92 and CanDualParry() ~= nil and env(ActionRequest, ACTION_ARM_L1) == TRUE and parriers[wep_cat] == curved"
        },
        {
            "function GetHandChangeType(hand)",
            "function GetHandChangeType(hand)\n"
            "    if CanDualParry() ~= nil then\n"
            "        return WEAPON_CHANGE_REQUEST_INVALID\n"
            "    end\n"
        },
        {
            "function Update()",
            "function checkENSAI()\n"
            "    if CanDualParry() ~= nil and env(ActionRequest, ACTION_ARM_L1) == TRUE then\n"
            "        return TRUE\n"
            "    end\n"
            "    return c_IsEnableSwordArts\n"
            "end\n"
            "\n"
            "function checkSAI()\n"
            "    if CanDualParry() ~= nil and env(ActionRequest, ACTION_ARM_L1) == TRUE then\n"
            "        SetVariable(\"IsEnoughArtPointsL2\", 0)\n"
            "        return 92\n"
            "    end\n"
            "    return c_SwordArtsID\n"
            "end\n"
            "\n"
            "function checkSAH()\n"
            "    local parry = CanDualParry()\n"
            "    if parry ~= nil and env(ActionRequest, ACTION_ARM_L1) == TRUE then\n"
            "        act(SetWeaponCancelType, env(GetWeaponCancelType, parry))\n"
            "        return parry\n"
            "    end\n"
            "    return c_SwordArtsHand\n"
            "end\n"
            "\n"
            "function CanDualParry()\n"
            "    if env(IsCOMPlayer) == TRUE then return nil end\n"
            "    if parriers[env(GetEquipWeaponCategory, HAND_LEFT)] ~= nil and (IsEnableDualWielding() ~= -1 or c_Style == HAND_LEFT_BOTH) then\n"
            "        return HAND_LEFT\n"
            "    end\n"
            "    if parriers[env(GetEquipWeaponCategory, HAND_RIGHT)] ~= nil and c_Style == HAND_RIGHT_BOTH then\n"
            "        return HAND_RIGHT\n"
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
            "    elseif request == TRUE and CanDualParry() ~= nil then\n"
            "        return FALSE\n"
            "    elseif request == TRUE and IsEnableDualWielding() ~= -1 and env(IsCOMPlayer) == FALSE then\n"
            "        return FALSE\n"
            "    end\n"
            "    return request\n"
            "end\n"
            "\n"
            "function checkL2()\n"
            "    local request = env(ActionRequest, ACTION_ARM_L2)\n"
            "    if CanDualParry() ~= nil and env(ActionRequest, ACTION_ARM_L1) == TRUE and env(IsCOMPlayer) == FALSE then\n"
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
            "    end\n"
        },
        {
            "global = {}",
            "claw = WEAPON_CATEGORY_CLAW\n"
            "fist = WEAPON_CATEGORY_FIST\n"
            "beast = WEAPON_CATEGORY_BEAST_CLAW\n"
            "dagger = WEAPON_CATEGORY_SHORT_SWORD\n"
            "throw = WEAPON_CATEGORY_THROW_DAGGER\n"
            "backhand = WEAPON_CATEGORY_BACKHAND_SWORD\n"
            "axe = WEAPON_CATEGORY_AX\n"
            "flail = WEAPON_CATEGORY_FLAIL\n"
            "whip = WEAPON_CATEGORY_WHIP\n"
            "hammer = WEAPON_CATEGORY_HAMMER\n"
            "rapier = WEAPON_CATEGORY_RAPIER\n"
            "katana = WEAPON_CATEGORY_KATANA\n"
            "curved = WEAPON_CATEGORY_CURVEDSWORD\n"
            "straight = WEAPON_CATEGORY_STRAIGHT_SWORD\n"
            "spear = WEAPON_CATEGORY_SPEAR\n"
            "twin = WEAPON_CATEGORY_TWINBLADE\n"
            "halberd = WEAPON_CATEGORY_HALBERD\n"
            "scythe = WEAPON_CATEGORY_LARGE_SCYTHE\n"
            "perfume = WEAPON_CATEGORY_PERFUME_BOTTLE\n"
            "l_spear = WEAPON_CATEGORY_LARGE_SPEAR\n"
            "l_rapier = WEAPON_CATEGORY_LARGE_RAPIER\n"
            "l_straight = WEAPON_CATEGORY_LARGE_SWORD\n"
            "l_katana = WEAPON_CATEGORY_LARGE_KATANA\n"
            "l_curved = WEAPON_CATEGORY_LARGE_CURVEDSWORD\n"
            "l_axe = WEAPON_CATEGORY_LARGE_AX\n"
            "l_hammer = WEAPON_CATEGORY_LARGE_HAMMER\n"
            "ll_straight = WEAPON_CATEGORY_LIGHT_LARGE_SWORD\n"
            "xl_straight = WEAPON_CATEGORY_EXTRALARGE_SWORD\n"
            "xl_hammer = WEAPON_CATEGORY_EXTRALARGE_AXHAMMER\n"
            "\n"
            "attackrequests = {\n"
            "    [ACTION_ARM_R1] = FALSE,\n"
            "    [ACTION_ARM_R2] = FALSE,\n"
            "    [ACTION_ARM_L1] = FALSE,\n"
            "    [ACTION_ARM_L2] = FALSE,\n"
            "}\n"
            "\n"
            "pokers = {\n"
            "    [spear] = TRUE,\n"
            "    [rapier] = TRUE,\n"
            "    [l_spear] = TRUE,\n"
            "    [l_rapier] = TRUE,\n"
            "}\n"
            "\n"
            "parriers = {\n"
            "    [claw] = dagger,\n"
            "    [fist] = dagger,\n"
            "    [rapier] = dagger,\n"
            "    [dagger] = dagger,\n"
            "    [throw] = dagger,\n"
            "    [backhand] = dagger,\n"
            "    [straight] = dagger,\n"
            "    [ll_straight] = dagger,\n"
            "    [l_straight] = dagger,\n"
            "    [l_rapier] = dagger,\n"
            "    [perfume] = dagger,\n"
            "    [hammer] = dagger,\n"
            "    [axe] = dagger,\n"
            "    [whip] = dagger,\n"
            "    [flail] = dagger,\n"
            "    [beast] = dagger,\n"
            "    [l_katana] = curved,\n"
            "    [curved] = curved,\n"
            "    [katana] = curved,\n"
            "    [scythe] = curved,\n"
            "    [halberd] = curved,\n"
            "    [spear] = curved,\n"
            "    [twin] = curved,\n"
            "}\n"
            "\n"
            "powerstances = {\n"
            // poke, slash, weight, up, down
            "    [claw] =\n"
            "        { 0,1,0,0,0 },\n"
            "    [fist] =\n"
            "        { 0,1,0,0,0 },\n"
            "    [beast] =\n"
            "        { 0,1,0,0,0 },\n"
            "    [dagger] =\n"
            "        { 3,1,0,1,0 },\n"
            "    [backhand] =\n"
            "        { 0,1,0,1,0 },\n"
            "    [axe] =\n"
            "        { 0,1,0,1,0 },\n"
            "    [flail] =\n"
            "        { 0,1,0,1,0 },\n"
            "    [hammer] =\n"
            "        { 0,1,0,1,0 },\n"
            "    [rapier] =\n"
            "        { 3,3,1,1,1 },\n"
            "    [katana] =\n"
            "        { 3,1,1,1,1 },\n"
            "    [curved] =\n"
            "        { 0,1,1,0,1 },\n"
            "    [straight] =\n"
            "        { 3,1,1,1,1 },\n"
            "    [spear] =\n"
            "        { 1,0,1,1,0 },\n"
            "    [twin] =\n"
            "        { 3,1,1,1,0 },\n"
            "    [scythe] =\n"
            "        { 0,1,1,2,0 },\n"
            "    [halberd] =\n"
            "        { 3,1,2,1,0 },\n"
            "    [l_spear] =\n"
            "        { 1,0,2,1,0 },\n"
            "    [l_rapier] =\n"
            "        { 1,3,2,1,0 },\n"
            "    [l_straight] =\n"
            "        { 3,1,2,1,0 },\n"
            "    [l_katana] =\n"
            "        { 3,1,2,1,0 },\n"
            "    [l_curved] =\n"
            "        { 0,1,2,1,0 },\n"
            "    [l_axe] =\n"
            "        { 0,1,3,0,0 },\n"
            "    [l_hammer] =\n"
            "        { 0,1,3,0,0 },\n"
            "    [xl_straight] =\n"
            "        { 0,1,3,0,0 },\n"
            "    [xl_hammer] =\n"
            "        { 0,1,3,0,0 },\n"
            "    [ll_straight] =\n"
            "        { 3,1,3,0,1 },\n"
            "}\n"
            "\n"
            "global = {}"
        },
// movement
        {
            "env(ActionRequest, ACTION_ARM_L3) == TRUE",
            "env(ActionCancelRequest, ACTION_ARM_L3) == TRUE and b_[\"sprint\"] == 0"
        },
        {
            "    elseif env(GetSpEffectID, 100220) == TRUE then",
            "    elseif b_[\"sprint\"] == 1 or env(IsCOMPlayer) == TRUE and env(GetSpEffectID, 100220) == TRUE then\n        act(LockonFixedAngleCancel)"
        },
        {
            "    elseif env(ActionDuration, ACTION_ARM_L1) > 0 then",
            "    elseif env(ActionDuration, ACTION_ARM_L1) > 0 or back and evasion then"
        },
        {
            "        elseif env(ActionRequest, ACTION_ARM_BACKSTEP) == TRUE then",
            "        elseif env(ActionRequest, ACTION_ARM_BACKSTEP) == TRUE or back and evasion then"
        },
        {
            "function ExecEvasion(backstep_limit, estep, is_usechainrecover)\n    if ",
            "function ExecEvasion(backstep_limit, estep, is_usechainrecover)\n    if env(ActionCancelRequest, ACTION_ARM_L3) == FALSE and "
        },
        {
            "function ExecEvent(state)",
            "function ExecEvent(state)\n"
            "    if string.find(state, \"ttack\") then\n"
            "        b_[\"cancelrate\"] = os.clock()\n"
            "    else\n"
            "        b_[\"cancelrate\"] = 0\n"
            "    end\n\n"
        },
        {
            "    if env(ActionRequest, ACTION_ARM_ROLLING) == TRUE then",
            "\n"
            "    c_RollingAngle = env(GetRollAngle) * 0.009999999776482582\n"
            "    c_ArtsRollingAngle = env(GetSwordArtsRollAngle) * 0.009999999776482582\n"
            "    local back = c_RollingAngle > 150 or c_RollingAngle < -150\n"
            "    local evasion = env(ActionRequest, ACTION_ARM_SP_MOVE) == TRUE or env(ActionDuration, ACTION_ARM_SP_MOVE) > 0 and os.clock() - b_[\"cancelrate\"] < 0.3 and env(IsCOMPlayer) == FALSE\n\n"
            "    if (env(ActionRequest, ACTION_ARM_ROLLING) == TRUE or evasion and GetVariable(\"MoveSpeedLevel\") > 0.05) and not back then"
        },
        {
        
            "\"W_AttackRightBackstep\", \"W_AttackRightHeavy1Start\",\n"
            "        \"W_AttackLeftLight1\", \"W_AttackLeftHeavy1\", \"W_AttackBothBackstep\", \"W_AttackBothHeavy1Start\",",
            "\"W_AttackRightBackstep\", \"W_AttackRightHeavyDash\",\n"
            "        \"W_AttackLeftLight1\", \"W_AttackLeftHeavy1\", \"W_AttackBothBackstep\", \"W_AttackBothHeavyDash\","
        },
        {
        
            "\"W_AttackRightLightStep\", \"W_AttackRightHeavy1Start\",\n"
            "        \"W_AttackLeftLight1\", \"W_AttackLeftHeavy1\", \"W_AttackBothLightStep\", \"W_AttackBothHeavy1Start\",",
            "\"W_AttackRightLightStep\", \"W_AttackRightHeavy1End\",\n"
            "        \"W_AttackLeftLight1\", \"W_AttackLeftHeavy1\", \"W_AttackBothLightStep\", \"W_AttackBothHeavy1End\","
        },
        {
        
            "            if env(GetSpEffectID, 100020) == TRUE then",
            "            if env(GetSpEffectID, 100020) == TRUE and env(ActionRequest, ACTION_ARM_RIDEON) == TRUE then"
        },
        {
        
            "                SetVariable(\"ToggleDash\", 0)\n            else",
            "                SetVariable(\"ToggleDash\", 0)\n            elseif env(ActionRequest, ACTION_ARM_RIDEON) == TRUE then"
        },
        {
            "function Update()",
            "function Update()\n"
            "    act(AddSpEffect, 20380100)\n"
            "\n"
            "    if (env(ActionDuration, ACTION_ARM_L3) >= 250 and GetVariable(\"MoveSpeedLevel\") > 0.05\n"
            "    or env(ActionDuration, ACTION_ARM_L3) > 0 and GetVariable(\"MoveSpeedLevel\") > 0.4000000059604645 and c_IsStealth == FALSE)\n"
            "    and env(GetStamina) > 0 and env(IsCOMPlayer) == FALSE then\n"
            "        b_[\"sprint\"] = 1\n"
            "    elseif env(ActionCancelRequest, ACTION_ARM_L3) == FALSE then\n"
            "        b_[\"sprint\"] = 0\n"
            "    end\n"
        },
        {
            "global = {}",
            "b_ = {}\n\nglobal = {}"
        },
    };
    
    ::careful( "c_SwordArtsID", "checkSAI()", pattern );
    ::careful( "c_SwordArtsHand", "checkSAH()", pattern );
    ::careful( "c_IsEnableSwordArts", "checkENSAI()", pattern );

    return common::replace( common::fromw( path ), pattern, true ).second;
}

void common::hks::hksmain() {
    for ( std::wstring i : { L"c0000.hks", L"c9997.hks" } ) {
        common::time();

        auto path = common::modengine + L"\\mod\\action\\script\\" + i;
        
        if ( !std::filesystem::exists( path ) ) {
            common::write( L"found missing files, acquiring " + i );

            std::filesystem::create_directories( common::modengine + L"\\mod\\action\\script\\" );

            if ( !::system( common::fromw( L"curl -o \"" + path + L"\" \"https://raw.githubusercontent.com/ividyon/EldenRingHKS/main/" + i + L"\"" ).c_str() ) ) {
                common::write( L"succesfully acquired " + i );
            } else {
                common::write( L"failed to acquire " + i );
                continue;
            }
        }

        DWORD attributes = ::GetFileAttributesW( path.c_str() );
        bool read = attributes & FILE_ATTRIBUTE_READONLY;

        if ( read ) attributes &= ~FILE_ATTRIBUTE_READONLY;
        ::SetFileAttributesW( path.c_str(), attributes );

        if ( read && std::filesystem::exists( path + L".bak" ) )
            std::filesystem::copy_file( path + L".bak", path, std::filesystem::copy_options::overwrite_existing );
        else
            std::filesystem::copy_file( path, path + L".bak", std::filesystem::copy_options::overwrite_existing );

        if ( i == L"c0000.hks" ) common::write( L"modified and verified ", ::c0000( path ), L" characters for the c0000.hks in ", common::time() , L" microseconds" );
        if ( i == L"c9997.hks" ) common::write( L"modified and verified ", ::c9997( path ), L" characters for the c0000.hks in ", common::time() , L" microseconds" );
        
        ::SetFileAttributesW( path.c_str(), FILE_ATTRIBUTE_READONLY );
    }
}