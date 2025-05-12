#pragma once

//NewWeapon -- Class
bool norecoil = false;
bool RapidFire = false;

//WeaponController -- Class
bool MassLoopReload = false;

//RateMenu -- Class
bool GetReward = false;


//PlayerMainController -- Class
bool SpeedTest = false;
float SpeedTestSlider = 0.f;


//KeyBoardControls -- Class
bool JumpBoost = false;
bool Fly = false;
bool InfiniteJump = false;


//InGameLoadouts -- Class
bool SetWeapon = false;



bool (*flexorg_NewWeapon)(Unity::CObject* MObj);
bool NewWeapon(Unity::CObject* MObj) {

	if (norecoil)
	{
		MObj->SetMemberValue<float>("maxRecoil", 0.f);
		MObj->SetObscuredValue<float>("newRecoil", 0.f);
		MObj->SetMemberValue<float>("hipRecoil", 0.f);
		MObj->SetObscuredValue<float>("newHipRecoil", 0.f);
	}

	if (RapidFire)
	{
		MObj->SetObscuredValue<float>("newFireRate", 0.f);
		MObj->SetMemberValue<float>("fireRate", 0.f);
	}

    return flexorg_NewWeapon(MObj);
}

bool (*flexorg_WeaponController)(Unity::CObject* MObj);
bool WeaponController(Unity::CObject* MObj) {

	if (MassLoopReload)
	{
		MObj->CallMethodSafe<void*>("reloadAllWeapons");
	}

    return flexorg_WeaponController(MObj);
}
bool (*flexorg_RateMenu)(Unity::CObject* MObj);
bool RateMenu(Unity::CObject* MObj) {

	if (GetReward)
	{
		MObj->CallMethodSafe<void*>("doReward");
	}

    return flexorg_RateMenu(MObj);
}

bool (*flexorg_PlayerMainController)(Unity::CObject* MObj);
bool PlayerMainController(Unity::CObject* MObj) {

	if (SpeedTest)
	{
		MObj->SetObscuredValue<float>("realBaseSpeed", SpeedTestSlider);
	}

    return flexorg_PlayerMainController(MObj);
}

bool (*flexorg_KeyboardControls)(Unity::CObject* MObj);
bool KeyboardControls(Unity::CObject* MObj) {

	if (JumpBoost)
	{
		MObj->SetObscuredValue<float>("jumpModifier", 90.f);
		MObj->SetMemberValue<float>("jump", 90.f);
	}

	if (Fly)
	{
		MObj->SetMemberValue<bool>("onLadder", true);
	}

	if (InfiniteJump)
	{
		MObj->SetMemberValue<bool>("grounded", true);
	}

    return flexorg_KeyboardControls(MObj);
}
bool (*flexorg_InGameLoadouts)(Unity::CObject* MObj);
bool InGameLoadouts(Unity::CObject* MObj) {

	if (SetWeapon)
	{
		MObj->CallMethodSafe<void*, int, int>("setWeapon", 1606, 1606);
	}

    return flexorg_InGameLoadouts(MObj);
}

bool hookz()
{
	Z("NewWeapon", "Update", NewWeapon);
	Z("WeaponController", "Update", WeaponController);
	Z("RateMenu", "Update", RateMenu);
	Z("PlayerController", "Update", PlayerMainController);
	Z("KeyboardControls", "Update", KeyboardControls);
	Z("InGameLoadouts", "Start", InGameLoadouts);

}

