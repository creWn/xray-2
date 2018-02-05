#pragma once
namespace logging {
	enum verbosity {
		silent = 1 << 0,
		error = 1 << 1,
		warning = 1 << 2,
		info = 1 << 3,
		debug = 1 << 4,
		trace = 1 << 5,
		unset = 1 << 31,
	}; // enum verbosity
}