#pragma once

#include <hkBase.h>
#include <hkTypeTraits.h>

class hkArrayUtil
{
public:

    template<typename T> static HK_FORCE_INLINE void construct(T* t, int n, hkTypeIsPod)
    {
    }
	template<typename T> static HK_FORCE_INLINE void construct(T* t, int n, hkTypeIsClass)
    {
        for (int i = 0; i < n; ++i)
        {
            ::new (reinterpret_cast<hkPlacementNewArg*>(t + 1)) T;
        }
    }

	template<typename T> static HK_FORCE_INLINE void constructWithCopy(T* t, int n, const T& tcopy, hkTypeIsPod)
    {
        for (int i = 0; i < n; ++i)
        {
            t[i] = tcopy;
        }
    }
	template<typename T> static HK_FORCE_INLINE void constructWithCopy(T* t, int n, const T& tcopy, hkTypeIsClass)
    {
        for (int i = 0; i < n; ++i)
        {
            void *buffer = (void*)hkAddByteOffsetConst(t, sizeof(T) * i);
            ::new(reinterpret_cast<hkPlacementNewArg*>(buffer)) T(tcopy);
        }
    }

	template<typename T> static HK_FORCE_INLINE void destruct(T* t, int n, hkTypeIsPod)
    {
    }
	template<typename T> static HK_FORCE_INLINE void destruct(T* t, int n, hkTypeIsClass)
    {
        for (int i = n - 1; i >= 0; --i)
        {
            static_cast<T*>(t)[i].~T();
        }
    }

	template<typename T> static HK_FORCE_INLINE void constructWithArray(T* t, int n, const T* tcopy, hkTypeIsPod)
    {
        for (int i = 0; i < n; ++i)
        {
            t[i] = tcopy[i];
        }
    }
	template<typename T> static HK_FORCE_INLINE void constructWithArray(T* t, int n, const T* tcopy, hkTypeIsClass)
    {
        for (int i = 0; i < n; ++i)
        {
            ::new (reinterpret_cast<hkPlacementNewArg*>(t + i)) T(tcopy[i]);
        }
    }
};