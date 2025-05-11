#pragma once
bool norecoil = false;

bool (*flexorg_NewWeapon)(Unity::CObject* MObj);
bool NewWeapon(Unity::CObject* MObj) {

	if (norecoil)
	{
		MObj->SetMemberValue<float>("maxRecoil", 0.f);
		MObj->SetObscuredValue<float>("newRecoil", 0.f);
		MObj->SetMemberValue<float>("hipRecoil", 0.f);
		MObj->SetObscuredValue<float>("newHipRecoil", 0.f);
	}

    return flexorg_NewWeapon(MObj);
}
#define ㅇ_ㅇ "NewWeapon"
#define ㅎ_ㅎ "Update"
bool hookz()
{
	_Z(ㅇ_ㅇ, ㅎ_ㅎ, NewWeapon);

}

