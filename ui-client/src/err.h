// OpenTransferClient (OTC) - err.h
// Version: 0.0.1-dev - NDVX - 2026

#ifndef ERR_H
#define ERR_H

namespace err
{
	class code
	{
		private:
			const unsigned short m_code;
		public:
			explicit constexpr code(unsigned short c) : m_code(c) {}
			explicit constexpr operator unsigned short() const { return m_code; }
	};
	constexpr code sdl_init_failed(1);
	constexpr code sdl_window_creation_failed(2);
	constexpr code axis_out_of_range(3);
}

#endif // ERR_H