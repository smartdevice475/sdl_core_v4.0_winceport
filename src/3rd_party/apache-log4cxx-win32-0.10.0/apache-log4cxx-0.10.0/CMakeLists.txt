
add_definitions(-DLOG4CXX_STATIC)
add_definitions(-DAPR_DECLARE_STATIC)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  add_definitions(-DHAVE_STRING_H)
 # add_definitions(-D_WINDOWS_)
endif()

include_directories (
../
  ./
  ./src/main/include
  ../apr/include/
  ../apr-util/xml/expat/lib
)


set (LOG4CXX_SOURCES
   src/main/cpp/action.cpp
src/main/cpp/zipcompressaction.cpp
src/main/cpp/xmlsocketappender.cpp
src/main/cpp/xmllayout.cpp
src/main/cpp/writerappender.cpp
src/main/cpp/writer.cpp
src/main/cpp/ttcclayout.cpp
src/main/cpp/triggeringpolicy.cpp
src/main/cpp/transform.cpp
src/main/cpp/transcoder.cpp
src/main/cpp/timezone.cpp
src/main/cpp/timebasedrollingpolicy.cpp
src/main/cpp/throwableinformationpatternconverter.cpp
src/main/cpp/threadspecificdata.cpp
src/main/cpp/threadpatternconverter.cpp
src/main/cpp/threadlocal.cpp
src/main/cpp/threadcxx.cpp
src/main/cpp/telnetappender.cpp
src/main/cpp/systemoutwriter.cpp
src/main/cpp/systemerrwriter.cpp
src/main/cpp/system.cpp
src/main/cpp/syslogwriter.cpp
src/main/cpp/syslogappender.cpp
src/main/cpp/synchronized.cpp
src/main/cpp/stringtokenizer.cpp
src/main/cpp/stringmatchfilter.cpp
src/main/cpp/stringhelper.cpp
src/main/cpp/strftimedateformat.cpp
src/main/cpp/socketoutputstream.cpp
src/main/cpp/sockethubappender.cpp
src/main/cpp/socketappenderskeleton.cpp
src/main/cpp/socketappender.cpp
src/main/cpp/socket.cpp
src/main/cpp/smtpappender.cpp
src/main/cpp/sizebasedtriggeringpolicy.cpp
src/main/cpp/simplelayout.cpp
src/main/cpp/simpledateformat.cpp
src/main/cpp/serversocket.cpp
src/main/cpp/rootlogger.cpp
src/main/cpp/rolloverdescription.cpp
src/main/cpp/rollingpolicybase.cpp
src/main/cpp/rollingpolicy.cpp
src/main/cpp/rollingfileappender.cpp
src/main/cpp/resourcebundle.cpp
src/main/cpp/relativetimepatternconverter.cpp
src/main/cpp/relativetimedateformat.cpp
src/main/cpp/reader.cpp
src/main/cpp/propertysetter.cpp
src/main/cpp/propertyresourcebundle.cpp
src/main/cpp/propertyconfigurator.cpp
src/main/cpp/propertiespatternconverter.cpp
src/main/cpp/properties.cpp
src/main/cpp/pool.cpp
src/main/cpp/patternparser.cpp
src/main/cpp/patternlayout.cpp
src/main/cpp/patternconverter.cpp
src/main/cpp/outputstreamwriter.cpp
src/main/cpp/outputstream.cpp
src/main/cpp/outputdebugstringappender.cpp
src/main/cpp/optionconverter.cpp
src/main/cpp/onlyonceerrorhandler.cpp
src/main/cpp/odbcappender.cpp
src/main/cpp/obsoleterollingfileappender.cpp
src/main/cpp/objectptr.cpp
src/main/cpp/objectoutputstream.cpp
src/main/cpp/objectimpl.cpp
src/main/cpp/nteventlogappender.cpp
src/main/cpp/ndcpatternconverter.cpp
src/main/cpp/ndc.cpp
src/main/cpp/namepatternconverter.cpp
src/main/cpp/nameabbreviator.cpp
src/main/cpp/mutex.cpp
src/main/cpp/methodlocationpatternconverter.cpp
src/main/cpp/messagepatternconverter.cpp
src/main/cpp/messagebuffer.cpp
src/main/cpp/mdc.cpp
src/main/cpp/manualtriggeringpolicy.cpp
src/main/cpp/logstream.cpp
src/main/cpp/logmanager.cpp
src/main/cpp/loglog.cpp
src/main/cpp/loggingeventpatternconverter.cpp
src/main/cpp/loggingevent.cpp
src/main/cpp/loggerpatternconverter.cpp
src/main/cpp/logger.cpp
src/main/cpp/locationinfo.cpp
src/main/cpp/locale.cpp
src/main/cpp/loader.cpp
src/main/cpp/literalpatternconverter.cpp
src/main/cpp/lineseparatorpatternconverter.cpp
src/main/cpp/linelocationpatternconverter.cpp
src/main/cpp/levelrangefilter.cpp
src/main/cpp/levelpatternconverter.cpp
src/main/cpp/levelmatchfilter.cpp
src/main/cpp/level.cpp
src/main/cpp/layout.cpp
src/main/cpp/integerpatternconverter.cpp
src/main/cpp/integer.cpp
src/main/cpp/inputstreamreader.cpp
src/main/cpp/inputstream.cpp
src/main/cpp/inetaddress.cpp
src/main/cpp/htmllayout.cpp
src/main/cpp/hierarchy.cpp
src/main/cpp/gzcompressaction.cpp
src/main/cpp/fulllocationpatternconverter.cpp
src/main/cpp/formattinginfo.cpp
src/main/cpp/fixedwindowrollingpolicy.cpp
src/main/cpp/filterbasedtriggeringpolicy.cpp
src/main/cpp/filter.cpp
src/main/cpp/filewatchdog.cpp
src/main/cpp/filerenameaction.cpp
src/main/cpp/fileoutputstream.cpp
src/main/cpp/filelocationpatternconverter.cpp
src/main/cpp/fileinputstream.cpp
src/main/cpp/filedatepatternconverter.cpp
src/main/cpp/fileappender.cpp
src/main/cpp/file.cpp
src/main/cpp/fallbackerrorhandler.cpp
src/main/cpp/exception.cpp
src/main/cpp/domconfigurator.cpp
src/main/cpp/defaultrepositoryselector.cpp
src/main/cpp/defaultloggerfactory.cpp
src/main/cpp/defaultconfigurator.cpp
src/main/cpp/datepatternconverter.cpp
src/main/cpp/datelayout.cpp
src/main/cpp/dateformat.cpp
src/main/cpp/date.cpp
src/main/cpp/datagramsocket.cpp
src/main/cpp/datagrampacket.cpp
src/main/cpp/dailyrollingfileappender.cpp
src/main/cpp/cyclicbuffer.cpp
src/main/cpp/consoleappender.cpp
src/main/cpp/configurator.cpp
src/main/cpp/condition.cpp
src/main/cpp/classregistration.cpp
src/main/cpp/classnamepatternconverter.cpp
src/main/cpp/class.cpp
src/main/cpp/charsetencoder.cpp
src/main/cpp/charsetdecoder.cpp
src/main/cpp/cacheddateformat.cpp
src/main/cpp/bytebuffer.cpp
src/main/cpp/bytearrayoutputstream.cpp
src/main/cpp/bytearrayinputstream.cpp
src/main/cpp/bufferedwriter.cpp
src/main/cpp/basicconfigurator.cpp
src/main/cpp/asyncappender.cpp
src/main/cpp/aprinitializer.cpp
src/main/cpp/appenderskeleton.cpp
src/main/cpp/appenderattachableimpl.cpp
   
)


add_definitions(-DAPR_DECLARE_STATIC)
add_definitions(-DAPU_DECLARE_STATIC)

add_library("log4cxx"  ${LOG4CXX_SOURCES} ${APR_UTIL_SOURCES} ${APR_SOURCES} ${EXPAT_SOURCES})
#add_executable("log4cxx" ${LOG4CXX_SOURCES})
#
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
list(APPEND LIBRARIES apr-1 aprutil-1 expat ws2_32 wsock32 rpcrt4 advapi32 odbc32 kernel32)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
list(APPEND LIBRARIES  winsock coredll)
endif()

target_link_libraries("log4cxx"  apr-1 aprutil-1 expat  ${LIBRARIES})

