// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UE4EscapeRoom/OpenDoor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOpenDoor() {}
// Cross Module References
	UE4ESCAPEROOM_API UClass* Z_Construct_UClass_UOpenDoor_NoRegister();
	UE4ESCAPEROOM_API UClass* Z_Construct_UClass_UOpenDoor();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_UE4EscapeRoom();
// End Cross Module References
	void UOpenDoor::StaticRegisterNativesUOpenDoor()
	{
	}
	UClass* Z_Construct_UClass_UOpenDoor_NoRegister()
	{
		return UOpenDoor::StaticClass();
	}
	struct Z_Construct_UClass_UOpenDoor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOpenDoor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_UE4EscapeRoom,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOpenDoor_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "OpenDoor.h" },
		{ "ModuleRelativePath", "OpenDoor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOpenDoor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOpenDoor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UOpenDoor_Statics::ClassParams = {
		&UOpenDoor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UOpenDoor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOpenDoor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOpenDoor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UOpenDoor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UOpenDoor, 3130435132);
	template<> UE4ESCAPEROOM_API UClass* StaticClass<UOpenDoor>()
	{
		return UOpenDoor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UOpenDoor(Z_Construct_UClass_UOpenDoor, &UOpenDoor::StaticClass, TEXT("/Script/UE4EscapeRoom"), TEXT("UOpenDoor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOpenDoor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
