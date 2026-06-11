#pragma once

#include <cCamera.h>
#include <cCameraTypes.h>

class cCameraApp : public cCamera, public cCameraTypes
{
public:
	class cCameraMatrix
	{
	public:
		Hw::cVec4 m_Trans;
		Hw::cVec4 m_Target;
		Hw::cVec4 m_Up;
		Hw::cVec4 m_Rot;
		float m_Roll;
		float m_Dist;
		float m_Fovy;
	private:
		int _pad4C;
	public:

		void setWatchAt(const Hw::cVec4& target, const Hw::cVec4& rot, float dist) { MAKE_CALL(shared::base + 0x9A11A0, void(__thiscall *)(cCameraMatrix*, const Hw::cVec4&, const Hw::cVec4&, float), this, target, rot, dist); }
		cCameraMatrix &operator=(const cCameraMatrix &lvalue) { MAKE_CALL(shared::base + 0x9A01F0, cCameraMatrix&(__thiscall *)(cCameraMatrix*, const cCameraMatrix&), this, lvalue); return *this; }

		Hw::cVec4 calculateViewOffset()
		{
			Hw::cVec4 result;
			result = MAKE_CALL(shared::base + 0x9B9090, Hw::cVec4&(__thiscall *)(cCameraMatrix*, Hw::cVec4*), this, &result);
			return result;
		}
	};
	
	Hw::cMtx field_3D0;
	cCameraMatrix field_410;
	cCameraMatrix m_NowMatrix;
	cCameraMatrix m_TarMatrix;
	int field_500;
	float field_504;
	int field_508;
	int field_50C;
	float field_510;
	float field_514;
	float field_518;
	float field_51C;
	float field_520;
	float field_524;
	float field_528;
	float field_52C;
	float field_530;
	float field_534;
	float field_538;
	float field_53C;
	float field_540;
	float field_544;
	float field_548;
	float field_54C;
	float field_550;
	float field_554;
	float field_558;
	float field_55C;
	float field_560;
	float field_564;
	float field_568;
	int field_56C;
	int field_570;
	int field_574;
	int field_578;
	int field_57C;
	int field_580;
	int field_584;
	int field_588;
	int field_58C;
	int field_590;
	int field_594;
	int field_598;
	int field_59C;
	int field_5A0;
	int field_5A4;
	int field_5A8;
	int field_5AC;
	int field_5B0;
	int field_5B4;
	int field_5B8;
	int field_5BC;
	int field_5C0;
	int field_5C4;
	int field_5C8;
	int field_5CC;
	char field_5D0;
	int field_5D4;
	int field_5D8;
	int field_5DC;
	int field_5E0;
	int field_5E4;
	int field_5E8;
	int field_5EC;
	int field_5F0;
	int field_5F4;
	int field_5F8;
	int field_5FC;
	int field_600;
	int field_604;
	int field_608;
	int field_60C;
	Hw::cVec4 field_610;
	int field_620;
	int field_624;
	int field_628;
	int field_62C;
	int field_630;
	int field_634;
	int field_638;
	int field_63C;
	int field_640;
	int field_644;
	int field_648;
	int field_64C;
	int field_650;
	int field_654;
	int field_658;
	int field_65C;
	int field_660;
	int field_664;
	int field_668;
	int field_66C;
	int field_670;
	int field_674;
	int field_678;
	int field_67C;
	int field_680;
	int field_684;
	int field_688;
	int field_68C;
	int field_690;
	int field_694;
	int field_698;
	int field_69C;
	int field_6A0;
	float field_6A4;
	float field_6A8;
	int field_6AC;
	int field_6B0;
	int field_6B4;
	int field_6B8;
	int field_6BC;
	int field_6C0;
	int field_6C4;
	int field_6C8;
	int field_6CC;
	int field_6D0;
	int field_6D4;
	float field_6D8;
	int field_6DC;

	cCameraApp() { MAKE_CALL(shared::base + 0x840760, void(__thiscall *)(cCameraApp*), this); }
	void updateCamAng() { MAKE_CALL(shared::base + 0x9B7E00, void(__thiscall *)(cCameraApp*), this); }

	void startup() { MAKE_VCALL(2, void(__thiscall*)(cCamera*), this); }
	void cleanup() { MAKE_VCALL(3, void(__thiscall*)(cCamera*), this); }
	void update() { MAKE_VCALL(4, void(__thiscall*)(cCamera*), this); }
};

VALIDATE_SIZE(cCameraApp, 0x6E0);
