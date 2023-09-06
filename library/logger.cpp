
#include <boost/log/expressions.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/utility/setup.hpp>
#include <fstream>
#include <ostream>
#include <boost/log/common.hpp>
#include <boost/log/core.hpp>


// Define the path to the log file

#include "../include/logger.h"

namespace logging = boost::log;



namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;
namespace attrs=boost::log::attributes;


BOOST_LOG_ATTRIBUTE_KEYWORD(line_id, "lineID", unsigned int)
BOOST_LOG_ATTRIBUTE_KEYWORD(timestamp, "timeStamp",boost::posix_time::ptime)
BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "severity",logging::trivial::severity_level)



BOOST_LOG_GLOBAL_LOGGER_INIT(logger, src::severity){

    src::severity_channel_logger_mt<boost::log::trivial::severity_level> logger;

    // Add attributes
    logger.add_attribute("lineID", attrs::counter<unsigned int>(1));
    logger.add_attribute("TimeStamp", attrs::local_clock());

    // Add a text sink
    typedef sinks::synchronous_sink<sinks::text_ostream_backend> text_sink;
    boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
    
    sink->locked_backend()->add_stream(boost::make_shared<std::ofstream>("example.txt"));
    
 
    // Add "console" output stream
    sink->locked_backend()->add_stream(boost::shared_ptr<std::ostream>(&std::clog, boost::null_deleter()));

    // Specify the format of the log message
    logging::formatter formatter = expr::stream
        << std::setw(7) << std::setfill('0') << line_id << std::setfill(' ') << "|"
        << expr::format_date_time(timestamp, "%Y-$m-%d, %H:%M:%S,%f") << " ["
        << logging::trivial::severity << "] - " << expr::smessage;
    sink->set_formatter(formatter);

    // Only messages with severity >= severity threshold
 //   sink->set_filter(severity >= SEVERITY_THRESHOLD);

    // Register our sink
    logging::core::get()->add_sink(sink);

    return logger;
   
}



