////////////////////////////////////////////////////////////////////////////
//	Created		: 06.05.2010
//	Author		: Sergey Chechin
//	Copyright (C) GSC Game World - 2010
////////////////////////////////////////////////////////////////////////////

#ifndef FS_HELPER_H_INCLUDED
#define FS_HELPER_H_INCLUDED

namespace xray {
namespace fs {

template <class Ordinal>
void			reverse_bytes	(Ordinal& res);

// @post: position in files are changed
bool			files_equal		(FILE* f1, FILE* f2, unsigned size);
// @post: position in files are changed
void			copy_data		(FILE* f_dest, FILE* f_src, unsigned size, unsigned* hash = NULL);


unsigned				path_crc32		(pcstr const data, unsigned const size, unsigned const start_value = 0);
unsigned				crc32			(pcstr const data, unsigned const size, unsigned const start_value = 0);
bool			file_exists		(pcstr path);

} // namespace fs
} // namespace xray 

#include "fs_helper_inline.h"

#endif // FS_HELPER_H_INCLUDED

