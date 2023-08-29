

#include <boost/log/expressions.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/utility/setup.hpp>
#include <fstream>
#include <ostream>
#include <boost/log/common.hpp>
#include <boost/log/core.hpp>



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
    src::severity_channel_logger_mt<boost::log::trivial::severity_level>logger;
    
    //add attributes
   logger.add_attribute("lineID", attrs::counter<unsigned int>(1));
   logger.add_attribute("TimeStamp", attrs::local_clock());

    //add a text sink
    typedef sinks::synchronous_sink<sinks::text_ostream_backend> text_sink;
    boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();

    //add a logfile stream 
    sink->locked_backend()->add_stream(boost::make_shared<std::ofstream>(LOGFILE));

    //add "console" output stream
    sink->locked_backend()->add_stream(boost::shared_ptr<std::ostream>(&std::clog, boost::null_deleter()));

    //specify the format of the log message
    logging::formatter formatter = expr::stream
    <<std::setw(7)<<std::setfill('0')<<line_id<<std::setfill(' ')<<"|"<<expr::format_date_time(timestamp, "%Y-$m-%d, %H:%M:%S,%f")<<" "<<"["<<logging::trivial::severity<<"]"<<"-"<<expr::smessage;
    sink->set_formatter(formatter);



    //only messages with severity >= severity thresold
    sink->set_filter(severity>=SEVERITY_THRESHOLD);


    //register our sink
    logging::core::get()->add_sink(sink);
   
   
   
    return logger;

}



