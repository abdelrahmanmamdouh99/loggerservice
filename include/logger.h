#ifndef logger_h_
#define logger_h_

#define BOOST_LOG_DYN_LINK //library when linking the boost_log library dynamically


#include <boost/log/trivial.hpp>
#include <boost/log/sources/global_logger_storage.hpp>


#include <boost/log/sources/severity_channel_logger.hpp>




#define LOGFILE "logfile.txt"

//just log messages with severity >=severity _threthold
#define SEVERITY_THRESHOLD logging::trivial::warning


BOOST_LOG_GLOBAL_LOGGER(logger, boost::log::sources::severity_channel_logger_mt<boost::log::trivial::severity_level>)



#define LOG_TRACE   BOOST_LOG_TRIVIAL(trace)
#define LOG_DEBUG   BOOST_LOG_TRIVIAL(debug)
#define LOG_INFO    BOOST_LOG_TRIVIAL(info)
#define LOG_WARNING BOOST_LOG_TRIVIAL(warning)
#define LOG_ERROR   BOOST_LOG_TRIVIAL(error)
#define LOG_FATAL   BOOST_LOG_TRIVIAL(fatal)



#endif