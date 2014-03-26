#include <glog/logging.h>      
int main(int argc, char* argv[]) 
{   
    // Initialize Google's logging library.      
    google::InitGoogleLogging(argv[0]);        
    google::SetLogDestination(google::INFO|google::ERROR,"./log/");
    google::SetLogFilenameExtension(argv[0]);
    // ...       
    int num_cookies=0;
    LOG(INFO) << "Found " << num_cookies << " cookies";    
    LOG(ERROR) << "error Found " << num_cookies << " cookies";    
}
