#pragma once

#include <hkBase.h>

#ifdef HK_COMPILER_INTEL
#pragma warning disable 327 // #Null reference not allowed#  from the type traits cast below
#endif

template <bool N> struct hkTraitBool { typedef hkTraitBool<N> type; enum { result = N }; };
typedef hkTraitBool<true> hkTypeIsPod;
typedef hkTraitBool<false> hkTypeIsClass;

template <typename T>
hkBool::CompileTimeFalseType operator==(const T&, const hkTypeIsPod&);

// Default hkIsPodType<T>::type() == hkBoolean<false>.
#if defined(__GCCXML__)
  template <typename T>
  struct hkIsPodType : public hkTraitBool< ( sizeof(*static_cast<T*>(0) == *static_cast<const hkTypeIsPod*>(0)) == sizeof(hkBool::CompileTimeTrueType) ) > {};
#else
  template <typename T>
  struct hkIsPodType : public hkTraitBool< ( sizeof(*reinterpret_cast<T*>(128) == *reinterpret_cast<const hkTypeIsPod*>(128)) == sizeof(hkBool::CompileTimeTrueType) ) > {};
#endif

// Type with one level of const removed: hkRemoveConst<int>::type is int, so is hkRemoveConst<const int>::type
template <typename T>
struct hkRemoveConst{ typedef T type; };
template <typename T>
struct hkRemoveConst<const T>{ typedef T type; };

// Checking for "const"
template <typename T>
struct hkIsConstType : public hkTraitBool<false>{};
template <typename T>
struct hkIsConstType<const T> : public hkTraitBool<true>{};

// This declaration is required to treat a class or struct as a pod type. Must have public visibility.
#define HK_DECLARE_POD_TYPE() \
	hkBool::CompileTimeTrueType operator== (const hkTypeIsPod&) const

#define HK_DECLARE_POD_TYPE_IF_POD(TYPE) \
	hkBool::CompileTimeTrueType operator== (const hkTraitBool< hkIsPodType< TYPE >::result >&) const

// This can be used to define a type as a pod type.
#define HK_DEFINE_AS_POD_TYPE(T) \
	template<> struct hkIsPodType< T > : public hkTypeIsPod {}

//
// Define Havok pod types.
//
HK_DEFINE_AS_POD_TYPE(bool);
HK_DEFINE_AS_POD_TYPE(hkBool);
HK_DEFINE_AS_POD_TYPE(char);
HK_DEFINE_AS_POD_TYPE(hkInt8);
HK_DEFINE_AS_POD_TYPE(hkUint8);
HK_DEFINE_AS_POD_TYPE(hkInt16);
HK_DEFINE_AS_POD_TYPE(hkUint16);
HK_DEFINE_AS_POD_TYPE(hkInt32);
HK_DEFINE_AS_POD_TYPE(hkUint32);
HK_DEFINE_AS_POD_TYPE(hkInt64);
HK_DEFINE_AS_POD_TYPE(hkUint64);
#if HK_POINTER_SIZE != 8
	HK_DEFINE_AS_POD_TYPE(hkLong);
	HK_DEFINE_AS_POD_TYPE(hkUlong);
#endif
HK_DEFINE_AS_POD_TYPE(hkHalf);
HK_DEFINE_AS_POD_TYPE(hkFloat32);
HK_DEFINE_AS_POD_TYPE(hkDouble64);

// built-in hkVariant
HK_DEFINE_AS_POD_TYPE(hkVariant);

// Pointers are pod types
template <typename T> struct hkIsPodType<T*> : public hkTypeIsPod {};
// Arrays
template <typename T, unsigned int N> struct hkIsPodType<T[N]> : public hkIsPodType< T > {};