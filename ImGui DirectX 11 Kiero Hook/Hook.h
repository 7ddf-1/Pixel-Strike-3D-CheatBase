#pragma once


//Random Vir
bool esp2d = false;
bool showaimbotmenu = false;
float Smoothness = 2.0f;
bool aimact = false;
int aimKey = VK_XBUTTON2;
float fov = 60.0f;
bool showFov = true;
bool aimbot = true;
int currentHotkey = 1;


//NewWeapon -- Class
bool norecoil = false;
bool RapidFire = false;
bool GrenadeBullet = false;

//WeaponController -- Class
bool MassLoopReload = false;
bool NoEquipmentCooldown = false;

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

	if (GrenadeBullet)
	{
		MObj->SetMemberValue<int>("weaponType", 5); // 0=STANDARD, 1=SHOTGUN, 2=SNIPER, 3=DUAL, 4=MELEE, 5=GRENADE, 6=BURST, 7=AREA_DAMAGE, 8=CUSTOM, 9=PROJECTILE, 10=BURST_SHOTGUN, 11=DUAL_MELEE

	}

    return flexorg_NewWeapon(MObj);
}

bool (*flexorg_WeaponController)(Unity::CObject* MObj);
bool WeaponController(Unity::CObject* MObj) {

	if (MassLoopReload)
	{
		MObj->CallMethodSafe<void*>("reloadAllWeapons");
	}

	if (NoEquipmentCooldown)
	{
		MObj->SetMemberValue<float>("equipmentCooldown", 0.f);
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

	return true;
}

inline const char* HotKeys[] =
{
	"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
	"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
	"F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12",
	"Esc", "Tab", "Caps Lock", "Num Lock", "Scroll Lock", "Enter", "Backspace",
	"Insert", "Delete", "Home", "End", "Page Up", "Page Down",
	"Up Arrow", "Down Arrow", "Left Arrow", "Right Arrow", "Print Screen", "Pause/Break",
	"Left Shift", "Right Shift", "Left Ctrl", "Right Ctrl", "Left Alt", "Right Alt", "Left Win", "Right Win",
	"Left Mouse Button", "Right Mouse Button", "Middle Mouse Button", "Mouse Button 4", "Mouse Button 5",
	"Spacebar", "Menu"
};
inline int HotKeyCodes[] =
{
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	VK_F1, VK_F2, VK_F3, VK_F4, VK_F5, VK_F6, VK_F7, VK_F8, VK_F9, VK_F10, VK_F11, VK_F12,
	VK_ESCAPE, VK_TAB, VK_CAPITAL, VK_NUMLOCK, VK_SCROLL, VK_RETURN, VK_BACK,
	VK_INSERT, VK_DELETE, VK_HOME, VK_END, VK_PRIOR, VK_NEXT,
	VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT, VK_SNAPSHOT, VK_PAUSE,
	VK_LSHIFT, VK_RSHIFT, VK_LCONTROL, VK_RCONTROL, VK_LMENU, VK_RMENU, VK_LWIN, VK_RWIN,
	VK_LBUTTON, VK_RBUTTON, VK_MBUTTON, VK_XBUTTON1, VK_XBUTTON2,
	VK_SPACE, VK_APPS
};
