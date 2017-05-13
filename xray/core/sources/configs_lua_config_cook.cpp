////////////////////////////////////////////////////////////////////////////
//	Created		: 02.04.2009
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "configs_lua_config_cook.h"

namespace xray {
namespace core {
namespace configs {

extern memory::doug_lea_allocator_type	g_lua_allocator;

mutable_buffer   lua_config_cook::allocate_resource	(resources::query_result_for_cook &	in_query, 
													 const_buffer						raw_file_data, 
													 bool								file_exist)
{
	XRAY_UNREFERENCED_PARAMETERS			(& in_query, & raw_file_data, & file_exist);

	void* buffer;

	core::configs::g_lua_allocator.user_current_thread_id();
	buffer = XRAY_MALLOC_IMPL(xray::core::configs::g_lua_allocator,sizeof(xray::configs::lua_config),"lua");

	return									mutable_buffer (buffer, 
															sizeof(xray::configs::lua_config));
}

void   lua_config_cook::destroy_resource	(resources::unmanaged_resource * resource)
{
	xray::configs::lua_config* cfg = static_cast_checked<xray::configs::lua_config*>(resource);
	cfg->~lua_config();
}

void   lua_config_cook::deallocate_resource	(pvoid buffer)
{
	core::configs::g_lua_allocator.user_current_thread_id();
	XRAY_FREE_IMPL(xray::core::configs::g_lua_allocator, buffer);
}

void   lua_config_cook::create_resource (resources::query_result_for_cook &	in_out_query, 
											 						  const_buffer							raw_file_data,
											 						  mutable_buffer						in_out_unmanaged_resource_buffer)
{
//	xray::memory::reader reader		((u8 const*)raw_file_data.c_ptr(), raw_file_data.size());

	pstr path						= 0;	
	STR_DUPLICATEA					( path, in_out_query.get_requested_path() );	
	pstr const found				= strrchr( path, '.');	
	if ( found )		
		*found						= 0;	
	char const resources_string[]	= "resources/";	
	if ( strings::starts_with(path, resources_string) )		
		path						+= sizeof(resources_string) - 1;

	cJSON* cfg = cJSON_Parse((char*)raw_file_data.c_ptr());

	if(!cfg)
	{
		const char *js = (char*)raw_file_data.c_ptr(), *err = cJSON_GetErrorPtr();
		u32 line = 1;

		for(; js < err; js++)
			if(*js == '\n') line++;

		LOG_ERROR("JSON '%s' parsing failed. Error at line %d",path,line);

		cfg = cJSON_CreateObject(); //avoid access violation error
	}
#if !XRAY_USE_CRT_MEMORY_ALLOCATOR
	xray::core::configs::g_lua_allocator.user_current_thread_id();
#endif
	xray::configs::lua_config * const out_config = new (in_out_unmanaged_resource_buffer.c_ptr()) xray::configs::lua_config(path,cfg);
	//create_lua_config_inplace( in_out_unmanaged_resource_buffer, path, reader);

	in_out_query.set_unmanaged_resource	( out_config, 
										 resources::memory_type_non_cacheable_resource, 
										 in_out_unmanaged_resource_buffer.size());

	in_out_query.finish_query		(result_success);
}

} // namespace configs
} // namespace core
} // namespace xray