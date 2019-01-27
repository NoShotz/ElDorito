#include "Script.hpp"

#include "../ElDorito.hpp"
#include "../Patch.hpp"
#include "../Modules/ModuleSettings.hpp"
#include "../Scripting/hs_function_definition.h"
#include "../Scripting/hs_function_index.h"

#define MS23_SCRIPT_OP_COUNT 1697

#define address(addr) (addr - 0x400000)
#define _address_to_bytes(addr) (unsigned char)(addr & 0xFF), (unsigned char)(addr >> 8 & 0xFF), (unsigned char)(addr >> 16 & 0xFF), (unsigned char)(addr >> 24 & 0xFF)
#define address_to_bytes(addr) _address_to_bytes((unsigned int)addr)

typedef int(__cdecl *hs_evaluate_arguments_internal_func)(int a1, __int16 a2, int a3, char a4);
hs_evaluate_arguments_internal_func hs_evaluate_arguments_internal;

//std::vector<hs_function_definition*> custom_hs_function_definitions;

hs_function_definition* custom_hs_function_definitions[0xFFFFu];
hs_function_definition my_custom_op;
hs_script_op_callback sleep_evaluate;

/*
* Overrides the existing hs_evaluate_arguments function with
* the custom_hs_function_definitions array
*/
int __cdecl hs_evaluate_arguments(__int16 opcode, int a2, char a3)
{
	return hs_evaluate_arguments_internal(
		a2,
		custom_hs_function_definitions[opcode]->unknown2,
		(int)&custom_hs_function_definitions[opcode]->unknown2 + 2,
		a3);
}

/*
* Custom opcode
*/
__int16 __cdecl custom_op_callback(int a, int b, char c)
{
	printf("My custom script option was called\n");
	return sleep_evaluate(a, b, c);
	return 0;
}

namespace Patches::Script
{
	void CopyExistingOpcodes()
	{
		hs_function_definition** ptr = (hs_function_definition**)Pointer::Base(address(0x18ED378));
		
		// copy existing ops
		//custom_hs_function_definitions = std::vector<hs_function_definition*>(ptr, ptr + MS23_SCRIPT_OP_COUNT);
		memset(custom_hs_function_definitions, 0, sizeof(custom_hs_function_definitions));
		memcpy(custom_hs_function_definitions, ptr, sizeof(ptr[0]) * MS23_SCRIPT_OP_COUNT);

		// reserve enough room for all ops
		//custom_hs_function_definitions.resize(0xFFFFu);

		// null out existing ops, if we crash its cause we haven't overridden properly
		memset(ptr, 0, sizeof(hs_function_definition**) * 1697);
	}

	/*
	 * Overrides the opcode access with the Eldorito overrides
	 */
	void OverrideOpcodeAccess()
	{
		hs_evaluate_arguments_internal = (hs_evaluate_arguments_internal_func)Pointer::Base(address(0x594140));
		Hook(address(0x5972F0), hs_evaluate_arguments).Apply();

		auto _testing0 = (void*)Pointer::Base(address(0x597537));
		auto _testing1 = (void*)Pointer::Base(address(0x598CEE));

		hs_function_definition** new_ptr = custom_hs_function_definitions;
		Patch(address(0x597537), { 0x8B, 0x04, 0x85, address_to_bytes((unsigned int)new_ptr) }).Apply();
		Patch(address(0x598CEE), { 0x8B, 0x04, 0x85, address_to_bytes((unsigned int)new_ptr) }).Apply();
	}

	/*
	 * This is a custom opcode that runs the sleep function
	 * but prints a message each time the function is hit
	 */
	void SetupCustomOpcode()
	{
		sleep_evaluate = (hs_script_op_callback)Pointer::Base(address(0x00595a00));

		my_custom_op.return_type = hs_value_type::k_hs_value_type_void;
		my_custom_op.unknown1 = 2;
		my_custom_op.callback = custom_op_callback;
		my_custom_op.usage = 0;
		my_custom_op.unknown2 = 0;
		my_custom_op.parameters[0] = hs_value_type::k_hs_value_type_boolean;
		my_custom_op.parameters[0] = hs_value_type::k_hs_value_type_unparsed;

		//custom_hs_function_definitions[1697] = &my_custom_op; // add a new opcode to index 1697
		custom_hs_function_definitions[hs_function_index::k_hs_eldewrito_custom_test_function] = &my_custom_op; // add a new opcode to index 5000
		//custom_hs_function_definitions[20] = &my_custom_op; // override existing opcode
	}

	void ApplyAll()
	{
		CopyExistingOpcodes();
		OverrideOpcodeAccess();
		SetupCustomOpcode();


		// test: hook a frame logging function
		//Hook(0x106FB0, sub_506FB0).Apply();
	}
}