/*
File:   orca_macros.h
Author: Taylor Robbins
Date:   09\22\2024
*/

#ifndef _ORCA_MACROS_H
#define _ORCA_MACROS_H

// +==============================+
// |          Constants           |
// +==============================+s
//Actual Value of Pi:      3.1415926535897932384626433832795...
#define Pi64               3.14159265358979311599796346854      //accurate to 15 digits
#define Pi32               3.1415927410125732421875f            //accurate to 6 digits
#define QuarterPi64        (Pi64/4.0)
#define ThirdPi64          (Pi64/3.0)
#define HalfPi64           (Pi64/2.0)
#define ThreeHalfsPi64     (Pi64*(3.0/2.0))
#define TwoPi64            (2*Pi64)
#define QuarterPi32        (Pi32/4.0f)
#define ThirdPi32          (Pi32/3.0f)
#define HalfPi32           (Pi32/2.0f)
#define ThreeHalfsPi32     (Pi32*(3.0f/2.0f))
#define TwoPi32            (2*Pi32)
//Actual Value of e:       2.7182818284590452353602874713526...
#define e64                2.71828182845904509079559829843      //accurate to 15 digits
#define e32                2.71828174591064453125f              //accurate to 6 digits
//Actual Value of sqrt(2): 1.4142135623730950488016887242096...
#define Sqrt2_64           1.41421356237309514547462185874      //accurate to 15 digits
#define Sqrt2_32           1.41421353816986083984375f           //accurate to 7 digits

// +==============================+
// |     Function-like Macros     |
// +==============================+
#define UNUSED(varName)        (void)sizeof(varName)
#define UNREFERENCED(varName)  (void)sizeof(varName)

#define IsVersionBelow(versionMajor, versionMinor, numberMajor, numberMinor) (((versionMajor) < (numberMajor)) || ((versionMajor) == (numberMajor) && (versionMinor) < (numberMinor)))
#define IsVersionAbove(versionMajor, versionMinor, numberMajor, numberMinor) (((versionMajor) > (numberMajor)) || ((versionMajor) == (numberMajor) && (versionMinor) > (numberMinor)))

#define IsEqualXor(variable1, variable2, condition1, condition2) (((variable1) == (condition1) && (variable2) == (condition2)) || ((variable1) == (condition2) && (variable2) == (condition1)))

#define ArrayCount(Array) (sizeof(Array) / sizeof((Array)[0]))

#define IsFlagSet(BitwiseField, Bit) ((Bit) != 0 && ((BitwiseField) & (Bit)) == (Bit))
#define FlagSet(BitwiseField, Bit)   (BitwiseField) |= (Bit)
#define FlagUnset(BitwiseField, Bit) (BitwiseField) &= ~(Bit)
#define FlagToggle(BitwiseField, Bit) ((BitwiseField) ^= (Bit))
#define FlagSetTo(BitwiseField, Bit, condition) if (condition) { FlagSet((BitwiseField), (Bit)); } else { FlagUnset((BitwiseField), (Bit)); }

#define FlagEnumSet(BitwiseField, Bit, enumType, castType)   (BitwiseField) = (enumType)(((castType)(BitwiseField)) | (castType)(Bit))
#define FlagEnumUnset(BitwiseField, Bit, enumType, castType) (BitwiseField) = (enumType)(((castType)(BitwiseField)) & ~((castType)(Bit)))
#define FlagEnumToggle(BitwiseField, Bit, enumType, castType) (BitwiseField) = (enumType)(((castType)(BitwiseField)) ^ ((castType)(Bit)))
#define FlagEnumSetTo(BitwiseField, Bit, condition, enumType, castType) if (condition) { FlagEnumSet((BitwiseField), (Bit), (enumType), (castType)); } else { FlagEnumUnset((BitwiseField), (Bit), (enumType), (castType)); }

#define Kilobytes(value) ((value) * 1024UL)
#define Megabytes(value) (Kilobytes((value)) * 1024UL)
#define Gigabytes(value) (Megabytes((value)) * 1024UL)
#define Terabytes(value) (Gigabytes((value)) * 1024UL)

#define ToRadians32(degrees)		((degrees)/180.0f * Pi32)
#define ToRadians64(degrees)		((degrees)/180.0 * Pi64)
#define ToDegrees32(radians)		((radians)/Pi32 * 180.0f)
#define ToDegrees64(radians)		((radians)/Pi64 * 180.0)

#define IsPntrWithin(regionStart, regionSize, pntr) (((u8*)(pntr)) >= ((u8*)(regionStart)) && ((u8*)(pntr)) <= (((u8*)(regionStart)) + (regionSize)))
#define IsSizedPntrWithin(regionStart, regionSize, pntr, size) (((u8*)(pntr)) >= ((u8*)(regionStart)) && (((u8*)(pntr)) + (size)) <= (((u8*)(regionStart)) + (regionSize)))

#define SetOptionalOutPntr(outputPntr, value) if ((outputPntr) != nullptr) { *(outputPntr) = (value); }

#define PluralEx(number, singularSuffix, multipleSuffix) (((number) == 1) ? (singularSuffix) : (multipleSuffix))
#define Plural(number, multipleSuffix) (((number) == 1) ? "" : (multipleSuffix))

#define TrackMax(isFirst, trackVariable, newValue) do { if ((isFirst) || (trackVariable) < (newValue)) { (trackVariable) = (newValue); } } while(0)
#define TrackMin(isFirst, trackVariable, newValue) do { if ((isFirst) || (trackVariable) > (newValue)) { (trackVariable) = (newValue); } } while(0)

#define EXTERN_C_START extern "C" {
#define EXTERN_C_END }

#define Square(value) ((value) * (value))
#define Cube(value)   ((value) * (value) * (value))

#define Increment(variable, max)           if ((variable) < (max)) { (variable)++; } else { (variable) = (max); }
#define IncrementU8(variable)              if ((variable) < 0xFF) { (variable)++; } else { (variable) = 0xFF; }
#define IncrementU16(variable)             if ((variable) < 0xFFFF) { (variable)++; } else { (variable) = 0xFFFF; }
#define IncrementU32(variable)             if ((variable) < 0xFFFFFFFFUL) { (variable)++; } else { (variable) = 0xFFFFFFFFUL; }
#define IncrementU64(variable)             if ((variable) < 0xFFFFFFFFFFFFFFFFULL) { (variable)++; } else { (variable) = 0xFFFFFFFFFFFFFFFFULL; }
#define IncrementBy(variable, amount, max) if ((variable) + (amount) < (max) && (variable) + (amount) > (variable)) { (variable) += (amount); } else { (variable) = (max); }
#define IncrementU8By(variable, amount)    if ((variable) + (amount) < 0xFF && (variable) + (amount) > (variable)) { (variable) += (amount); } else { (variable) = 0xFF; }
#define IncrementU16By(variable, amount)   if ((variable) + (amount) < 0xFFFF && (variable) + (amount) > (variable)) { (variable) += (amount); } else { (variable) = 0xFFFF; }
#define IncrementU32By(variable, amount)   if ((variable) + (amount) < 0xFFFFFFFFUL && (variable) + (amount) > (variable)) { (variable) += (amount); } else { (variable) = 0xFFFFFFFFUL; }
#define IncrementU64By(variable, amount)   if ((variable) + (amount) < 0xFFFFFFFFFFFFFFFFULL && (variable) + (amount) > (variable)) { (variable) += (amount); } else { (variable) = 0xFFFFFFFFFFFFFFFFULL; }
#define Decrement(variable)                if ((variable) > 0) { (variable)--; } else { (variable) = 0; }
#define DecrementBy(variable, amount)      if ((variable) >= (amount)) { (variable) -= (amount); } else { (variable) = 0; }

#define ReverseByteArray(array, size) do                  \
{                                                         \
	u8 _tempByte; u32 _bIndex = 0;                        \
	while (_bIndex < (u32)(size)/2)                       \
	{                                                     \
		_tempByte = (array)[_bIndex];                     \
		(array)[_bIndex] = (array)[(size) - 1 - _bIndex]; \
		(array)[(size) - 1 - _bIndex] = _tempByte;        \
		_bIndex++;                                        \
	}                                                     \
} while(0)

#define FlipEndianU32(variable) variable = (((*(((const u8*)&(variable)) + 0)) & 0xFF) << 24) | (((*(((const u8*)&(variable)) + 1)) & 0xFF) << 16) | (((*(((const u8*)&(variable)) + 2)) & 0xFF) << 8) | (((*(((const u8*)&(variable)) + 3)) & 0xFF) << 0);
#define OnesComplimentU32(variable) (variable ^ 0xFFFFFFFFL)

#define STRUCT_VAR_SIZE(structureName, variableName) sizeof(((const structureName*)0)->variableName)
#define STRUCT_VAR_OFFSET(structureName, variableName) (u32)((const u8*)&((const structureName*)0)->variableName - (const u8*)((const structureName*)0))
#define STRUCT_VAR_END_OFFSET(structureName, variableName) (u32)(((const u8*)&((const structureName*)0)->variableName + sizeof(((const structureName*)0)->variableName)) - (const u8*)((const structureName*)0))
#define IS_VAR_IN_X_BYTES_OF_STRUCT(structureName, numBytes, variableName) ((numBytes) >= STRUCT_VAR_END_OFFSET(structureName, variableName))

#define SWAP_VARIABLES(varType, var1, var2) do { varType tempVarWithLongNameThatWontConflict = (var2); (var2) = (var1); (var1) = tempVarWithLongNameThatWontConflict; } while(0)
#define SWAP_POINTERS(varType, pntr1, pntr2) do                                \
{                                                                              \
	varType tempVarWithLongNameThatWontConflict;                               \
	MyMemCopy(&tempVarWithLongNameThatWontConflict, (pntr2), sizeof(varType)); \
	MyMemCopy((pntr2), (pntr1), sizeof(varType));                              \
	MyMemCopy((pntr1), &tempVarWithLongNameThatWontConflict, sizeof(varType)); \
	varType* tempPntrWithLongNameThatWontConflict;                             \
	tempPntrWithLongNameThatWontConflict = (pntr2);                            \
	(pntr2) = (pntr1);                                                         \
	(pntr1) = tempPntrWithLongNameThatWontConflict;                            \
} while(0)

#define ClearArray(Array)      memset((Array), '\0', sizeof((Array)))
#define ClearStruct(Structure) memset(&(Structure), '\0', sizeof((Structure)))
#define ClearPointer(Pointer)  memset((Pointer), '\0', sizeof(*(Pointer)));

// +--------------------------------------------------------------+
// |                       Assertion Macros                       |
// +--------------------------------------------------------------+
//TODO: #define CompileAssertMsg(condition, message)
//TODO: #define CompileAssert(condition)
#define MyBreak()          OC_Abort("MyBreak() called!") //TODO: Should these be Abort? Can we debug orca code?
#define MyBreakEx(message) OC_Abort(message)
#if DEBUG_BUILD
#define MyDebugBreak() MyBreak()
#else
#define MyDebugBreak() //nothing
#endif

//NOTE: The application is expected to implement this function!
void AssertFailure(const char* filePath, int lineNumber, const char* funcName, const char* expressionStr, const char* messageStr);

#define AssertMsg_(Expression, message)                 do { if (!(Expression)) { MyBreakEx(message); } } while(0)
#define AssertMsg(Expression, message)                  do { if (!(Expression)) { AssertFailure(__FILE__, __LINE__, __func__, #Expression, (message)); } } while(0)
#define Assert_(Expression)                             do { if (!(Expression)) { MyBreak(); } } while(0)
#define Assert(Expression)                              do { if (!(Expression)) { AssertFailure(__FILE__, __LINE__, __func__, #Expression, nullptr); } } while(0)
#define AssertIf_(Precondition, Expression)             do { if (Precondition) { Assert_(Expression); } } while(0)
#define AssertIf(Precondition, Expression)              do { if (Precondition) { Assert(Expression); } } while(0)
#define AssertIfMsg_(Precondition, Expression, message) do { if (Precondition) { AssertMsg_(Expression, message); } } while(0)
#define AssertIfMsg(Precondition, Expression, message)  do { if (Precondition) { AssertMsg(Expression, message); } } while(0)

#if DEBUG_BUILD
#define DebugAssert_(Expression)                                          Assert_(Expression)
#define DebugAssert(Expression)                                           Assert(Expression);
#define DebugAssertMsg_(Expression, message)                              AssertMsg_(Expression, message)
#define DebugAssertMsg(Expression, message)                               AssertMsg(Expression, message)
#define DebugAssertAndUnused_(Expression, unusedVarInRelease)             Assert_(Expression);
#define DebugAssertAndUnused(Expression, unusedVarInRelease)              Assert(Expression);
#define DebugAssertAndUnusedMsg_(Expression, unusedVarInRelease, message) AssertMsg_(Expression, message)
#define DebugAssertAndUnusedMsg(Expression, unusedVarInRelease, message)  AssertMsg(Expression, message)
#else
#define DebugAssert_(Expression)                                          //nothing
#define DebugAssert(Expression)                                           //nothing
#define DebugAssertMsg_(Expression, message)                              //nothing
#define DebugAssertMsg(Expression, message)                               //nothing
#define DebugAssertAndUnused_(Expression, unusedVarInRelease)             UNUSED(unusedVarInRelease)
#define DebugAssertAndUnused(Expression, unusedVarInRelease)              UNUSED(unusedVarInRelease)
#define DebugAssertAndUnusedMsg_(Expression, unusedVarInRelease, message) UNUSED(unusedVarInRelease)
#define DebugAssertAndUnusedMsg(Expression, unusedVarInRelease, message)  UNUSED(unusedVarInRelease)
#endif

#define NotNull_(variable)                                                Assert_(variable != nullptr)
#define NotNull2_(variable1, variable2)                                   Assert_(variable1 != nullptr && variable2 != nullptr)
#define NotNull3_(variable1, variable2, variable3)                        Assert_(variable1 != nullptr && variable2 != nullptr && variable3 != nullptr)
#define NotNull4_(variable1, variable2, variable3, variable4)             Assert_(variable1 != nullptr && variable2 != nullptr && variable3 != nullptr && variable4 != nullptr)
#define NotNull(variable)                                                 Assert(variable != nullptr)
#define NotNull2(variable1, variable2)                                    Assert(variable1 != nullptr && variable2 != nullptr)
#define NotNull3(variable1, variable2, variable3)                         Assert(variable1 != nullptr && variable2 != nullptr && variable3 != nullptr)
#define NotNull4(variable1, variable2, variable3, variable4)              Assert(variable1 != nullptr && variable2 != nullptr && variable3 != nullptr && variable4 != nullptr)
#define NotNullMsg_(variable, message)                                    AssertMsg_(variable != nullptr, message)
#define NotNull2Msg_(variable1, variable2, message)                       AssertMsg_(variable1 != nullptr && variable2 != nullptr, message)
#define NotNull3Msg_(variable1, variable2, variable3, message)            AssertMsg_(variable1 != nullptr && variable2 != nullptr && variable3 != nullptr, message)
#define NotNull4Msg_(variable1, variable2, variable3, variable4, message) AssertMsg_(variable1 != nullptr && variable2 != nullptr && variable3 != nullptr && variable4 != nullptr, message)
#define NotNullMsg(variable, message)                                     AssertMsg(variable != nullptr, message)
#define NotNull2Msg(variable1, variable2, message)                        AssertMsg(variable1 != nullptr && variable2 != nullptr, message)
#define NotNull3Msg(variable1, variable2, variable3, message)             AssertMsg(variable1 != nullptr && variable2 != nullptr && variable3 != nullptr, message)
#define NotNull4Msg(variable1, variable2, variable3, variable4, message)  AssertMsg(variable1 != nullptr && variable2 != nullptr && variable3 != nullptr && variable4 != nullptr, message)

#define Unimplemented_() AssertMsg_(false, "This code path is unimplemented!")
#define Unimplemented()  AssertMsg(false, "This code path is unimplemented!")

#endif //  _ORCA_MACROS_H

// +--------------------------------------------------------------+
// |                   Autocomplete Dictionary                    |
// +--------------------------------------------------------------+
/*
@Defines
Pi64
Pi32
QuarterPi64
ThirdPi64
HalfPi64
ThreeHalfsPi64
TwoPi64
QuarterPi32
ThirdPi32
HalfPi32
ThreeHalfsPi32
TwoPi32
e64
e32
Sqrt2_64
Sqrt2_32
EXTERN_C_START
EXTERN_C_END
@Types
@Functions
#define UNUSED(varName)
#define UNREFERENCED(varName)
#define IsVersionBelow(versionMajor, versionMinor, numberMajor, numberMinor)
#define IsVersionAbove(versionMajor, versionMinor, numberMajor, numberMinor)
#define IsEqualXor(variable1, variable2, condition1, condition2)
#define ArrayCount(Array)
#define IsFlagSet(BitwiseField, Bit)
#define FlagSet(BitwiseField, Bit)
#define FlagUnset(BitwiseField, Bit)
#define FlagToggle(BitwiseField, Bit)
#define FlagSetTo(BitwiseField, Bit, condition)
#define FlagEnumSet(BitwiseField, Bit, enumType, castType)
#define FlagEnumUnset(BitwiseField, Bit, enumType, castType)
#define FlagEnumToggle(BitwiseField, Bit, enumType, castType)
#define FlagEnumSetTo(BitwiseField, Bit, condition, enumType, castType)
#define Kilobytes(value)
#define Megabytes(value)
#define Gigabytes(value)
#define Terabytes(value)
#define ToRadians32(degrees)
#define ToRadians64(degrees)
#define ToDegrees32(radians)
#define ToDegrees64(radians)
#define IsPntrWithin(regionStart, regionSize, pntr)
#define IsSizedPntrWithin(regionStart, regionSize, pntr, size)
#define SetOptionalOutPntr(outputPntr, value)
#define PluralEx(number, singularSuffix, multipleSuffix)
#define Plural(number, multipleSuffix)
#define TrackMax(isFirst, trackVariable, newValue)
#define TrackMin(isFirst, trackVariable, newValue)
#define Square(value)
#define Cube(value)
#define Increment(variable, max)
#define IncrementU8(variable)
#define IncrementU16(variable)
#define IncrementU32(variable)
#define IncrementU64(variable)
#define IncrementBy(variable, amount, max)
#define IncrementU8By(variable, amount)
#define IncrementU16By(variable, amount)
#define IncrementU32By(variable, amount)
#define IncrementU64By(variable, amount)
#define Decrement(variable)
#define DecrementBy(variable, amount)
#define ReverseByteArray(array, size)
#define FlipEndianU32(variable)
#define OnesComplimentU32(variable)
#define STRUCT_VAR_SIZE(structureName, variableName)
#define STRUCT_VAR_OFFSET(structureName, variableName)
#define STRUCT_VAR_END_OFFSET(structureName, variableName)
#define IS_VAR_IN_X_BYTES_OF_STRUCT(structureName, numBytes, variableName)
#define SWAP_VARIABLES(varType, var1, var2)
#define SWAP_POINTERS(varType, pntr1, pntr2)
#define ClearArray(Array)
#define ClearStruct(Structure)
#define ClearPointer(Pointer)
#define MyBreak()
#define MyBreakEx(message)
#define MyDebugBreak()
void AssertFailure(const char* filePath, int lineNumber, const char* funcName, const char* expressionStr, const char* messageStr)
#define AssertMsg_(Expression, message)
#define AssertMsg(Expression, message)
#define Assert_(Expression)
#define Assert(Expression)
#define AssertIf_(Precondition, Expression)
#define AssertIf(Precondition, Expression)
#define AssertIfMsg_(Precondition, Expression, message)
#define AssertIfMsg(Precondition, Expression, message)
#define DebugAssert_(Expression)
#define DebugAssert(Expression)
#define DebugAssertMsg_(Expression, message)
#define DebugAssertMsg(Expression, message)
#define DebugAssertAndUnused_(Expression, unusedVarInRelease)
#define DebugAssertAndUnused(Expression, unusedVarInRelease)
#define DebugAssertAndUnusedMsg_(Expression, unusedVarInRelease, message)
#define DebugAssertAndUnusedMsg(Expression, unusedVarInRelease, message)
#define NotNull_(variable)
#define NotNull2_(variable1, variable2)
#define NotNull3_(variable1, variable2, variable3)
#define NotNull4_(variable1, variable2, variable3, variable4)
#define NotNull(variable)
#define NotNull2(variable1, variable2)
#define NotNull3(variable1, variable2, variable3)
#define NotNull4(variable1, variable2, variable3, variable4)
#define NotNullMsg_(variable, message)
#define NotNull2Msg_(variable1, variable2, message)
#define NotNull3Msg_(variable1, variable2, variable3, message)
#define NotNull4Msg_(variable1, variable2, variable3, variable4, message)
#define NotNullMsg(variable, message)
#define NotNull2Msg(variable1, variable2, message)
#define NotNull3Msg(variable1, variable2, variable3, message)
#define NotNull4Msg(variable1, variable2, variable3, variable4, message)
#define Unimplemented_()
#define Unimplemented()
*/
