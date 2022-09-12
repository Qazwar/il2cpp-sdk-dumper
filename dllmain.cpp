
#include "dumper.h"

std::int32_t DllMain( 
	void* h_mod, 
	std::uint32_t call_reason, 
	[[maybe_unused]] void* reserved
) {
	if ( call_reason != DLL_PROCESS_ATTACH )
		return false;

	Dumper::__process(
		std::size_t(
			GetModuleHandleA( "GameAssembly.dll"
			)
		)
	);

	return true;
}