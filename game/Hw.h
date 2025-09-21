#pragma once
#define DIRECTINPUT_VERSION 0x800u
#include <Windows.h>
#include <d3dx9.h>
#include <dinput.h>
#include <shared.h>
#include <Xinput.h>

extern void PrintfLog(const char* fmt, ...);

namespace Hw
{
	struct cDvdFst;
	struct DvdReadManager;

	struct Thread;

	template <typename tC>
	class cSingleton;

	class cHeap;
	class cHeapVariableBase;
	class cHeapVariable;
	class cTexture;
	class cTextureInstance;
	class cLockableTexture;
	class cTargetTexture;
	class cShareTargetTexture;
	class CameraProj;
	class cCameraBase;
	class cHeapPhysical;
	class cHeapHook;
	class cHeapFixed;
	class cHeapOneTime;
	class cHeapPhysicalBase;
	class cHeapGlobal;
	class cShareHeapPhysical;
	class cPrimHeap;
	class cIndexBufferHeap;
	class cRenderTargetInfo;
	class cOtWork;
	class CriticalSection;
	class cShader;
	class cPixelShader;
	class cVertexShader;
	struct cVertexInfo;
	struct cPixelInfo;
	class cDepthSurface;

	class cOtManagerBase;

	class cPrimF;
	class cPrimFT;
	class cPrimFTyuv;
	class cPrimFV;
	class cPrimG;
	class cPrimIF;
	class cPrimIFT;

	class cRenderPredicate;

	class cShaderPreset;
	class cShaderCharacter;
	class cShaderPF;
	class cShaderPFT;
	class cShaderPFTyuv;
	class cShaderPFTyuva;
	class cShaderPFV;
	class cShaderPG;
	class cVertexFormat;
	class cVertexFormatP;
	class cVertexFormatPG;
	class cVertexFormatPT;
	class cVertexFormatPV;
	class cZTexture;

	struct RenderBufferHeapManager;

	template <typename T>
	struct cFixedVector;

	template <typename T>
	struct cFixedList;

	template <typename tC, typename tHeapBinder>
	struct cExpandableVector;

	struct cVec2;
	struct cVec3;
	struct cVec4;
	struct cQuaternion;

	inline BOOL createSubWindow(const char *classname, const char *windowname, unsigned int x, unsigned int y)
	{
		return ((BOOL(__cdecl *)(const char*, const char *, unsigned int, unsigned int))(shared::base + 0xB98770))(classname, windowname, x, y);
	}

	namespace TextureManager
	{
		struct Texture
		{
			LPDIRECT3DTEXTURE9 m_pTexture;
			LPDIRECT3DTEXTURE9 *m_ppTexture;
			int field_8;
			int m_nWidth;
			int m_nHeight;
			int field_14;
			D3DFORMAT m_Format;
			D3DPOOL m_Pool;
			int field_20;
			int field_24;
		};

		inline void removeTexture(Texture& texture)
		{
			((void(__cdecl *)(Texture &))(shared::base + 0xBA16D0))(texture);
		}

		inline cFixedList<Texture> &Textures = *(cFixedList<Texture>*)(shared::base + 0x1B20720);
		inline CriticalSection &TextureCriticalSection = *(CriticalSection*)(shared::base + 0x1B20740);
	} 

	namespace Wwise
	{
		namespace Command
		{
			class Work
			{
			public:
				
				virtual ~Work() {};
			};

			class ListenerPositionWork : public Work{};

			class ListenerSpatializationWork : public Work{};

			class ObjectEnvironmentDryLevelWork : public Work{};

			class ObjectEnvironmentValuesWork : public Work{};

			class ObjectListenerMaskWork : public Work{};

			class ObjectOutputMaskWork : public Work{};

			class ObjectPositionWork : public Work{};

			class ObjectRTPCValueWork : public Work{};

			class ObjectRegisterWork : public Work{};

			class ObjectReleaseWork : public Work{};

			class ObjectSwitchWork : public Work{};

			class PostEventWork : public Work{};

			class ReleaseEventWork : public Work{};

			class ScalingFactorWork : public Work{};

			class StateWork : public Work{};

			class StopEventWork : public Work{};
		}
	}

	inline LPDIRECT3D9 &Direct3D9 = *(LPDIRECT3D9*)(shared::base + 0x1B206D8);
	inline LPDIRECT3DDEVICE9 &GraphicDevice = *(LPDIRECT3DDEVICE9*)(shared::base + 0x1B206D4);
	inline HWND &OSWindow = *(HWND*)(shared::base + 0x19D504C);
	inline HWND &SecondWindow = *(HWND*)(shared::base + 0x1B205E0);

	inline LPDIRECT3DSWAPCHAIN9& MainSwapChain = *(LPDIRECT3DSWAPCHAIN9*)(shared::base + 0x1B206FC); // Seems to be unused
	inline LPDIRECT3DSWAPCHAIN9& SecondWindowSwapChain = *(LPDIRECT3DSWAPCHAIN9*)(shared::base + 0x1B20700); // This one unused too

	inline RenderBufferHeapManager& RenderBufferManager = *(RenderBufferHeapManager*)(shared::base + 0x1ADD490);
}

template <typename tC>
class Hw::cSingleton
{
private:
	// static inline tC m_instance; // it doesn't work like this, but we can't do it either way
	// static inline BOOL m_wasInitialized = FALSE; // C++11 versions create a guard near the static variable, so this member here is pointless

	cSingleton() {};
public:

	// remove copy, move and assign copy operators

	cSingleton(const cSingleton<tC> &) = delete;
	cSingleton(cSingleton<tC> &&) = delete;
	cSingleton<tC> &operator=(const cSingleton<tC> &) = delete;

	static tC& GetInstance()
	{
		static tC instance;
		return instance;
	}

	operator tC*()
	{
		return &GetInstance();
	}
};

class Hw::cDepthSurface
{
public:

	virtual ~cDepthSurface() {};
};

class Hw::cOtManagerBase
{
public:

	virtual ~cOtManagerBase() {};
};

struct Hw::Thread
{
	int m_ThreadId;
	int field_4;
	int m_ThreadIndex;
	void (__cdecl *m_func)(void *);
	void *m_arg;
};

struct Hw::cVec2
{
	float x;
	float y;

	cVec2()
	{
		x = 0.f;
		y = 0.f;
	}

	cVec2(float x, float y) : x(x), y(y) {}

	void operator=(const cVec2& lhs)
	{
		x = lhs.x;
		y = lhs.y;
	}

	cVec2 operator+(const cVec2& lhs) const
	{
		return cVec2(x + lhs.x, y + lhs.y);
	}

	cVec2& operator+=(const cVec2& lhs)
	{
		x += lhs.x;
		y += lhs.y;
		return *this;
	}

	cVec2 operator-(const cVec2& lhs) const
	{
		return cVec2(x - lhs.x, y - lhs.y);
	}

	cVec2& operator-=(const cVec2& lhs)
	{
		x -= lhs.x;
		y -= lhs.y;
		return *this;
	}

	cVec2 operator*(float scale) const
	{
		return cVec2(x * scale, y * scale);
	}

	cVec2 operator*(const cVec2& lhs) const
	{
		return cVec2(x * lhs.x, y * lhs.y);
	}

	cVec2& operator*=(float scale)
	{
		x *= scale;
		y *= scale;
		return *this;
	}

	cVec2& operator*=(const cVec2& lhs)
	{
		x *= lhs.x;
		y *= lhs.y;
		return *this;
	}

	cVec2 operator/(float scale) const
	{
		return cVec2(x / scale, y / scale);
	}

	cVec2 operator/(const cVec2& lhs) const
	{
		return cVec2(x / lhs.x, y / lhs.y);
	}

	cVec2& operator/=(float scale)
	{
		x /= scale;
		y /= scale;
		return *this;
	}

	cVec2& operator/=(const cVec2& lhs)
	{
		x /= lhs.x;
		y /= lhs.y;
		return *this;
	}

	float length()
	{
		return sqrtf(powf(x, 2) + powf(y, 2));
	}

	cVec2 Normalize()
	{
		float length = this->length();
		return cVec2(x / length, y / length);
	}

	bool operator==(const cVec2& rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}

	bool operator!=(const cVec2& rhs) const
	{
		return !(*this == rhs);
	}

	float dot(const cVec2& lhs) const 
	{
		return x * lhs.x + y * lhs.y;
	}
};

struct Hw::cVec3
{
	float x;
	float y;
	float z;

	cVec3()
	{
		x = 0.f;
		y = 0.f;
		z = 0.f;
	}

	cVec3(float x, float y, float z) : x(x), y(y), z(z) {}

	void operator=(const cVec3& lhs)
	{
		x = lhs.x;
		y = lhs.y;
		z = lhs.z;
	}

	cVec3 operator+(const cVec3& lhs) const
	{
		return cVec3(x + lhs.x, y + lhs.y, z + lhs.z);
	}

	cVec3& operator+=(const cVec3& lhs)
	{
		x += lhs.x;
		y += lhs.y;
		z += lhs.z;
		return *this;
	}

	cVec3 operator-(const cVec3& lhs) const
	{
		return cVec3(x - lhs.x, y - lhs.y, z - lhs.z);
	}

	cVec3& operator-=(const cVec3& lhs)
	{
		x -= lhs.x;
		y -= lhs.y;
		z -= lhs.z;
		return *this;
	}

	cVec3 operator*(float scale) const
	{
		return cVec3(x * scale, y * scale, z * scale);
	}

	cVec3 operator*(const cVec3& lhs) const
	{
		return cVec3(x * lhs.x, y * lhs.y, z * lhs.z);
	}

	cVec3& operator*=(float scale)
	{
		x *= scale;
		y *= scale;
		z *= scale;
		return *this;
	}

	cVec3& operator*=(const cVec3& lhs)
	{
		x *= lhs.x;
		y *= lhs.y;
		z *= lhs.z;
		return *this;
	}

	cVec3 operator/(float scale) const
	{
		return cVec3(x / scale, y / scale, z / scale);
	}

	cVec3 operator/(const cVec3& lhs) const
	{
		return cVec3(x / lhs.x, y / lhs.y, z / lhs.z);
	}

	cVec3& operator/=(float scale)
	{
		x /= scale;
		y /= scale;
		z /= scale;
		return *this;
	}

	cVec3& operator/=(const cVec3& lhs)
	{
		x /= lhs.x;
		y /= lhs.y;
		z /= lhs.z;
		return *this;
	}

	float length()
	{
		return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
	}

	float length2D()
	{
		return sqrtf(powf(x, 2) + powf(z, 2));
	}

	cVec3 Normalize()
	{
		float length = this->length();
		return cVec3(x / length, y / length, z / length);
	}

	bool operator==(const cVec3& rhs) const
	{
		return x == rhs.x && y == rhs.y && z == rhs.z;
	}

	bool operator!=(const cVec3& rhs) const
	{
		return !(*this == rhs);
	}

	float dot(const cVec3& lhs) const 
	{
		return x * lhs.x + y * lhs.y + z * lhs.z;
	}

	cVec3 cross(const cVec3& lhs) const 
	{
		return cVec3(
			y * lhs.z - z * lhs.y,
			z * lhs.x - x * lhs.z,
			x * lhs.y - y * lhs.x
		);
	}
};

struct Hw::cVec4
{
	float x;
	float y;
	float z;
	float w;

	void operator=(const cVec4& right)
	{
		this->x = right.x;
		this->y = right.y;
		this->z = right.z;
		this->w = right.w;
	}

	cVec4()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 1.f;
	}

	cVec4(float x, float y, float z, float w = 1.0f) : x(x), y(y), z(z), w(w)
	{
	};

	float length()
	{
		return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
	}

	float length2D()
	{
		return sqrtf(powf(x, 2) + powf(z, 2));
	}

	cVec4 operator+(const cVec4& rhs) const
	{
		return cVec4(x + rhs.x, y + rhs.y, z + rhs.z, 1.0f);
	}

	cVec4& operator+=(const cVec4& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	cVec4 operator-(const cVec4& rhs) const
	{
		return cVec4(x - rhs.x, y - rhs.y, z - rhs.z, w);
	}

	cVec4& operator-=(const cVec4& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	cVec4 operator*(float scale) const
	{
		return cVec4(x * scale, y * scale, z * scale, w);
	}

	cVec4 operator*(const cVec4& rhs) const
	{
		return cVec4(x * rhs.x, y * rhs.y, z * rhs.z, w);
	}

	cVec4& operator*=(float scale)
	{
		x *= scale;
		y *= scale;
		z *= scale;
		return *this;
	}

	cVec4& operator*=(const cVec4& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		return *this;
	}

	cVec4 operator/(float scale) const
	{
		return cVec4(x / scale, y / scale, z / scale, w);
	}

	cVec4 operator/(const cVec4& rhs) const
	{
		return cVec4(x / rhs.x, y / rhs.y, z / rhs.z, w);
	}

	cVec4& operator/=(float scale)
	{
		x /= scale;
		y /= scale;
		z /= scale;
		return *this;
	}

	cVec4& operator/=(const cVec4& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		return *this;
	}

	bool operator==(const cVec4& rhs) const
	{
		return x == rhs.x && y == rhs.y && z == rhs.z; // && w == rhs.w; <-- I'm not sure about using w here
	}

	bool operator!=(const cVec4& rhs) const
	{
		return !(*this == rhs);
	}
	
	cVec4 Normalize()
	{
		float length = this->length();
		return cVec4(x / length, y / length, z / length, w);
	}

	float dot(const cVec4& lhs) const 
	{
		return x * lhs.x + y * lhs.y + z * lhs.z + w * lhs.w;
	}

	cVec4 cross(const cVec4& lhs) const 
	{
		return cVec4(
			y * lhs.z - z * lhs.y,
			z * lhs.x - x * lhs.z,
			x * lhs.y - y * lhs.x,
			1.0f
		);
	}
};

struct Hw::cQuaternion
{
	float x;
	float y;
	float z;
	float w;

	cQuaternion(float x, float y, float z, float w = 1.0f) : x(x), y(y), z(z), w(w) {};
	cQuaternion() { x = 0.f; y = 0.f; z = 0.f; w = 1.f; };

	static inline void Multiply(cQuaternion &out, const cVec4& rotation)
	{
		((void(__cdecl*)(cQuaternion&, const cVec4&))(shared::base + 0x9DB590))(out, rotation);
	}
};

typedef Hw::cVec2 cVec2;
typedef Hw::cVec3 cVec3;
typedef Hw::cVec4 cVec4;
typedef Hw::cQuaternion cQuaternion;

namespace cInput
{
	enum eInputButton
	{
		DPAD_LEFT = 1,
		DPAD_RIGHT = 2,
		DPAD_DOWN = 4,
		DPAD_UP = 8,
		BUTTON_A = 0x10,
		BUTTON_B = 0x20,
		BUTTON_X = 0x40,
		BUTTON_Y = 0x80,
		BUTTON_START = 0x100,
		BUTTON_BACK = 0x200,
		LEFT_SHOULDER = 0x400,
		LEFT_TRIGGER = 0x800,
		LEFT_STICK = 0x1000,
		RIGHT_SHOULDER = 0x2000,
		RIGHT_TRIGGER = 0x4000,
		RIGHT_STICK = 0x8000
	};

	enum eSaveKeybind
	{
		KEYBIND_FORWARD,
		KEYBIND_BACK,
		KEYBIND_LEFT,
		KEYBIND_RIGHT,
		KEYBIND_WALK,
		KEYBIND_JUMP,
		KEYBIND_LIGHT_ATTACK,
		KEYBIND_HEAVY_ATTACK,
		KEYBIND_BLADEMODE,
		KEYBIND_NINJARUN,
		KEYBIND_ACTION,
		KEYBIND_RIPPERMODE,
		KEYBIND_SWITCH_LOCK_ON,
		KEYBIND_USE_SUBWEAPON,
		KEYBIND_USE_ITEM,
		KEYBIND_AR_MODE,
		KEYBIND_WEAPON_SELECT_SCREEN,
		KEYBIND_CODEC_SCREEN,
		KEYBIND_PAUSE,
		KEYBIND_CAMERA_RESET,
		KEYBIND_EXECUTION,
		KEYBIND_DEFFENSIVE_OFFENSIVE,
		KEYBIND_FIRE_SUBWEAPON,

		KEYBIND_TOTAL
	};

	struct ControllerState
	{
		XINPUT_STATE m_XInputState;
		int m_bAvailable;
		float m_fCurrentLeftVibration;
		float m_fTargetLeftVibration;
		float m_fCurrentRightVibration;
		float m_fTargetRightVibration;
		float m_fLeftMotorSpeed;
		float m_fRightMotorSpeed;
		int m_nCurrentVibrationTime;
		int m_nVibrationTotal;
		int m_bVibrationEnabled;
	};

	struct KeyInput
	{
		unsigned int m_aKeysDown[6];
		unsigned int m_aKeysPressed[6]; // bit is set when the key is pressed once
		unsigned int m_aKeysReleased[6];
		unsigned int m_aKeysAlternated[6];
		unsigned int m_aKeyHistory[6];
		int m_nPressDelay; // used for pressed last time timer

		BOOL isKeyDown(int vKey)
		{
			return ((BOOL(__thiscall*)(KeyInput*, int))(shared::base + 0x9D93A0))(this, vKey);
		}

		BOOL isKeyDown(char vKey) // unused
		{
			return ((BOOL(__thiscall*)(KeyInput*, char))(shared::base + 0x9D93D0))(this, vKey);
		}

		BOOL isKeyPressed(int vKey)
		{
			return ((BOOL(__thiscall*)(KeyInput*, int))(shared::base + 0x9D9400))(this, vKey);
		}

		BOOL isKeyPressed(char vKey) // unused
		{
			return ((BOOL(__thiscall*)(KeyInput*, char))(shared::base + 0x9D9430))(this, vKey);
		}

		BOOL isKeyReleased(int vKey)
		{
			return ((BOOL(__thiscall*)(KeyInput*, int))(shared::base + 0x9D9460))(this, vKey);
		}

		BOOL isKeyReleased(char vKey) // unused
		{
			return ((BOOL(__thiscall*)(KeyInput*, char))(shared::base + 0x9D9490))(this, vKey);
		}

		BOOL isKeyAlternated(int vKey)
		{
			return ((BOOL(__thiscall*)(KeyInput*, int))(shared::base + 0x9D94C0))(this, vKey);
		}

		BOOL isKeyAlternated(char vKey) // unused
		{
			return ((BOOL(__thiscall*)(KeyInput*, char))(shared::base + 0x9D94F0))(this, vKey);
		}

		void setKeyDown(int vKey, BOOL bDown)
		{
			((void(__thiscall*)(KeyInput*, int, BOOL))(shared::base + 0x9D9620))(this, vKey, bDown);
		}

		void setKeyPressed(int vKey)
		{
			((void(__thiscall*)(KeyInput*, int))(shared::base + 0x9D9650))(this, vKey);
		}
	};

	struct MouseInput
	{
		int m_nMouseButtons;
		int m_nButtonsPressed;
		int m_nButtonsReleased;
		int m_nButtonsAlternated;
		cVec2 m_MousePosition;
		int field_18;
		int m_nRepeatCount;
		cVec2 m_LastMousePosition;
	};

	struct InputUnit
	{
		unsigned int m_nButtonsDown;
		unsigned int m_nButtonsPressed;
		unsigned int m_nButtonsReleased;
		unsigned int m_nButtonsAlternated;
		cVec2 m_fLeftStick;
		cVec2 m_fRightStick;
		float m_fLeftTrigger;
		float m_fRightTrigger;
		int m_bValidInput;
		int m_nRepeatCount;
	};

	struct GlobalInput
	{
		char field_0;
		char field_1;
		char field_2;
		char field_3;
		__int16 field_4;
		__int16 field_6;
		int field_8;
		int field_C;
		int field_10;
		bool m_bIsPCInput;
		int field_18;
		int field_1C;
		int field_20;
		int field_24;
		int field_28;
	};

	inline void resetInputUnit(InputUnit* unit)
	{
		((void(__cdecl*)(InputUnit*))(shared::base + 0x9DAFC0))(unit);
	}

	inline int getControllerIndex(int dwUserIndex)
	{
		return ((int(__cdecl*)(int))(shared::base + 0x9FD140))(dwUserIndex);
	}

	inline int isControllerAvailable(int index)
	{
		return ((int(__cdecl*)(int))(shared::base + 0x9DA340))(index);
	}

	inline void updateInputUnit(InputUnit *unit, int dwUserIndex)
	{
		((void(__cdecl*)(InputUnit*, int))(shared::base + 0x9DAFE0))(unit, dwUserIndex);
	}

	inline void setVibrationEnabled(BOOL bEnabled)
	{
		((void(__cdecl*)(BOOL))(shared::base + 0x9DA2F0))(bEnabled);
	}

	inline void setInputUnitButtons(InputUnit *unit, unsigned int buttons)
	{
		((void(__cdecl*)(InputUnit*, unsigned int))(shared::base + 0x9DA210))(unit, buttons);
	}

	inline BOOL isKeybindDown(eSaveKeybind keybind)
	{
		return ((BOOL(__cdecl*)(eSaveKeybind))(shared::base + 0x61D280))(keybind);
	}

	inline void updateControllerStateInput(ControllerState* state, int index)
	{
		((void(__cdecl*)(ControllerState*, int))(shared::base + 0x9DA900))(state, index);
	}

	inline LPDIRECTINPUT8& ms_InputDevice = *(LPDIRECTINPUT8*)(shared::base + 0x19D06E4);
	inline LPDIRECTINPUTDEVICE8W* ms_aControllerDevices = (LPDIRECTINPUTDEVICE8W*)(shared::base + 0x19D05A8); // 4 elements
	inline LPDIRECTINPUTDEVICE8W& ms_MouseDevice = *(LPDIRECTINPUTDEVICE8W*)(shared::base + 0x19D06F4);
	inline LPDIRECTINPUTDEVICE8W& ms_PCInputDevice = *(LPDIRECTINPUTDEVICE8W*)(shared::base + 0x19D06E8);

	inline MouseInput& ms_MouseInput = *(MouseInput*)(shared::base + 0x177B798);
	inline KeyInput& ms_KeyInput = *(KeyInput*)(shared::base + 0x177B7C0);
	inline ControllerState *ms_aControllers = (ControllerState*)(shared::base + 0x19D05F0); // Maximum 4 controllers
	inline GlobalInput& ms_GlobalInput = *(GlobalInput*)(shared::base + 0x19C1404);

	inline char* ms_InputKeys = (char*)(shared::base + 0x19D06F8); // 256 elements
	inline char* ms_MouseStateInput = (char*)(shared::base + 0x19D06D0); // 20 elements

	inline bool& ms_bUpdateKeyboard = *(bool*)(shared::base + 0x14CDDE8);
	inline bool& ms_bUpdateMouse = *(bool*)(shared::base + 0x19D07F8);
	inline bool& ms_bMouseAvailable = *(bool*)(shared::base + 0x19D0800);
	inline bool& ms_bKeyboardAvailable = *(bool*)(shared::base + 0x19D06EC);

	inline int* ms_aKeyMap = (int*)(shared::base + 0x14CD838); // 364 elements...
	inline int* ms_aAvailableKeys = (int*)(shared::base + 0x14B5D80); // 107 elements, briefly, this array consists of keys that can be pressed
	inline int* ms_aMouseButtons = (int*)(shared::base + 0x14B5D74); // 3 elements, buttons that are checked via binary operations(and, xor, or, etc.)
	inline int& ms_nControllersAmount = *(int*)(shared::base + 0x19D0808); // how much were acquired

	inline float* ms_aStickButtonThreshold = (float*)(shared::base + 0x19D05C0); // 4 elements, threshold in any direction that will convert as a button press, also used for left or right triggers
	inline float* ms_aStickDeadzone = (float*)(shared::base + 0x19D05D0); // 4 elements
	inline float* ms_aMaxStickThreshold = (float*)(shared::base + 0x19D05E0); // 4 elements, threshold until the stick is fully moved
};

class Hw::CriticalSection
{
public:
	RTL_CRITICAL_SECTION m_critsection;
	BOOL m_bInit;

	CriticalSection()
	{
		this->m_bInit = FALSE;
	}

	BOOL init()
	{
		return ((BOOL(__thiscall*)(CriticalSection*))(shared::base + 0x9D7240))(this);
	}

	void enter()
	{
		if (this->m_bInit)
			EnterCriticalSection(&this->m_critsection);
	}

	void leave()
	{
		if (this->m_bInit)
			LeaveCriticalSection(&this->m_critsection);
	}

	void shutdown()
	{
		((void(__thiscall*)(CriticalSection*))(shared::base + 0x9D7270))(this);
	}
};

class Hw::cHeap
{
public:
	int field_4;
	Hw::CriticalSection m_CriticalSection;
	int field_24;
	Hw::cHeap* m_pReservedHeap;
	Hw::cHeap* m_pHeapOwner;
	Hw::cHeap* m_pNext;
	Hw::cHeap* m_pPrev;
	const char* m_TargetAlloc;
	int field_3C;

	cHeap()
	{
		((void(__thiscall*)(cHeap*))(shared::base + 0x9D3650))(this);
	}

	virtual ~cHeap() {};

	void startup()
	{
		CallVMTFunc<1, cHeap*>(this);
	}

	void shutdown()
	{
		CallVMTFunc<2, cHeap*>(this);
	}

	BOOL hasHandle()
	{
		return ReturnCallVMTFunc<BOOL, 3, cHeap*>(this);
	}

	size_t getMemoryLimit()
	{
		return ReturnCallVMTFunc<size_t, 4, cHeap*>(this);
	}

	size_t getUsedMemory()
	{
		return ReturnCallVMTFunc<size_t, 5, cHeap*>(this);
	}

	size_t getFreeMemory()
	{
		return ReturnCallVMTFunc<size_t, 6, cHeap*>(this);
	}

	void* getBlock(void *block)
	{
		return ReturnCallVMTFunc<void*, 7, cHeap*, void *>(this, block);
	}

	size_t getMemorySizeByBlock(void* block)
	{
		return ReturnCallVMTFunc<size_t, 8, cHeap*, void*>(this, block);
	}

	size_t getCriticalLimit()
	{
		return ReturnCallVMTFunc<size_t, 9, cHeap*>(this);
	}
	// memory that is used by child heaps
	size_t getChildHeapMemory()
	{
		return ReturnCallVMTFunc<size_t, 10, cHeap*>(this);
	}

	void unused(void *unk1)
	{
		CallVMTFunc<11, cHeap*, void*>(this, unk1);
	}

	void* createChildHeap(HANDLE* pHandle, size_t Size)
	{
		return ReturnCallVMTFunc<void*, 12, cHeap*, HANDLE*, size_t>(this, pHandle, Size);
	}

	void removeChildHeap(HANDLE* pHandle, size_t Size)
	{
		CallVMTFunc<13, cHeap*, HANDLE*, size_t>(this, pHandle, Size);
	}

	void* allocate(size_t size, size_t preserved, int a3, int a4)
	{
		return ReturnCallVMTFunc<void*, 14, cHeap*, size_t, size_t, int, int>(this, size, preserved, a3, a4);
	}

	void free(void* block, size_t size)
	{
		CallVMTFunc<15, cHeap*, void*, size_t>(this, block, size);
	}

	void *AllocateMemory(size_t size, size_t preserved, int alignment, int a3)
	{
		return ((void*(__thiscall*)(Hw::cHeap *, size_t, size_t, int, int))(shared::base + 0x9D29B0))(this, size, preserved, alignment, a3);
	}
};

class Hw::cHeapVariableBase : public Hw::cHeap
{
public:
	struct HeapBlock
	{
		HeapBlock* m_pPrevious;
		HeapBlock* m_pNext;
		void* m_pMemoryBlock;
		size_t m_MemorySize;
		cHeapVariableBase* m_pAllocator;
	};

	HANDLE m_HeapHandle;
	HeapBlock* m_pFirstBlock;
	HeapBlock* m_pLastBlock;
	size_t m_MemoryLimit;
	size_t m_FreeMemory;
	size_t m_UsedMemory;

	cHeapVariableBase()
	{
		((void(__thiscall*)(Hw::cHeapVariableBase*))(shared::base + 0x9D3AF0))(this);
	}
};

class Hw::cHeapVariable : public Hw::cHeapVariableBase
{
public:

	cHeapVariable()
	{
		((void(__thiscall*)(Hw::cHeapVariable*))(shared::base + 0x9D44F0))(this);
	}
};

class Hw::cHeapPhysicalBase : public Hw::cHeap
{
public:
	struct HeapBlock
	{
		HeapBlock* m_pPrevious;
		HeapBlock* m_pNext;
		size_t m_TotalSize;
		size_t m_Size;
		int field_10;
		int field_14;
		cHeapPhysicalBase* m_pAllocator;
	};
public:
	HeapBlock* m_pMainBlock;
	HeapBlock* m_pFirstBlock;
	HeapBlock *m_pLastBlock;
	size_t m_MemoryLimit;
	size_t m_FreeMemory;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	HeapBlock* m_pBlocks[256];

	cHeapPhysicalBase()
	{
		((void(__thiscall*)(Hw::cHeapPhysicalBase*))(shared::base + 0x9D3860))(this);
	}
};

class Hw::cHeapPhysical : public Hw::cHeapPhysicalBase
{
public:

	cHeapPhysical()
	{
		((void(__thiscall*)(Hw::cHeapPhysical*))(shared::base + 0x9D48F0))(this);
	}
};

class Hw::cHeapHook
{
public:

	virtual ~cHeapHook() {};
};

class Hw::cHeapFixed : public Hw::cHeap
{
public:
	struct HeapBlock 
	{
		HeapBlock *m_pPrevious;
		HeapBlock *m_pNext;
		cHeapFixed *m_pAllocator;
	};
public:
	HANDLE m_HeapHandle;
	int field_44;
	size_t m_nFixedSize;
	int field_4C;
	size_t m_nFixedReservedSize;
	size_t m_nFixedAmount;
	int field_58;
	int field_5C;

	cHeapFixed()
	{
		((void(__thiscall *)(Hw::cHeapFixed*))(shared::base + 0x9D36F0))(this);
	}

	void* AllocateMemory()
	{
		return ((void* (__thiscall*)(Hw::cHeapFixed*))(shared::base + 0x9D2BC0))(this);
	}

	BOOL create(size_t fixedSize, size_t allocAmount, size_t reservedSize, Hw::cHeap *creator, const char *name)
	{
		return ReturnCallVMTFunc<BOOL, 16, cHeapFixed*, size_t, size_t, size_t, Hw::cHeap *, const char*>(this, fixedSize, allocAmount, reservedSize, creator, name);
	}
};

class Hw::cHeapOneTime : public Hw::cHeap
{
public:


};

class Hw::cHeapGlobal : public Hw::cHeapVariableBase
{
public:

	cHeapGlobal()
	{
		((void(__thiscall *)(cHeapGlobal *))(shared::base + 0x9D3F20))(this);
	}

	static inline cHeapGlobal* GetInstance() // -> return Hw::cHeapGlobal::ms_Instance.GetInstance();
	{
		return ((cHeapGlobal * (__cdecl*)())(shared::base + 0x61D830))();
	}

	BOOL create(size_t size, const char *target) // Got optimised away
	{
		if (hasHandle())
			return FALSE;

		if (!this->m_CriticalSection.init())
			return FALSE;

		this->m_HeapHandle = HeapCreate(1u, 0u, 0u);

		if (!this->m_HeapHandle)
			return FALSE;

		this->m_MemoryLimit = size;
		this->m_FreeMemory = size;
		this->m_TargetAlloc = target;
		this->m_pFirstBlock = nullptr;
		this->m_pLastBlock = nullptr;
		return TRUE;
	}

	static inline cHeapGlobal &ms_Instance = *(cHeapGlobal*)(shared::base + 0x1783AF0); // Actually a singleton
};

class Hw::cShareHeapPhysical : Hw::cHeapPhysical
{
public:


};

class Hw::cTexture
{
public:
	void *m_Texture;
	cTextureInstance *m_pTextureInstance;
	int m_nTextureAmount;
	int field_10;
	int field_14;
	void *m_TextureAttributes;

	cTexture()
	{
		((void(__thiscall *)(cTexture *))(shared::base + 0xB972C0))(this);
	}

	virtual ~cTexture() {};

	BOOL create(void *wtb)
	{
		return ((BOOL(__thiscall *)(cTexture *, void *))(shared::base + 0xBA25D0))(this, wtb);
	}

	BOOL create(void *wta, void *wtp)
	{
		return ((BOOL(__thiscall *)(cTexture *, void *, void*))(shared::base + 0xBA4D00))(this, wta, wtp);
	}

	void reset()
	{
		((void(__thiscall *)(cTexture *))(shared::base + 0xB972F0))(this);
	}
};

class Hw::cTextureInstance
{
public:
	IDirect3DTexture9 *m_Texture;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;

	virtual ~cTextureInstance() {};
};

class Hw::cLockableTexture : public Hw::cTexture
{
public:
	Hw::cTextureInstance m_Texture;
};

class Hw::cTargetTexture : public Hw::cTexture
{
public:
	Hw::cTextureInstance m_Texture;
};

class Hw::cShareTargetTexture : public Hw::cTargetTexture
{
public:
	int field_4C;
};

class Hw::CameraProj
{
public:
	int field_4;
	int field_8;
	int field_C;
	D3DXMATRIX m_projectionMatrix;
	D3DXMATRIX m_invertedProjectionMatrix;
	float m_fAspectRatio;
	float m_fFOV;
	float m_fNearClip;
	float m_fFarClip;
	int field_A0;
	int field_A4;
	int field_A8;
	int field_AC;

	virtual ~CameraProj() {};
};

VALIDATE_SIZE(Hw::CameraProj, 0xB0);

class Hw::cCameraBase
{
public:
	struct CameraMatrix
	{
		cVec4 m_vecPosition;
		cVec4 m_vecLookAtPosition;
		cVec4 m_vecOffset;
		cVec4 m_vecCameraOffset;
		float m_fRoll;
		float m_fDistance;
		float m_fFOV;

		CameraMatrix &operator=(const CameraMatrix &lvalue)
		{
			((void(__thiscall *)(CameraMatrix *, const CameraMatrix &))(shared::base + 0x9A01F0))(this, lvalue);
			return *this;
		}

		cVec4 calculateViewOffset()
		{
			cVec4 result;
			result = *((cVec4*(__thiscall*)(CameraMatrix*, cVec4*))(shared::base + 0x9B9090))(this, &result);
			return result;
		}
	};

	D3DXMATRIX m_viewMatrix;
	D3DXMATRIX field_40;
	D3DXMATRIX m_invertedViewMatrix;
	D3DXMATRIX field_C0;
	CameraMatrix m_CameraMatrix;
	float field_14C;

	void setViewMatrix(const D3DXMATRIX& matrix)
	{
		((void(__thiscall *)(cCameraBase *, const D3DXMATRIX&))(shared::base + 0x9E5170))(this, matrix);
	}

	void move(const cVec4& offset)
	{
		((void(__thiscall *)(cCameraBase *, const cVec4&))(shared::base + 0x9E4F20))(this, offset);
	}

	// Move camera according to the offset of camera
	void moveWithOffset(const cVec4& offset)
	{
		((void(__thiscall *)(cCameraBase *, const cVec4&))(shared::base + 0x9E4FA0))(this, offset);
	}

	// Move camera according to the Y offset
	void moveWithY(const cVec4& offset)
	{
		((void(__thiscall *)(cCameraBase *, const cVec4&))(shared::base + 0x9E5090))(this, offset);
	}

	void setPosition(const cVec4& position)
	{
		((void(__thiscall *)(cCameraBase *, const cVec4&))(shared::base + 0x9E5F20))(this, position);
	}

	void setOffset(const cVec4& offset)
	{
		((void(__thiscall *)(cCameraBase *, const cVec4&))(shared::base + 0x9E6060))(this, offset);
	}

	void setLookAt(const cVec4& lookAt)
	{
		((void(__thiscall *)(cCameraBase *, const cVec4&))(shared::base + 0x9E5FC0))(this, lookAt);
	}

	void setCameraOffset(const cVec4& cameraOffset)
	{
		((void(__thiscall *)(cCameraBase *, const cVec4&))(shared::base + 0x9E6090))(this, cameraOffset);
	}

	void setDistance(float distance)
	{
		((void(__thiscall *)(cCameraBase *, float))(shared::base + 0x9E62D0))(this, distance);
	}

	// m_fDistance += clamp(distance, minDistance, maxDistance)
	void adjustDistanceToLookAt(float distance, float maxDistance, float minDistance)
	{
		((void(__thiscall *)(cCameraBase *, float, float, float))(shared::base + 0x9E62F0))(this, distance, maxDistance, minDistance);
	}

	void adjustDistanceToPosition(float distance, float maxDistance, float minDistance)
	{
		((void(__thiscall *)(cCameraBase *, float, float, float))(shared::base + 0x9E6390))(this, distance, maxDistance, minDistance);
	}

	// m_vecLookAtPosition += with
	void setLookAtAlong(const cVec4& with)
	{
		((void(__thiscall *)(cCameraBase *, const cVec4&))(shared::base + 0x9E6000))(this, with);
	}

	void place(const cVec4& position, const cVec4& lookAt, const cVec4& offset)
	{
		((void(__thiscall *)(cCameraBase*, const cVec4&, const cVec4&, const cVec4&))(shared::base + 0x9E5D10))(this, position, lookAt, offset);
	}

	void place(const cVec4& position, const cVec4& cameraOffset, float distance)
	{
		((void(__thiscall *)(cCameraBase*, const cVec4&, const cVec4&, float))(shared::base + 0x9E5DA0))(this, position, cameraOffset, distance);
	}

	void lookAt(const cVec4& lookAt, const cVec4& cameraOffset, float distance)
	{
		((void(__thiscall *)(cCameraBase*, const cVec4&, const cVec4&, float))(shared::base + 0x9E5E60))(this, lookAt, cameraOffset, distance);
	}

	// m_vecPosition += with
	void moveAlong(const cVec4& with)
	{
		((void(__thiscall *)(cCameraBase*, const cVec4&))(shared::base + 0x9E5F60))(this, with);
	}

	void updatePosition()
	{
		((void(__thiscall *)(cCameraBase*))(shared::base + 0x9E51B0))(this);
	}

	void updateLookAtPos() // z = -distance
	{
		((void(__thiscall *)(cCameraBase *))(shared::base + 0x9E5260))(this);
	}

	void resetOffset()
	{
		((void(__thiscall *)(cCameraBase *))(shared::base + 0x9E5310))(this);
	}

	void calculateCameraOffset()
	{
		((void(__thiscall *)(cCameraBase*))(shared::base + 0x9E5380))(this);
	}

	void calculateCameraDistance()
	{
		((void(__thiscall *)(cCameraBase *))(shared::base + 0x9E54E0))(this);
	}

	void updateCameraViewMatrix()
	{
		((void(__thiscall *)(cCameraBase *))(shared::base + 0x9E6410))(this);
	}

	void calculateInverseViewMatrix()
	{
		((void(__thiscall *)(cCameraBase *))(shared::base + 0x9E5170))(this);
	}
};

VALIDATE_SIZE(Hw::cCameraBase, 0x150);

class Hw::cPrimHeap
{
public:
	int field_4;
	int field_8;
	int field_C;
	int field_10;

	cPrimHeap()
	{
		((void(__thiscall*)(Hw::cPrimHeap*))(shared::base + 0xB97EC0))(this);
	}

	virtual ~cPrimHeap() {};

	void* allocBuffer(size_t size, size_t reserved = 0x20)
	{
		return ((void* (__thiscall*)(cPrimHeap*, size_t, size_t))(shared::base + 0xB9B1F0))(this, size, reserved);
	}
};

class Hw::cIndexBufferHeap
{
public:
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;

	cIndexBufferHeap()
	{
		((void(__thiscall*)(cIndexBufferHeap*))(shared::base + 0xB9C7F0))(this);
	}

	virtual ~cIndexBufferHeap() {};
};

struct Hw::RenderBufferHeapManager
{
	cPrimHeap *field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	cPrimHeap field_20[2];
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	cIndexBufferHeap field_80[2];
	int field_B8;
};

class Hw::cRenderTargetInfo
{
public:
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;

	virtual ~cRenderTargetInfo() {};
};

class Hw::cOtWork
{
public:

	virtual ~cOtWork() {};

	void draw()
	{
		CallVMTFunc<1, Hw::cOtWork*>(this);
	}
};

struct Hw::cVertexInfo
{
	LPDIRECT3DVERTEXSHADER9 m_VertexShader;
	LPD3DXCONSTANTTABLE m_ConstantTable;
	unsigned short field_C;
};

struct Hw::cPixelInfo
{
	LPDIRECT3DPIXELSHADER9 m_PixelShader;
	LPD3DXCONSTANTTABLE m_ConstantTable;
	unsigned short field_C;
};

class Hw::cVertexShader
{
public:
	cVertexInfo m_VertexData;

	virtual ~cVertexShader() {};
};

class Hw::cPixelShader
{
public:

	cPixelInfo m_PixelData;

	virtual ~cPixelShader() {};
};

class Hw::cShader
{
public:
	Hw::cVertexShader m_VertexShader;
	Hw::cPixelShader m_PixelShader;
	int field_24;

	virtual ~cShader() {};
};

VALIDATE_SIZE(Hw::cShader, 0x28);

class Hw::cVertexFormat
{
public:

	IDirect3DVertexDeclaration9 *m_VertexDeclaration;
	int m_UsageFlags;

	virtual void dummyVM() {};
};

class Hw::cPrimF : public Hw::cOtWork
{
public:
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	int field_88;
	int field_8C;
};

class Hw::cPrimFT : public Hw::cOtWork{};

class Hw::cPrimFTyuv : public Hw::cOtWork{};

class Hw::cPrimFV : public Hw::cOtWork{};

class Hw::cPrimG : public Hw::cOtWork{};

class Hw::cPrimIF : public Hw::cOtWork{};

class Hw::cPrimIFT : public Hw::cOtWork{};

class Hw::cRenderPredicate
{
public:

	virtual ~cRenderPredicate() {};
};

class Hw::cShaderPreset : public Hw::cShader{};

class Hw::cShaderCharacter : public Hw::cShaderPreset{};

class Hw::cShaderPF : public Hw::cShaderPreset{};

class Hw::cShaderPFT : public Hw::cShaderPreset{};

class Hw::cShaderPFTyuv : public Hw::cShaderPreset{};

class Hw::cShaderPFTyuva : public Hw::cShaderPreset{};

class Hw::cShaderPFV : public Hw::cShaderPreset{};

class Hw::cShaderPG : public Hw::cShaderPreset{};

class Hw::cVertexFormatP : public Hw::cVertexFormat{};

class Hw::cVertexFormatPG : public Hw::cVertexFormat{};

class Hw::cVertexFormatPT : public Hw::cVertexFormat{};

class Hw::cVertexFormatPV : public Hw::cVertexFormat{};

class Hw::cZTexture : public Hw::cTargetTexture{};

class cFilterShaderCopyTex : public Hw::cShader
{
public:
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
};

class cFilterShaderCopyTexAlp : public cFilterShaderCopyTex{};

inline void *__cdecl operator new(size_t s, Hw::cHeap *allocator)
{
	return ((void*(__cdecl *)(size_t, Hw::cHeap *))(shared::base + 0x9D3500))(s, allocator);
}

inline void __cdecl operator delete(void* block, Hw::cHeap* allocator) // to separate the delete operator
{
	return ((void(__cdecl*)(void*, size_t))(shared::base + 0x9D48D0))(block, 0);
}

// Usage after heap startup
inline void* __cdecl memAlloc(size_t s)
{
	return ((void* (__cdecl*)(size_t))(shared::base + 0x61E180))(s);
}

// Usage after heap startup
inline void __cdecl memDealloc(void* block)
{
	((void(__cdecl*)(void*))(shared::base + 0x61D3D0))(block);
}

template <typename T>
struct Hw::cFixedVector
{
	int field_0;
	T* m_vector;
	size_t m_capacity;
	size_t m_size;
	BOOL m_bInitialized;

	cFixedVector()
	{
		field_0 = 0;
		m_vector = nullptr;
		m_capacity = 0;
		m_size = 0;
		m_bInitialized = 0;
	}

	BOOL create(size_t capacity, Hw::cHeap* allocator)
	{
		if (m_vector)
			return 0;

		m_vector = allocator->AllocateMemory(sizeof(T) * capacity);
		if (m_vector)
		{
			m_capacity = capacity;
			m_size = 0;
			m_bInitialized = 1; // is initialized?
			return 1;
		}
		else
		{
			ePrintf("cFixedVector::create Failed to allocate memory[%s need:%d Allocatable:%d]", allocator->m_TargetAlloc, sizeof(T) * capacity, allocator->getFreeMemory());
			return 0;
		}
		return 0;
	}

	bool push_back(const T& element)
	{
		if (!m_vector)
			return false;

		if (m_size >= m_capacity)
			return false;

		m_vector[m_size++] = element;
		return true;
	}

	bool push_front(const T& element)
	{
		insert(m_vector[0], element);
		return true;
	}

	void insert(T& insIndex, const T& element)
	{
		if (!m_vector)
			return;

		if (m_size >= m_capacity)
			return;

		size_t insertIndex = &insIndex - m_vector;
		if (insertIndex > m_size)
			return;

		for (int i = m_size; i > insertIndex; --i)
			m_vector[i] = m_vector[i - 1];

		m_vector[insertIndex] = element;
		++m_size;
	}

	void remove(T& element)
	{
		if (!m_vector)
			return;

		if (&element - m_vector >= m_size)
			return;

		for (T* i = &element; i != m_vector[m_size - 1]; ++i)
			*i = i[1];

		--m_size;
	}

	T& get(size_t index)
	{
		return m_vector[index];
	}

	T& get(size_t index) const
	{
		return m_vector[index];
	}

	T& operator[](size_t index)
	{
		return get(index);
	}

	T& operator[](size_t index) const
	{
		return get(index);
	}

	T* begin()
	{
		return m_vector;
	}

	T* begin() const
	{
		return m_vector;
	}

	T* end()
	{
		return m_vector + m_size;
	}

	T* end() const
	{
		return m_vector + m_size;
	}
};

template <typename T>
struct Hw::cFixedList
{
	struct Node
	{
		T m_value;
		Node* m_prev;
		Node* m_next;
	};

	Node* m_pHead;
	Node* m_ListBegin;
	size_t m_capacity;
	size_t m_size;
	Node* m_ListEnd;
	Node* m_pFirst;
	Node* m_pLast;

	class iterator
	{
	private:
		Node* m_current;
	public:
		explicit iterator(Node* node) : m_current(node) {};

		iterator& operator++()
		{
			if (m_current)
				m_current = m_current->m_next;

			return *this;
		}

		iterator& operator--()
		{
			if (m_current)
				m_current = m_current->m_prev;

			return *this;
		}

		T& operator*() const
		{
			return m_current->m_value;
		}

		bool operator==(const iterator& other) const
		{
			return m_current == other.m_current;
		}

		bool operator!=(const iterator& other) const
		{
			return !(*this == other);
		}
	};

	iterator begin()
	{
		return iterator(m_pFirst);
	}

	iterator begin() const
	{
		return iterator(m_pFirst);
	}

	iterator end() const
	{
		return iterator(m_pLast);
	}

	iterator end()
	{
		return iterator(m_pLast);
	}

	iterator rbegin()
	{
		return iterator(m_pLast);
	}

	iterator rbegin() const
	{
		return iterator(m_pLast);
	}

	iterator rend()
	{
		return iterator(m_pFirst);
	}

	iterator rend() const
	{
		return iterator(m_pFirst);
	}

	void setupNodes()
	{
		if (m_capacity > 0)
		{
			Node* current = m_ListBegin;
			for (int i = 0; i < m_capacity; i++)
			{
				current->m_prev = (current - 1);
				current->m_next = (current + 1);
				++current;
			}
		}

		m_ListBegin->m_prev = nullptr;

		m_ListBegin[m_capacity - 1].m_next = 0;

		m_pLast->m_prev = nullptr;
		m_pLast->m_next = nullptr;

		m_pFirst = m_pLast;
		m_ListEnd = m_ListBegin;

		m_size = 0;
	}

	BOOL create(size_t capacity, Hw::cHeap *allocator)
	{
		if (m_ListBegin)
			return 0;

		m_ListBegin = (Node*)allocator->AllocateMemory(sizeof(Node) * capacity + sizeof(Node), 32, 0, 0);
		if (m_ListBegin)
		{
			m_capacity = capacity;
			m_size = 0;
			m_pLast = m_ListBegin + capacity;

			setupNodes();

			return 1;
		}
		return 0;
	}

	void insert(Node* &retNode, Node* const& where, const T & element)
	{
		Node *m_pLast = m_ListEnd;
		if (m_pLast == m_pHead)
		{
			m_pLast = m_pHead;
		}
		else
		{
			Node *m_prev = m_pLast->m_prev;
			Node *m_next = m_pLast->m_next;
			if (m_prev)
				m_prev->m_next = m_next;
			if (m_next)
				m_next->m_prev = m_prev;
			m_ListEnd = m_next;
			++m_size;
		}
		if (m_pLast == m_pHead)
		{
			PrintfLog("cFixedList<tC>::insert  list max over!");
			retNode = m_pHead;
		}
		else
		{
			if (m_pLast)
				m_pLast->m_value = element;
			Node *v8 = where;
			Node* v9;
			if (where)
				v9 = v8->m_prev;
			else
				v9 = 0;
			m_pLast->m_prev = v9;
			m_pLast->m_next = v8;
			if (v9)
				v9->m_next = m_pLast;
			if (v8)
				v8->m_prev = m_pLast;
			if (m_pFirst == where)
				m_pFirst = m_pLast;
			retNode = m_pLast;
		}
	}

	void insert(Node *&where, const T& element)
	{
		Node *node;
		insert(node, where, element);
	}

	void push_back(const T& element)
	{
		insert(m_pLast, element);
	}

	void push_front(const T& element)
	{
		insert(m_pFirst, element);
	}

	void remove(Node*& node)
	{
		Node* m_prev = node->m_prev;
		Node* m_next = node->m_next;

		if (m_prev)
			m_prev->m_next = m_next;
		if (m_next)
			m_next->m_prev = m_prev;

		if (m_pFirst == node)
			m_pFirst = m_next;

		--m_size;

		Node* m_pLast = this->m_pLast;

		Node* v10;

		if (m_pLast)
			v10 = m_pLast->m_prev;
		else
			v10 = nullptr;

		node->m_prev = v10;
		node->m_next = m_pLast;

		if (v10)
			v10->m_next = node;

		if (m_pLast)
			m_pLast->m_prev = node;

		m_pLast = node;
	}

	void Remove(const T& value)
	{
		Node *current = m_pFirst;
		while (current)
		{
			if (current->m_value == value)
			{
				remove(current);
				return;
			}

			current = current->m_next;
		}
	}
};

template <typename tC, typename tHeapBinder = Hw::cHeap>
struct Hw::cExpandableVector
{
	int field_0;
	tC *m_vector;
	size_t m_capacity;
	size_t m_size;
	BOOL m_ArrayInitialized;
	tHeapBinder* m_Allocator;

	cExpandableVector()
	{
		field_0 = 0;
		m_vector = nullptr;
		m_capacity = 0;
		m_size = 0;
		m_ArrayInitialized = FALSE;
	};

	cExpandableVector(tHeapBinder* allocator) : m_Allocator(allocator) 
	{
		field_0 = 0;
		m_vector = nullptr;
		m_capacity = 0;
		m_size = 0;
		m_ArrayInitialized = FALSE;
	}

	~cExpandableVector()
	{
		operator delete(m_vector, m_Allocator);
		m_vector = nullptr;

		m_capacity = 0;
		m_size = 0;
		m_ArrayInitialized = FALSE;
	}

	BOOL create(size_t size)
	{
		if (m_vector)
			return FALSE;

		m_vector = (tC*)m_Allocator->AllocateMemory(sizeof(tC) * size, 32, 0, 0);
		if (m_vector)
		{
			m_size = 0;
			m_capacity = size;
			m_ArrayInitialized = TRUE;

			return TRUE;
		}

		ePrintf("Hw::cExpandableVector<tC, tHeapBinder>::create lack of memory[%s %d/%d]", m_Allocator->m_TargetAlloc, sizeof(tC) * size, m_Allocator->getFreeMemory());
		return FALSE;
	}

	void insert(tC& where, const tC& element)
	{
		if (!m_vector)
			return;

		size_t index = &where - m_vector;

		if (index > m_size)
			return;

		if (m_size >= m_capacity)
		{
			if (!m_capacity)
				create(32u);
			else
				reallocate(m_capacity * 2);
		}

		for (size_t i = index; i < m_size; i++)
			m_vector[i] = m_vector[i - 1];

		m_vector[index] = element;
		++m_size;
	}

	void push_back(const tC& element)
	{
		if (!m_vector)
			return;

		if (m_size >= m_capacity)
		{
			if (!m_capacity)
				create(32u);
			else
				reallocate(m_capacity * 2);
		}

		m_vector[m_size++] = element;
	}

	void push_front(const tC& element)
	{
		insert(m_vector[0], element);
	}

	void remove(tC& element)
	{
		if (!m_vector)
			return;

		if (&element - m_vector >= m_size)
			return;

		size_t index = &element - m_vector;

		if (index >= m_capacity) //< Invalid element for vector
			return; 

		for (tC* elem = m_vector + index; elem != m_vector + m_size - 1; elem++)
			*elem = elem[1];

		--m_size;
	}

	void clear()
	{
		if (m_vector)
			m_size = 0;
	}

	tC& get(size_t index)
	{
		return m_vector[index];
	}

	tC& get(size_t index) const
	{
		return m_vector[index];
	}

	tC& operator[](size_t index)
	{
		return get(index);
	}

	tC& operator[](size_t index) const
	{
		return get(index);
	}

	tC* begin()
	{
		return m_vector;
	}

	tC* begin() const
	{
		return m_vector;
	}

	tC* end()
	{
		return m_vector + m_size;
	}

	tC* end() const
	{
		return m_vector + m_size;
	}

	tC* rbegin()
	{
		return m_vector + m_size;
	}

	tC* rbegin() const
	{
		return m_vector + m_size;
	}

	tC* rend()
	{
		return m_vector;
	}

	tC* rend() const
	{
		return m_vector;
	}

	BOOL reallocate(size_t newSize)
	{
		if (m_capacity == newSize)
			return TRUE;

		tC* newArray = (tC*)m_Allocator->AllocateMemory(sizeof(tC) * newSize, 32, 0, 0);

		if (newArray)
		{
			if (m_size >= newSize)
			{
				if (m_size > 0)
				{
					for (size_t elementIndex = 0; elementIndex < m_size; elementIndex++)
						newArray[elementIndex] = m_vector[elementIndex];
				}
				m_size = newSize;
			}
			else
			{
				for (size_t elementIndex = 0; elementIndex < m_size; elementIndex++)
					newArray[elementIndex] = m_vector[elementIndex];
			}
			if (m_ArrayInitialized)
			{
				operator delete(m_vector, m_Allocator);
				m_ArrayInitialized = FALSE;
			}

			m_vector = newArray;
			m_capacity = newSize;
			m_ArrayInitialized = TRUE;

			return TRUE;
		}
		else
		{
			PrintfLog("Hw::cExpandableVector<tC,tHeapBinder>::reallocate Out of memory");
			return FALSE;
		}

		return FALSE;
	}

	BOOL resize(size_t size)
	{
		if (size <= m_capacity || reallocate(size))
		{
			if (size != m_size)
				m_size = size;
			return TRUE;
		}
		else
		{
			PrintfLog("Hw::cExpandableVector<tC,tHeapBinder>::resize insufficient capacity");
			return FALSE;
		}
		return FALSE;
	}
};

#include <CriFs.h>

struct Hw::cDvdFst
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	int field_88;
	int field_8C;
	int field_90;
	int field_94;
	int field_98;
	int field_9C;
	int field_A0;
	int field_A4;
	int field_A8;
	int field_AC;
	int field_B0;
	int field_B4;
	int field_B8;

	struct Work
	{
		int m_State;
		CriFsBinderWork *m_CriBinderWork;
		CriFsLoaderHn *m_CriLoader;
		char m_Filepath[64];
		int m_MaxTime;
		int m_AttemptTime;
		void *m_Filedata;
		int m_Buffersize;
		int m_Priority;
		int field_60;
		int field_64;
		int field_68;
		Work *m_pNext;
		Work *m_pPrevious;
	};

	struct ReadWork : Work // Probably FileReadWork
	{
		char m_Filepath[64];
		void *m_Filedata;
		int m_Buffersize;
		int field_BC;
		int m_WaitAmount;
		int m_ReaderFlags;
		int m_Priority;
	}; 
};

struct Hw::DvdReadManager
{
	int field_0;
	int field_4;
	Hw::cHeapFixed m_DvdReadFactory;
};

VALIDATE_SIZE(Hw::cHeap, 0x40);