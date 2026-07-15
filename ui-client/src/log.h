// OpenTransferClient (OTC) - log.h
// Version: 0.0.1-dev - NDVX - 2026

#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <SDL3/SDL.h>

class Log
{
	public:
		class endl_t{};
		constexpr static endl_t endl{};
		class logpoint
		{
			public:
				constexpr static std::string_view m_app = "OpenTransferClient";
				const std::string m_worker;
				std::string m_step;
				logpoint(const logpoint& p_other) : m_worker(p_other.m_worker), m_step(p_other.m_step){}
				logpoint(const logpoint& p_other, const std::string& p_step) : m_worker(p_other.m_worker), m_step(p_step) {}
				logpoint(const std::string& p_worker) : m_worker(p_worker){}
				logpoint(const std::string& p_worker, const std::string& p_step) : m_worker(p_worker), m_step(p_step){}
		};
	private:
		std::vector<std::ostream*> m_streams{&std::cout};
	public:
		void addstream(std::ostream& p_stream)
		{
			m_streams.push_back(&p_stream);
		}
		void setstreams(const std::vector<std::ostream*>& p_streams)
		{
			m_streams = p_streams;
		}
		template<typename T> Log& operator<<(const T& p_data)
		{
			for(auto& stream : m_streams)
			{
				*stream << p_data;
			}
			return *this;
		}
		Log& operator<<(logpoint m_logpoint)
		{
			for(auto& stream : m_streams)
			{
				*stream << ">" << m_logpoint.m_app << "[" << m_logpoint.m_worker << "/" << m_logpoint.m_step << "] ";
			}
			return *this;
		}
		Log& operator<<(endl_t)
		{
			for (auto& stream : m_streams)
			{
				*stream << std::endl;
			}
			return *this;
		}
};

#endif // LOG_H