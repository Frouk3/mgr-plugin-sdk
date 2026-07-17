#pragma once
#include <Windows.h>
#include <stdlib.h>

#pragma warning(disable : 26495)

#define PI 3.14159265359f
#define DEG_TO_RAD(x) (x * (PI / 180))
#define RAD_TO_DEG(x) (x * (180 / PI))
#define VALIDATE_SIZE(struc, size) static_assert(sizeof(struc) == size, "Invalid structure size of " #struc)

class shared
{
private:
#ifdef SHARED_USE_EX_FUNCS
	// used for extended usage of key pressing(requires updating)
	/*
	static inline bool key_state_ex[256] = {};
	static inline bool prev_key_state[256] = {};
	*/
	static inline unsigned int aPressedKeys[8] = { 0 }; // Compressed int's will weight less
	static inline unsigned int aPressedKeysHistory[8] = { 0 }; 

#else
	// used for simple key checking
	// static inline bool key_state[256] = {};
	static inline unsigned int aPressedKeys[8] = { 0 }; 
#endif
public:
	static inline DWORD base = (DWORD)GetModuleHandleA(NULL);

	static inline unsigned int random(unsigned int min, unsigned int max) { return min + (rand() % (max - min + 1)); }
	static inline int random(int min, int max) { return min + (rand() % (max - min + 1)); }
	static inline float random(float min, float max) { return min + (max - min) * (rand() / float(RAND_MAX + 1)); }
#ifdef SHARED_USE_EX_FUNCS
	static inline bool IsKeyPressed(int vKey, bool bRepeat = true)
	{
		if (!*(bool*)(shared::base + 0x19D509C)) // if not foreground
			return false;

		if (!vKey) // Might get true if controller is connected
			return false;

		unsigned int mask = 1 << (vKey & 0x1F);

		if (bRepeat)
			return (aPressedKeys[vKey >> 5] & mask) != 0;

		return (aPressedKeys[vKey >> 5] & mask) != 0 && !(aPressedKeysHistory[vKey >> 5] & mask);
	}

	// should be passed after the update of everything(OnUpdateEvent.after for example)
	static inline void ExPressKeyUpdate()
	{
		memcpy(aPressedKeysHistory, aPressedKeys, sizeof(aPressedKeys));

		for (int i = 0; i < 256; i++)
		{
			if (SHORT state = GetKeyState(i); state & 0x80)
				aPressedKeys[i >> 5] |= 1 << (i & 0x1F);
			else
				aPressedKeys[i >> 5] &= ~(1 << (i & 0x1F));
		}
	}

#else
	static inline bool IsKeyPressed(int vKey, bool bRepeat = true)
	{
		if (!*(bool*)(shared::base + 0x19D509C)) // if not foreground
			return false;

		if (!vKey)
			return false;

		bool isKeyDown = GetKeyState(vKey) & 0x80;

		bool condition = isKeyDown && !(aPressedKeys[vKey >> 5] & (1 << (vKey & 0x1F)));

		if (isKeyDown)
			aPressedKeys[vKey >> 5] |= 1 << (vKey & 0x1F);
		else
			aPressedKeys[vKey >> 5] &= ~(1 << (vKey & 0x1F));

		if (bRepeat)
			return isKeyDown;

		return condition;
	}

#endif

	template <typename T>
	static inline T clamp(T x, T min, T max) { return (x < min) ? min : (x > max) ? max : x; }
};

/*
* why even bother making wrapper functions for different type of calls? Just make a simple macro that would apply the type instead
*/

// get virtual table pointer from the instance
#define GET_VTABLE(instance) (*(void***)(instance))

// get function pointer based on the index from the instance
#define GET_VFTABLE(instance, index) (GET_VTABLE(instance)[index])

// apply a type to target to make a call
#define MAKE_CALL(target, type, ...) ((type)(target))(__VA_ARGS__)

// apply a type to virtual function stored in index from instance and make a call
#define MAKE_VCALL(index, type, instance, ...) MAKE_CALL(GET_VFTABLE(instance, index), type, instance, __VA_ARGS__)