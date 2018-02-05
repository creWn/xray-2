////////////////////////////////////////////////////////////////////////////
//	Created		: 18.02.2009
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include <xray/math_aabb_plane.h>

using xray::math::aabb_plane;
using xray::math::intersection;
using xray::math::aabb;

static unsigned const min_x	= 0;
static unsigned const min_y	= 1;
static unsigned const min_z	= 2;
static unsigned const max_x	= 3;
static unsigned const max_y	= 4;
static unsigned const max_z	= 5;
static unsigned const aabb_lut[8][6]	= {
	{ max_x, max_y, max_z, min_x, min_y, min_z}, 
	{ max_x, max_y, min_z, min_x, min_y, max_z}, 
	{ max_x, min_y, max_z, min_x, max_y, min_z}, 
	{ max_x, min_y, min_z, min_x, max_y, max_z}, 
	{ min_x, max_y, max_z, max_x, min_y, min_z}, 
	{ min_x, max_y, min_z, max_x, min_y, max_z}, 
	{ min_x, min_y, max_z, max_x, max_y, min_z}, 
	{ min_x, min_y, min_z, max_x, max_y, max_z}
};

void aabb_plane::normalize		( )
{
	plane.vector		*= 1.f / plane.normal.magnitude( );
	
	unsigned					x = (*(unsigned*)&plane.normal.x >> 31) << 2;
	unsigned					y = (*(unsigned*)&plane.normal.y >> 31) << 1;
	unsigned					z = (*(unsigned*)&plane.normal.z >> 31);

	m_lut_id			= x | y | z;
}

intersection aabb_plane::test	( aabb const& aabb ) const
{
	typedef unsigned			lut_ids_type[6];
	lut_ids_type const&	ids = aabb_lut[m_lut_id];

	typedef float		values_type[6];
	values_type const&	values = (values_type const&)aabb.min.x;

	// test negative first
	if ( plane.classify( float3( values[ ids[3] ], values[ ids[4] ], values[ ids[5] ] ) ) > 0.f )
		return			(intersection_outside);

	// test positive
	if ( plane.classify( float3( values[ ids[0] ], values[ ids[1] ], values[ ids[2] ] ) ) <= 0.f )
		return			(intersection_inside);

	return				(intersection_intersect);
}