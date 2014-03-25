/** 
 * @file	confparser.hpp
 * @brief	一个简单的配置解析管理类.
 *
 *  配置文件经解析后，加载到内存(map)中，后续直接从内存中查询配置信息.
 *  类似XML的DOM机制.
 * 
 * 
 *  提供配置文件的解析功能. 
 *      目前仅支持单个文件的解析, 后续考虑目录下同种多文件的解析.
 *
 *  用法：
 *      1. 在应用系统初始化时，初始化配置单体.
                CONF_PARSER_SIMPLE_INIT(conf_file);

                // 如果同时要加载更多的配置文件.
                CONF_PARSER_ADD_FILE(ano_conf_file1);
                CONF_PARSER_ADD_FILE(ano_conf_file2);
                ...
                CONF_PARSER_ADD_FILE(ano_conf_fileN);
                // 注: 这里多配置文件调多次CONF_PARSER_SIMPLE_INIT效果是一样的，
                //     但是调CONF_PARSER_ADD_FILE感觉更合适些.

                // 如果配置项已在缓冲区里，也可以采用以下方法.
                CONF_PARSER_ADD_TEXT(txt1)
                CONF_PARSER_ADD_TEXT(txt2)
                ...
                CONF_PARSER_ADD_TEXT(txtN)

        2. 读取信息.
                // 字符串型
                const char* pval = CONF_PARSER_GET_VAL(sec_name, key);
                // 整形.
                int val = CONF_PARSER_GET_NUM_VAL(sec_name, key);
                // bool型(由基本类型转换而来).
                int val = CONF_PARSER_GET_NUM_VAL(sec_name, key);                
                bool bval = (val != 0);                
                // ...

        同时请注意，因为考虑到是内部、低层调用，这里忽略了入口参数检查!!        
 *
 *  注：这个配置文件解析是以前写的，参考了网上的一些文章，做小工具时用过，今天就是重新排版了一下.
 *      如果使用时其中有什么错误，请网友自行修正哈^_^
 *      并同时发个邮件告诉我一声哈. bbxyard@gmail.com
 *
 * @release 
 *      1.0     第一版.
 *      1.0.1   第一版小幅修改，改文件名为conf_parser.hpp --> confparser.hpp
 *      1.1.0   第一版增量小修改:
 *              增加了配置更新功能，方便在外围如命令行更新个别信息等
 *　　　　　　　由于锁要考虑到OS－API的问题，这里更新功能，请注意在程序初始化时完成!
 *              此外，还修正了win32-vs2008下报"C2784"错误的问题，
 *              这里是由于<string>先前STL在容器中已隐式包含，在vs2008中未包含所致.
 *      1.2.0   第一版增量小修改:
 *              废弃了CONF_PARSER_ADD_MORE宏. 做了为细分.
 *              CONF_PARSER_ADD_TEXT --> 支持从文本缓冲区中读取配置.(此版新加功能)
 *              CONF_PARSER_ADD_FILE --> 支持从文本文件  中读取配置.(原CONF_PARSER_ADD_MORE功能)
 *
 * 
 * @author	bbxyard
 * @version	1.0.1
 * @date	2011年6月27日
 * 
 * @see
 * 
 * @par 版本记录：
 * <table border=1>
 *  <tr> <th>版本	<th>日期			<th>作者	<th>备注 </tr>
 *  <tr> <td>1.0	<td>2011年6月26日	<td>bbxyard	<td>创建 </tr>
 *  <tr> <td>1.0.1	<td>2011年6月27日	<td>bbxyard	<td>小幅修改 </tr>
 *  <tr> <td>1.1.0	<td>2012年12月27日	<td>bbxyard	<td>增加更新功能 </tr>
 * </table>
 */
#ifndef __CONF_PARSER_H__
#define __CONF_PARSER_H__


/************************************************************************/
/* #. 对外提供的接口功能.                                               */
/************************************************************************/
namespace txtutils
{
    class conf_info_t;
    class conf_parser
    {
    public:
        static conf_parser* get_inst()
        {
            static conf_parser* inst = NULL;
            if (NULL == inst)
            {
                inst = new conf_parser;
            }
            return inst;
        }

        // 将文件配置信息加载到内存.
        int init(const char* path, const char* params, void* reserved);

        // 如果要加载多个配置文件，可以考虑使用以下接口
        int add_entry(const char* file);            // 从一个文本文件  读取配置信息
        int add_text_entry(const char* txt);        // 从一段文本缓冲区读取配置信息

        // 提供字符串、数值类型的配置项查询功能.
        const char* get_value(const char* sec_name, const char* key) const;
        int get_num_value(const char* sec_name, const char* key) const;

        // 修改/更新功能.
        void set_value(const char* sec_name, const char* key, const char* value);

        ~conf_parser();

    protected:
        conf_parser();      // 单体将构造函数隐藏起来.
    private:
        conf_info_t*     conf_info_p_;
    };
}

// 方便使用的宏, 基本用法.
#define __GET_CONF_PARSER_INST()            txtutils::conf_parser::get_inst()
#define CONF_PARSER_SIMPLE_INIT(conf_file)  __GET_CONF_PARSER_INST()->init(conf_file, NULL, NULL)
#define CONF_PARSER_GET_VAL(sec, key)       __GET_CONF_PARSER_INST()->get_value(sec, key)
#define CONF_PARSER_GET_NUM_VAL(sec, key)   __GET_CONF_PARSER_INST()->get_num_value(sec, key)
#define CONF_PARSER_SET_VAL(sec, key, val)  __GET_CONF_PARSER_INST()->set_value(sec, key, val)

// 高级用法...
//#define CONF_PARSER_ADD_MORE(ano_conf_file) __GET_CONF_PARSER_INST()->add_entry(ano_conf_file)
#define CONF_PARSER_ADD_FILE(file)          __GET_CONF_PARSER_INST()->add_entry(file)
#define CONF_PARSER_ADD_TEXT(txt)           __GET_CONF_PARSER_INST()->add_text_entry(txt)



/************************************************************************/
/* #. 内部实现(下面的实现，可以放在其它文件中).                         */
/************************************************************************/
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <stdio.h>

#ifdef WIN32
#if _MSC_VER > 1300
#   pragma warning(disable:4996)
#endif  // _MSC_VER > 1300
#endif  // WIN32

namespace txtutils
{
    // #. 公共类型这定义.
    typedef std::pair<std::string, std::string> str_str_pair;
    typedef std::map<std::string, std::string>  str_str_map;
    typedef str_str_map::const_iterator         str_str_map_citer;

    /**
     * 使用map来管理配置信息对.
     */
    class conf_info_t
    {
    public:
        // 组合sec_name 和 key 生成内部使用的KEY.
        static const char* make_inside_key(const char* sec_name, const char* key, std::string& inside_key)
        {
            const std::string MIX_STR = "___#@#___";
            inside_key = std::string(sec_name) + MIX_STR + key;
            return inside_key.c_str();
        }

        const char* get_value(const char* sec_name, const char* key) const
        {
            std::string key_inside;
            make_inside_key(sec_name, key, key_inside);
            str_str_map_citer it = kv_map_.find(key_inside);

            return (kv_map_.end() == it)? "" : it->second.c_str();
        }

        int get_num_value(const char* sec_name, const char* key) const
        {
            std::string key_inside;
            make_inside_key(sec_name, key, key_inside);
            str_str_map_citer it = kv_map_.find(key_inside);

            std::string tmp = (kv_map_.end() == it)? "" : it->second.c_str();
            return atoi(tmp.c_str() );
        }

        void set_value(const char* sec_name, const char* key, const char* value)
        {
            std::string key_inside;
            make_inside_key(sec_name, key, key_inside);
            //str_str_map_citer it = kv_map_.find(key_inside); //wugk comments out for avoid warning as compiling
            kv_map_[key_inside] = value;
        }

        int add_cfg(const char* conf_file);
        int add_txt(const char* txt);

    protected:
        str_str_map         kv_map_;
    };

    /**
     * 一个简单的配置文件解析算法类.
     */
    struct conf_txt_line_parser
    {
    public:
        conf_txt_line_parser(str_str_map& kv_map) : kv_map_(kv_map) {}
    
        void operator() (const std::string &line)
        {
            size_t first    = 0;
            size_t last     = 0;

            static const size_t npos                = std::string::npos;        
            static const std::string BLANK_STR      = " \t\n";
            static const std::string COMMENT_STR    = "#;";     // 注释字符.
            static const std::string VAL_END_TAGS[] = 
            {
                " #",   " ;",
                "\t#",  "\t;",
            };

            // case0: 注释
            first   = line.find_first_of(COMMENT_STR);
            last    = line.find_first_of("=[");
            if (first < last) return;

            // case1: [section]
            first   = line.find('[');
            last    = line.find(']');
            if (npos != first && npos != last)
            {
                if (first+1 != last)
                    sec_ = line.substr(first+1, last-first-1);
                return;
            }

            // case 2: key-val
            str_str_pair key_val_pair;
            // 将行按"="，一分为二，得到粗糙的key-val
            first = line.find('=');
            if (npos == first)  return;
            std::string key_part = line.substr(0, first);
            std::string val_part = line.substr(first + 1);

            // 得到key
            first = key_part.find_first_not_of(BLANK_STR);
            last  = key_part.find_last_not_of(BLANK_STR);
            if (npos == first || npos == last)  return;
            key_val_pair.first = key_part.substr(first, last+1-first);

            // 解析val
            first = val_part.find_first_not_of(BLANK_STR);
            if (npos == first) return;
            size_t flag_size = sizeof(VAL_END_TAGS)/sizeof(VAL_END_TAGS[0]);
            size_t ix = 0;
            do 
            {
                last = val_part.find(VAL_END_TAGS[ix], first);
                ++ix;
            } while(ix < flag_size && npos == last);
            if (npos == last) last = val_part.length();
            val_part = val_part.substr(first, last-first);

            last = val_part.find_last_not_of(BLANK_STR);
            if (npos == last) return;
            key_val_pair.second = val_part.substr(0, last+1);

            conf_info_t::make_inside_key(sec_.c_str(), key_val_pair.first.c_str(), key_val_pair.first);
            kv_map_[key_val_pair.first] = key_val_pair.second;
            return;
        }
    private:
        str_str_map&    kv_map_;
        std::string     sec_;
    };

    inline int conf_info_t::add_cfg(const char* conf_file)
    {
        const int MAX_LINE_SIZE = 1024;
        char buf[MAX_LINE_SIZE + 1] = {0};
        FILE* fp = fopen(conf_file, "r");
        if (NULL == fp)
        {
            return -1;
        }

        // 方便处理期间把原文本先保存到内存(数组)里，后面整体解析.
        std::vector<std::string> org_txt;
        while (fgets(buf, MAX_LINE_SIZE, fp) != NULL)
        {
            org_txt.push_back(buf);    
        }
        fclose(fp);

        // 执行解析.
        std::for_each(org_txt.begin(), org_txt.end(), conf_txt_line_parser(kv_map_) );
        return 0;
    }

    inline int conf_info_t::add_txt(const char* txt_buff)
    {
        std::vector<std::string> org_txt;
        const char* psz_start = txt_buff;
        const char* psz_find  = txt_buff;

        while (*psz_find != 0)
        {
            while ( *psz_find != 0 && *psz_find != '\r' && *psz_find != '\n')
                ++psz_find;
            org_txt.push_back(std::string(psz_start, psz_find - psz_start) );
            // 跳过所有\r,\n
            while ( *psz_find != 0 && (*psz_find == '\r' || *psz_find == '\n') )
                ++psz_find;
            psz_start = psz_find;
        }

        // 执行解析.
        std::for_each(org_txt.begin(), org_txt.end(), conf_txt_line_parser(kv_map_) );
        return 0;
    }


    /************************************************************************/
    /* #. 对外管理类实现.                                                   */
    /************************************************************************/
    inline conf_parser::conf_parser()
    {
        conf_info_p_ = new conf_info_t;
    }
    inline conf_parser::~conf_parser()
    {
        delete conf_info_p_;
    }

    inline int conf_parser::init(const char* path, const char* params, void* reserved)
    {
        // 假定path是个文件路径. 如果目录，请自行扩展.
        int ret = 0;
        if (0) // 目录...
        {
            return 0;
        }
        else
        {
            // 先就考虑是单个文件.
            ret = add_entry(path);
            return ret;
        }        
    }
    inline int conf_parser::add_entry(const char* file)
    {        
        return conf_info_p_->add_cfg(file);
    }
    inline int conf_parser::add_text_entry(const char* txt)
    {
        return conf_info_p_->add_txt(txt);
    }

    inline const char* conf_parser::get_value(const char* sec_name, const char* key) const
    {
        if (NULL == conf_info_p_)    return NULL;
        return conf_info_p_->get_value(sec_name, key);
    }
    inline int conf_parser::get_num_value(const char* sec_name, const char* key) const
    {
        if (NULL == conf_info_p_)    return -1;
        return conf_info_p_->get_num_value(sec_name, key);
    }

    // 修改/更新功能.
    inline void conf_parser::set_value(const char* sec_name, const char* key, const char* value)
    {
        if (NULL == conf_info_p_)    return;
        return conf_info_p_->set_value(sec_name, key, value);
    }
}

#endif // __CONF_PARSER_H__
