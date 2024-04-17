#pragma once

#include <cmath>

namespace Engine::ByteLiterals
{
	constexpr std::size_t operator""_KiB(uint64_t x) {
		return 1024ULL * x;
	}

	constexpr std::size_t operator""_MiB(uint64_t x) {
		return 1024_KiB * x;
	}

	constexpr std::size_t operator""_GiB(uint64_t x) {
		return 1024_MiB * x;
	}

	constexpr std::size_t operator""_TiB(uint64_t x) {
		return 1024_GiB * x;
	}

	constexpr std::size_t operator""_PiB(uint64_t x) {
		return 1024_TiB * x;
	}
}