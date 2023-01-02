#include "queryhomeroz.h"

std::string QueryHomeRoz::Query(std::string query)
{
    std::string output;
    auto separated = additional_string_lib::SplitStr(query);
    if (separated == "SIZE")
    {
        separated = additional_string_lib::SplitStr(query);
        if (separated == "OF")
        {
            separated = additional_string_lib::SplitStr(query);
            if (separated == "lessons")
            {
                output = std::to_string(mgr_.SizeLessons());
                goto Answer;
            }
        }
    }
    Answer:
    return output;
}
