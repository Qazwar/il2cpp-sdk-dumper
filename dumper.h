#pragma once

#include <iostream>
#include <windows.h>
#include <cstdint>
#include <vector>
#include <memory>
#include <fstream>
#include <atomic>
#include <iostream>
#include <string>
#include <functional>

#pragma region defines

#define FIELD_ATTRIBUTE_FIELD_ACCESS_MASK     0x0007
#define FIELD_ATTRIBUTE_COMPILER_CONTROLLED   0x0000
#define FIELD_ATTRIBUTE_PRIVATE               0x0001
#define FIELD_ATTRIBUTE_FAM_AND_ASSEM         0x0002
#define FIELD_ATTRIBUTE_ASSEMBLY              0x0003
#define FIELD_ATTRIBUTE_FAMILY                0x0004
#define FIELD_ATTRIBUTE_FAM_OR_ASSEM          0x0005
#define FIELD_ATTRIBUTE_PUBLIC                0x0006

#define FIELD_ATTRIBUTE_STATIC                0x0010
#define FIELD_ATTRIBUTE_INIT_ONLY             0x0020
#define FIELD_ATTRIBUTE_LITERAL               0x0040
#define FIELD_ATTRIBUTE_NOT_SERIALIZED        0x0080
#define FIELD_ATTRIBUTE_SPECIAL_NAME          0x0200
#define FIELD_ATTRIBUTE_PINVOKE_IMPL          0x2000

/* For runtime use only */
#define FIELD_ATTRIBUTE_RESERVED_MASK         0x9500
#define FIELD_ATTRIBUTE_RT_SPECIAL_NAME       0x0400
#define FIELD_ATTRIBUTE_HAS_FIELD_MARSHAL     0x1000
#define FIELD_ATTRIBUTE_HAS_DEFAULT           0x8000
#define FIELD_ATTRIBUTE_HAS_FIELD_RVA         0x0100

/*
 * Method Attributes (22.1.9)
 */

#define METHOD_IMPL_ATTRIBUTE_CODE_TYPE_MASK       0x0003
#define METHOD_IMPL_ATTRIBUTE_IL                   0x0000
#define METHOD_IMPL_ATTRIBUTE_NATIVE               0x0001
#define METHOD_IMPL_ATTRIBUTE_OPTIL                0x0002
#define METHOD_IMPL_ATTRIBUTE_RUNTIME              0x0003

#define METHOD_IMPL_ATTRIBUTE_MANAGED_MASK         0x0004
#define METHOD_IMPL_ATTRIBUTE_UNMANAGED            0x0004
#define METHOD_IMPL_ATTRIBUTE_MANAGED              0x0000

#define METHOD_IMPL_ATTRIBUTE_FORWARD_REF          0x0010
#define METHOD_IMPL_ATTRIBUTE_PRESERVE_SIG         0x0080
#define METHOD_IMPL_ATTRIBUTE_INTERNAL_CALL        0x1000
#define METHOD_IMPL_ATTRIBUTE_SYNCHRONIZED         0x0020
#define METHOD_IMPL_ATTRIBUTE_NOINLINING           0x0008
#define METHOD_IMPL_ATTRIBUTE_MAX_METHOD_IMPL_VAL  0xffff

#define METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK        0x0007
#define METHOD_ATTRIBUTE_COMPILER_CONTROLLED       0x0000
#define METHOD_ATTRIBUTE_PRIVATE                   0x0001
#define METHOD_ATTRIBUTE_FAM_AND_ASSEM             0x0002
#define METHOD_ATTRIBUTE_ASSEM                     0x0003
#define METHOD_ATTRIBUTE_FAMILY                    0x0004
#define METHOD_ATTRIBUTE_FAM_OR_ASSEM              0x0005
#define METHOD_ATTRIBUTE_PUBLIC                    0x0006

#define METHOD_ATTRIBUTE_STATIC                    0x0010
#define METHOD_ATTRIBUTE_FINAL                     0x0020
#define METHOD_ATTRIBUTE_VIRTUAL                   0x0040
#define METHOD_ATTRIBUTE_HIDE_BY_SIG               0x0080

#define METHOD_ATTRIBUTE_VTABLE_LAYOUT_MASK        0x0100
#define METHOD_ATTRIBUTE_REUSE_SLOT                0x0000
#define METHOD_ATTRIBUTE_NEW_SLOT                  0x0100

#define METHOD_ATTRIBUTE_STRICT                    0x0200
#define METHOD_ATTRIBUTE_ABSTRACT                  0x0400
#define METHOD_ATTRIBUTE_SPECIAL_NAME              0x0800

#define METHOD_ATTRIBUTE_PINVOKE_IMPL              0x2000
#define METHOD_ATTRIBUTE_UNMANAGED_EXPORT          0x0008

 /*
  * For runtime use only
  */
#define METHOD_ATTRIBUTE_RESERVED_MASK             0xd000
#define METHOD_ATTRIBUTE_RT_SPECIAL_NAME           0x1000
#define METHOD_ATTRIBUTE_HAS_SECURITY              0x4000
#define METHOD_ATTRIBUTE_REQUIRE_SEC_OBJECT        0x8000

  /*
  * Type Attributes (21.1.13).
  */
#define TYPE_ATTRIBUTE_VISIBILITY_MASK       0x00000007
#define TYPE_ATTRIBUTE_NOT_PUBLIC            0x00000000
#define TYPE_ATTRIBUTE_PUBLIC                0x00000001
#define TYPE_ATTRIBUTE_NESTED_PUBLIC         0x00000002
#define TYPE_ATTRIBUTE_NESTED_PRIVATE        0x00000003
#define TYPE_ATTRIBUTE_NESTED_FAMILY         0x00000004
#define TYPE_ATTRIBUTE_NESTED_ASSEMBLY       0x00000005
#define TYPE_ATTRIBUTE_NESTED_FAM_AND_ASSEM  0x00000006
#define TYPE_ATTRIBUTE_NESTED_FAM_OR_ASSEM   0x00000007

#define TYPE_ATTRIBUTE_LAYOUT_MASK           0x00000018
#define TYPE_ATTRIBUTE_AUTO_LAYOUT           0x00000000
#define TYPE_ATTRIBUTE_SEQUENTIAL_LAYOUT     0x00000008
#define TYPE_ATTRIBUTE_EXPLICIT_LAYOUT       0x00000010

#define TYPE_ATTRIBUTE_CLASS_SEMANTIC_MASK   0x00000020
#define TYPE_ATTRIBUTE_CLASS                 0x00000000
#define TYPE_ATTRIBUTE_INTERFACE             0x00000020

#define TYPE_ATTRIBUTE_ABSTRACT              0x00000080
#define TYPE_ATTRIBUTE_SEALED                0x00000100
#define TYPE_ATTRIBUTE_SPECIAL_NAME          0x00000400

#define TYPE_ATTRIBUTE_IMPORT                0x00001000
#define TYPE_ATTRIBUTE_SERIALIZABLE          0x00002000

#define TYPE_ATTRIBUTE_STRING_FORMAT_MASK    0x00030000
#define TYPE_ATTRIBUTE_ANSI_CLASS            0x00000000
#define TYPE_ATTRIBUTE_UNICODE_CLASS         0x00010000
#define TYPE_ATTRIBUTE_AUTO_CLASS            0x00020000

#define TYPE_ATTRIBUTE_BEFORE_FIELD_INIT     0x00100000
#define TYPE_ATTRIBUTE_FORWARDER             0x00200000

#define TYPE_ATTRIBUTE_RESERVED_MASK         0x00040800
#define TYPE_ATTRIBUTE_RT_SPECIAL_NAME       0x00000800
#define TYPE_ATTRIBUTE_HAS_SECURITY          0x00040000

  /*
  * Flags for Params (22.1.12)
  */
#define PARAM_ATTRIBUTE_IN                 0x0001
#define PARAM_ATTRIBUTE_OUT                0x0002
#define PARAM_ATTRIBUTE_OPTIONAL           0x0010
#define PARAM_ATTRIBUTE_RESERVED_MASK      0xf000
#define PARAM_ATTRIBUTE_HAS_DEFAULT        0x1000
#define PARAM_ATTRIBUTE_HAS_FIELD_MARSHAL  0x2000
#define PARAM_ATTRIBUTE_UNUSED             0xcfe0

  // Flags for Generic Parameters (II.23.1.7)
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_NON_VARIANT                           0x00
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_COVARIANT                             0x01
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_CONTRAVARIANT                         0x02
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_VARIANCE_MASK                         0x03
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_REFERENCE_TYPE_CONSTRAINT             0x04
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_NOT_NULLABLE_VALUE_TYPE_CONSTRAINT    0x08
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_DEFAULT_CONSTRUCTOR_CONSTRAINT        0x10
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_SPECIAL_CONSTRAINT_MASK               0x1C

/**
 * 21.5 AssemblyRefs
 */
#define ASSEMBLYREF_FULL_PUBLIC_KEY_FLAG      0x00000001
#define ASSEMBLYREF_RETARGETABLE_FLAG         0x00000100
#define ASSEMBLYREF_ENABLEJITCOMPILE_TRACKING_FLAG 0x00008000
#define ASSEMBLYREF_DISABLEJITCOMPILE_OPTIMIZER_FLAG 0x00004000

#pragma endregion defines

namespace Dumper
{
	using __u32 = std::uint32_t;
	using __u64 = std::uint64_t;
	using __ptr = std::uint8_t*;
		
	namespace __il2cpp
	{
		#define e_export( t, n, nn ) using c__##n = t; c__##n n = ( c__##n )GetProcAddress( GetModuleHandleA( "GameAssembly.dll"), nn );

		const struct c__type
		{
			enum class e__type_enum
			{
				IL2CPP_TYPE_END = 0x00,
				IL2CPP_TYPE_VOID = 0x01,
				IL2CPP_TYPE_BOOLEAN = 0x02,
				IL2CPP_TYPE_CHAR = 0x03,
				IL2CPP_TYPE_I1 = 0x04,
				IL2CPP_TYPE_U1 = 0x05,
				IL2CPP_TYPE_I2 = 0x06,
				IL2CPP_TYPE_U2 = 0x07,
				IL2CPP_TYPE_I4 = 0x08,
				IL2CPP_TYPE_U4 = 0x09,
				IL2CPP_TYPE_I8 = 0x0A,
				IL2CPP_TYPE_U8 = 0x0B,
				IL2CPP_TYPE_R4 = 0x0C,
				IL2CPP_TYPE_R8 = 0x0D,
				IL2CPP_TYPE_STRING = 0x0E,
				IL2CPP_TYPE_PTR = 0x0F,
				IL2CPP_TYPE_BYREF = 0x10,
				IL2CPP_TYPE_VALUETYPE = 0x11,
				IL2CPP_TYPE_CLASS = 0x12,
				IL2CPP_TYPE_VAR = 0x13,
				IL2CPP_TYPE_ARRAY = 0x14,
				IL2CPP_TYPE_GENERICINST = 0x15,
				IL2CPP_TYPE_TYPEDBYREF = 0x16,
				IL2CPP_TYPE_I = 0x18,
				IL2CPP_TYPE_U = 0x19,
				IL2CPP_TYPE_FNPTR = 0x1B,
				IL2CPP_TYPE_OBJECT = 0x1C,
				IL2CPP_TYPE_SZARRAY = 0x1D,
				IL2CPP_TYPE_MVAR = 0x1E,
				IL2CPP_TYPE_CMOD_REQD = 0x1F,
				IL2CPP_TYPE_CMOD_OPT = 0x20,
				IL2CPP_TYPE_INTERNAL = 0x21,
				IL2CPP_TYPE_MODIFIER = 0x40,
				IL2CPP_TYPE_SENTINEL = 0x41,
				IL2CPP_TYPE_PINNED = 0x45,
				IL2CPP_TYPE_ENUM = 0x55,
			};

			union
			{
				void* dummy;
				std::uint32_t klassIndex;
				const void* type;
				void* array;
				std::uint32_t genericParameterIndex;
				void* generic_class;
			} data;
			std::uint32_t attrs : 16;
			e__type_enum type : 8;
			unsigned int num_mods : 6;
			unsigned int byref : 1;
			unsigned int pinned : 1;

			std::add_const_t< char* > __name_get( )
			{
				e_export( std::add_const_t< char* >( * )( decltype( this ) ), __name_get, "il2cpp_type_get_name" );
				return __name_get( this );
			}

			bool __is_pointer( )
			{
				e_export( bool( * )( decltype( this ) ), __is_pointer, "il2cpp_type_is_pointer_type" );
				return __is_pointer( this );
			}

			struct c__class* __class_get( )
			{
				e_export( c__class * ( * )( decltype( this ) ), __class_get, "il2cpp_class_from_type" );
				return __class_get( this );
			}
		};

		const struct c__field
		{
			const char* name;
			const c__type* type;
			void* parent;
			int32_t offset;
			uint32_t token;

			c__type* __type_get( )
			{
				e_export( c__type * ( * )( decltype( this ) ), __type_get, "il2cpp_field_get_type" );
				return __type_get( this );
			}
		};

		const struct c__param_info
		{
			const char* name;
			int32_t position;
			uint32_t token;
			c__type* parameter_type;
		};

		const struct c__method
		{
			void* methodPointer;
			void* invoker_method;
			const char* name;
			void* klass;
			const c__type* return_type;
			const c__param_info* parameters;
			union
			{
				const void* rgctx_data;
				const c__method* methodDefinition;
			};
			union
			{
				const void* genericMethod;
				const void* genericContainer;
			};
			uint32_t token;
			uint16_t flags;
			uint16_t iflags;
			uint16_t slot;
			uint8_t parameters_count;
			uint8_t is_generic : 1;
			uint8_t is_inflated : 1;
			uint8_t wrapper_type : 1;
			uint8_t is_marshaled_from_native : 1;

			c__type* __type_get( )
			{
				e_export( c__type * ( * )( decltype( this ) ), __type_get, "il2cpp_method_get_return_type" );
				return __type_get( this );
			}
		};

		const struct c__class
		{
			const struct c__image* image;
			void* gc_desc;
			const char* name;
			const char* namespaze;
			c__type* byval_arg;
			c__type* this_arg;
			c__class* element_class;
			c__class* castClass;
			c__class* declaringType;
			c__class* parent;
			void* generic_class;
			const void* typeDefinition;
			const void* interopData;
			c__class* klass;
			c__field* fields;
			const void* events;
			const void* properties;
			const c__method** methods;
			c__class** nestedTypes;
			c__class** implementedInterfaces;
			void* interfaceOffsets;
			void* static_fields;
			const void* rgctx_data;
			c__class** typeHierarchy;
			void* unity_user_data;
			uint32_t initializationExceptionGCHandle;
			uint32_t cctor_started;
			uint32_t cctor_finished;
			__declspec( align( 8 ) ) size_t cctor_thread;
			void* genericContainerIndex;
			uint32_t instance_size;
			uint32_t actualSize;
			uint32_t element_size;
			int32_t native_size;
			uint32_t static_fields_size;
			uint32_t thread_static_fields_size;
			int32_t thread_static_fields_offset;
			uint32_t flags;
			uint32_t token;
			uint16_t method_count;
			uint16_t property_count;
			uint16_t field_count;
			uint16_t event_count;
			uint16_t nested_type_count;
			uint16_t vtable_count;
			uint16_t interfaces_count;
			uint16_t interface_offsets_count;
			uint8_t typeHierarchyDepth;
			uint8_t genericRecursionDepth;
			uint8_t rank;
			uint8_t minimumAlignment;
			uint8_t naturalAligment;
			uint8_t packingSize;
			uint8_t initialized_and_no_error : 1;
			uint8_t valuetype : 1;
			uint8_t initialized : 1;
			uint8_t enumtype : 1;
			uint8_t is_generic : 1;
			uint8_t has_references : 1;
			uint8_t init_pending : 1;
			uint8_t size_inited : 1;
			uint8_t has_finalize : 1;
			uint8_t has_cctor : 1;
			uint8_t is_blittable : 1;
			uint8_t is_import_or_windows_runtime : 1;
			uint8_t is_vtable_initialized : 1;
			uint8_t has_initialization_error : 1;
			void* vtable[ 32 ];

			[[ nodiscard( "__fields_get" ) ]]
			c__field* __fields_get( void** iter )
			{
				e_export( c__field * ( * )( decltype( this ), void** ), __fields_get, "il2cpp_class_get_fields" );
				return __fields_get( this, iter );
			}

			[[ nodiscard( "__methods_get" ) ]]
			c__method* __methods_get( void** iter )
			{
				e_export( c__method * ( * )( decltype( this ), void** ), __methods_get, "il2cpp_class_get_methods" );
				return __methods_get( this, iter );
			}

			c__type* __type_get( )
			{
				e_export( c__type * ( * )( decltype( this ) ), __type_get, "il2cpp_class_get_type" );
				return __type_get( this );
			}

			c__class* __parent_get( )
			{
				e_export( c__class * ( * )( decltype( this ) ), __parent_get, "il2cpp_class_get_parent" );
				return __parent_get( this );
			}
		};

		const struct c__image
		{
			const char* name;
			const char* nameNoExt;
			void* assembly;
			std::uint32_t typeStart;
			uint32_t typeCount;
			std::uint32_t exportedTypeStart;
			uint32_t exportedTypeCount;
			std::uint32_t customAttributeStart;
			uint32_t customAttributeCount;
			std::uint32_t entryPointIndex;
			void* nameToClassHashTable;
			const void* codeGenModule;
			uint32_t token;
			uint8_t dynamic;

			[[ nodiscard( "__class_get" ) ]]
			std::add_pointer_t< c__class > __class_get( std::size_t idx )
			{
				e_export( c__class * ( * )( decltype( this ), std::size_t ), __class_get, "il2cpp_image_get_class" );
				return __class_get( this, idx );
			}

			[[ nodiscard( "__class_count_get" ) ]]
			std::size_t __class_count_get( )
			{
				e_export( std::size_t( * )( decltype( this ) ), __class_count_get, "il2cpp_image_get_class_count" );
				return __class_count_get( this );
			}
		};

		const struct c__assembly
		{
			[[ nodiscard( "__image_get" ) ]]
			std::add_pointer_t< c__image > __image_get( )
			{
				e_export( c__image * ( * )( decltype( this ) ), __image_get, "il2cpp_assembly_get_image" );
				return __image_get( this );
			}
		};

		const struct c__domain
		{

			[[ nodiscard( "__domain_get" ) ]]
			static std::add_pointer_t< c__domain > __domain_get( )
			{
				e_export( c__domain *( * )( ), __domain_get, "il2cpp_domain_get" );
				return __domain_get( );
			}

			[[ nodiscard( "__assemblies" ) ]]
			std::vector< std::add_pointer_t< c__assembly > > __assemblies( )
			{
				std::vector< std::add_pointer_t< c__assembly > > __temp;

				e_export( c__assembly * *( * )( decltype( this ), std::uintptr_t* ), __assemblies, "il2cpp_domain_get_assemblies" );

				std::uintptr_t size = {};
				c__assembly** __assemblies_ = __assemblies( this, &size );

				for ( std::size_t idx = {}; idx < size; idx++ )
				{
					c__assembly* __assembly = __assemblies_[ idx ];
					if( !__assembly )
						continue;

					__temp.push_back( __assembly );
				}

				return __temp;
			}
		};
	}


	enum class __status : std::int32_t
	{
		success = 64,
		error = 32
	};

	struct  __cfg
	{
		struct __cfg_field
		{
			bool use_pads;
			bool  use_alignment;
			bool use_field_getter;
			std::string prefix;
			std::string postfix;
		};

		struct __cfg_method
		{
			bool  use_rva;
			bool  use_method_getter;
			std::string prefix;
			std::string postfix;
		};

		std::shared_ptr< __cfg_method  > __method_cfg;
		std::shared_ptr< __cfg_field  > __field_cfg;
		std::add_const_t < boolean > $DumpClasses;		

		std::remove_all_extents_t< std::ofstream > __sdk;
	};

	template<typename T>
	concept __concept_t = std::same_as<T, std::pair< __cfg*, std::size_t > >;

	inline std::pair< __cfg* , std::size_t > dumper_data;

	struct c__dumper_ctx
	{
		std::vector< __il2cpp::c__field* > __static_fields;
		std::vector< __il2cpp::c__field* > __fields;

		std::vector< __il2cpp::c__class* > __structs;
		std::vector< __il2cpp::c__class* > __classes;
		std::vector< __il2cpp::c__class* > __enums;

		std::vector< __il2cpp::c__method* > __methods;
	};

	inline std::vector< std::string > class_names;

	inline c__dumper_ctx __dumper_ctx = {};

	const auto replace_all = [ & ]( std::string str, const std::string& from, const std::string& to ) -> std::string
	{
		size_t start_pos = 0;
		while ( ( start_pos = str.find( from, start_pos ) ) != std::string::npos ) {
			str.replace( start_pos, from.length( ), to );
			start_pos += to.length( ); // Handles case where 'to' is a substring of 'from'
		}
		return str;
	};

	inline std::function< std::add_const_t < void >( ) > __dump( )
	{
		[[unlikely]]
		if ( !dumper_data.first || !dumper_data.second )
			return {};

		__cfg* __config = dumper_data.first;
		
		if ( !__config->__sdk )
			return {};

		__config->__sdk << "//@ lelomaster at unknowncheats\n";

		static __il2cpp::c__domain* domain = __il2cpp::c__domain::__domain_get( );
		if ( !domain )
			return {};

		for ( __il2cpp::c__assembly* __assembly : domain->__assemblies( ) )
		{
			if( !__assembly )
				continue;

			__il2cpp::c__image* __image = __assembly->__image_get( );
			if( !__image )
				continue;

			for ( std::size_t idx = {}; idx < __image->__class_count_get( ); idx++ )
			{
				__il2cpp::c__class* __class = __image->__class_get( idx );
				if( !__class )
					continue;

				auto invalid_chars = [ ]( __il2cpp::c__class* __class ) -> bool
				{
					if ( !__class )
						return false;

					std::string __name = __class->name;
					if ( __name.empty( ) )
						return false;
					
					if ( __name.contains( "<" ) || __name.contains( ">" ) || __name.contains( "`" ) || __name.contains( "1" ) )
						return true;

					return false;
				};
				if( invalid_chars( __class ) )
					continue;

				__il2cpp::c__type* __type = __class->__type_get( );
				if( !__type )
					continue;

				std::string __namespaze = __class->namespaze;
				__namespaze = replace_all( __namespaze, ".", "::" );

				std::string __name = __class->name;

				if ( __type->type == __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_CLASS ) {
					__dumper_ctx.__classes.push_back( __class );

					if ( !__namespaze.empty( ) )
						__config->__sdk << "namespace " << __namespaze << "{";

					if ( __namespaze.empty( ) )
						__config->__sdk << "class __declspec( align( 8 ) ) " << __class->name << ";\n";
					else
						__config->__sdk << "class __declspec( align( 8 ) ) " << __class->name << ";";

					if ( !__namespaze.empty( ) )
						__config->__sdk << "}\n";
				}
			
				auto is_enum = [ ]( __il2cpp::c__class* __class ) -> bool
				{
					if ( !__class->__parent_get( ) )
						return false;

					__il2cpp::c__type* __type = __class->__type_get( );
					if ( !__type )
						return false;

					std::string __parent_name = __class->__parent_get( )->name;

					if ( __parent_name.contains( "enum" ) || __parent_name.contains( "Enum" ) )
						return true;

					return false;
				};

				if ( is_enum( __class ) ) {
					__dumper_ctx.__enums.push_back( __class );
				}
	
			
				if ( !is_enum( __class ) ) {
					__dumper_ctx.__structs.push_back( __class );

					if ( !__namespaze.empty( ) ) {
						if ( __namespaze == __name )
							__config->__sdk << "class " << __namespaze << "{";
						else
							__config->__sdk << "namespace " << __namespaze << "{";
					}

					if ( __namespaze.empty( ) )
						__config->__sdk << "class __declspec( align( 8 ) ) " << __class->name << ";\n";
					else
						__config->__sdk << "class __declspec( align( 8 ) ) " << __class->name << ";";

					if ( !__namespaze.empty( ) )
						__config->__sdk << "}\n";
				}
			}
		}

		auto clean_type = [ ]( __il2cpp::c__type* __type ) -> std::string
		{
			if ( !__type )
				return {};

			std::string __name = __type->__name_get( );

			switch ( __type->type )
			{
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_VOID:
				return "void";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_BOOLEAN:
				return "bool";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_CHAR:
				return "std::uint16_t";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_I1:
				return "std::int8_t";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_U1:
				return "std::uint8_t";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_I2:
				return "std::int16_t";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_U2:
				return "std::uint16_t";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_I4:
				return "std::int32_t";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_U4:
				return "std::uint32_t";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_I8:
				return "std::int64_t";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_U8:
				return "std::uint64_t";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_R4:
				return "float";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_R8:
				return "double";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_STRING:
				return "::System::String*";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_TYPEDBYREF:
				return "void*";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_I:
				return "std::intptr_t";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_U:
				return "std::uintptr_t";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_OBJECT:
				return "void*";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_ARRAY:
				return "::System::Array*";
			case __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_SZARRAY:
				return "::System::Array*";
			}

			if ( __name.contains( "Collections.Generic.List" ) )
				return "::System::List*";

			if ( __name.contains( "System.Func" ) || __name.contains( "System.Action" ) )
				return "";

			__name = replace_all( __name, ".", "::" );

			if ( __type->type == __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_CLASS )
				__name.push_back( '*' );

			return std::string( "::" + __name );
		};

		for ( __il2cpp::c__class* __class : __dumper_ctx.__classes )
		{
			if ( !__class )
				continue;

			std::string __p_name = "";

			__il2cpp::c__class* __parent = __class->__parent_get( );
			if ( __parent )
			{
				std::string namespaze = __parent->namespaze;
				__p_name = !namespaze.empty( ) ? std::string( namespaze + "::" + __parent->name ) : __parent->name;
			}

			std::string namespaze = __class->namespaze;

			std::string __pp_name = !namespaze.empty( ) ? std::string( namespaze + "::" + __class->name ) : __class->name;

			if ( !__p_name.empty( ) )
				__config->__sdk << "class __declspec( align( 8 ) ) ::" << __pp_name << " : public ::" << __p_name << "\n";
			else
				__config->__sdk << "class __declspec( align( 8 ) ) ::" << __pp_name << "\n";

			__config->__sdk << "{ \n";

			__config->__sdk << "public: \n";

			auto __class_addr = std::uint64_t( __class ) - std::uintptr_t( dumper_data.second );

			__config->__sdk << "STATIC_CLASS( ""\"" << __class->namespaze << "\", " << "\"" << __class->name << "\");\n";

			std::vector< __il2cpp::c__field* > __static_fields;

			if ( __class->field_count > 0 )
			{
				void* iter = {};

				while ( std::add_const_t< __il2cpp::c__field* > __field = __class->__fields_get( &iter ) )
				{
					if ( !__field )
						continue;

					__il2cpp::c__type* __type = __field->__type_get( );
					if ( !__type )
						continue;

					if ( __type->attrs & FIELD_ATTRIBUTE_STATIC )
					{
						__static_fields.push_back( __field );
						continue;
					}

					std::string __name = clean_type( __type );
					if( __name.empty() )
						continue;

					__il2cpp::c__class* __f_class = __type->__class_get( );
					if ( !__f_class )
						continue;
					

					__config->__sdk << __name << " " << __field->name << ";\n";
				}
			}

			if ( !__static_fields.empty( ) )
			{
				__config->__sdk << "struct StaticFields\n";
				__config->__sdk << "{ \n";

				for ( __il2cpp::c__field* __static_field : __static_fields )
				{
					__il2cpp::c__type* __type = __static_field->__type_get( );
					if ( !__type )
						continue;

					std::string __name = clean_type( __type );
					if ( __name.empty( ) )
						continue;

					__config->__sdk << "StaticField( " << __name << ", " << __static_field->name << ", " << "\"" << __class->namespaze << "\", " << "\"" << __class->name << "\" ); \n";
				}

				__config->__sdk << "}; \n";
			}

			if ( __class->method_count > 0 )
			{
				void* iter = 0;
				while ( std::add_const_t< __il2cpp::c__method* > __method = __class->__methods_get( &iter ) )
				{
					if ( !__method )
						continue;

					__il2cpp::c__type* __type = __method->__type_get( );
					if ( !__type )
						continue;

					std::string __ret_type = clean_type( __type );
					if ( __ret_type.empty( ) )
						continue;

					if ( std::string( __method->name ).contains( "ctor" ) )
						continue;

					if ( !__method->methodPointer )
						continue;

					auto __rva = std::uint64_t( __method->methodPointer ) - std::uintptr_t( dumper_data.second );

					if ( __method->flags & METHOD_ATTRIBUTE_STATIC )
						__config->__sdk << "static ";

					__config->__sdk << __ret_type << " " << __method->name << "(";

					struct c__param {
						std::string __name;
						std::string __type;
					};

					std::vector< c__param > __saved_params;

					for ( std::size_t idx = {}; idx < __method->parameters_count; idx++ )
					{
						const __il2cpp::c__param_info& param = __method->parameters[ idx ];					
						__il2cpp::c__type* __type = param.parameter_type;

						std::string __param_type = clean_type( __type );
						if ( __param_type.empty( ) )
							continue;

						c__param __param;
						__param.__name = param.name;
						__param.__type = __param_type;
						__saved_params.emplace_back( __param );

						__config->__sdk << __param_type << " " << param.name;
						__config->__sdk << ", ";
					}

					if ( __method->parameters_count > 0 )
						__config->__sdk.seekp( -2, __config->__sdk.cur );

					__config->__sdk << ")\n";
					__config->__sdk << "{\n";

					__config->__sdk << "static auto " << __method->name << " = *reinterpret_cast< " << __ret_type << "( ** )( ";

					if ( __method->flags & METHOD_ATTRIBUTE_STATIC )
					{

					}
					else
					{
						if ( !__saved_params.empty( ) )
							__config->__sdk << "void*, ";
						else
							__config->__sdk << "void* ";
					}
						
					if ( !__saved_params.empty( ) )
					{
						for ( c__param __param : __saved_params )
						{
							if ( __param.__type.empty( ) || __param.__name.empty( ) )
								continue;
				
							__config->__sdk << __param.__type;
						
							__config->__sdk << ", ";
						}

						__config->__sdk.seekp( -2, __config->__sdk.cur );						
					}

					__config->__sdk << ")>( StaticClass()->Method( ""\"" << __method->name << "\"" << " ) );\n";

					__config->__sdk << "return " << __method->name << "( ";

					if ( __method->flags & METHOD_ATTRIBUTE_STATIC )
					{
					}
					else
					{
						__config->__sdk << "this,  ";
					}
				
					if ( !__saved_params.empty( ) )
					{
						for ( c__param __param : __saved_params )
						{
							if ( __param.__type.empty( ) || __param.__name.empty( ) )
								continue;

							__config->__sdk << __param.__name;

							__config->__sdk << ", ";
						}
					}
					else
					{
						__config->__sdk.seekp( -3, __config->__sdk.cur );
					}

					if ( __method->parameters_count > 0 )
						__config->__sdk.seekp( -2, __config->__sdk.cur );

					__config->__sdk << " );\n";

					__config->__sdk << "}\n";
				}
			}

			__config->__sdk << "}; \n";
		}


		for ( __il2cpp::c__class* __struct : __dumper_ctx.__structs )
		{
			if( !__struct )
				continue;

			std::string namespaze = __struct->namespaze;

			std::string __pp_name = !namespaze.empty( ) ? std::string( namespaze + "::" + __struct->name ) : __struct->name;

			__config->__sdk << "struct ::" << __pp_name;
			__config->__sdk << "{ \n";

			__config->__sdk << "STATIC_CLASS( ""\"" << __struct->namespaze << "\", " << "\"" << __struct->name << "\");\n";

			std::vector< __il2cpp::c__field* > __static_fields;

			if ( __struct->field_count > 0 )
			{
				void* iter = {};
				while ( std::add_const_t< __il2cpp::c__field* > __field = __struct->__fields_get( &iter ) )
				{
					if ( !__field )
						continue;

					__il2cpp::c__type* __type = __field->__type_get( );
					if ( !__type )
						continue;

					if ( __type->attrs & FIELD_ATTRIBUTE_STATIC )
					{
						__static_fields.push_back( __field );
						continue;
					}

					std::string __name = clean_type( __type );
					if ( __name.empty( ) )
						continue;

					__il2cpp::c__class* __f_class = __type->__class_get( );
					if ( !__f_class )
						continue;

					if ( __type->type == __il2cpp::c__type::e__type_enum::IL2CPP_TYPE_CLASS )
						__name.push_back( '*' );

					__config->__sdk << __name << " " << __field->name << ";\n";
				}
			}

			if ( !__static_fields.empty( ) )
			{
				__config->__sdk << "struct StaticFields\n";
				__config->__sdk << "{ \n";

				for ( __il2cpp::c__field* __static_field : __static_fields )
				{
					__il2cpp::c__type* __type = __static_field->__type_get( );
					if ( !__type )
						continue;

					std::string __name = clean_type( __type );
					if ( __name.empty( ) )
						continue;

					__config->__sdk << "StaticField( " << __name << ", " << __static_field->name << ", " << "\"" << __struct->namespaze << "\", " << "\"" << __struct->name << "\" ); \n";
				}

				__config->__sdk << "}; \n";
			}

			if ( __struct->method_count > 0 )
			{
				void* iter = 0;
				while ( std::add_const_t< __il2cpp::c__method* > __method = __struct->__methods_get( &iter ) )
				{
					if ( !__method )
						continue;

					__il2cpp::c__type* __type = __method->__type_get( );
					if ( !__type )
						continue;

					std::string __ret_type = clean_type( __type );
					if ( __ret_type.empty( ) )
						continue;

					if ( !__method->methodPointer )
						continue;

					auto __rva = std::uint64_t( __method->methodPointer ) - std::uintptr_t( dumper_data.second );

					if ( __method->flags & METHOD_ATTRIBUTE_STATIC )
						__config->__sdk << "static ";

					__config->__sdk << __ret_type << " " << __method->name << "(";

					struct c__param {
						std::string __name;
						std::string __type;
					};

					std::vector< c__param > __saved_params;

					int count = 0;

					for ( std::size_t idx = {}; idx < __method->parameters_count; idx++ )
					{
						const __il2cpp::c__param_info& param = __method->parameters[ idx ];
						__il2cpp::c__type* __type = param.parameter_type;

						std::string __param_type = clean_type( __type );
						if ( __param_type.empty( ) )
							continue;

						c__param __param;
						__param.__name = param.name;
						__param.__type = __param_type;
						__saved_params.emplace_back( __param );

						__config->__sdk << __param_type << " " << param.name;
						__config->__sdk << ", ";
					}

					if ( __method->parameters_count > 0 )
						__config->__sdk.seekp( -2, __config->__sdk.cur );

					__config->__sdk << ")\n";
					__config->__sdk << "{\n";

					__config->__sdk << "static auto " << __method->name << " = *reinterpret_cast<" << __ret_type << "( ** )( ";

					if ( __method->flags & METHOD_ATTRIBUTE_STATIC )
					{
					}
					else
					{
						if ( !__saved_params.empty( ) )
							__config->__sdk << "void*, ";
						else
							__config->__sdk << "void* ";
					}

					if ( !__saved_params.empty( ) )
					{
						for ( c__param __param : __saved_params )
						{
							if ( __param.__type.empty( ) || __param.__name.empty( ) )
								continue;

							__config->__sdk << __param.__type;

							__config->__sdk << ", ";
						}

						__config->__sdk.seekp( -2, __config->__sdk.cur );
					}

					__config->__sdk << ")>( StaticClass()->Method(" << "\"" << __method->name << "\" , " << std::to_string(count) << ");\n";

					__config->__sdk << "return " << __method->name << "(";

					if ( __method->flags & METHOD_ATTRIBUTE_STATIC )
					{
					}
					else
						__config->__sdk << "this, ";

					if ( !__saved_params.empty( ) )
					{
						for ( c__param __param : __saved_params )
						{
							if ( __param.__type.empty( ) || __param.__name.empty( ) )
								continue;

							__config->__sdk << __param.__name;

							__config->__sdk << ", ";
						}
					}
					else
					{
						__config->__sdk.seekp( -3, __config->__sdk.cur );
					}

					if ( __method->parameters_count > 0 )
						__config->__sdk.seekp( -2, __config->__sdk.cur );

					__config->__sdk << ");\n";


					__config->__sdk << "}\n";
				}
			}


			__config->__sdk << "}; \n";
		}

		for ( __il2cpp::c__class* __enum : __dumper_ctx.__enums )
		{
			if( !__enum )
				continue;

			__config->__sdk << "enum class ::" << __enum->name;
			__config->__sdk << "{ \n";

			void* iter = {};
			while ( std::add_const_t< __il2cpp::c__field* > __field = __enum->__fields_get( &iter ) )
			{
				if( !__field )
					continue;

				__config->__sdk << __field->name << " = 0x" << std::hex << ( uintptr_t )__field->token << ",\n";
			}

			__config->__sdk << "}; \n";
		}

		return {};
	}

	template< typename BitSize >
	inline std::add_cv_t< std::atomic< __status > > __process( [[ unused ]] BitSize __bit_size )
	{
		__cfg cfg 
		{
			.__method_cfg = std::make_shared<__cfg::__cfg_method>( ),
			.__field_cfg = std::make_shared<__cfg::__cfg_field>( ),
			.__sdk = std::ofstream( "" ), //put ur output path here 
		};

		[[unlikely]]
		if ( !cfg.__field_cfg || !cfg.__method_cfg )
			return __status::error;

		cfg.__field_cfg->use_alignment = false;
		cfg.__field_cfg->use_pads = false;
		cfg.__field_cfg->use_field_getter = true;
		cfg.__field_cfg->prefix = "c_";

		cfg.__method_cfg->use_rva = false;
		cfg.__method_cfg->use_method_getter = true;

		dumper_data = std::make_pair( &cfg, std::size_t( __bit_size ) );

		__dump( );

		return __status::success;
	}


}
