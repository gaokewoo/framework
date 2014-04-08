#include "GLog.h"

GLog::GLog()
{
    google::InitGoogleLogging("");
    FLAGS_logbufsecs = 0; //缓冲日志输出，默认为30秒，此处改为立即输出
//    FLAGS_servitysinglelog = false; // 用来按照等级区分log文件
    FLAGS_stop_logging_if_full_disk = true; //当磁盘被写满时，停止日志输出
    google::SetLogDestination(google::GLOG_INFO, "./log/"); //设置 google::INFO 级别的日志存储路径和文件名前缀
    google::SetLogFilenameExtension("PluginManager_"); //设置文件名扩展，如平台？或其它需要区分的信息
    google::InstallFailureSignalHandler(); //捕捉 core dumped (linux)
 //   google::InstallFailureWriter(&Log); //默认捕捉 SIGSEGV 信号信息输出会输出到 stderr (linux)
}

void GLog::setLogFilenameExtension(string extension)
{
    google::SetLogFilenameExtension(extension.c_str()); //设置文件名扩展，如平台？或其它需要区分的信息
}

void GLog::setLogDestination(LOG_LEVEL level,string prefix)
{
    google::SetLogDestination(getMappingLevel(level), prefix.c_str());
}

google::LogSeverity GLog::getMappingLevel(LOG_LEVEL level)
{
    switch(level)
    {
        case INFO:
            return google::GLOG_INFO;
        case WARNING:
            return google::GLOG_WARNING;
        case ERROR:
            return google::GLOG_ERROR;
        case FATAL:
            return google::GLOG_FATAL;
        default:
            return google::GLOG_FATAL;
    }
}


