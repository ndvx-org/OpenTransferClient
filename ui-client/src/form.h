// OpenTransferClient (OTC) - form.h
// Version: 0.0.1-dev - NDVX - 2026

#include <array>
#include <initializer_list>
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include "err.h"

#ifndef FORM_H
#define FORM_H

template<typename p_t, size_t axis_c> class point
{
public:
	using position_t = p_t;
	constexpr static size_t axis_count = axis_c;
	using self_t = point<position_t, axis_count>;
	using data_t = std::array<position_t, axis_count>;

private:
	data_t m_pos{};

	static_assert(axis_count >= 0, "axis_count must be non-negative");

public:
	point() = default;
	point(const self_t& other) : m_pos(other.m_pos) {}
	point(self_t&& other) noexcept : m_pos(std::move(other.m_pos)) {}
	explicit point(const data_t& pos) : m_pos(pos) {}
	point(std::initializer_list<position_t> pos)
	{
		if(pos.size() != axis_count)
			throw err::axis_out_of_range;
		std::copy(pos.begin(), pos.end(), m_pos.begin());
	}

	explicit operator data_t(void) const
	{
			return m_pos;
	}
		
	position_t& operator[](size_t p_axis)
	{
		if(p_axis >= axis_count)
			throw err::axis_out_of_range;
		return m_pos[p_axis];
	}
	const position_t& operator[](size_t p_axis) const
	{
		if(p_axis >= axis_count)
			throw err::axis_out_of_range;
		return m_pos[p_axis];
	}
	template <size_t p_axis> position_t& operator()(void)
	{
		if constexpr(p_axis >= axis_count)
			throw err::axis_out_of_range;
		return m_pos[p_axis];
	}

	self_t& operator=(const data_t& p_pos)
	{
		m_pos = p_pos;
		return *this;
	}
	self_t& operator=(std::initializer_list<position_t> p_pos)
	{
		if (p_pos.size() != axis_count)
			throw err::axis_out_of_range;
		std::copy(p_pos.begin(), p_pos.end(), m_pos.begin());
		return *this;
	}
	self_t& operator=(const self_t& p_other)
	{
		m_pos = p_other.m_pos;
		return *this;
	}
	self_t& operator=(self_t&& p_other) noexcept
	{
		m_pos = std::move(p_other.m_pos);
		return *this;
	}

	bool operator==(const self_t& p_other) const
	{
		return m_pos == p_other.m_pos;
	}
	bool operator!=(const self_t& p_other) const
	{
		return !(*this == p_other);
	}

	self_t operator+(const self_t& p_other) const
	{
		self_t result;
		for (size_t i = 0; i < axis_count; ++i)
			result[i] = m_pos[i] + p_other[i];
		return result;
	}
	self_t operator-(const self_t& p_other) const
	{
		self_t result;
		for (size_t i = 0; i < axis_count; ++i)
			result[i] = m_pos[i] - p_other[i];
		return result;
	}
	self_t operator*(const self_t& p_other) const
	{
		self_t result;
		for (size_t i = 0; i < axis_count; ++i)
			result[i] = m_pos[i] * p_other[i];
		return result;
	}
	self_t operator/(const self_t& p_other) const
	{
		self_t result;
		for (size_t i = 0; i < axis_count; ++i)
			result[i] = m_pos[i] / p_other[i];
		return result;
	}
	self_t operator%(const self_t& p_other) const
	{
		self_t result;
		for (size_t i = 0; i < axis_count; ++i)
			result[i] = m_pos[i] % p_other[i];
		return result;
	}

	self_t operator+(const position_t& p_scalar) const
	{
		self_t result;
		for (size_t i = 0; i < axis_count; ++i)
			result[i] = m_pos[i] + p_scalar;
		return result;
	}
	self_t operator-(const position_t& p_scalar) const
	{
		self_t result;
		for (size_t i = 0; i < axis_count; ++i)
			result[i] = m_pos[i] - p_scalar;
		return result;
	}
	self_t operator*(const position_t& p_scalar) const
	{
		self_t result;
		for (size_t i = 0; i < axis_count; ++i)
			result[i] = m_pos[i] * p_scalar;
		return result;
	}
	self_t operator/(const position_t& p_scalar) const
	{
		self_t result;
		for (size_t i = 0; i < axis_count; ++i)
			result[i] = m_pos[i] / p_scalar;
		return result;
	}
	self_t operator%(const position_t& p_scalar) const
	{
		self_t result;
		for (size_t i = 0; i < axis_count; ++i)
			result[i] = m_pos[i] % p_scalar;
		return result;
	}

	self_t& operator+=(const self_t& p_other)
	{
		for (size_t i = 0; i < axis_count; ++i)
			m_pos[i] += p_other[i];
		return *this;
	}
	self_t& operator-=(const self_t& p_other)
	{
		for (size_t i = 0; i < axis_count; ++i)
			m_pos[i] -= p_other[i];
		return *this;
	}
	self_t& operator*=(const self_t& p_other)
	{
		for (size_t i = 0; i < axis_count; ++i)
			m_pos[i] *= p_other[i];
		return *this;
	}
	self_t& operator/=(const self_t& p_other)
	{
		for (size_t i = 0; i < axis_count; ++i)
			m_pos[i] /= p_other[i];
		return *this;
	}
	self_t& operator%=(const self_t& p_other)
	{
		for (size_t i = 0; i < axis_count; ++i)
			m_pos[i] %= p_other[i];
		return *this;
	}

	self_t& operator+=(const position_t& p_scalar)
	{
		for (size_t i = 0; i < axis_count; ++i)
			m_pos[i] += p_scalar;
		return *this;
	}
	self_t& operator-=(const position_t& p_scalar)
	{
		for (size_t i = 0; i < axis_count; ++i)
			m_pos[i] -= p_scalar;
		return *this;
	}
	self_t& operator*=(const position_t& p_scalar)
	{
		for (size_t i = 0; i < axis_count; ++i)
			m_pos[i] *= p_scalar;
		return *this;
	}
	self_t& operator/=(const position_t& p_scalar)
	{
		for (size_t i = 0; i < axis_count; ++i)
			m_pos[i] /= p_scalar;
		return *this;
	}
	self_t& operator%=(const position_t& p_scalar)
	{
		for (size_t i = 0; i < axis_count; ++i)
			m_pos[i] %= p_scalar;
		return *this;
	}

	self_t& operator++(void)
	{
		for (size_t i = 0; i < axis_count; ++i)
			++m_pos[i];
		return *this;
	}
	self_t& operator--(void)
	{
		for (size_t i = 0; i < axis_count; ++i)
			--m_pos[i];
		return *this;
	}
	
	self_t operator++(int)
	{
		self_t result(*this);
		++(*this);
		return result;
	}
	self_t operator--(int)
	{
		self_t result(*this);
		--(*this);
		return result;
	}
};

namespace d0
{
	class point : public ::point<int64_t, 0>
	{
		public:
			using self_t::point;
			point(const self_t& p_other) : self_t(p_other) {}
			point(self_t&& p_other) noexcept : self_t(std::move(p_other)) {}
	};
}

namespace d1
{
	class point : public ::point<int64_t, 1>
	{
		public:
			using self_t::point;
			point(const self_t& p_other) : self_t(p_other) {}
			point(self_t&& p_other) noexcept : self_t(std::move(p_other)) {}
			position_t& x()
			{
				return (*this)[0];
			}
			const position_t& x() const
			{
				return (*this)[0];
			}
	};
}

namespace d2
{
	class point : public ::point<int64_t, 2>
	{
	public:
		using self_t::point;
		point(const self_t& p_other) : self_t(p_other) {}
		point(self_t&& p_other) noexcept : self_t(std::move(p_other)) {}
		position_t& x()
		{
			return (*this)[0];
		}
		const position_t& x() const
		{
			return (*this)[0];
		}
		position_t& y()
		{
			return (*this)[1];
		}
		const position_t& y() const
		{
			return (*this)[1];
		}
	};
}

namespace d3
{
	class point : public ::point<int64_t, 3>
	{
	public:
		using self_t::point;
		point(const self_t& p_other) : self_t(p_other) {}
		point(self_t&& p_other) noexcept : self_t(std::move(p_other)) {}
		position_t& x()
		{
			return (*this)[0];
		}
		const position_t& x() const
		{
			return (*this)[0];
		}
		position_t& y()
		{
			return (*this)[1];
		}
		const position_t& y() const
		{
			return (*this)[1];
		}
		position_t& z()
		{
			return (*this)[2];
		}
		const position_t& z() const
		{
			return (*this)[2];
		}
	};
}

#endif // FORM_H